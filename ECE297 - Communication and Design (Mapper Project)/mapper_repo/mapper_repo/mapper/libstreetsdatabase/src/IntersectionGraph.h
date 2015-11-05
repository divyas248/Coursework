#pragma once
#include <boost/graph/astar_search.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/properties.hpp>

#include <map>
#include <vector>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/split_member.hpp>

#include <boost/graph/adj_list_serialize.hpp>

#include <boost/range/adaptor/indexed.hpp>

#include "StreetSegmentEnds.h"
#include "OSMDatabase.h"

using namespace std;
using namespace boost;

class VTKDrawing;

using boost::begin;
using boost::end;

typedef struct StreetProperties {
	string name;
	unsigned long long osmWayID;
	StreetProperties(unsigned long long osmWayID_=0,string name_="(unknown)") : name(name_),osmWayID(osmWayID_){};

    template<class Archive>void serialize(Archive& ar,const unsigned version){
    	ar & name & osmWayID;
    }
} StreetProperties;

// Bundled node and edge properties
typedef struct IntersectionProperties {
	unsigned long long osmNodeID=0;
	unsigned iseq=0;						// intersection sequence number (for when a given name is not distinct)
	LatLon pos={0,0};
	IntersectionProperties(){}
	IntersectionProperties(const Node& n) : osmNodeID(n.getID()),pos{n.getLat(),n.getLon()}{}

    template<class Archive>void serialize(Archive& ar,const unsigned version){
    	ar & osmNodeID & iseq & pos;
    }
} IntersectionProperties;


typedef struct {
	double speedLimit=0;
	double length=0;
	bool oneway=false;
	unsigned streetID=0;
	unsigned streetSegmentID=0;	// NOTE: not serialized, must be re-derived
	unsigned curvePointStart=0;
	unsigned curvePointEnd=0;

    template<class Archive>void serialize(Archive& ar,const unsigned version){
    	ar & speedLimit & length & oneway & streetID & curvePointStart & curvePointEnd;
    }
} StreetSegmentProperties;

typedef struct POIProperties {
	string name="";
	unsigned long long osmNodeID=0;
	LatLon pos;

	POIProperties(){}
	POIProperties(string name_,unsigned long long osmNodeID_,LatLon pos_) : name(name_),osmNodeID(osmNodeID_),pos(pos_){}
	template<class Archive>void serialize(Archive& ar,const unsigned version){
		ar & name & osmNodeID & pos;
	}
} POIProperties;

class IntersectionGraph {
public:
	typedef adjacency_list<vecS,vecS,bidirectionalS,
			IntersectionProperties,
			StreetSegmentProperties,
			no_property,
			vecS> Graph;

private:
	Graph G;
	map<unsigned long long,Graph::vertex_descriptor> nodes_map;

	vector<NaturalFeature> features;
private:

	map<string,unsigned> streetNames{make_pair("(unknown)",0)};
	vector<StreetProperties> streetProperties{StreetProperties()};

	vector<POIProperties> pointsOfInterest;

	vector<Graph::edge_descriptor> streetSegmentDescriptors;

	vector<LatLon> 		streetSegmentCurvePoints;

	unsigned add_street_if_new(const Way&);

	Graph::vertex_descriptor add_vertex_if_new(const Node&);
	Graph::edge_descriptor   add_edge_if_new(const Way&,Graph::vertex_descriptor u,Graph::vertex_descriptor v);

	BOOST_SERIALIZATION_SPLIT_MEMBER()

    template<class Archive>void save(Archive& ar,const unsigned version) const {
    	ar << G << nodes_map << streetNames << streetProperties << pointsOfInterest << streetSegmentCurvePoints << features;
    }

	template<class Archive>void load(Archive& ar,const unsigned version){
		ar >> G >> nodes_map >> streetNames >> streetProperties >> pointsOfInterest >> streetSegmentCurvePoints >> features;

		cout << "INFO: Loaded " << features.size() << " features" << endl;

		unsigned i=0;
		for (const auto& f : features)
		{
			string water = f.getTag("water");
			string land  = f.getTag("land");
//			if (water=="lake" || water=="river")
//				cout << "feature " << i << " has water=" << water << " with " << f.coords.size() << " points" << endl;
//			if (land=="island")
//				cout << "feature " << i << " has land=" << land << "with " << f.coords.size() << " points" << endl;
			++i;
		}

		//cout << "INFO: Loaded lake ID 13237 with " << features[13237].coords.size() << " points " << endl;

		// rebuild the edge index
		streetSegmentDescriptors.resize(num_edges(G));
        i=0;
        for(auto e : edges(G))
        {
            streetSegmentDescriptors[i] = e;
            G[e].streetSegmentID=i++;
        }
	}


	vector<string> poi_node_attrs{"convenience_store","cinema","amenity","beverages","building","cafe","microbrewery","social_facility", "railway"};

	// filter by
	class POIFilterByAttributes {
		vector<string> tags;
	public:
		POIFilterByAttributes(const vector<string>& tags_) : tags(tags_){}
		bool operator()(const Node& n) const {
			for(const string& tag : tags)
				if (n.hasTag(tag))
					return true;
			return false;
		}
	};

public:

	IntersectionGraph(){};
	IntersectionGraph(const OSMDatabase& wv,const vector<pair<unsigned long long,LatLon>>& append_poly = vector<pair<unsigned long long,LatLon>>());
	IntersectionGraph(const IntersectionGraph&) = default;

	unsigned long long getNumberOfIntersections() const  { return num_vertices(G); }
	unsigned long long getNumberOfStreetSegments() const { return num_edges(G); }
	unsigned long long getNumberOfStreets() const { return streetProperties.size(); }

	LatLon getStreetSegmentCurvePoint(unsigned ssID,unsigned i) const
		{ return streetSegmentCurvePoints[G[streetSegmentDescriptors[ssID]].curvePointStart+i]; }

	unsigned getStreetSegmentCurvePointCount(unsigned ssID) 	const
		{
			return G[streetSegmentDescriptors[ssID]].curvePointEnd -
				G[streetSegmentDescriptors[ssID]].curvePointStart;
		}

	unsigned long long getNumberOfPointsOfInterest() const { return pointsOfInterest.size(); }
	const POIProperties& getPointOfInterest(unsigned i) const { return pointsOfInterest[i]; }

	vector<unsigned long> getShortestPath(unsigned long long nu,unsigned long long nv);
	vector<unsigned long> getShortestPath(Graph::vertex_descriptor u,Graph::vertex_descriptor v);

	const StreetProperties& 		getStreet(unsigned i) const { return streetProperties[i]; }
	const StreetSegmentProperties& 	getStreetSegment(unsigned i) const { return G[streetSegmentDescriptors[i]]; }

	StreetSegmentEnds getStreetSegmentEnds(unsigned streetSegmentID) const {
		IntersectionGraph::Graph::edge_descriptor e = streetSegmentDescriptors[streetSegmentID];

		return StreetSegmentEnds {
			boost::source(e,G),
			boost::target(e,G)
		};
	}

	// TODO: NOTE - Features do not have their ndrefs populated and the nodes may be trimmed because they are not referenced
	// Not currently used, but may cause problems at some point

	LatLon getFeaturePoint(unsigned featureID,unsigned pointIdx) const { return features[featureID].coords[pointIdx]; }
	unsigned getFeaturePointCount(unsigned featureID) const { return features[featureID].coords.size(); }

	string getFeatureAttribute(unsigned id,const std::string& attr) const
	    {
	    	const Way& feature = features[id];
	    	if (feature.hasTag(attr))
	    		return feature.getTag(attr);
	    	else
	    		return "";
	    }
	unsigned getFeatureCount() const { return features.size(); }

	set<unsigned> getStreetsIncidentOnIntersection(unsigned i) const;
	set<unsigned> getStreetSegmentsIncidentOnIntersection(unsigned i) const;

	double getStreetSegmentSpeedLimit(unsigned i) const { return G[streetSegmentDescriptors[i]].speedLimit; }

	class distance_heuristic {
		const IntersectionGraph& IG;
		LatLon pos={0,0};
		typedef Graph::vertex_descriptor Vertex;
	public:
		typedef double CostType;

		distance_heuristic(const IntersectionGraph& IG_,Graph::vertex_descriptor v_) : IG(IG_),pos(IG_.G[v_].pos){ }

		CostType operator()(Vertex v){
			LatLon vpos=IG.G[v].pos;
			double d_lat=vpos.lat-pos.lat,d_lon=vpos.lon-pos.lon;
			return sqrt(d_lat*d_lat + d_lon*d_lon);					/// <===== THIS IS NOT A CORRECT DISTANCE METRIC; FOR DEMO ONLY
		}
	};

	friend boost::serialization::access;

	friend class VTKDrawing;

	string getIntersectionName(unsigned);
	LatLon getIntersectionPosition(unsigned intersectionID) const { return G[intersectionID].pos; }
};

struct found_goal {};

/** A* search visitor which throws a found_goal() exception when it finds the named vertex.
 * Visitor just visits everything in A* order; need to throw exception to terminate search.
 * Idea from boost astar-cities.cpp example.
 *
 * @tparam Vertex	Vertex type
 */

template<class Vertex>class astar_visitor_goal : public boost::default_astar_visitor {

	Vertex goal;

public:
	astar_visitor_goal(Vertex goal_) : goal(goal_){}
	template<class Graph>void examine_vertex(Vertex u,Graph& g)
	{
		if(u==goal)
			throw found_goal();
	}
};
