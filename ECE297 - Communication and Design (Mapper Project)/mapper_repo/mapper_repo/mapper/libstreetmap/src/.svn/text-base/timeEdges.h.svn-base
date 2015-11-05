/* 
 * File:   timeEdges.h
 * Author: wangedga
 *
 * Created on March 29, 2015, 5:36 PM
 */

#ifndef TIMEEDGES_H
#define	TIMEEDGES_H

#include "graphics.h"


class timeEdges {
public:
    timeEdges(unsigned _source,unsigned _destination, double _time){source=_source; destination=_destination; time=_time;}
    
    bool operator< (timeEdges const& rhs) const { return time < rhs.time; }
    bool operator> (timeEdges const& rhs) const { return time > rhs.time; }
    bool operator<= (timeEdges const& rhs) const { return time <= rhs.time; }
    bool operator>= (timeEdges const& rhs) const { return time >= rhs.time; }
    bool operator== (timeEdges const& rhs) const { return (time == rhs.time || (source==rhs.destination && destination==rhs.source));}
    
    unsigned getSource(){return source;}
    unsigned getDestination(){return destination;}
    double getTime(){return time;}
    
private:
    unsigned source,destination;
    double time;
};


#endif	/* TIMEEDGES_H */

