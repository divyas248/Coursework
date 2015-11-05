#pragma once
#include "OSMEntity.h"

#include <array>
#include <utility>
#include <cmath>

class Node : public OSMEntity {
	double lat,lon;

	friend boost::serialization::access;
	template<class Archive>void serialize(Archive& ar,unsigned int version){ OSMEntity::serialize(ar,version); ar & lat & lon; }

public:
	Node(unsigned long long id_=0,double lat_=NAN,double lon_=NAN) : OSMEntity(id_),lat(lat_),lon(lon_){}

	double getLat() const { return lat; }
	double getLon() const { return lon; }
	std::pair<double,double> getLatLon() const { return std::make_pair(lat,lon); }

	friend std::ostream& operator<<(std::ostream&,const Node&);
};

std::ostream& operator<<(std::ostream&,const Node&);
