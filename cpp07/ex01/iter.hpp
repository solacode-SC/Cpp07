#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename F>
void iter(T* array, std::size_t length, F function) {
    if (array == NULL || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

template <typename T, typename F>
void iter(const T* array, std::size_t length, F function) {
    if (array == NULL || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}
#endif