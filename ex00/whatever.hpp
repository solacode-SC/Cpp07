#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>



// swap
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// min

template <typename T>
T const &min(T const &a, T const &b) {
    return (a < b) ? a : b;
}


// max
template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b) ? a : b;
}

#endif 