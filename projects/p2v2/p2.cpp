// Author:      Duc Vo
// Filename:    jumpPrime.h
// Date:        January 28, 2022,
// Version:     1.0
// Description: This program tests the duelingJP class
// Input:       none
// Process:     Create a list of jumpPrime objects that used to create
//              duelingJP objects. The program tests all the public methods
//              of duellingJP classes and finish without error.
// Output:      none

#include <iostream>
#include <memory>

#include <vector>
#include <stdio.h>
#include "duelingJP.h"
using namespace std;

void generateValues(int values[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        int value = rand() % (max - min + 1) + min;
        values[i] = value;
    }

}

int main() {
    const int size = 10;
    int MIN = 1000;
    int MAX = 1040;

    const int SIZE = 10;
    int values[SIZE];


    vector<unique_ptr<duelingJP>> uv;
    vector<shared_ptr<duelingJP>> sv;

    generateValues(values, SIZE, MIN, MAX);
    shared_ptr<duelingJP> ptr(new duelingJP(size, values));

    generateValues(values, SIZE, MIN, MAX);
    unique_ptr<duelingJP> ptr1(new duelingJP(size, values));

    generateValues(values, SIZE, MIN, MAX);
    unique_ptr<duelingJP> ptr2(new duelingJP(size, values));

    generateValues(values, SIZE, MIN, MAX);
    unique_ptr<duelingJP> ptr3(new duelingJP(size, values));



    printf("\nTEST CONSTRUCTOR");
    duelingJP djp(size, values);

    printf("\nTEST COPY CONSTRUCTOR");
    printf("\n  TEST 1 USING STL CONTAINER");
    sv.push_back(ptr);
    sv.pop_back();
    shared_ptr<duelingJP> copiedSharedPtr = ptr;
    printf("\n  TEST 2 USING DIRECT COPY CONSTRUCTOR");
    duelingJP djp2(*copiedSharedPtr);
    printf("\n  TEST 3 USING COPY CONSTRUCTOR WITH = SIGN");
    duelingJP djp3 = *ptr;

    printf("\nTEST COPY OVERLOADED = OPERATOR");
    djp3 = djp2;


    printf("\nTEST MOVE CONSTRUCTOR");
    printf("\n  TEST USING STL CONTAINER");
    printf("\n  TEST MOVE IN STL CONTAINER");
    uv.push_back(move(ptr1)); // move inside container
    printf("\n  TEST MOVE OUT STL CONTAINER");
    ptr1 = move(uv[uv.size()-1]);
    printf("\n  TEST 2 USING DIRECT MOVE CONSTRUCTOR");
    duelingJP djp4(move(*ptr1)); // move outside container
    uv.pop_back();
    printf("\n  TEST 3 USING MOVE CONSTRUCTOR WITH = SIGN");
    duelingJP djp5 = move(djp4);

    printf("\nTEST MOVE OVERLOADED = OPERATOR\n");
    djp4 = move(djp5);

    printf("\nTEST COLLISIONS CALL");
    cout << "\nCOLLISIONS " << djp4.getCollisions() << endl;
    printf("\nTEST INVERSIONS CALL");
    cout << "\nINVERSIONS " << djp4.getInversions() << endl;

    printf("\nTEST COPY OBJECTS WITH DIFFERENT SIZES");
    printf("\nCREATE DIFFERENT SIZE JUMP PRIMES LIST\n");

    const int SIZE2 = 15;

    shared_ptr<duelingJP> sharedPtr2(new duelingJP(SIZE2, values));
    printf("  TEST 1 USING DIRECT COPY CONSTRUCTOR:\n");
    duelingJP djp6(*sharedPtr2);
    printf("  TEST 2 USING COPY CONSTRUCTOR WITH = SIGN\n");
    duelingJP djp7 = *sharedPtr2;
    printf("\nTEST COLLISIONS CALL");
    cout << "\nCOLLISIONS " << djp7.getCollisions() << endl;
    printf("\nTEST INVERSIONS CALL");
    cout << "\nINVERSIONS " << djp7.getInversions() << endl;

    return 0;
}