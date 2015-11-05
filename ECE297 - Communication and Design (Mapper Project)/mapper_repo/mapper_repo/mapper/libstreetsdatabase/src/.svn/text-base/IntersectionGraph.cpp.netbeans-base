#include "IntersectionGraph.h"

#include <fstream>
#include <functional>

#include <functional>

#include <boost/iterator/counting_iterator.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/range.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>

#include <unordered_map>

using boost::begin;
using boost::end;

/**
 * Constructs an IntersectionGraph from an OSMDatabase.
 *
 * Adds a node to the intersection graph for:
 *  (1) The beginning of every way
 *  (2) The end of every way
 *  (3) All intermediate nodes referenced by >1 way
 *
 * Decreases the number of redundant nodes (where there is no routing choice)
 */

typedef enum { Include, Exclude } HighwayAction;

typedef enum { Bidirectional, Forward, Backward } StreetDirection;

std::unordered_map<string,HighwayAction> highwayTags{
	make_pair("motorway",Include),
	make_pair("trunk",Include),
	make_pair("primary",Include),
	make_pair("secondary",Include),
	make_pair("tertiary",Include),
	make_pair("unclassified",Include),
	make_pair("residential",Include),
	make_pair("service",Include),
	make_pair("motorway_link",Include),
	make_pair("trunk_link",Include),
	make_pair("primary_link",Include),
	make_pair("secondary_link",Include),
	make_pair("tertiary_link",Include),
	make_pair("living_street",Include),
	make_pair("road",Include),

	make_pair("pedestrian",Exclude),
	make_pair("track",Exclude),
	make_pair("bus_guideway",Exclude),
	make_pair("raceway",Exclude),
	make_pair("footway",Exclude),
	make_pair("cycleway",Exclude),
	make_pair("bridleway",Exclude),
	make_pair("steps",Exclude),
	make_pair("path",Exclude),
	make_pair("proposed",Exclude),
	make_pair("construction",Exclude)
};


template<typename A,typename B>const B& take_first (const std::pair<A,B>& p){ return p.first; }
template<typename A,typename B>const B& take_second(const std::pair<A,B>& p){ return p.second; }

// *****************************************************************************
// TODO: Ideally should populate ndrefs vector as well in Way for NaturalFeature
// *****************************************************************************

std::vector<LatLon> merge_poly_segments(const std::vector<std::vector<std::pair<unsigned long long,LatLon>>>& outer)
{
    std::unordered_multimap<unsigned long long,int> outermap;

    // create a map of node ID to begin/end of curve

    unsigned i=0;
    for(const auto& v : outer)
    {
    	outermap.insert(make_pair(v.front().first,i));
    	outermap.insert(make_pair(v.back().first,-i));
    	++i;
    }


	double max_gap = 0;
	unsigned max_gap_ends_at = -1;

	i=0;
    for(const auto& u : outer)
    {
    	LatLon posu = u.back().second;

    	double dlat;
    	double dlon;
    	double best_d2    = std::numeric_limits<double>::infinity();
    	int best_idx = -1;

    	unsigned j=0;
    	for(const auto& v : outer)
    	{
    		if (i != j)
    		{
    		LatLon posv = v.front().second;
    		dlat = posu.lat - posv.lat;
    		dlon = posu.lon - posv.lon;

    		double d2;

    		if ((d2 = dlat*dlat+dlon*dlon) < best_d2)
    		{
    			best_d2 = d2;
    			best_idx = j;
    		}

    		posv = v.back().second;
    		dlat = posu.lat - posv.lat;
    		dlon = posu.lon - posv.lon;

    		if ((d2 = dlat*dlat+dlon*dlon) < best_d2)
    		{
    			best_d2 = d2;
    			best_idx = -j;
    		}
    		}
    		j++;
    	}

    	if (best_d2 > max_gap)
    	{
    		max_gap = best_d2;
    		max_gap_ends_at = i;
    	}

    	cout << "Curve " << i << " end best match to curve begin is curve " << best_idx << endl;
    	i++;
    }

    cout << "Largest curve gap ends at " << max_gap_ends_at << endl;


    // project

    std::vector<LatLon>  outer_p;

    for(unsigned i=max_gap_ends_at;i<outer.size();++i)
    	for(const auto p : outer[i]
    	                         | boost::adaptors::reversed
    	                         | boost::adaptors::transformed(take_second<unsigned long long,LatLon>))
    		outer_p.push_back(p);

    for(unsigned i=0;i<max_gap_ends_at;++i)
    	for(const auto p : outer[i]
    	                         | boost::adaptors::reversed
    	                         | boost::adaptors::transformed(take_second<unsigned long long,LatLon>))
    		outer_p.push_back(p);

    cout << "Returning vector of " << outer_p.size() << " points for outer boundary" << endl;

    return outer_p;

}

IntersectionGraph::IntersectionGraph(const OSMDatabase& osmdb,const vector<pair<unsigned long long,LatLon>>& poly_append)
{
	unsigned cpStart=0;
	map<unsigned long long,unsigned> node_ref_counts;
	unsigned total_refs;

	unsigned long long ways_include=0,ways_exclude=0,ways_unknown=0;

	std::unordered_map<string,unsigned> unknownHighwayTypes;

	tie(total_refs,node_ref_counts)=osmdb.getNodeRefCounts();

	// create mapping from Node ID to Node*
	std::unordered_map<unsigned long long,const Node*> node_id_map;
	for(const Node& n : osmdb.nodes)
		node_id_map.insert(make_pair(n.getID(),&n));

	std::unordered_map<unsigned long long,const Way*> way_id_map;
	for(const Way& w : osmdb.ways)
		way_id_map.insert(make_pair(w.getID(),&w));

	// loop over all ways
	for(const Way& w : osmdb.ways)
	{
		//if(w.hasTag("natural") && (w.getTag("natural")=="coastline" || w.getTag("natural")=="water" || w.getTag("natural")=="bay"))
		if (w.hasTag("natural") || w.hasTag("waterway") || w.hasTag("leisure"))
		{
			//cout << "Natural feature (way " << w.getID() << ") with " << w.ndrefs.size() << " node refs" << endl;
			string name;
			if ((name=w.getTag("name:en")).length() > 0)
			{
				//cout << "  name:en=" << name << endl;
			}
			else if ((name=w.getTag("name")).length() > 0)
			{
				//cout << "  name=" << name << endl;
			}

			if (w.hasTag("natural")){
				//cout << "  natural=" << w.getTag("natural") << endl;
			}
			if (w.hasTag("waterway")){
				//cout << "  waterway=" << w.getTag("waterway") << endl;
			}

			if (w.hasTag("leisure"))
			{
				string leisure=w.getTag("leisure");
				if (leisure == "park" || leisure == "nature_reserve"){
//					cout << "  leisure=" << w.getTag("leisure") << endl;
				}
				else
					continue;
			}

			features.push_back(w);
			features.back().coords.resize(features.back().ndrefs.size());
			auto feature_coords = features.back().coords.begin();

			for(unsigned long long ndr : features.back().ndrefs)
			{
				auto map_it = node_id_map.find(ndr);
				if (map_it == node_id_map.end())	// has dangling reference
				{
					features.pop_back();
					cout << "  ** Removed feature due to dangling reference to node " << ndr << endl;
					break;
				}
				else
					*(feature_coords++) = map_it->second->getLatLon();
			}
			continue;
		}

		if(!w.hasTag("highway"))
		{
			++ways_exclude;
			continue;
		}


		string highwaytype = w.getTag("highway");
		std::unordered_map<string,HighwayAction>::const_iterator tag_it=highwayTags.find(highwaytype);

		if(tag_it == highwayTags.end())
		{
			unknownHighwayTypes[highwaytype]++;
			++ways_unknown;
			continue;
		}
		else if (tag_it->second == Exclude)
		{
			++ways_exclude;
			continue;
		}
		else
			++ways_include;
		// falls through to here only if tag marked for inclusion


		// grab max speed if present, defaulting to 50
		double default_max=40;
		double maxspeed=default_max;
		if (w.hasTag("maxspeed"))
		{
			string s = w.getTag("maxspeed");
			stringstream ss(s);
			ss >> maxspeed;
			if (ss.fail() || !ss.eof())
			{
				cerr << "Invalid max speed '" << s << "' set to default" << endl;
				maxspeed=default_max;
			}
		}

		// check oneway status
		StreetDirection dir=Bidirectional;
		if (w.hasTag("oneway"))
		{
			string s = w.getTag("oneway");
			if (s=="yes")
				dir=Forward;
			else if (s=="-1")
				dir=Backward;
			else if (s=="no")
				dir=Bidirectional;
			else
				cerr << "Invalid street direction tag '" << s << "'" << endl;
		}



		Graph::vertex_descriptor u,v;

		// loop over all node references within a way
		double distance=0;

		vector<unsigned long long>::const_iterator way_nodes_it=w.ndrefs.begin();

		// skip if way list is empty or if the reference is not valid
		if (way_nodes_it == w.ndrefs.end() || node_id_map.find(*way_nodes_it) == node_id_map.end())
			continue;

		unsigned streetID=add_street_if_new(w);

		// insert into nodes->vertex descriptor map if new, set u = vertex descriptor
		u = add_vertex_if_new(*node_id_map.at(*way_nodes_it));

		LatLon last_pos = G[u].pos;
		LatLon pos;

		for(++way_nodes_it; way_nodes_it != w.ndrefs.end(); ++way_nodes_it)
		{
			// find node ID -> ref count map
			// should always be able to find; if exists a reference, reference count must be >= 1 and therefore in map
			// at() throws an exception if this is not the case
			if (node_id_map.find(*way_nodes_it)==node_id_map.end())
				continue;
			tie(pos.lat,pos.lon) = node_id_map.at(*way_nodes_it)->getLatLon();

			double d_lat=pos.lat-last_pos.lat;
			double d_lon=pos.lon-last_pos.lon;
			distance += sqrt(d_lat*d_lat+d_lon*d_lon);
			last_pos=pos;

			if (node_ref_counts.at(*way_nodes_it) >= 2 || way_nodes_it+1 == w.ndrefs.end())	// always include first/last of way, or anything with intersection
			{
				v = add_vertex_if_new(*node_id_map.at(*way_nodes_it));

				// add edge; should be new
				Graph::edge_descriptor e;
				bool added;
				//tie(e,added) = (dir == Backward ? add_edge(v,u,G) : add_edge(u,v,G));
				tie(e,added) = add_edge(u,v,G);
				assert(added);

				// update distance
				G[e].length=distance;
				G[e].streetID=streetID;
				G[e].oneway= dir != Bidirectional;
				G[e].speedLimit=maxspeed;
				G[e].curvePointStart=cpStart;
				G[e].curvePointEnd=cpStart=streetSegmentCurvePoints.size();
				distance=0;
				u=v;
			}
			else
				streetSegmentCurvePoints.push_back(pos);
		}
	}

	// dump tag report for highways
	cout << "Highways processed: of " << osmdb.ways.size() << " ways, included " << ways_include << ", excluded " << ways_exclude << endl;
	cout << "  Total of " << ways_unknown << " with unknown highway= tags; details: " << endl;
	for (const auto& p : unknownHighwayTypes)
		cout << "  " << p.first << ": " << p.second << " instances" << endl;


	// count oneways
	unsigned long long N_oneway=0;
	for (auto e : edges(G))
		if (G[e].oneway)
			++N_oneway;

	cout << "Of " << num_edges(G) << " street segments, there are " << N_oneway << " one-ways" << endl;


	// create vector of edge descriptors for quick edge access
	streetSegmentDescriptors.resize(num_edges(G));
	unsigned i=0;
	for(auto e : edges(G))
		G[e].streetSegmentID=i++;
	boost::copy(edges(G),streetSegmentDescriptors.begin());


	// intersection uniqueness (list of intersections -> # of instances)
	std::unordered_map<string,unsigned> icount;
	map<unsigned,unsigned> intersection_multiplicity;

	icount.reserve(num_vertices(G));			// reserve space for all vertices

	for(auto vp = vertices(G); vp.first != vp.second; ++vp.first)
	{
		stringstream ss;
		boost::copy(getStreetsIncidentOnIntersection(*vp.first),ostream_iterator<unsigned>(ss," "));
		G[*vp.first].iseq = icount[ss.str()]++;
	}

	for(const pair<string,unsigned>& p : icount)
		intersection_multiplicity[p.second]++;

	cout << "Intersection multiplicity: " << endl;
	for(const pair<unsigned,unsigned>& p : intersection_multiplicity)
		cout << "  " << p.first << " instances: " << p.second << endl;




	cout << "Filtering points of interest " << endl;
	cout << "  Tags: ";
	boost::copy(poi_node_attrs,std::ostream_iterator<string>(cout," "));

	for (const Node& n : osmdb.nodes | boost::adaptors::filtered(POIFilterByAttributes(poi_node_attrs)))
	{
		string name=n.getTag("name:en");
		if (name.length()==0)
			name = n.getTag("name");
		if (name.length()>0)
		{
			POIProperties poi(name,n.getID(),LatLon{n.getLat(),n.getLon()});
			pointsOfInterest.push_back(poi);
		}
	}
	cout << "  Of " << osmdb.nodes.size() << " nodes, filtered " << pointsOfInterest.size() << " points of interest" << endl;

	cout << "Graph conversion complete: " << num_vertices(G) << " vertices, " << num_edges(G) << " edges" << endl;

	vector<string> inames(num_vertices(G));
	for(unsigned i=0;i<inames.size();++i)
		inames[i] = getIntersectionName(i);

	sort(inames.begin(),inames.end());
	vector<string>::const_iterator it=inames.begin();

	cout << "checking for duplicate intersection names" << endl;
	while((it=adjacent_find(it,inames.cend())) != inames.cend())
		cout << "  Duplicate found: " << *(it++) << endl;
	cout << "DONE" << endl << flush;

	cout << "Extracting coastlines from multipolygon relation" << endl;

	for(const Relation& rel : osmdb.relations)
	{
		string water;
		if ((water = rel.getTag("water")).length() > 0)
		{
			if (water=="lake" || water == "river")
			{
				std::vector<std::vector<std::pair<unsigned long long,LatLon>>> outer;
				std::vector<std::vector<std::pair<unsigned long long,LatLon>>> inner;

				cout << "Found a water feature (" << water << ") named " << rel.getTag("name") << endl;

				if (!empty(rel.cnodes()))
					cerr << "  WARNING: Relation has " << boost::size(rel.cnodes()) << " node references which are not handled" << endl;
				if (!empty(rel.crels()))
					cerr << "  WARNING: Relation has " << boost::size(rel.crels()) << " relation references which are not handled" << endl;

				for(const auto& w : rel.cways())
				{
					unsigned long long wayID=w.first;
					const string& role=w.second;

					std::unordered_map<unsigned long long,const Way*>::const_iterator it;
					if ((it=way_id_map.find(wayID)) != way_id_map.end())
					{
						if (role.length() == 0)
							cerr << "WARNING: Missing role in water relation" << endl;
						else if (role=="inner" || role == "outer")
						{
							cout << "  Added way " << wayID << " with " << it->second->ndrefs.size() << " node refs as '" << role << "'" <<endl;
							if (role=="inner")
							{
								inner.emplace_back();//it->second->ndrefs.size());
								std::map<unsigned long long,unsigned>::const_iterator node_map_it;

								if (it->second->ndrefs.front() != it->second->ndrefs.back())
									cout << "WARNING: inner way in multipolygon relation is not closed" << endl;

								for(unsigned i=0;i<it->second->ndrefs.size();++i)
									if((node_map_it=osmdb.nodes_map.find(it->second->ndrefs[i])) != osmdb.nodes_map.end())
										inner.back().emplace_back(it->second->ndrefs[i],osmdb.nodes[node_map_it->second].getLatLon());
									else
										cout << "WARNING: Node ref " << it->second->ndrefs[i] << " dangling in relation" << endl;

							}
							else if (role=="outer")
							{
								std::map<unsigned long long,unsigned>::const_iterator node_map_it;
								outer.emplace_back();//it->second->ndrefs.size());
								for(unsigned i=0;i<it->second->ndrefs.size();++i)
									if((node_map_it=osmdb.nodes_map.find(it->second->ndrefs[i])) != osmdb.nodes_map.end())
										outer.back().emplace_back(it->second->ndrefs[i],osmdb.nodes[node_map_it->second].getLatLon());
									else
										cout << "WARNING: Node ref " << it->second->ndrefs[i] << " dangling in relation" << endl;
							}
						}
						else
							cerr << "WARNING: Unknown role '" << role << "' in water relation" << endl;
					}
					else
						cerr << "WARNING: Dangling way reference (ID " << wayID << ")" <<endl;


				}


				// serialize to binary file
//				std::ofstream os("lake_shape_ordered.bin");
//				boost::archive::binary_oarchive oa(os);

				// Here we have the inner and outer vectors populated
				features.push_back(NaturalFeature());
				features.back().coords = merge_poly_segments(outer);
				features.back().setTag("water",water);
//
//				oa & features.back().coords;

				// append if needed
			    for (const auto& app : poly_append)
			    	if (rel.getID() == app.first)
			    	{
			    		features.back().coords.push_back(app.second);
			    		cout << "Appending point (" << app.second.lat << "," << app.second.lon << ") to multipoly " << rel.getID() << endl;
			    	}

				std::vector<std::vector<LatLon>> inner_ll;

				// copy LatLon of inner features
			    for(unsigned i=0;i<inner.size();++i)
			    {
			    	features.emplace_back();
			    	features.back().coords.resize(inner[i].size());
			    	features.back().setTag("land","island");
			        boost::copy(inner[i]
			                          	  | boost::adaptors::transformed(take_second<unsigned long long,LatLon>),
			                          features.back().coords.begin());

			        inner_ll.push_back(features.back().coords);
			    }
//
//			    oa & inner_ll;

			}
		}

	}


}

IntersectionGraph::Graph::vertex_descriptor IntersectionGraph::add_vertex_if_new(const Node& node)
{
	unsigned long long osmNodeID=node.getID();
	map<unsigned long long,IntersectionGraph::Graph::vertex_descriptor>::iterator vdesc_it;
	bool isNew;

	tie(vdesc_it,isNew) = nodes_map.insert(make_pair(osmNodeID,0));

	if (isNew)
	{
		Graph::vertex_descriptor u = vdesc_it->second = add_vertex(G);
		G[u].osmNodeID=osmNodeID;
		tie(G[u].pos.lat,G[u].pos.lon) = node.getLatLon();
	}
	return vdesc_it->second;
}

unsigned IntersectionGraph::add_street_if_new(const Way& w)
{
	string streetName;

	if(w.hasTag("name:en"))
		streetName=w.getTag("name:en");
	else if (w.hasTag("name"))
		streetName=w.getTag("name");
	else streetName="(unknown)";

	map<string,unsigned>::iterator it;
	bool newStreet;
	tie(it,newStreet)=streetNames.insert(make_pair(streetName,0));
	if(newStreet)
	{
		it->second = streetProperties.size();
		streetProperties.emplace_back(w.getID(),streetName);
	}
	return it->second;
}

set<unsigned> IntersectionGraph::getStreetsIncidentOnIntersection(unsigned i) const
{
	set<unsigned> streetIDs;
	for(auto e : in_edges(i,G))
		streetIDs.insert(G[e].streetID);
	for(auto e : out_edges(i,G))
		streetIDs.insert(G[e].streetID);
	return streetIDs;
}

set<unsigned> IntersectionGraph::getStreetSegmentsIncidentOnIntersection(unsigned i) const
{
	set<unsigned> streetSegmentIDs;
	for(auto e : in_edges(i,G))
		streetSegmentIDs.insert(G[e].streetSegmentID);
	for(auto e : out_edges(i,G))
		streetSegmentIDs.insert(G[e].streetSegmentID);
	return streetSegmentIDs;
}

string IntersectionGraph::getIntersectionName(unsigned intersectionID)
{
	stringstream ss;
	unsigned Ns=0;

	for(unsigned streetID : getStreetsIncidentOnIntersection(intersectionID))
	{
		if (Ns > 0)
			ss << " & ";
		ss << streetProperties[streetID].name;
		++Ns;
	}

	unsigned i;
	if ((i=G[intersectionID].iseq) != 0)
		ss << " (" << i << ')';

	return ss.str();
}
