#ifndef MYPOI_H
#define	MYPOI_H
#include "../../libstreetsdatabase/src/LatLon.h"
#include <string>
#include <vector>
using namespace std;

class MyPOI {
public:
    // Constructor
    MyPOI(LatLon _ll, string _name) {ll = _ll; name = _name;}
    // Getters
    LatLon getLatLon() {return ll;}
    string getName() {return name;}
    vector<unsigned> getIDs() {return ids;}
    // Setter to add IDs
    void addID(unsigned id) {ids.push_back(id);}
private:
    // LatLon
    LatLon ll;
    // Name of POI
    string name;
    // IDs of POIs
    vector<unsigned> ids;
};

#endif	/* MYPOI_H */

