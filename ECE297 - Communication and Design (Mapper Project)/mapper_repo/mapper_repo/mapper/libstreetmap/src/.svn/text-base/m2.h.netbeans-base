#pragma once
#include <string>
#include "graphics.h"

#define SCALE_FACTOR 1 / 6
#define HIGH_ZOOM 0.001
#define MED_ZOOM 0.1
#define POI_THRESHOLD 0.00055
#define POI_HOVER_THRESHOLD 0.00055
#define POI_RADIUS 0.00005
#define FAST_ROAD_THRESHOLD 80
#define MED_ROAD_LENGTH 15000
#define RAD_TO_DEGREES 180.0 / 3.14159
#define MAX_NAME_LENGTH 25
#define NUM_GRID 4
#define HOVER_GRID 100
#define HOVER_TEXT_OFFSET 0.00015
#define TEXT_FONT 8
#define LENGTH_SCALE 50
#define LEFT_CLICK 1
#define RIGHT_CLICK 3
#define FIRST 1
#define SECOND 2
#define CLEARED 0
#define INVALID -1

// Define variables that can be used across other files.
extern bool hoverGrid[HOVER_GRID][HOVER_GRID];
extern unsigned hoverGridID[HOVER_GRID][HOVER_GRID];
extern float tmpLeft;
extern float tmpRight;
extern float tmpTop;
extern float tmpBot;
extern bool setSearched;
extern bool setDirectionClicked;

// Draws the map whose at map_path; this should be a .bin file.
void draw_map(std::string map_path);

// Respond to users after mouse clicks. On the first two clicks, the nearest intersections
// and the shortest path between them are found. To clear this saved path, right click.
void act_on_mousebutton(float, float, t_event_buttonPressed);

// Respond when the user clicks on the search button
void search(void (*drawscreen)(void));

// Respond when the user clicks the Path Button
void directions(void (*drawscreen)(void));

//Act on user hover over a location
void act_on_mousemove(float x, float y);

// Helper function to find the nearest intersection after a mouse click.
// Changes the x and y values that are given to the function to allow a marker to be drawn.
int find_closest_intersection(float &x, float &y);

// Redraw the screen after each event loop.
void draw_screen(void);

// Draw all water (water, ponds, lakes, lagoons, rivers, and streams) features.
void draw_water(void);

// Draw the remaining closed features (woods, grasslands, sand, beaches, and islands).
void draw_closed_features(void);

// Draw the streets based on the level of zoom.
void draw_streets(float, float, float, float, float, float);

// Draw the street names based on the level of zoom.
void draw_street_names(float, float, float, float, float, float);

// Draw a red circle at all points of interest.
void draw_POI(float, float, float, float);

// Draw the text given a point of interest and change the POI circle to blue.
void draw_POI_text(unsigned id_poi);

// Find the angle between three LatLon points
double find_angle_between_LatLon(LatLon, LatLon, LatLon);

// Draws the intersections to visit
void draw_intersections(vector<unsigned>);