#ifndef MYSTREETDATA_H
#define	MYSTREETDATA_H
#include <vector>
#include <algorithm>
#include "MyStreetSegData.h"
#include <set>

using namespace std;

/* Data structure holds street information:
 * Street ID
 * Street segments belonging to the street
 */
class MyStreetData {
public:
    // Used constructor
    MyStreetData(unsigned _id) {id = _id;}
    // Setters
    void addStreetSegID(unsigned);
    void addInterID(unsigned);
    void setLength(double);
    // Getters
    unsigned getID() const;
    vector<unsigned> getStreetSegIDs() const;
    vector<unsigned> getInterIDs() const;
    double getLength() const;
    // Changes set to vector, for quicker return
    void setToVectorInterIDs(vector<unsigned>);
    set<unsigned> getIDfromSet() const;
private:
    // Street ID
    unsigned id;
    // Street segment ids
    vector<unsigned> streetSegIDs;
    // Vector of intersections in the street
    set<unsigned> interIDs;
    vector<unsigned> accessedInterIDs;
    double length;
};

#endif	/* MYSTREETDATA_H */

