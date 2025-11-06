#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array {
    private:
        T* _array;
        unsigned int _size;
    
    public:
        // Default constructor
        Array() : _array(NULL), _size(0) {}
        Array(unsigned int size) : _array(new T[size]()), _size(size) {}
        // Copy constructor
        Array(const Array& other) : _array(new T[other._size]()), _size(other._size) {
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = other._array[i];
            }
        }
        // Assignment operator
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] _array;
                _size = other._size;
                _array = new T[_size]();
                for (unsigned int i = 0; i < _size; ++i) {
                    _array[i] = other._array[i];
                }
            }
            return *this;
        }
        // Destructor
        ~Array() {
            delete[] _array;
        }

        // Subscript operator
        T& operator[](unsigned int index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of bounds");
            }
            return _array[index];
        
        }
        const T& operator[](unsigned int index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of bounds");
            }
            return _array[index];
        }

        // Size method
        unsigned int size() const {
            return _size;
        }
};

#endif