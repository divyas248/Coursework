#include "m1.h"
#include "m2.h"
#include "m3.h"
#include "m4.h"
#include "graphics.h"
#include "preCompData.h"
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include "timeEdges.h"

// A hash table within a hashtable, first key is the starting intersection
// second key is the destination intersection, and the within preCompData
// is the travel time between the two, calculated by shortest paths using
// Dijkstra's algorithm, along with street names to detect street name changes
unordered_map<unsigned, unordered_map<unsigned, preCompData>> preComputedTimes;

//A hastable with a timeEdge object which contains the start and end destination with the weight as the time
vector<timeEdges> computedEdges;

//A vector with depot locations in them
vector<unsigned> depotVecs;

//A counter for the number of depotCount
unsigned depotCount;

//A vector with the intersections to search in them
vector<unsigned> intersectionsVecs;

//Number of number of intersections
unsigned numIntersectionsToTraverse;

// Travelling salesman algorithm, takes in intersections and depots and returns
// an approximately optimal path using greedy search algorithms (nearest neighbour
// and two-opt) intermittently with randomized hill climbing (simulated annealing)
vector<unsigned> traveling_salesman(vector<unsigned>& intersections_to_traverse, vector<unsigned> depot_locations) {
    // Initialize a clock in order to stop before 30s time limit
    clock_t startTime = clock();
    vector<unsigned> optimalPath;
    vector<unsigned> tempPath;
    vector<unsigned> inters = intersections_to_traverse;
    vector<unsigned> tempInter = inters;
    double travelTime = FLT_MAX;
    double tempTime;
    
    depotVecs=depot_locations;
    intersectionsVecs=intersections_to_traverse;
    
    numIntersectionsToTraverse=intersections_to_traverse.size();
    
    //The check for invalid graphs
    bool isValid=1;
    
    // Calculates all the times between every intersection and depot
    // Determines is the points are searchable through isValid
    preComputeTimes(inters, depot_locations,isValid);
    
    //Check if the graph is disconnected, return a empty vector if so
    if (!isValid){
        //cout<<"caught error"<<endl;
        return optimalPath;
    }
    // Use nearest neighbour multiple times for an initial locally optimized tour
  
    if(intersections_to_traverse.size() == 1) {
        vector<unsigned> path_inter;
        path_inter.push_back(intersections_to_traverse[0]);
        add_depots(path_inter, depot_locations);
        inters = path_inter;
    }
    
    else {
        // Use nearest neighbour multiple times for an initial locally optimized tour
        for (unsigned i = 0; i < MULTI_START_TRIES; i++) {
            nearest_neighbour(tempInter);
            tempTime = compute_inter_travel_time(tempInter);

            if (tempTime < travelTime) {
                travelTime = tempTime;
                inters = tempInter;
            }

            // Swaps the starting point to check if it's more optimal
            start_swap(tempInter);
        }

        // Uses simulated annealing, and two-opt within to find the best path
        simulated_annealing(inters, depot_locations, startTime);
    }
    
    intersections_to_traverse = inters;
    
    optimalPath = connect_next(inters);
    cout << "Optimal time: " << compute_path_travel_time(optimalPath) << endl;
    //Christophides(inters);
    
    return optimalPath;
}

// Returns a path based on the nearest neighbor heuristic for TSP
void nearest_neighbour(vector<unsigned> & intersections) {
    // Vector inters holds the correct order of intersections
    vector<unsigned> inters;
    // Set inters holds the visited intersections, makes it easier to
    // find (O(1)) if an intersection has been visited
    set<unsigned> visitedInters;
    double distance = 0;
    double bestDistance = FLT_MAX;
    unsigned bestInter = intersections[0];
    
    // Insert the first intersection, as it's already been visited
    visitedInters.insert(bestInter);
    inters.push_back(bestInter);
    
    for (unsigned i = 0; i < intersections.size(); i++) {
        bestDistance = FLT_MAX;
        LatLon currLatLon = mapInterName.find(bestInter)->second.getLatLon();
        
        for (unsigned j = 0; j < intersections.size(); j++) {
            // If the current intersection is not found (i.e. has not been visited)
            if (visitedInters.find(intersections[j]) == visitedInters.end()) {
                LatLon nextLatLon = mapInterName.find(intersections[j])->second.getLatLon();
                distance = find_distance_between_two_points(currLatLon, nextLatLon);
                
                // Compute the distance, and check if it's lower than the current best
                if (distance != 0 && distance < bestDistance) {
                    bestDistance = distance;
                    bestInter = intersections[j];
                }
            }
        }
        
        if (visitedInters.find(bestInter) == visitedInters.end()) {
            visitedInters.insert(bestInter);
            inters.push_back(bestInter);
        }
    }
    
    intersections = inters;
}

vector<unsigned> connect_next(vector<unsigned> & intersections) {
    vector<unsigned> path;
    vector<unsigned> tempPath;
    
    // Run through the intersections and connect all of them in the given order
    for (unsigned i = 0; i < intersections.size() - 1; i++) {
        tempPath = find_path_between_intersections(intersections[i], intersections[i + 1]);
        for (unsigned j = 0; j < tempPath.size(); j++) {
            path.push_back(tempPath[j]);
        }
    }
    return path;
}

// Modifies a path using the two-opt heuristic
void two_opt(vector<unsigned> & intersections, vector<unsigned> & depots) {
    vector<unsigned> tempInter = intersections;
    vector<unsigned> interWithDepots = intersections;
    // Initialize the intersection by finding depots
    add_depots(interWithDepots, depots);
    vector<unsigned> tempInterWithDepots;
    
    // Compute the travel time based on the depots
    double travelTime = compute_inter_travel_time(interWithDepots);
    double tempTime;
    unsigned tries = 0;
    
    while (tries < MAXIMUM_ATTEMPTS) {
        // Go through the intersections and perform two-opt
        // Starts at the first node, and iterates through until 
        // most combinations have been tested
        for (int i = 0; i < (int) intersections.size() - 1; i++) {
            for (int j = i + 1; j < (int) intersections.size(); j++) {
                // Calls two_opt_swap to perform swapping
                two_opt_swap(intersections, i, j, tempInter);
                tempInterWithDepots = tempInter;
                add_depots(tempInterWithDepots, depots);
                tempTime = compute_inter_travel_time(tempInterWithDepots);
                
                if (tempTime < travelTime) {
                    // Take the new path as the best path, reset tries
                    travelTime = tempTime;
                    intersections = tempInter;
                    interWithDepots = tempInterWithDepots;
                    // Reset tries count, as the result improved
                    tries = 0;
                }
                else {
                    tries++;
                }
            }
        }
    }

    intersections = interWithDepots;
}

// As part of the two-opt heuristic, this is the main mechanism
// that two-opt uses in order to sort and find a path
void two_opt_swap(vector<unsigned> & interPath, int index1, int index2, vector<unsigned> & tempInter) {
    vector<unsigned> newInter;
    
    // Take path[0] and connect it to path[index1 - 1]
    for (int i = 0; i < index1; i++) {
        newInter.push_back(interPath[i]);
    }
    
    // Take path[index1] and go till path[index2] and add them in reverse order to new route
    for(int j = index2; j >= index1; j--) {
        newInter.push_back(interPath[j]);
    }
    
    // Take path [index2 + 1] till path.end() and add them.
    for (int k = index2 + 1; k < (int) interPath.size(); k++) {
        newInter.push_back(interPath[k]);
    }
    
    // Assign the new path to our path-by-reference
    tempInter = newInter;
}

// Returns a path using the simulated annealing heuristic
void simulated_annealing(vector<unsigned> &intersections, vector<unsigned> &depots, clock_t startTime) {
    double temp = INITIAL_TEMPERATURE;
    vector<unsigned> newIntersections = intersections;
    vector<unsigned> tempInters;
    vector<unsigned> bestInters;
    double oldTravelTime = compute_inter_travel_time(intersections);
    double newTravelTime = 0;
    double travelTime = FLT_MAX;
    double AcceptProbability = 0;
    clock_t currentTime = clock();
    double timeLimit = TIME_LIMIT;
    
    double adaptiveAnnealing=1;
    
    if (intersections.size() < 20) {
        timeLimit = 20.0;
    }
    
    do {
        // Uses random heuristic to randomize the order
        start_swap(newIntersections);
        rotate_inter(newIntersections);
        newIntersections = random_neighbour(newIntersections);
        start_swap(newIntersections);
        newIntersections = random_neighbour(newIntersections);
        
        newTravelTime = compute_inter_travel_time(newIntersections);
        
        // Calculates a probability to accept the new route
        AcceptProbability=1/(1+exp(-(newTravelTime-oldTravelTime) / temp));
        
        if (AcceptProbability > ((double) rand() / (double) (RAND_MAX))){
            // Randomly accepts the new path, in order to try different permutations
            oldTravelTime = newTravelTime;
            tempInters = newIntersections;
            
            // Uses two opt algorithm in order to locally optimize the route
            two_opt(tempInters, depots);
            newTravelTime = compute_inter_travel_time(tempInters);
            
            if (newTravelTime < travelTime) {
                //cout << "Best from: " << travelTime << " to " << newTravelTime << endl;
                travelTime = newTravelTime;
                bestInters = tempInters;
                adaptiveAnnealing+=0.15;
            }

        }
        else if (temp < MINIMUM_TEMPERATURE) {
            // If the temperature falls below a minimum, it is refreshed
            // in order to try additional routes

            temp = INITIAL_TEMPERATURE;
        }
        adaptiveAnnealing-=0.1;
        temp *= TEMP_FACTOR*adaptiveAnnealing;
        currentTime = clock();
        
    } while((float) ((currentTime - startTime)/CLOCKS_PER_SEC) < timeLimit);
    
    // Assign the fastest path to the returning vector
    intersections = bestInters;
}

//returns a path with 2 intersections randomly swapped different than the given path
vector<unsigned> random_neighbour(vector<unsigned> intersections){
    unsigned pathSize = intersections.size();
    unsigned firstRandomNum = rand() % pathSize;
    unsigned secondRandomNum = rand() % pathSize;
    
    //adjust for random tending toward larger paths
    if (pathSize > 1) {
        while (firstRandomNum == secondRandomNum) {
            firstRandomNum = rand() % pathSize;
        }
    }
    
    //randomly select and then swap 2 of the intersections
    unsigned tempInter = intersections[firstRandomNum];
    intersections[firstRandomNum] = intersections[secondRandomNum];
    intersections[secondRandomNum] = tempInter;
    
    return intersections;
}

// Rotates the intersection order
void rotate_inter(vector<unsigned>& intersections) {
    // Choose indexes at each quarter of the vector
    unsigned index1 = intersections.size() / 4;
    unsigned index2 = intersections.size() / 2;
    unsigned index3 = intersections.size() * 3 / 4;
   
    // Set the iterators to their proper place
    auto iter1 = intersections.begin() + index1;
    auto iter2 = intersections.begin() + index2;
    auto iter3 = intersections.begin() + index3;
    
    // Randomly chooses the third index to be the end instead
    if (rand() > RAND_MAX / 2) {
        iter3 = intersections.end();
    }
    
    // Rotates the intersection using STL algorithm
    rotate(iter1, iter2, iter3);
}

// Returns the travel time given a vector of intersections (in order)
double compute_inter_travel_time(vector<unsigned> & inters) {
    double travelTime = 0;
    double tempTime;
    // Iterate through the inter vector to find the travel time
    // between each pair of intersections
    for (unsigned i = 0; i < inters.size() - 1; i++) {
        tempTime = preComputedTimes.find(inters[i])->second.find(inters[i + 1])->second.travelTime;
        
        // Checks to see if there is a street name change between different intersection
        // Paths, i.e. You have 3 intersections (1, 2, 3), and paths A between 1, 2 and 
        // B between 2, 3. If there is a street name change between the last street
        // segment of A, and the first street segment of B, add street change delay
        if ((i < (inters.size() - 2)) && preComputedTimes.find(inters[i])->second.find(inters[i + 1])->second.lastStreet != preComputedTimes.find(inters[i + 1])->second.find(inters[i + 2])->second.firstStreet) {
            tempTime += STREET_CHANGE_DELAY/SECS_PER_MIN;
        }
        travelTime += tempTime;
    }
    
    return travelTime;
}

// Randomly swaps the starting intersection with another
void start_swap(std::vector<unsigned> & inters) {
    unsigned index = rand() % inters.size();
    unsigned tempInter = inters[0];
    inters[0] = inters[index];
    inters[index] = tempInter;
}

// Adds the depots to the front and end of our path, in order to
// make a complete path
void add_depots(vector<unsigned> & inters, vector<unsigned> & depots) {
    double distance;
    double bestDistanceFirst = FLT_MAX;
    double bestDistanceLast = FLT_MAX;
    unsigned firstDepot = depots[0];
    unsigned lastDepot = depots[0];
    vector<unsigned> empty;
    // Add the front and back to the path
    for (unsigned i = 0; i < depots.size(); i++) {
        // Check the distance from depots to the fronts
        
        if (preComputedTimes.find(depots[i])->second.find(inters[0]) != preComputedTimes.find(depots[i])->second.end() && preComputedTimes.find(inters[inters.size() - 1])->second.find(depots[i]) != preComputedTimes.find(inters[inters.size() - 1])->second.end()) {
            distance = preComputedTimes.find(depots[i])->second.find(inters[0])->second.travelTime;
            if (distance < bestDistanceFirst) {
                bestDistanceFirst = distance;
                firstDepot = depots[i];
            }

            distance = preComputedTimes.find(inters[inters.size() - 1])->second.find(depots[i])->second.travelTime;
            if (distance < bestDistanceLast) {
                bestDistanceLast = distance;
                lastDepot = depots[i];
            }
        }
    }
    
    if (inters.size() != 0) {
        // Adds the closest (by time) depots to the back and front of the vector
        inters.push_back(lastDepot);
        inters.insert(inters.begin(), firstDepot);
    }
}

// Precompute the times between all combinations of points. Store these times in
// a hash table.
void preComputeTimes(vector<unsigned> deliveryIDs, vector<unsigned> depotIDs,bool &isValid) {
    // Combine all delivery locations and depots into one set.
    set<unsigned> allPoints(depotIDs.begin(), depotIDs.end());
    allPoints.insert(deliveryIDs.begin(), deliveryIDs.end());
    
    // Calculate all times from one location to all other locations.
    for(auto iter = allPoints.begin(); iter != allPoints.end(); iter++) {
        
        // Calls a function for each intersection and depot to calculate the
        // travel time between them (using dijkstra's) and saves it in the
        // global hash table of hash tables
        preComputeTimeHelper(*iter, allPoints, isValid);
        
        // Clears intersection flags as it's set in the previous function
        clearInterFlags();
        
        if (!isValid)
            return;
    }   
}

// Helper function uses Dijkstra's algorithm to find distance from one source
// to all other locations.
void preComputeTimeHelper(unsigned source, set<unsigned> locations,bool &isValid) {
    unordered_map<unsigned, preCompData> tempMapTimes;
    priority_queue<waveElem> wavefront;
    wavefront.push(waveElem(&(mapInterName.find(source)->second), NO_EDGE, 0.0));

    unsigned count = 0;
    double bestTime = FLT_MAX;
    double leastEntryTime = 0.0;
    
    while ((!wavefront.empty()) && count < locations.size()) {
        waveElem curr = wavefront.top();
        unsigned currID = curr.interPtr->getID();
        
        // Remove node from the front of wavefront.
        wavefront.pop();

        // Checks to see if the wavefront travel time (current path) is better than
        // any older path's travel time (saved from previous iterations).
        if (leastEntryTime < curr.interPtr->travelTime) {
            curr.interPtr->reachingEdge = curr.streetSegID;
            curr.interPtr->travelTime = curr.travelTime;
            
            if (currID != source && locations.find(currID) != locations.end()) { 
                // Reached destination.
                
                bestTime = curr.interPtr->travelTime;
                
                // Find the first and last street segment
                string firstStreet = getFirstStreet(currID);
                string lastStreet = mapStreetSeg.find(curr.interPtr->reachingEdge)->second.getStreetName();
                
                // Construct data member to be inserted
                preCompData pcd(bestTime, firstStreet, lastStreet);
                
                // Store in tempMapTimes.
                tempMapTimes.insert(make_pair(currID, pcd));
                         
                //Construct data member to make edges with weights as time
                timeEdges te(source,currID,bestTime);

                //check for duplicates
                if (find(computedEdges.begin(),computedEdges.end(),te)==computedEdges.end()){
                //Store timeEdges into the computedEdges vector  
                    if (find(depotVecs.begin(),depotVecs.end(),source)==depotVecs.end() && find(depotVecs.begin(),depotVecs.end(),currID)==depotVecs.end()  )
                    computedEdges.push_back(te);
                }
                count++;
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
                    
                    // Check if the street name changes
                    if ((curr.interPtr->reachingEdge != NO_EDGE) && (mapStreetSeg.find(curr.interPtr->reachingEdge)->second.getStreetName() != mapStreetSeg.find(streetSegIDs[i])->second.getStreetName())) {
                        travelTime += STREET_CHANGE_DELAY / SECS_PER_MIN;
                    }
                    
                    // Add the new intersection, the edge it took tor each and the travel time to the wavefront.
                    wavefront.push(waveElem(&(mapInterName.find(toID)->second), (int) streetSegIDs[i], travelTime));     
                }
            }
            
            if (!wavefront.empty()) {
                leastEntryTime = wavefront.top().travelTime;
                
            }
        }
    }
    //Checks for any disconnected intersections: return isValid=false if so
    if (count==0 && find(intersectionsVecs.begin(),intersectionsVecs.end(), source)!=intersectionsVecs.end())
        isValid=false;
    //Checks if all the number of discontinuities equals the number of depots & this discontinuity is a depot
    else if (count!=(locations.size()-1) && (locations.size()-1-count)==depotVecs.size()) {
        depotCount++;
        if(depotCount == depotVecs.size()) {
            isValid=false;
        }
    }
    
  // Insert small hash table into larger, global hash table.
    preComputedTimes.insert(make_pair(source, tempMapTimes));
}

// Returns the first street of the path
string getFirstStreet(unsigned currID) {
    MyInterData *currNode = &(mapInterName.find(currID)->second);
    int prevEdge = currNode->reachingEdge;
    unsigned prevNode;
    int lastEdge = prevEdge;
    
    // Checks until it reaches the first edge, lastEdge will save the last
    // available edge and then returns the name
    while (prevEdge != NO_EDGE) {
            if (mapStreetSeg.find(prevEdge)->second.getFrom() == currNode->getID()) {
                prevNode = mapStreetSeg.find(prevEdge)->second.getTo();
            }

            else {
                prevNode = mapStreetSeg.find(prevEdge)->second.getFrom();
            }
            currNode = &(mapInterName.find(prevNode)->second);
            lastEdge = prevEdge;
            prevEdge = currNode->reachingEdge;
    }
    
    return mapStreetSeg.find(lastEdge)->second.getStreetName();
}


void Christophides(vector<unsigned> & intersections){
    vector <timeEdges> minSpanTree;
    vector<unsigned>indices;
    
    //sort the edges of the tree
    sort(computedEdges.begin(), computedEdges.end());
    
    //for (auto iter=computedEdges.begin();iter!=computedEdges.end();iter++)
    //    cout<<computedEdges.size()<<endl;
     
    minSpanTree=form_minimum_spanning_tree(indices);
    
    for (auto iter=indices.begin();iter!=indices.end();iter++)
        cout<<(*iter);
    
    return;
}

//Form a minimum spanning tree using Kruskals Algorithm
vector<timeEdges>  form_minimum_spanning_tree(vector<unsigned> &indices){
    
    vector<timeEdges>minSpanTree;


    //add an intersection to the minimum spanning tree IF the node is not cyclic
    //cyclic: when multiple nodes are repeated in a given path
    for (auto iter=computedEdges.begin(); iter!=computedEdges.end(); iter++){
        //If not cyclic then add to the minSpanTree
        if (!isCyclic(minSpanTree, *iter, indices))
        {
            minSpanTree.push_back(*iter);
            //cout<<"source "<<(*iter).getSource()<<" dest "<<(*iter).getDestination()<<endl;
        }
    }
    
    return minSpanTree;
}

//Determines if a node forms a cyclic graph with a tree
bool isCyclic(vector<timeEdges> &minSpanTree, timeEdges& inputTimeEdge, vector<unsigned> &indices ){
    //if the destination is found in the tree then the graph is cyclic
    if (find(indices.begin(),indices.end(), inputTimeEdge.getDestination())!=indices.end())
        return true;
    
    else
    {
        //update the vertices in the searched tree
        indices.push_back(inputTimeEdge.getDestination());
        return false;
    }
}
