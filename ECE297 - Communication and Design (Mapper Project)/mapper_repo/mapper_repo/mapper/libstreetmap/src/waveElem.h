#pragma once

class waveElem {
public:
    MyInterData *interPtr;
    int streetSegID;
    double travelTime;
    waveElem(MyInterData *ip, int ssID, double tt) 
        {interPtr = ip; streetSegID = ssID; travelTime = tt;}
    waveElem(waveElem const& source) {interPtr = source.interPtr; streetSegID = source.streetSegID; travelTime = source.travelTime;}
    bool operator< (waveElem const& rhs) const { return travelTime > rhs.travelTime; }
    bool operator> (waveElem const& rhs) const { return travelTime < rhs.travelTime; }
    bool operator<= (waveElem const& rhs) const { return travelTime >= rhs.travelTime; }
    bool operator>= (waveElem const& rhs) const { return travelTime <= rhs.travelTime; }
    bool operator== (waveElem const& rhs) const { return travelTime == rhs.travelTime; }
};

