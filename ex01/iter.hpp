#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// basic version 

template <typename T, typename H>
void iter(T* array, size_t length, H func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// const array version
template <typename T, typename H>
void iter(const T* array, size_t length, H func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif