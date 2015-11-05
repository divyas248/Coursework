#pragma once

class distElem {
public:
    unsigned id;
    double distance;
    distElem(unsigned _id, double _distance) {id = _id; distance = _distance;}
    distElem(distElem const &source) {id = source.id; distance = source.distance;}
    bool operator< (distElem const& rhs) const { return distance > rhs.distance; }
    bool operator> (distElem const& rhs) const { return distance < rhs.distance; }
    bool operator<= (distElem const& rhs) const { return distance >= rhs.distance; }
    bool operator>= (distElem const& rhs) const { return distance <= rhs.distance; }
    bool operator== (distElem const& rhs) const { return distance == rhs.distance; }
};