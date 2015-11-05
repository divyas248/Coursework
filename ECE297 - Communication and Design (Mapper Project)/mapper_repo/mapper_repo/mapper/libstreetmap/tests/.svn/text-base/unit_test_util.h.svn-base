#ifndef UNIT_TEST_UTIL_HPP
#define UNIT_TEST_UTIL_HPP
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define MAX_VEC_PRINT 200

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for(size_t i = 0; i < vec.size(); i++) {
        os << vec[i];
#ifdef MAX_VEC_PRINT
        if(i > MAX_VEC_PRINT) {
            os << "...";
            break;
        }
#endif
        if(i != vec.size() - 1) {
            os << ", " ;
        }
    }
    os << "}";
    return os;
}

template<typename T>
float relative_error(T A, T B) {
    if (A == B) {
        return 0.;
    }

    if (fabs(B) > fabs(A)) {
        return fabs((A - B) / B);
    } else {
        return fabs((A - B) / A);
    }
}

template<typename T>
float absolute_error(T A, T B) {
    return fabs(A - B);
}

#endif
