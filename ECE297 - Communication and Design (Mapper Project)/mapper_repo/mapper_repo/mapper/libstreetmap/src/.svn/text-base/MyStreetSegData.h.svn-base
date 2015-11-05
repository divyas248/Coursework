#ifndef MYSTREETSEGDATA_H
#define	MYSTREETSEGDATA_H

#include <vector>
#include "../../libstreetsdatabase/src/LatLon.h"
#include "../../libstreetsdatabase/src/StreetSegmentEnds.h"

using namespace std;

/* Data structure to hold street segment information:
 * Street segment ID
 * The intersection IDs of the end of the street segment
 * Speed Limit
 * Latitude and longitude representation of each curve point in the segment
 */
class MyStreetSegData {
public:
    // Used constructor
    MyStreetSegData(
                    unsigned _from,
                    unsigned _to, 
                    unsigned _speed, 
                    vector<LatLon> &_curvepoints,
                    double &_travelTime,
                    string &_streetName,
                    unsigned _streetID,
                    double &_length
                    );
    
    // Getters
    unsigned getFrom() const;
    unsigned getTo() const;
    unsigned getSpeed() const;
    vector<LatLon> getCurves() const;
    double getTravelTime() const;
    string getStreetName() const;
    unsigned getStreetID() const;
    double getLength() const;
    
    // Setters
    void addCurvePoint(LatLon& _cp);
    
private:
    // Intersection ID at each end of MyStreetSegData
    unsigned from;
    unsigned to;
    // Speed limit
    unsigned speed;
    // Vector of LatLon's of curvepoints in MyStreetSegData
    vector<LatLon> curvepoints;
    // Travel time in minutes
    double travelTime;
    // Associated street name
    string streetName;
    // Associated street id
    unsigned streetID;
    // Length of street segment
    double length;
};

#endif	/* STREETSEG_H */

