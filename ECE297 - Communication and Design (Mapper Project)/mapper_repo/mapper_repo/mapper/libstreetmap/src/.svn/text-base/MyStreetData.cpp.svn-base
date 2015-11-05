#include "MyStreetData.h"

// Adds a street segment into the vector of street segments belonging to the street
void MyStreetData::addStreetSegID(unsigned _streetSegID) {
    streetSegIDs.push_back(_streetSegID);
}
// Adds a intersection id to the vector of intersection ids
void MyStreetData::addInterID(unsigned _interID) {
    if(interIDs.find(_interID) == interIDs.end()) {
        interIDs.insert(_interID);
    }
}
// Sets street length.
void MyStreetData::setLength(double _length) {
    length = _length;
}
// Retrieves street ID
unsigned MyStreetData::getID() const {
    return id;
}
// Retrieves street length.
double MyStreetData::getLength() const {
    return length;
}
// Retrieves the vector of all street segments belonging to the street
vector<unsigned> MyStreetData::getStreetSegIDs() const {
    return streetSegIDs;
}
// Retrieves vector of all intersections belonging to the street
vector<unsigned> MyStreetData::getInterIDs() const {
    return accessedInterIDs;
}
// Changes our set to vector, for return purposes
void MyStreetData::setToVectorInterIDs(vector<unsigned> _ids) {
    accessedInterIDs = _ids;
    //std::copy(interIDs.begin(), interIDs.end(), accessedInterIDs.begin());
}

set<unsigned> MyStreetData::getIDfromSet() const {
    return interIDs;
}