#include "MyStreetSegData.h"

// Used constructor
MyStreetSegData::MyStreetSegData(
                    unsigned _from,
                    unsigned _to, 
                    unsigned _speed, 
                    vector<LatLon> &_curvepoints,
                    double &_travelTime,
                    string &_streetName,
                    unsigned _streetID,
                    double &_length
            ) 
{
    from = _from;
    to = _to;
    speed = _speed;
    curvepoints = _curvepoints;
    travelTime = _travelTime;
    streetName = _streetName;
    streetID = _streetID;
    length = _length;
}
// Retrieves intersection ID at from
unsigned MyStreetSegData::getFrom() const {
    return from;
}
// Retrieves intersection ID at to
unsigned MyStreetSegData::getTo() const {
    return to;
}
// Retrieves speed limit of street segment
unsigned MyStreetSegData::getSpeed() const {
    return speed;
}
// Retrieves a vector of curvepoints of the street segment
vector<LatLon> MyStreetSegData::getCurves() const {
    return curvepoints;
}
// Retrieves the travel time for the street segment
double MyStreetSegData::getTravelTime() const {
    return travelTime;
}
// Retrieves the name of the street to which the segment belongs
string MyStreetSegData::getStreetName() const {
    return streetName;
}
// Retrieves the ID of the street to which the segment belongs
unsigned MyStreetSegData::getStreetID() const {
    return streetID;
}
// Retrieves the length of the segment in km
double MyStreetSegData::getLength() const {
    return length;
}
// Adds a curvepoint
void MyStreetSegData::addCurvePoint(LatLon& _cp) {
    curvepoints.push_back(_cp);
}