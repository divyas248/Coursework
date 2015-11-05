#include <string>
#include <iostream>
#include "StreetsDatabaseAPI.h"
#include "IntersectionGraph.h"

#include <fstream>
#include <string>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Load and close the database

IntersectionGraph ig;


bool loadStreetDatabaseBIN(const std::string& fn)
{
	cout << "Loading binary database from file '" << fn << "'" << endl;
	ifstream is(fn.c_str());
        //Must check that stream is open and good, since good 
        //only checks error flags
	if (!is.is_open() || !is.good()) 
		return false;
	boost::archive::binary_iarchive ia(is);
	ia & ig;
	return true;
}

void closeStreetDatabase()
{
    ig = IntersectionGraph();
}



////////////////////////////////////////////////////////////////////////////////
// Aggregate queries

unsigned long long getNumberOfStreets()
{
	return ig.getNumberOfStreets();
}

unsigned long long getNumberOfStreetSegments()
{
	return ig.getNumberOfStreetSegments();
}

unsigned long long getNumberOfIntersections()
{
    return ig.getNumberOfIntersections();
}

unsigned long long getNumberOfPointsOfInterest()
{
    return ig.getNumberOfPointsOfInterest();
}


////////////////////////////////////////////////////////////////////////////////
// Intersection query

string getIntersectionName(unsigned intersectionID)
{
	return ig.getIntersectionName(intersectionID);
}

LatLon getIntersectionPosition(unsigned intersectionID)
{
	return ig.getIntersectionPosition(intersectionID);
}



// cache the out set
unsigned intersectionID_last=-1;
vector<unsigned> incidentStreetSegments;

unsigned getIntersectionStreetSegment(unsigned intersectionID,unsigned idx)
{
	if (intersectionID_last != intersectionID)
	{
		intersectionID_last = intersectionID;
		set<unsigned> s = ig.getStreetSegmentsIncidentOnIntersection(intersectionID);
		incidentStreetSegments = vector<unsigned>(s.begin(),s.end());
	}
    return incidentStreetSegments[idx];
}

unsigned getIntersectionStreetSegmentCount(unsigned intersectionID)
{
	if (intersectionID_last != intersectionID)
	{
		intersectionID_last = intersectionID;
		set<unsigned> s = ig.getStreetSegmentsIncidentOnIntersection(intersectionID);
		incidentStreetSegments = vector<unsigned>(s.begin(),s.end());
	}
    return incidentStreetSegments.size();
}

string getStreetName(unsigned streetID)
{
	return ig.getStreet(streetID).name.c_str();
}


////////////////////////////////////////////////////////////////////////////////
// Street segment query

unsigned getStreetSegmentStreetID(unsigned streetSegmentID)
{
	return ig.getStreetSegment(streetSegmentID).streetID;
}

bool getStreetSegmentOneWay(unsigned streetSegmentID)
{
    return ig.getStreetSegment(streetSegmentID).oneway;
}

StreetSegmentEnds getStreetSegmentEnds(unsigned streetSegmentID)
{
	return ig.getStreetSegmentEnds(streetSegmentID);
}

unsigned getStreetSegmentCurvePointCount(unsigned streetSegmentID)
{
	return ig.getStreetSegmentCurvePointCount(streetSegmentID);
}

LatLon getStreetSegmentCurvePoint(unsigned streetSegmentID,unsigned idx)
{
	return ig.getStreetSegmentCurvePoint(streetSegmentID,idx);
}

double getStreetSegmentSpeedLimit(unsigned streetSegmentID)
{
	return ig.getStreetSegmentSpeedLimit(streetSegmentID);
}



////////////////////////////////////////////////////////////////////////////////
// Points of Interest query


LatLon getPointOfInterestPosition(unsigned pointOfInterestID)
{
	return ig.getPointOfInterest(pointOfInterestID).pos;
}

string getPointOfInterestName(unsigned pointOfInterestID)
{
	return ig.getPointOfInterest(pointOfInterestID).name;
}

unsigned getFeatureCount()
{
	return ig.getFeatureCount();
}

string getFeatureAttribute(unsigned id,const std::string& attr)
{
	return ig.getFeatureAttribute(id,attr);
}

LatLon getFeaturePoint(unsigned featureID,unsigned pointIdx)
{
	return ig.getFeaturePoint(featureID,pointIdx);
}

unsigned getFeaturePointCount(unsigned id)
{
	return ig.getFeaturePointCount(id);
}

