#pragma once //protects against multiple inclusions of this header file

#include <string>
#include <vector>
#include <unordered_map>
#include <cfloat>
#include "StreetsDatabaseAPI.h"
#include "MyInterData.h"
#include "MyStreetData.h"
#include "MyStreetSegData.h"
#include "MyPOI.h"
#include "myFeatureData.h"

//use these defines whenever you need earth radius 
//or conversion from degrees to radians
#define EARTH_RADIUS_IN_METERS 6372797.560856
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define METERS_TO_KILOMETERS 1.0/1000.0
#define HOURS_TO_MINUTES 60.0
#define MAX_LATLON_SENTINEL 10000.0
#define ZOOM_FOR_SEARCH 0.001
#define INTER_GRID_SIZE 10

extern unordered_map<unsigned, MyStreetSegData> mapStreetSeg;
extern unordered_map<unsigned, MyFeatureData> mapFeatures;
extern unordered_map<string, MyStreetData> mapStreet;
extern unordered_map<string, MyInterData> mapInterID;
extern unordered_map<unsigned, MyInterData> mapInterName;
extern unordered_map<unsigned, MyPOI> mapPOIName;
extern unordered_map<string, MyPOI> mapPOIID;
extern vector<unsigned> interGrid[10][10];
extern vector<const char*> intersection_names;
extern vector<const char*> street_names;
extern vector<const char*> POI_names;
extern double maxLatitude;
extern double minLatitude;
extern double minLongitude;
extern double maxLongitude;
extern float longestLength;
extern unsigned long long numStreet;
extern unsigned long long numStreetSegs;
extern unsigned long long numIntersections;
extern unsigned long long numPOIs;
extern unsigned long long numFeatures;

//function to load bin or osm map
bool load_map(std::string map_name);

//close the loaded map
void close_map();

//function to return intersection id for an intersection name
unsigned find_intersection_id_from_name(std::string intersection_name);

//function to return street id for a street name
unsigned find_street_id_from_name(std::string street_name);

//function to return the street segments for a given intersection given an intersection name
std::vector<unsigned> find_intersection_street_segments(std::string intersection_name);

//function to return the street segments for a given intersection given an intersection id
std::vector<unsigned> find_intersection_street_segments(unsigned intersection_id);

//function to return street names at an intersection
std::vector<std::string> find_intersection_street_names(std::string intersection_name);

//function to return vector with the streets connected to an intersection
std::vector<std::string> find_intersection_street_names(unsigned intersection_id);

//can you get from intersection1 to intersection2 using a single street segment (hint: check for 1-way streets too)
bool are_directly_connected(std::string intersection_name1, std::string intersection_name2);

//find all intersections connected by one street segment from given intersection (hint: check for 1-way streets too)
std::vector<unsigned> find_adjacent_intersections(std::string intersection_name);

//for a given street, return all the street segments
std::vector<unsigned> find_street_street_segments(std::string street_name);

//for a given street, find all the intersections
std::vector<unsigned> find_all_street_intersections(std::string street_name);

//find distance between two coordinates
double find_distance_between_two_points(LatLon point1, LatLon point2);

//find the length of a given street segments
double find_street_segment_length(unsigned street_segment_id);

//find the length of a whole street
double find_street_length(std::string street_name);

//find the travel time to drive a street segment (time(minutes) = distance(Km)/speed_limit(Km/h)*60)
double find_segment_travel_time(unsigned street_segment_id);

//find the nearest point of interest (by name) to a given position
std::string find_closest_point_of_interest(LatLon my_position);

//sets intersection data into MyInterData
void collect_intersection_data(void);

//sets street segment data into MyStreetSegData
void collect_street_seg_data(void);

//sets street data into MyStreetData
void collect_street_data_a(void);
void collect_street_data_b(void);

//sets POI data into MyPOI
void collect_POI_data(void);

//sets Feature data into MyFeatureData
void collect_feature_data(void);

//helper function to set up a hashtable of key: sstreetid, value: street name
void helper_street_data(void);

//loads the intersection grid with the proper data
void load_inter_grid(void);