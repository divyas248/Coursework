#include "m1.h"
#include "m2.h"
#include "m3.h"
#include "graphics.h"
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <queue>

// Comment the definitions to prevent drawing of the search and the final path.
//#define VISUALIZE_PATH
//#define VISUALIZE_SEARCH

using namespace std;

// Returns a path (route) between the start intersection and the end 
// intersection, if one exists. If no path exists, this routine returns 
// an empty (size == 0) vector. If more than one path exists, the path 
// with the shortest travel time is returned. The path is returned as a vector 
// of street segment ids; traversing these street segments, in the given order,
// would take one from the start to the end intersection.
vector<unsigned> find_path_between_intersections(unsigned intersect_id_start, unsigned intersect_id_end) {
    vector<unsigned> path;
    // Checks for identical start and end point. If identical, return a vector of size 0.
    if (intersect_id_start == intersect_id_end) {
        return path;
    }

    // If the bfsPath returns false, return empty path.
    if(!bfsPath(&(mapInterName.find(intersect_id_start)->second), intersect_id_end)) {
        return path;
    }
    
    path = bfsTraceBack(intersect_id_end);
    
    #ifdef VISUALIZE_PATH
    if (!path.empty()) {
        drawPath(path);
    }
    #endif
    
    return path;
}

// Returns the time required to travel along the path specified. The path
// is passed in as a vector of street segment ids, and this function can 
// assume the vector either forms a legal path or has size == 0.
// The travel time is the sum of the length/speed-limit of each street 
// segment, plus 15 seconds per turn implied by the path. A turn occurs
// when two consecutive street segments have different street names.
double compute_path_travel_time(const vector<unsigned>& path) {
    double travelTime = 0;
    
    // Checks if the path vector is empty
    if (path.size() == 0) {
        return travelTime;
    }
    
    // Get the first street segment's street name, for comparison in for loop.
    unsigned lastStreet = mapStreetSeg.find(*(path.begin()))->second.getStreetID();
    
    // Iterate through path, adding each segment's time.
    for (auto iter = path.begin(); iter != path.end(); iter++) {
        // Increment travel time using pre-built M1 function.
        travelTime += find_segment_travel_time(*iter) * SECS_PER_MIN;

        unsigned currentStreet = mapStreetSeg.find(*iter)->second.getStreetID();
        
        if (currentStreet != lastStreet) { // If there is a street name change, add a 15 second delay.
            travelTime += STREET_CHANGE_DELAY;
            lastStreet = currentStreet;
        }
    }
    
    return travelTime / SECS_PER_MIN;
}

// Returns the shortest travel time path (vector of street segments) from 
// the start intersection to a point of interest with the specified name.
// If no such path exists, returns an empty (size == 0) vector.
vector<unsigned> find_path_to_point_of_interest (unsigned intersect_id_start, string point_of_interest_name) {
    // Find a few of the closest POIs first.
    vector<unsigned> closePOIs = find_close_POIs(intersect_id_start, point_of_interest_name);
    vector<unsigned> path;
    vector<unsigned> tempPath;
    double travelTime = FLT_MAX;
    double lastTime = FLT_MAX;
    
    // Search through the closest 2 POIs.
    for (unsigned i = 0; i < closePOIs.size(); i++) {
        float lon = mapPOIName.find(closePOIs[i])->second.getLatLon().lon;
        float lat = mapPOIName.find(closePOIs[i])->second.getLatLon().lat;
        
        // Find the closest intersection to each POI.
        unsigned interID = find_closest_intersection_to_POI(lon, lat);
        
        // Checks if there is a interID to be found for a particular LatLon.
        if (interID == numIntersections) {
            vector<unsigned> empty;
            return empty;
        }
        
        // Find the path between the intersections.
        tempPath = find_path_between_intersections(intersect_id_start, interID);
        
        // Compute the travel time for the new path.
        travelTime = compute_path_travel_time(tempPath);
        
        // If the new travel time is less than the old, write over the path.
        if (travelTime != 0 && travelTime < lastTime) {
            lastTime = travelTime;
            path = tempPath;
        }
    }
    
    return path;
}
// Finds the ID of the closest POI to an intersection.
unsigned find_ID_of_closest_POI(unsigned intersect_id_start, string point_of_interest_name){
    // Find a few of the closest POIs first.
    vector<unsigned> closePOIs = find_close_POIs(intersect_id_start, point_of_interest_name);
    double travelTime = FLT_MAX;
    double lastTime = FLT_MAX;
    vector<unsigned> path;
    vector<unsigned> tempPath;
    unsigned closestID=0;
    
    // Search through the closest 2 POIs.
    for (unsigned i = 0; i < closePOIs.size(); i++) {
        float lon = mapPOIName.find(closePOIs[i])->second.getLatLon().lon;
        float lat = mapPOIName.find(closePOIs[i])->second.getLatLon().lat;
        
        // Find the closest intersection to each POI.
        unsigned interID = find_closest_intersection(lon, lat);
        
        // Find the path between the intersections.
        tempPath = find_path_between_intersections(intersect_id_start, interID);
        
        // Compute the travel time for the new path.
        travelTime = compute_path_travel_time(tempPath);
        
        // If the new travel time is less than the old, write over the path.
        if (travelTime != 0 && travelTime < lastTime) {
            closestID = closePOIs[i];
            lastTime = travelTime;
            path = tempPath;
        }
    }
    
    return closestID;
}

// Returns a boolean if a path is found, using Dijkstra's algorithm with A* heuristics.
// Flags in MyInterData are set in order to provide "breadcrumbs" to find
// the original path using the function bfsTraceBack.
bool bfsPath (MyInterData *source, int dest) {
    priority_queue<waveElem> wavefront;
    wavefront.push(waveElem(source, NO_EDGE, 0.0));
    
    bool found = false;
    double bestTime = FLT_MAX;
    double leastEntryTime = 0.0;
    
    while ((!wavefront.empty()) && (leastEntryTime < bestTime)) {
        waveElem curr = wavefront.top();
        unsigned currID = curr.interPtr->getID();
        
        // Remove node from the front of wavefront.
        wavefront.pop();

        // Checks to see if the wavefront travel time (current path) is better than
        // any older path's travel time (saved from previous iterations).
        if (leastEntryTime < curr.interPtr->travelTime) {
            curr.interPtr->reachingEdge = curr.streetSegID;
            curr.interPtr->travelTime = curr.travelTime;
            
            //Draw the search path
            #ifdef VISUALIZE_SEARCH
            drawSearchPath(curr.streetSegID);
            #endif
            
            if (currID == (unsigned) dest) { 
                // Reached destination.
                found = true;
                bestTime = curr.interPtr->travelTime;
            }
            
            vector<unsigned> streetSegIDs = mapInterName.find(currID)->second.getSSIDs();
            
            unsigned toID;
            for (unsigned i = 0; i < streetSegIDs.size(); i++) {
                // Checks which side of the street segment is adjacent, i.e. not our current node.
                if (currID == mapStreetSeg.find(streetSegIDs[i])->second.getTo()) {
                    toID = (mapStreetSeg.find(streetSegIDs[i])->second.getFrom());
                }
                
                else {
                    toID = mapStreetSeg.find(streetSegIDs[i])->second.getTo();
                }
                
                // Check if our current node can reach the to node
                if ( (!getStreetSegmentOneWay(streetSegIDs[i])) || (currID == mapStreetSeg.find(streetSegIDs[i])->second.getFrom())) {             
                    // Initialize travel time and add current time
                    double travelTime = mapStreetSeg.find(streetSegIDs[i])->second.getTravelTime();
                    travelTime += curr.travelTime;
                    
                    // Heuristic for A* algorithm.
                    LatLon currLatLon = mapInterName.find(currID)->second.getLatLon();
                    LatLon destLatLon = mapInterName.find(dest)->second.getLatLon();
                    LatLon nextLatLon = mapInterName.find(toID)->second.getLatLon(); 

                    travelTime += heuristic(currLatLon, destLatLon, nextLatLon);
                    
                    // Check if the street name changes
                    if ((curr.interPtr->reachingEdge != NO_EDGE) && (mapStreetSeg.find(curr.interPtr->reachingEdge)->second.getStreetName() != mapStreetSeg.find(streetSegIDs[i])->second.getStreetName())) {
                        travelTime += STREET_CHANGE_DELAY / SECS_PER_MIN;
                    }
                    
                    // Add the new intersection, the edge it took tor each and the travel time to the wavefront.
                    wavefront.push(waveElem(&(mapInterName.find(toID)->second), (int) streetSegIDs[i], travelTime));     
                }
            }
            
            if (!wavefront.empty()) leastEntryTime = wavefront.top().travelTime;
        }
    }
    
    return found;
}

// Traces back using the breadcrumbs left in bfsPath to return the
// optimal path from source to destination.
vector<unsigned> bfsTraceBack (int dest) {
    vector<unsigned> path;
    MyInterData *currNode = &(mapInterName.find(dest)->second);
    int prevEdge = currNode->reachingEdge;
    unsigned prevNode;
    
    while (prevEdge != NO_EDGE) {
        path.push_back(prevEdge);
        
        if (mapStreetSeg.find(prevEdge)->second.getFrom() == currNode->getID()) {
            prevNode = mapStreetSeg.find(prevEdge)->second.getTo();
        }
        
        else {
            prevNode = mapStreetSeg.find(prevEdge)->second.getFrom();
        }
        
        currNode = &(mapInterName.find(prevNode)->second);
        prevEdge = currNode->reachingEdge;
    }
    
    // Reverse the path as it currently goes from destination to source.
    reverse(path.begin(), path.end());
    
    // Reset the reachingEdge and travelTime flags of all intersections.
    clearInterFlags();
    
    return (path);
}

// Resets the flags (reachingEdge and travelTime) in our MyInterData structure
// as path-finding uses them.
void clearInterFlags() {
    for (unsigned i = 0; i < numIntersections; i++) {
        mapInterName.find(i)->second.reachingEdge = NO_EDGE;
        mapInterName.find(i)->second.travelTime = FLT_MAX;
    }
}

// A heuristic function for path-finding based on the straight-line distance 
// between the node and the destination.
double heuristic(LatLon source, LatLon dest, LatLon next) {
    double distance1 = find_distance_between_two_points(next, dest);
    double distance2 = find_distance_between_two_points(source, dest);
    
    return (distance1 - distance2) * METERS_TO_KILOMETERS / FAST_KM_PER_HR * MINS_PER_HR;
}

// Draws the identified path.
void drawPath(vector<unsigned> & path) {
    for (unsigned i = 0; i < path.size(); i++) {
        setcolor(PURPLE);
        setlinewidth(5);
        unsigned prevID = mapStreetSeg.find(path[i])->second.getFrom();
        unsigned nextID = mapStreetSeg.find(path[i])->second.getTo();
        
        vector<LatLon> curvePoints = mapStreetSeg.find(path[i])->second.getCurves();
        
        double x_prev = mapInterName.find(prevID)->second.getLatLon().lon;
        double y_prev = mapInterName.find(prevID)->second.getLatLon().lat;
        double x_to = mapInterName.find(nextID)->second.getLatLon().lon;
        double y_to = mapInterName.find(nextID)->second.getLatLon().lat;
        
        if (curvePoints.empty()) {
            drawline(x_prev, y_prev, x_to, y_to);
        }
        
        else {
            unsigned curvePointCount = curvePoints.size();
                    
            // Draw from the "from" intersection to the first curvePoint.
            // Then iteratively draw lines between the curvePoints.
            // Finally, connect the last curvePoint to the "to" intersection.

            double x = curvePoints[0].lon;
            double y = curvePoints[0].lat;

            drawline(x_prev, y_prev, x, y);

            for(unsigned j = 1; j < curvePointCount; j++) {
                x = curvePoints[j].lon;
                y = curvePoints[j].lat;

                x_prev = curvePoints[j - 1].lon;
                y_prev = curvePoints[j - 1].lat;

                drawline(x_prev, y_prev, x, y);
            }

            drawline(curvePoints[curvePointCount - 1].lon, curvePoints[curvePointCount - 1].lat, x_to, y_to);
        }
    }
}

// Draws all of the paths searched. Primarily used for visualization for debugging purposes.
void drawSearchPath(int streetSegID) {
    if (streetSegID != NO_EDGE) {
        setcolor(SADDLEBROWN);
        setlinewidth(3);
        unsigned interFrom = mapStreetSeg.find(streetSegID)->second.getFrom();
        unsigned interTo = mapStreetSeg.find(streetSegID)->second.getTo();
        double x_prev = mapInterName.find(interFrom)->second.getLatLon().lon;
        double y_prev = mapInterName.find(interFrom)->second.getLatLon().lat;
        double x = mapInterName.find(interTo)->second.getLatLon().lon;
        double y = mapInterName.find(interTo)->second.getLatLon().lat;
        drawline(x_prev, y_prev, x, y);
   }
}

// Finds the closest 2 POIs with a matching name relative to a starting intersection.
vector<unsigned> find_close_POIs(unsigned startID, string & POIname) {
    // Retrieve all IDs belonging to a POI name
    vector<unsigned> allPOIids = mapPOIID.find(POIname)->second.getIDs();
    vector<unsigned> POIids;
    priority_queue<distElem> POIpq;
    unsigned count = 0;
    
    // Check if the POI is in our database.
    if (allPOIids.empty()) { 
        return POIids; 
    }
    
    LatLon startLL = mapInterName.find(startID)->second.getLatLon();
    double distance;
    
    // Based on the distance from the start location, add the element into our queue.
    for (unsigned i = 0; i < allPOIids.size(); i++) {
        distance = find_distance_between_two_points(startLL, mapPOIName.find(allPOIids[i])->second.getLatLon());
        POIpq.push(distElem(allPOIids[i], distance));
    }
    
    // Push (up to) the closest 2 POIs to our returning vector.
    while(!POIpq.empty() && count < 2) {
        distElem temp = POIpq.top();
        POIpq.pop();
        POIids.push_back(temp.id);
        count++;
    }
    
    return POIids;
}

// Finds the closest POI relative to the center of the screen.
unsigned find_closest_poi_to_center(std::vector<unsigned> currPOIs){
    float currentLocationLon = get_visible_world().get_ycenter();
    float currentLocationLat = get_visible_world().get_xcenter();
    
    LatLon currentLocation(currentLocationLon, currentLocationLat);
    
    unsigned closestPOI = SENTINEL_ID;
    double distanceAway = DISTANCE_MAX;
    
    // Iterate through the POIs to find the closest one.
    for (auto iter= currPOIs.begin(); iter!=currPOIs.end(); iter++){
        double findDistance= find_distance_between_two_points(currentLocation,mapPOIName.find(*iter)->second.getLatLon());

        if (findDistance < distanceAway){  
            distanceAway = findDistance; 
            closestPOI = (*iter);
        }
    }
    return closestPOI;
}

// Finds the closest intersection from the grid given a POI.
unsigned find_closest_intersection_to_POI(double lon, double lat) {
    if(lon > maxLongitude || lat > maxLatitude) {
        return numIntersections;
    }
    
    double x = lon - minLongitude;
    double y = lat - minLatitude;
    
    // First find the interGrid index to which the POI belongs to
    int lonIndex = 0;
    int latIndex = 0;
    double latSpacing = (maxLatitude - minLatitude) / (INTER_GRID_SIZE - 1);
    double lonSpacing = (maxLongitude - minLongitude) / (INTER_GRID_SIZE - 1);

    for (unsigned j = 0; j < INTER_GRID_SIZE; j++) {
        if (x >= lonSpacing * j) {
            lonIndex = j;
        }
        
        if (y >= latSpacing * j) {
            latIndex = j;
        }
    }
    
    double minDistance = FLT_MAX;
    int interID = INVALID;
    
    // Checks the grid in a 3x3 box around the lon/lat to find
    // the closest intersection
    for (int i = lonIndex - 1; i < lonIndex + 1; i++) {
        if (i > -1 && i < INTER_GRID_SIZE) {
            for (int j = latIndex - 1; j < latIndex + 1; j++) {
                if (j > -1 && j < INTER_GRID_SIZE) {
                    for (unsigned k = 0; k < interGrid[i][j].size(); k++) {
                        LatLon location(lat, lon);
                        LatLon currLL = mapInterName.find(interGrid[i][j][k])->second.getLatLon();
                        
                        double distance = find_distance_between_two_points(currLL, location);

                        // Save the relevant information if the intersection is closer.
                        if (distance < minDistance){
                            minDistance = distance;
                            interID = interGrid[i][j][k];
                        }
                        
                    }
                }
            }
        }
    }
    
    return interID;
}

// Returns a LatLon of the desired intersection or POI.
LatLon find_intersection_or_poi(string searchQuery){
    bool isIntersection=(mapInterID.find(searchQuery)!=mapInterID.end());
    bool isPOI=(mapPOIID.find(searchQuery)!=mapPOIID.end());
    LatLon searchLatLon;
    
    if (isIntersection) {
        auto searchIter = mapInterID.find(searchQuery);
        
        if (searchIter!= mapInterID.end()){
            //perform the search on the intersection
            //collect the intersection latlon 
            auto iter= mapInterID.find(searchQuery);
            searchLatLon=iter->second.getLatLon();
        }
    }
    
    else if (isPOI){
        auto iter2= mapPOIID.find(searchQuery);
        //get the vector for the searched point
        
        vector <unsigned> currentPOI= iter2->second.getIDs();
        searchLatLon= mapPOIName.find(find_closest_poi_to_center(currentPOI))->second.getLatLon();
    }
    
    else 
        cout<<"Invalid Intersection or POI"<<endl;
    
    return searchLatLon;
}
