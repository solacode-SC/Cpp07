#include "iter.hpp"
#include <iostream>
#include <string>

// print fts
template <typename T>
void printElement(T const &element) {
    std::cout << element << std::endl;
}

// increment fts
template <typename T>
void incrementElement(T &element) {
    ++element;
}

// non-temp 
void printInt(int const &element) {
    std::cout << element << std::endl;
}

// main 
int main() {
    // int array test
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array:" << std::endl;
    iter(intArray, intArrayLength, printElement<int>);

    iter(intArray, intArrayLength, incrementElement<int>);

    std::cout << "Incremented int array:" << std::endl;
    iter(intArray, intArrayLength, printElement<int>);

    // string array test
    std::string strArray[] = {"hello", "world", "iter", "template"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array:" << std::endl;
    iter(strArray, strArrayLength, printElement<std::string>);

    return 0;
}