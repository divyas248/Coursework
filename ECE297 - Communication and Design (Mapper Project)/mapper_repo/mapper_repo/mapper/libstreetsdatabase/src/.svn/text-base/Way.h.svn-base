#pragma once
#include "OSMEntity.h"

#include <boost/serialization/base_object.hpp>

#include <vector>

class OSMDatabase;
class IntersectionGraph;

class Way : public OSMEntity {

	friend boost::serialization::access;
	template<class Archive>void serialize(Archive& ar,unsigned int version){
		ar & boost::serialization::base_object<OSMEntity>(*this);
		ar & ndrefs;
	}

public:

	bool is_closed() const { return ndrefs.front() == ndrefs.back(); }

	std::vector<unsigned long long> ndrefs;		/// SHOULD BE PRIVATE!!

	Way(unsigned long long id_=0) : OSMEntity(id_){}

	void addNode(unsigned long long id_){ ndrefs.push_back(id_); }

	unsigned getNRefs() const { return ndrefs.size(); }

	const std::vector<unsigned long long>& getRefs() const { return ndrefs; }

	std::pair<std::vector<unsigned long long>::const_iterator,std::vector<unsigned long long>::const_iterator> getRefsRange() const { return make_pair(ndrefs.begin(),ndrefs.end()); }

	friend std::ostream& operator<<(std::ostream& os,const Way& w);
	friend class OSMDatabase;
	friend class IntersectionGraph;
};


// TODO: merge_poly_segments populates only coords; ndrefs (in Way) are left blank; not currently used but may cause problems

class NaturalFeature : public Way {

	template<class Archive>void serialize(Archive& ar,const unsigned int ver)
	{
		ar & boost::serialization::base_object<Way>(*this);
		ar & coords;
	}
public:
	std::vector<LatLon> coords;

	NaturalFeature() : Way(){}
	NaturalFeature(const Way& w) : Way(w){}

	friend class boost::serialization::access;
};

std::ostream& operator<<(std::ostream& os,const Way& w);
