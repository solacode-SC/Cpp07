#include "iter.hpp"

#include <iostream>

#include <string>

// Function to increment integer
void incrementInt(int& n)
{
    n++;
}

// Function to print integer
void printInt(const int& n)
{
    std::cout << n << " ";
}

// Template function to double value
template <typename T>
void doubleValue(T& value)
{
    value *= 2;
}

// Template function to print value
template <typename T>
void printValue(const T& value)
{
    std::cout << value << " ";
}

// Function to print string
void printString(const std::string& str)
{
    std::cout << str << std::endl;
}

int main(void)
{
    std::cout << "=== Test 1: Print integer array ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "Original array: ";
    ::iter(intArray, intLen, printInt);
    std::cout << std::endl;

    std::cout << "\n=== Test 2: Modify integer array (increment) ===" << std::endl;
    ::iter(intArray, intLen, incrementInt);
    std::cout << "After increment: ";
    ::iter(intArray, intLen, printInt);
    std::cout << std::endl;

    std::cout << "\n=== Test 3: String array ===" << std::endl;
    std::string strArray[] = {"Hello", "World", "from", "iter"};
    size_t strLen = 4;
    ::iter(strArray, strLen, printString);

    std::cout << "\n=== Test 4: Float array ===" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};
    size_t floatLen = 4;
    std::cout << "Original: ";
    ::iter(floatArray, floatLen, printValue<float>);
    std::cout << std::endl;

    ::iter(floatArray, floatLen, doubleValue<float>);
    std::cout << "After doubling: ";
    ::iter(floatArray, floatLen, printValue<float>);
    std::cout << std::endl;

    std::cout << "\n=== Test 5: Const array ===" << std::endl;
    const int constArray[] = {10, 20, 30, 40, 50};
    size_t constLen = 5;
    std::cout << "Const array: ";
    ::iter(constArray, constLen, printInt);
    std::cout << std::endl;

    return 0;
}