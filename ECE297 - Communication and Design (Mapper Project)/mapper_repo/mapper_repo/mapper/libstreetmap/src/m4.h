#pragma once
#include <vector>
#include <ctime>

#include "timeEdges.h"

#define MAXIMUM_ATTEMPTS 1000
#define MAXIMUM_COUNT 10000
#define INITIAL_TEMPERATURE 1.0
#define MINIMUM_TEMPERATURE 0.08
#define TEMP_FACTOR 0.99
#define MULTI_START_TRIES 5
#define TIME_LIMIT 300.0
#define NEGATIVE_SENTINEL -1

    // This routine takes in a vector of N intersections that must be 
    // traversed in a path, and another vector of M intersections that 
    // are legal start and end points for the path. The first vector 
    // gives the intersection ids of a set of locations at which 
    // deliveries must be made. The second vector gives the intersection
    // ids of courier company depots containing trucks; you start at any
    // one of these depots and end at any one of the depots.
    // You can assume that N is always at least 1, and M is always at 
    // least one (i.e. both input vectors are non-empty).  You can also
    // assume that no intersection is repeated in either list and that
    // no intersection is both a delivery location and a depot (i.e. no
    // intersection will appear in both vectors).
    // This routine returns a vector of street segment ids that form a 
    // path, where the first street segment id is connected to a depot
    // intersection, and the last street segment id also connects to a
    // depot intersection.  If no path connecting all the delivery locations
    // and a start and end depot exists, this routine should return an 
    // empty (size == 0) vector.

std::vector<unsigned> traveling_salesman(   std::vector<unsigned>& intersections_to_traverse, 
                                            std::vector<unsigned> depot_locations   );

// Returns a path based on the nearest neighbour heuristic
void nearest_neighbour(std::vector<unsigned> &);

// Returns a path by connecting itself to the next intersection of
// the parameter given
std::vector<unsigned> connect_next(std::vector<unsigned> &);

// Modifies a path using the two-opt heuristic
void two_opt(std::vector<unsigned> &, vector<unsigned> &);

// As part of the two-opt heuristic, this is the main mechanism
// that two-opt uses in order to sort and find a path
void two_opt_swap(std::vector<unsigned> &, int, int, std::vector<unsigned> &);

// Returns a path using the simulated annealing heuristic
void simulated_annealing(std::vector<unsigned> &, std::vector<unsigned> &, std::clock_t);

// Returns a path that is 1 street different than the given path
std::vector<unsigned> random_neighbour(std::vector<unsigned>);

// Incrementally rotates the intersection order
void rotate_inter(std::vector<unsigned> &);

// Returns the travel time given a vector of intersections (in order)
double compute_inter_travel_time(std::vector<unsigned> &);

// Randomly swaps the starting intersection with another
void start_swap(std::vector<unsigned> &);

// Adds the depots to the front and end of our path, in order to
// make a complete path
void add_depots(vector<unsigned> &, vector<unsigned> &);

// Precompute the times between all combinations of points. Store these times in
// a hash table.
void preComputeTimes(std::vector<unsigned>, std::vector<unsigned>, bool &isValid);

// Helper function uses Dijkstra's algorithm to find distance from one source
// to all other locations.
void preComputeTimeHelper(unsigned source, std::set<unsigned> locations,bool &isValid);

// Returns the first street given the traceback edge
std::string getFirstStreet(unsigned);
//returns a path that is 1 street different than the given path
vector<unsigned> find_neighbour(std::vector<unsigned> intersections);

//Use Christophides Algorithm to find a tour given a set of intersection
void Christophides(vector<unsigned> & intersections);

//Form a minimum spanning tree using Kruskals Algorithm
vector<timeEdges> form_minimum_spanning_tree(vector<unsigned>&indices);

//Determines if a node forms a cyclic graph with a tree
bool isCyclic(vector<timeEdges> &minSpanTree, timeEdges& inputTimeEdge,vector<unsigned> &indices );
