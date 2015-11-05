#ifndef MYFEATURES_H
#define	MYFEATURES_H

#include <vector>
#include <iostream>

#include "../../libstreetsdatabase/src/LatLon.h"

using namespace std;

class MyFeatureData{
public:
    //Constructor
    MyFeatureData(string _attribute,unsigned _featurePointCount, vector<LatLon> _inputLatLon,bool _isOpen);
    
    //getters
    string getAttribute() const;
    unsigned getFeaturePointCount() const;
    vector<LatLon> getVectorFeaturePoints() const;
    bool getIsOpen() const;
    
    //setters
    void setAttribute(string _attribute){attributeType=_attribute;}
    void setFeaturePointCount(unsigned _featurePointCount){featurePointCount= _featurePointCount;}
    void setVectorFeaturePoints(vector<LatLon> _inputLatLon){featurePointsVector=_inputLatLon;}
    void setIsOpen(bool _isOpen){isOpen=_isOpen;}
    
private:
    //Attribute type
    string attributeType;
    //number of points for each feature
    unsigned featurePointCount;
    //Latlon for attribute features points
    vector <LatLon> featurePointsVector;
    bool isOpen;
};

#endif	/* MYFEATURES_H */

