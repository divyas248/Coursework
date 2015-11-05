#include "StreetSegmentEnds.h"
#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <complex>
#include "../../libstreetsdatabase/src/LatLon.h"
#include <cmath>
#include <cfloat>
#include <supportDataM1.h>

/* This function sets up several data structures for intersections, streets, street
 * segments, POIs, features and the intersection grid.
 * First, all of the intersections are iterated through using
 * the API calls, and all relevant data, including the intersection ID, LatLon,
 * adjacent intersections, street names, and street segments are stored in hash tables.
 * Second, all of the street segments are iterated through and relevant data is stored in the
 * street hash table and the street segment hash table. Third, all of the 
 * points of interest are iterated through and the corresponding names and LatLons are
 * stored in the POI hash table. Finally, the intersection grid is initialized by
 * partitioning them into their respective grid sections.
 */
bool load_map(std::string map_name) {

    bool load_success = loadStreetDatabaseBIN(map_name);
    
    if (!load_success) return load_success;
    
    numStreet = getNumberOfStreets();
    numStreetSegs = getNumberOfStreetSegments();
    numIntersections = getNumberOfIntersections();
    numPOIs = getNumberOfPointsOfInterest();
    numFeatures=getFeatureCount();
    
    helper_street_data();
    
    collect_intersection_data();
    collect_street_data_a();
    collect_street_seg_data();
    collect_street_data_b();
    collect_POI_data();
    collect_feature_data();
    
    load_inter_grid();
    
    return load_success;
}

// Close the map.
void close_map() {
    closeStreetDatabase();
}

// Implement the rest of the functions provided in m1.h

// Return intersection ID given the intersection name.
unsigned find_intersection_id_from_name(std::string intersection_name) {
    auto iter = mapInterID.find(intersection_name);
    if(iter == mapInterID.end()) {
        // Return a value that is not a valid intersection ID.
        return numIntersections + 1;
    }
    
    else {
        return iter->second.getID();
    }
}

// Return street ID given the street name.
unsigned find_street_id_from_name(string street_name) {
    auto iter = mapStreet.find(street_name);
    if(iter == mapStreet.end()) {
        // Return a value that is not a valid street ID.
        return numStreet + 1;
    }
    
    else {
        return iter->second.getID();
    }
}

// Returns a vector of street segments connected to an intersection given it's name
vector<unsigned> find_intersection_street_segments(std::string intersection_name){
    return mapInterID.find(intersection_name)->second.getSSIDs();
}

// Returns a vector of street segment IDs connected to an intersection given its ID
vector<unsigned> find_intersection_street_segments(unsigned intersection_id){
    return mapInterName.find(intersection_id)->second.getSSIDs();
}

// Function to return street names at an intersection
std::vector<std::string> find_intersection_street_names(std::string intersection_name) {
    return mapInterID.find(intersection_name)->second.getInterStreets();
}
// Same as above, but takes in the intersection ID instead
std::vector<std::string> find_intersection_street_names(unsigned intersection_id) {
    return mapInterName.find(intersection_id)->second.getInterStreets();
}

// Returns all adjacent intersections to the given intersection (not including itself)
std::vector<unsigned> find_adjacent_intersections(std::string intersection_name) {
    return mapInterID.find(intersection_name)->second.getAdjInterIDs();
}

// Returns the name of the closest point of Interest to a given latitude and longitude
string find_closest_point_of_interest(LatLon my_position){
    double min=0;
    string nameOfPointofInterest("");
    
    for (auto iter = mapPOIName.begin(); iter != mapPOIName.end(); iter++) {
    
        double distanceFromPointofInterest=find_distance_between_two_points(my_position,iter->second.getLatLon());
        
        //find the point of intersection with the minimum distance away
        if (distanceFromPointofInterest<min || min==0){
            min = distanceFromPointofInterest;
            nameOfPointofInterest=iter->second.getName();     
        }
    }
    
    return nameOfPointofInterest; 
}

//This function returns true if 2 given intersections are directly connected
bool are_directly_connected(std::string intersection_name1, std::string intersection_name2){
    if (intersection_name1 == intersection_name2) return true;
    vector<unsigned> adjInterIDs = mapInterID.find(intersection_name1)->second.getAdjInterIDs();
    unsigned interID2 = find_intersection_id_from_name(intersection_name2);
    for (unsigned i = 0; i < adjInterIDs.size(); i++) {
        if (adjInterIDs[i] == interID2) {
            return true;
        }
    }
    return false;
}
    
// For a given street name, return a vector of street segment id's
std::vector<unsigned> find_street_street_segments(std::string street_name) {
    return mapStreet.find(street_name)->second.getStreetSegIDs();
}

// For a given street, find all the intersections.
vector<unsigned> find_all_street_intersections(std::string street_name) {
    return mapStreet.find(street_name)->second.getInterIDs();
}

//Given 2 LatLon Points, calculates the distance between them in meters
double find_distance_between_two_points(LatLon point1, LatLon point2){
    double latOfPoint1=point1.lat*DEG_TO_RAD;
    double lonOfPoint1=point1.lon*DEG_TO_RAD;
    double latOfPoint2=point2.lat*DEG_TO_RAD;
    double lonOfPoint2=point2.lon*DEG_TO_RAD;
    double latAvg = cos((latOfPoint1 + latOfPoint2) / 2);
    
    //xDifference and yDifference are the coordinate differences x2-x1
    //where the x value is determined through the formula
    //(x,y)=(lon*cos(avgLat),lat) where avgLat = (latofIntersectionBeingChecked+latmy_position)/2
    double xDifference=lonOfPoint1*latAvg-lonOfPoint2*latAvg;
    double yDifference=latOfPoint1-latOfPoint2;
        
    //uses pythagorean theorem to calculate the distance between 2 coordinates
    double distanceBetweenTwoPoints=sqrt((xDifference*xDifference)+(yDifference*yDifference));
   
    return EARTH_RADIUS_IN_METERS * distanceBetweenTwoPoints;
    
}

// Find the length of a given street segment.
double find_street_segment_length(unsigned street_segment_id) {
    return mapStreetSeg.find(street_segment_id)->second.getLength();  
}

//Given a street name, find the street length
double find_street_length(std::string street_name){
    vector<unsigned> streetSegmentIDs = mapStreet.find(street_name)->second.getStreetSegIDs();
    double streetLength = 0;
    // Runs through and gets each street segment length
    for (unsigned i = 0; i < streetSegmentIDs.size(); i++) {
        streetLength += mapStreetSeg.find(streetSegmentIDs[i])->second.getLength();
    }
    return streetLength;
}

//find the travel time to drive a street segment (time(minutes) = distance(Km)/speed_limit(Km/h)*60)
double find_segment_travel_time(unsigned street_segment_id){
    return mapStreetSeg.find(street_segment_id)->second.getTravelTime();
}

//Gather and insert intersection data into MapInterID & MapInterName hashtables
void collect_intersection_data(void) {
    //sentinel values for maximum and minimum latlon
    minLatitude=MAX_LATLON_SENTINEL;
    maxLatitude=-MAX_LATLON_SENTINEL;

    minLongitude=MAX_LATLON_SENTINEL;
    maxLongitude=-MAX_LATLON_SENTINEL;

    for(unsigned a = 0; a < numIntersections; a++) {
        // Collect the intersection data.
        string thisName(getIntersectionName(a));
        LatLon thisLatLon = getIntersectionPosition(a);
        
        //find the max and min Lat where -90<=lat<=90 
        if (thisLatLon.lat>maxLatitude)
            maxLatitude=thisLatLon.lat;
        if (thisLatLon.lat<minLatitude)
            minLatitude=thisLatLon.lat;
        
        //find the max and min Lon where -180<=lon<=180
        if (thisLatLon.lon>maxLongitude)
            maxLongitude=thisLatLon.lon;
        if (thisLatLon.lon<minLongitude)
            minLongitude=thisLatLon.lon;
        
        // Find street segments that are connected to the intersection
        // and the street names that go through the intersection.
        vector<unsigned> vectorStreetSegments;
        unsigned numInterStreetSegs = getIntersectionStreetSegmentCount(a);
        
        vector<string> vectorSSNames;
        for(unsigned k = 0; k < numInterStreetSegs; k++) {
            unsigned interStreetSeg = getIntersectionStreetSegment(a, k);
            string interStreetName=(helperStreetData.find(getStreetSegmentStreetID(interStreetSeg))->second);
            
            auto vectorSSNamesEnd=vectorSSNames.end();
            auto iter = find(vectorSSNames.begin(), vectorSSNamesEnd, interStreetName);
            // If the street name is not found, insert it into the vector.
            if(iter == vectorSSNamesEnd) {
                vectorSSNames.push_back(interStreetName);
            }
            
            vectorStreetSegments.push_back(interStreetSeg);
        }
        
        // Find adjacent intersections.
        vector<unsigned> adjacent;
        
        for(auto iter = vectorStreetSegments.begin(); iter!= vectorStreetSegments.end(); iter++) {
            StreetSegmentEnds ssEnds = getStreetSegmentEnds(*iter);
            auto adj_end = adjacent.end();
            
            if(ssEnds.from == a) {
                if(adj_end == find(adjacent.begin(), adj_end, ssEnds.to))
                    adjacent.push_back(ssEnds.to);
            }

            else if(!getStreetSegmentOneWay(*iter)) {
                if(adj_end == find(adjacent.begin(), adj_end, ssEnds.from))
                    adjacent.push_back(ssEnds.from);
            }
        }
        
        // Store the data in an object of class MyInterData and add it to the hash table.
        MyInterData thisIntersection = MyInterData(a, thisName, thisLatLon, vectorStreetSegments, vectorSSNames, adjacent);
        mapInterID.insert(make_pair(thisName, thisIntersection));
        mapInterName.insert(make_pair(a, thisIntersection));
    }
}

//Gather and insert street segment data into mapStreetSeg hashtable
void collect_street_seg_data(void) {
    
    for(unsigned b = 0; b < numStreetSegs; b++) {
        // Collect the street data.
        unsigned thisStreetID = getStreetSegmentStreetID(b);
        string thisStreetName(helperStreetData.find(thisStreetID)->second);
        
        // Collect the street segment data.
        StreetSegmentEnds currentSegments=getStreetSegmentEnds(b);
        unsigned long thisFrom = currentSegments.from;
        unsigned long thisTo = currentSegments.to;
        double thisSpeedLimit = getStreetSegmentSpeedLimit(b);
        
        // Create a vector of curve points.
        unsigned curvePointCount = getStreetSegmentCurvePointCount(b);
        vector<LatLon> curvePoints;
        
        for(unsigned c = 0; c < curvePointCount; c++) {
            curvePoints.push_back(getStreetSegmentCurvePoint(b, c));
        }
        // Calculate the street segment length.
        LatLon start = mapInterName.find(thisFrom)->second.getLatLon();
        LatLon end = mapInterName.find(thisTo)->second.getLatLon();
        double length = 0;
        
        if(curvePoints.empty()) {
            length += find_distance_between_two_points(start, end);
        }
        
        else {
            length += find_distance_between_two_points(start, curvePoints[0]);
            
            for(unsigned i = 1; i < curvePointCount; i++) {
                length += find_distance_between_two_points(curvePoints[i], curvePoints[i - 1]);
            }
            
            length += find_distance_between_two_points(curvePoints[curvePointCount - 1], end);
        }
        
        // Calculate the street segment travel time.
        double lengthInKM = length * METERS_TO_KILOMETERS;
        
        //find the total length of all streets.    
        if(length > longestLength && thisStreetName!="(unknown)") {
            longestLength = length;
        }
        
        double timeInMinutes = lengthInKM / thisSpeedLimit * HOURS_TO_MINUTES;
        // Store the data in an object of class MyStreetSegData and add it to the hash table.
        MyStreetSegData thisStreetSeg(thisFrom, thisTo, thisSpeedLimit, curvePoints,
                timeInMinutes, thisStreetName, thisStreetID, length);
        mapStreetSeg.insert(make_pair(b, thisStreetSeg));
        
        // Add the street segment and its ends (from/to) to the associated street hash table.
        auto iter3 = mapStreet.find(thisStreetName);
        iter3->second.addStreetSegID(b);
        iter3->second.addInterID(thisFrom);
        iter3->second.addInterID(thisTo);
    }
   
}

//Gather and insert street data to mapStreet hashtable
void collect_street_data_a(void) {
    for(unsigned d = 0; d < numStreet; d++) {
        string thisStreetName (helperStreetData.find(d)->second);
        MyStreetData thisStreet(d);
        mapStreet.insert(make_pair(thisStreetName, thisStreet));
    }
}

//Gather and insert intersection ID data to mapStreet hashtable
void collect_street_data_b(void) {
    for(unsigned d = 0; d < numStreet; d++) {
        
        string currentStreetName=helperStreetData.find(d)->second;
        
        set<unsigned> setInterID = mapStreet.find(currentStreetName)->second.getIDfromSet();
        vector<unsigned> interID;
        for(auto iter = setInterID.begin(); iter != setInterID.end(); iter++) {
            interID.push_back(*iter);
        }
        
        mapStreet.find(currentStreetName)->second.setToVectorInterIDs(interID);
        
        vector<unsigned> streetSegmentIDs = mapStreet.find(currentStreetName)->second.getStreetSegIDs();
        double streetLength = 0;
        
        // Runs through and gets each street segment length
        for (unsigned i = 0; i < streetSegmentIDs.size(); i++) {
            streetLength += mapStreetSeg.find(streetSegmentIDs[i])->second.getLength();
        }
        
        mapStreet.find(currentStreetName)->second.setLength(streetLength);
    }
}

//Gather and insert point of interest data
void collect_POI_data(void) {
    for(unsigned i = 0; i < numPOIs; i++) {
        // Collect the point of interest data.
        MyPOI thisPOI(getPointOfInterestPosition(i), getPointOfInterestName(i));
        
        // Store the data in an object of class MyPOI and add it to the hash table.
        mapPOIName.insert(make_pair(i, thisPOI));
        if (mapPOIID.find(getPointOfInterestName(i)) == mapPOIID.end()) {
            mapPOIID.insert(make_pair(getPointOfInterestName(i), thisPOI));
        }
        mapPOIID.find(getPointOfInterestName(i))->second.addID(i);
        
    }
}

//sets Feature data into MyFeatureData
void collect_feature_data(void){
    for (unsigned i=0;i<numFeatures;i++){
        //Collect feature attributes and points for each feature
        unsigned numFeaturePoints=getFeaturePointCount(i);
        vector<LatLon> featureLatLon;
        
        //create a vector of feature LatLon points
        for (unsigned k=0;k<numFeaturePoints;k++){
            featureLatLon.push_back(getFeaturePoint(i,k));
        }
        
        // If the first and last feature points are equal, the feature is closed.
        bool currentOpen = !(featureLatLon[0].lat == featureLatLon[numFeaturePoints - 1].lat && featureLatLon[0].lon == featureLatLon[numFeaturePoints - 1].lon);
        
        //returns all natural, water, waterway or land features
        
        string currentFeature=getFeatureAttribute(i,"water");
        if (currentFeature=="")
            currentFeature=getFeatureAttribute(i,"natural");
        if (currentFeature=="")
            currentFeature=getFeatureAttribute(i,"waterway");
        if (currentFeature=="")
            currentFeature=getFeatureAttribute(i,"land");
        
        MyFeatureData currentFeatures(currentFeature,numFeaturePoints, featureLatLon, currentOpen);
        
        //store data in an object of class MyFeatureData for the hashtable
        mapFeatures.insert(make_pair(i,currentFeatures));
    }
}

//helper function to set up a hastable of key: streetid value: street name
void helper_street_data(void){
    for(unsigned d = 0; d < numStreet; d++) {
        string thisStreetName (getStreetName(d));
        helperStreetData.insert(make_pair(d, thisStreetName));
    }
}

// Loads the intersection data into the grid
void load_inter_grid(void) {
    // Splits the map into a 10x10 grid
    double latSpacing = (maxLatitude - minLatitude) / (INTER_GRID_SIZE - 1);
    double lonSpacing = (maxLongitude - minLongitude) / (INTER_GRID_SIZE - 1);
    int lonIndex = 0;
    int latIndex = 0;
    
    for (unsigned i = 0; i < numIntersections; i++) {
        LatLon currLatLon = mapInterName.find(i)->second.getLatLon();
        double x = currLatLon.lon - minLongitude;
        double y = currLatLon.lat - minLatitude;
        
        // Depending on the intersections coordinates, finds the 
        // appropriate index of the grid to insert the intersection into
        for (unsigned j = 0; j < INTER_GRID_SIZE; j++) {
            if (x >= lonSpacing * j) {
                lonIndex = j;
            }
            if (y >= latSpacing * j) {
                latIndex = j;
            }
        }
        interGrid[lonIndex][latIndex].push_back(i);
    }
}