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

int main() {
    int size = 10;

    vector<duelingJP> list;
    unique_ptr<duelingJP> uniquePtr(new duelingJP(size));
    shared_ptr<duelingJP> sharedPtr(new duelingJP(size));

    printf("\nTEST CONSTRUCTOR");
    duelingJP djp(size);

    printf("\nTEST COPY CONSTRUCTOR");
    printf("\n  TEST 1 USING STL CONTAINER");
    list.push_back(*sharedPtr);
    list.pop_back();
    shared_ptr<duelingJP> copiedSharedPtr = sharedPtr;
    printf("\n  TEST 2 USING DIRECT COPY CONSTRUCTOR");
    duelingJP djp2(*copiedSharedPtr);
    printf("\n  TEST 3 USING COPY CONSTRUCTOR WITH = SIGN");
    duelingJP djp3 = *sharedPtr;

    printf("\nTEST COPY OVERLOADED = OPERATOR");
    djp3 = djp2;

    printf("\nTEST MOVE CONSTRUCTOR");
    printf("\n  TEST 1 USING STL CONTAINER");
    list.push_back(move(*uniquePtr));
    printf("\n  TEST 2 USING DIRECT MOVE CONSTRUCTOR");
    duelingJP djp4(move(list[list.size()-1]));
    list.pop_back();
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

    size = 15;

    shared_ptr<duelingJP> sharedPtr2(new duelingJP(size));
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