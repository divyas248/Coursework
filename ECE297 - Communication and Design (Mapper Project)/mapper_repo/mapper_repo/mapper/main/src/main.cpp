#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m2.h"
#include "m3.h"
#include <iostream>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>
#include <string>

using namespace std;

int main(){
    string city;
    bool valid_city = 0;
    
    cout << "City? (Must be in /cad2/ece297s/public/maps directory!)" << endl;
    
    while(!valid_city) { // Allow user to keep trying until a valid city is entered.
        cin >> city;
        city = "/cad2/ece297s/public/maps/" + city + ".bin";
        
        if(load_map(city)) {
            valid_city = 1;
        }
        
        else {
            cout << "City not found! Please try again!" << endl;
        }
    }
    
    draw_map(city);
    
    close_map();
    
    return 0;
}

