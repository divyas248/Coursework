#include <iostream>
#include <unittest++/UnitTest++.h>
#include "m1.h"
/*
 * This is the main that drives running
 * unit tests.
 */
int main(int argc, char** argv) {
    //Load the test map
    std::string map_name = "/cad2/ece297s/public/maps/toronto.bin";
    if(!load_map(map_name)) {
        std::cout << "ERROR: Could not load map file: '" << map_name << "'!";
        std::cout << " Subsequent tests will likely fail." << std::endl;
        //Don't abort tests, since we still want to show that all
        //tests fail.
    }

    //Run the unit tests
    int num_failures = UnitTest::RunAllTests();

    //Cleanup
    close_map();

    return num_failures;



}
