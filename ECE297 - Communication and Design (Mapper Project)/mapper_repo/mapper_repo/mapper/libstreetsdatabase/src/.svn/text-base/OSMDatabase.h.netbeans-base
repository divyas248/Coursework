#pragma once
#include "Node.h"
#include "Way.h"
#include "Relation.h"

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>

#include <boost/range/adaptor/map.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <unordered_set>

class IntersectionGraph;

template<class Result>class ConstFn {
	Result val;
public:
	ConstFn(const Result& val_) : val(val_){}
	typedef Result result_type;
	template<typename... Args>result_type operator()(Args...){ return val; }
};

class OSMDatabase {
	std::vector<Node> nodes;
	std::vector<Way>  ways;
	std::vector<Relation> relations;

	// maps from input ID# to vector position
	std::map<unsigned long long,unsigned> nodes_map;
	std::map<unsigned long long,unsigned> ways_map;
	//std::map<unsigned long long,unsigned> rel_map;

	std::vector<Way> ways_mapped;

	std::vector<Way> mapWays(const std::map<unsigned long long,unsigned>& nodes_map_) const;

	friend class boost::serialization::access;
	template<class Archive>void serialize(Archive& ar,const unsigned int version)
	{
		ar & nodes;
		ar & ways;
		ar & nodes_map;
		ar & ways_map;

		if (typename Archive::is_loading())
			ways_mapped = mapWays(nodes_map);
	}

public:

	OSMDatabase(){}
	OSMDatabase(const std::vector<Node>& nodes_,const std::vector<Way>& ways_,const std::vector<Relation>& relations_);
	//template<class NodePred=ConstFn<bool>,class WayPred=ConstFn<bool>>OSMDatabase(const OSMDatabase& wv_,NodePred np=ConstFn<bool>(true),WayPred wp=ConstFn<bool>(true));

	unsigned long long countWays() const { return ways_mapped.size(); }

	static bool isHighway(const Way& w){ return w.hasTag("highway"); }

	std::vector<std::string> getNodeAttributeKeys() const {
		std::unordered_set<std::string> node_attrs;
		for(auto n : nodes)
			for(auto t : n.getTags() | boost::adaptors::map_keys)
				node_attrs.insert(t);

		std::vector<std::string> attr_order(node_attrs.size());
		boost::copy(node_attrs,attr_order.begin());
		boost::sort(attr_order);
		return attr_order;
	}

	std::vector<std::string> getWayAttributeKeys() const {
		std::unordered_set<std::string> way_attrs;
		for(auto w : ways)
			for(auto t : w.getTags() | boost::adaptors::map_keys)
				way_attrs.insert(t);

		std::vector<std::string> attr_order(way_attrs.size());
		boost::copy(way_attrs,attr_order.begin());
		boost::sort(attr_order);
		return attr_order;
	}

	std::map<unsigned,unsigned> getNodeRefHist() const;

	std::pair<unsigned,std::map<unsigned long long,unsigned>> getNodeRefCounts() const;

	friend class IntersectionGraph;
};
