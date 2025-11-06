#include <iostream>
#include "Array.hpp"

// Test 1: Empty Array
void testEmptyArray() {
    std::cout << "\n=== Test 1: Empty Array ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    try {
        std::cout << "Trying to access empty[0]..." << std::endl;
        empty[0] = 42;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught (expected): " << e.what() << std::endl;
    }
}

// Test 2: Basic Construction and Access
void testBasicConstruction() {
    std::cout << "\n=== Test 2: Basic Construction ===" << std::endl;
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;
    
    // Fill array
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i * 10;
    }
    
    // Print array
    std::cout << "Array contents: ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Test 3: Deep Copy with Copy Constructor
void testCopyConstructor() {
    std::cout << "\n=== Test 3: Copy Constructor (Deep Copy) ===" << std::endl;
    Array<int> original(5);
    
    // Fill original
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i * 2;
    }
    
    std::cout << "Original: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    // Copy via copy constructor
    Array<int> copy(original);
    
    // Modify original
    original[0] = 999;
    original[1] = 888;
    
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy:     ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;
    
    if (copy[0] == 0 && copy[1] == 2) {
        std::cout << "✓ Deep copy works correctly!" << std::endl;
    } else {
        std::cout << "✗ Deep copy FAILED!" << std::endl;
    }
}

// Test 4: Deep Copy with Assignment Operator
void testAssignmentOperator() {
    std::cout << "\n=== Test 4: Assignment Operator (Deep Copy) ===" << std::endl;
    Array<int> original(5);
    
    // Fill original
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i + 100;
    }
    
    std::cout << "Original: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    // Copy via assignment operator
    Array<int> copy = original;
    
    // Modify original
    original[2] = 777;
    original[3] = 666;
    
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy:     ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;
    
    if (copy[2] == 102 && copy[3] == 103) {
        std::cout << "✓ Assignment operator deep copy works!" << std::endl;
    } else {
        std::cout << "✗ Assignment operator FAILED!" << std::endl;
    }
}

// Test 5: Out of Bounds Access
void testOutOfBounds() {
    std::cout << "\n=== Test 5: Out of Bounds Access ===" << std::endl;
    Array<int> arr(5);
    
    // Test negative index
    try {
        std::cout << "Trying to access arr[-1]..." << std::endl;
        arr[-1] = 42;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught (expected): " << e.what() << std::endl;
    }
    
    // Test index >= size
    try {
        std::cout << "Trying to access arr[5] (size is 5)..." << std::endl;
        arr[5] = 42;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught (expected): " << e.what() << std::endl;
    }
    
    // Test way out of bounds
    try {
        std::cout << "Trying to access arr[100]..." << std::endl;
        int x = arr[100];
        (void)x;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught (expected): " << e.what() << std::endl;
    }
}

// Test 6: String Array
void testStringArray() {
    std::cout << "\n=== Test 6: String Array ===" << std::endl;
    Array<std::string> strings(4);
    
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "from";
    strings[3] = "Templates!";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;
    
    // Test copy
    Array<std::string> copy = strings;
    strings[0] = "Modified";
    
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original: " << strings[0] << std::endl;
    std::cout << "Copy:     " << copy[0] << std::endl;
}

// Test 7: Const Array
void testConstArray() {
    std::cout << "\n=== Test 7: Const Array ===" << std::endl;
    Array<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    const Array<int> constArr = arr;
    
    std::cout << "Const array: ";
    for (unsigned int i = 0; i < constArr.size(); i++) {
        std::cout << constArr[i] << " ";
    }
    std::cout << std::endl;
    
    // This should not compile if uncommented:
    // constArr[0] = 99;
}

// Test 8: Self-Assignment
void testSelfAssignment() {
    std::cout << "\n=== Test 8: Self-Assignment ===" << std::endl;
    Array<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    std::cout << "Before self-assignment: ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    arr = arr;  // Self-assignment
    
    std::cout << "After self-assignment:  ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "✓ Self-assignment handled correctly!" << std::endl;
}

// Test 9: Different Size Assignment
void testDifferentSizeAssignment() {
    std::cout << "\n=== Test 9: Different Size Assignment ===" << std::endl;
    Array<int> arr1(3);
    Array<int> arr2(5);
    
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i;
    }
    
    for (unsigned int i = 0; i < arr2.size(); i++) {
        arr2[i] = i * 10;
    }
    
    std::cout << "arr1 (size " << arr1.size() << "): ";
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "arr2 (size " << arr2.size() << "): ";
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    // Assign arr2 to arr1
    arr1 = arr2;
    
    std::cout << "After arr1 = arr2:" << std::endl;
    std::cout << "arr1 (size " << arr1.size() << "): ";
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    // Modify arr2
    arr2[0] = 999;
    
    std::cout << "After modifying arr2[0] = 999:" << std::endl;
    std::cout << "arr1[0]: " << arr1[0] << " (should still be 0)" << std::endl;
    std::cout << "arr2[0]: " << arr2[0] << " (should be 999)" << std::endl;
}

// Test 10: Float Array
void testFloatArray() {
    std::cout << "\n=== Test 10: Float Array ===" << std::endl;
    Array<float> floats(4);
    
    floats[0] = 3.14f;
    floats[1] = 2.71f;
    floats[2] = 1.41f;
    floats[3] = 1.73f;
    
    std::cout << "Float array: ";
    for (unsigned int i = 0; i < floats.size(); i++) {
        std::cout << floats[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   Array Template Test Suite           ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    testEmptyArray();
    testBasicConstruction();
    testCopyConstructor();
    testAssignmentOperator();
    testOutOfBounds();
    testStringArray();
    testConstArray();
    testSelfAssignment();
    testDifferentSizeAssignment();
    testFloatArray();
    
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   All Tests Completed!                 ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    return 0;
}