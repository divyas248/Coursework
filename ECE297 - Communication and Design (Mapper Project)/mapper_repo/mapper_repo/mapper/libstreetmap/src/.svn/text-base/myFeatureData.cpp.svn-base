#include "myFeatureData.h"

//Constructor for MyFeature Data
 MyFeatureData::MyFeatureData(string _attribute,unsigned _featurePointCount, vector<LatLon> _inputLatLon,bool _isOpen){
     attributeType=_attribute;
     featurePointCount=_featurePointCount;
     featurePointsVector=_inputLatLon;
     isOpen=_isOpen;
 }
 
 //Returns attribute name
 string MyFeatureData::getAttribute() const{
     return attributeType;
 }
 
 //Returns Feature point count
 unsigned MyFeatureData::getFeaturePointCount() const{
     return featurePointCount;
 }
 
 //Returns Vector of Feature Poin LatLons
 vector<LatLon> MyFeatureData::getVectorFeaturePoints() const{
     return featurePointsVector;
 }
   
 //Returns true if feature set is open
 bool MyFeatureData::getIsOpen()const{
     return isOpen;
 }