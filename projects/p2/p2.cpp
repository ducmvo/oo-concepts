// Author:      Duc Vo
// Filename:    jumpPrime.h
// Date:        January 28, 2022,
// Version:     1.0
// Description:
// Input:
// Process:
// Output:

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <vector>
#include "duelingJP.h"
using namespace std;

int sampleFunc(void*);
// This function ...
// IN:
// MODIFY:
// OUT:

int main() {
    vector<shared_ptr<duelingJP>> list;
    vector<unique_ptr<duelingJP>> list2;
    int SIZE = 5;

    for (int i = 0; i < SIZE; i++) {
        int size = rand() % 10 + 5;
        int nums[size];
        for (int j = 0; j < size; j++) {
            nums[j] = rand() % 50 + 1000;
            cout << nums[j] << " | ";
        }
        cout << endl;
        shared_ptr<duelingJP> ptr(new duelingJP(size, nums));
        list.push_back(ptr);
    }

    for (shared_ptr<duelingJP> jp : list) {
        cout <<"INVERSIONS " <<jp->getInversions() << " | ";
        cout <<"COLLISIONS " <<jp->getCollisions() << endl;
    }


    for (int i = 0; i < SIZE; i++) {
        cout << "SIZE " << list.size() << endl;
        list.pop_back();
    }

    cout << "TEST MOVE SEMANTIC WITH UNIQUE POINTER" << endl;
    for (int i = 0; i < 5; i++) {
        int size = rand() % 10 + 5;
        int nums[size];
        for (int j = 0; j < size; j++) {
            nums[j] = rand() % 50 + 1000;
            cout << nums[j] << " | ";
        }
        cout << endl;
        unique_ptr<duelingJP> ptr(new duelingJP(size, nums));
        list2.push_back(move(ptr));
    }

    for (int i = 0; i < list2.size(); i++) {
        cout <<"INVERSIONS " <<list2[i]->getInversions() << " | ";
        cout <<"COLLISIONS " <<list2[i]->getCollisions() << endl;
    }



    return 0;
}