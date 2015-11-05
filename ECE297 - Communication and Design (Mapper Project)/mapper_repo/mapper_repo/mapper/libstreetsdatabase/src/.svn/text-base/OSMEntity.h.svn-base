#pragma once
#include <iostream>
#include <string>
#include <map>
#include <cmath>

//#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/serialization.hpp>

#include "LatLon.h"

class OSMDatabase;

class OSMEntity {
	std::map<std::string,std::string> tags;
	unsigned long long id;

protected:

	friend boost::serialization::access;
	template<class Archive>void serialize(Archive& ar,unsigned int version){ ar & id & tags; }

public:
	OSMEntity(unsigned long long id_) : id(id_){}

	virtual ~OSMEntity(){}

	typedef std::map<std::string,std::string>::const_iterator tag_const_iterator;

	void setTag(const std::string& k,const std::string& v){ tags[k]=v; }
	std::string getTag(const std::string& k) const {
		tag_const_iterator it=tags.find(k);
		return it == tags.end() ? std::string() : it->second;
	}

	bool hasTag(const std::string& s) const { return tags.find(s) != tags.end(); }

	unsigned long long getID() const { return id; }

	void replaceTags(const std::map<std::string,std::string>& tags_){ tags=tags_; }
	const std::map<std::string,std::string>& getTags() const { return tags; }

	tag_const_iterator tags_begin() const { return tags.begin(); }
	tag_const_iterator tags_end()   const { return tags.end(); }

	// comparison functions
	static bool IDEqual(const OSMEntity& a,const OSMEntity& b){ return a.id==b.id; }
	static bool IDOrder(const OSMEntity& a,const OSMEntity& b){ return a.id<b.id; }

	friend class OSMDatabase;
};
