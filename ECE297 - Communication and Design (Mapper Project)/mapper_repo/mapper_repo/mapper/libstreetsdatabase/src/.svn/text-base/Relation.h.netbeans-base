#pragma once
#include "OSMEntity.h"
#include <boost/serialization/base_object.hpp>

#include <vector>

using namespace std;

class Relation : public OSMEntity {
	vector<pair<unsigned long long,string>> ndrefs;
	vector<pair<unsigned long long,string>> wayrefs;
	vector<pair<unsigned long long,string>> relrefs;

	friend boost::serialization::access;
	template<class Archive>void serialize(Archive& ar,unsigned int version){
		ar & boost::serialization::base_object<OSMEntity>(*this) &  ndrefs & wayrefs & relrefs;
	}
public:
	Relation(unsigned long long id_) : OSMEntity(id_){}

	void add_way_ref(unsigned long long id,const string& role){ wayrefs.push_back(make_pair(id,role)); }
	void add_node_ref(unsigned long long id,const string& role){ ndrefs.push_back(make_pair(id,role)); }
	void add_rel_ref(unsigned long long id,const string& role){ relrefs.push_back(make_pair(id,role)); }

	const vector<pair<unsigned long long,string>>& crels() const { return relrefs; }
	const vector<pair<unsigned long long,string>>& cnodes() const { return ndrefs; }
	const vector<pair<unsigned long long,string>>& cways() const { return wayrefs; }

	friend ostream& operator<<(ostream& os,const Relation& r);
};

ostream& operator<<(ostream& os,const Relation& r);
