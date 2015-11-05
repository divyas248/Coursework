#pragma once
#include <cmath>
#include <boost/serialization/serialization.hpp>

struct LatLon {
    // The member data, in degrees. Data is public. Initialized to invalid
    double lat=NAN;
    double lon=NAN;

    // Handy constructors.  The constructor with no arguments  is marked 
    // explicit so the compiler can't use it to type convert a void (missing)
    // argument to a (initialized to invalid) LatLon in a function call.
    LatLon(double lat_,double lon_) : lat(lat_),lon(lon_){}
    LatLon(std::pair<double,double> p) : lat(p.first),lon(p.second){}
    explicit LatLon(){} 

    // This function is used when loading the map database data in from a 
    // database.bin file. Will not be used by students.
    template<class Archive>void serialize(Archive& ar,const unsigned version){
    	ar & lat & lon;
    }
};
