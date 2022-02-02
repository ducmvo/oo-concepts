// Author:      Duc Vo
// Filename:    jumpPrime.h
// Date:        January 28, 2022,
// Version:     1.0
// Description: This program tests the duelingJP class
// Input:       none
// Process:     Create arrays of integer values to instantiate duelingJP objects.
//              The program create containers of smart pointers to hold a variety
//              of duelingJP objects and tests all of its public methods
// Output:      none

#include <iostream>
#include <memory>
#include <vector>
#include <stdio.h>
#include "duelingJP.h"
using namespace std;

void generateValues(int[], int, int, int);
// Description: this program tests the duelingJP class
// Input:       array of integer, size of the array, minimum and maximum values
// Process:     generate and array of random integer values with input size within
//              the provided minimum and maximum values
// Modify:      the input array
// Output:      none

int main() {

    const int SIZE = 10;
    const int MIN = 1000;
    const int MAX = 1040;
    int values[SIZE];

    printf("\n=== Welcome to duelingJP testing driver ====\n");

    // Create containers for smart pointers
    vector<unique_ptr<duelingJP>> uv;
    vector<shared_ptr<duelingJP>> sv;

    // Create Shared pointers
    generateValues(values, SIZE, MIN, MAX);
    shared_ptr<duelingJP> sharePtr(new duelingJP(SIZE, values));

    generateValues(values, SIZE, MIN, MAX);
    shared_ptr<duelingJP> sharePtr1(new duelingJP(SIZE, values));

    // Create unique pointers
    generateValues(values, SIZE, MIN, MAX);
    unique_ptr<duelingJP> ptr1(new duelingJP(SIZE, values));

    generateValues(values, SIZE, MIN, MAX);
    unique_ptr<duelingJP> ptr2(new duelingJP(SIZE, values));

    generateValues(values, SIZE, MIN, MAX);
    unique_ptr<duelingJP> ptr3(new duelingJP(SIZE, values));

    // Test duelingJP objects
    printf("\n=== TEST CONSTRUCTOR ===\n");
    generateValues(values, SIZE, MIN, MAX);
    duelingJP djp(SIZE, values);
    printf("  CREATED OBJECT STATS\n");
    cout << "    collisions " << djp.getCollisions() << endl;
    cout << "    inversions " << djp.getInversions() << endl;

    printf("\n=== TEST COPY OBJECT ===\n");
    printf(" 1. Using shared pointer\n");
    shared_ptr<duelingJP> copiedSharedPtr(new duelingJP(*sharePtr));
    printf(" 2. Using copy constructor directly\n");
    duelingJP djp2(*copiedSharedPtr);
    printf(" 3. Using copy constructor with = operator\n");
    duelingJP djp3 = *sharePtr;
    printf(" 4. Using copy overloaded = operator\n");
    sv.push_back(sharePtr);
    *sv[0] = *copiedSharedPtr;

    printf("\n=== TEST MOVE SEMANTICS ===\n");
    printf(" 1. Move into container\n");
    uv.push_back(move(ptr1)); // move inside container
    printf("    Object stats inside container\n");
    cout << "    collisions " << uv[0]->getCollisions() << endl;
    cout << "    inversions " << uv[0]->getInversions() << endl;

    printf(" 2. MOVE OUT CONTAINER\n");
    ptr1 = move(uv[uv.size()-1]); // move outside container
    printf("    Object stats outside container\n");
    cout << "    collisions " << ptr1->getCollisions() << endl;
    cout << "    inversions " << ptr1->getInversions() << endl;

    printf(" 3. Using move constructor directly\n");
    duelingJP djp4(move(*ptr2));
    printf(" 4. Using move constructor with = operator\n");
    duelingJP djp5 = move(djp4);
    printf(" 5. Using move overloaded = operator\n");
    uv[0] = move(ptr3);

    printf("    Object stats inside container\n");
    cout << "    collisions " << uv[0]->getCollisions() << endl;
    cout << "    inversions " << uv[0]->getInversions() << endl;

    printf("\n=== Thank you for using duelingJP testing driver ====\n");

    return 0;
}

void generateValues(int values[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        int value = rand() % (max - min + 1) + min;
        values[i] = value;
    }
}