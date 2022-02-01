// Author:      Duc Vo
// Filename:    duelingJP.cpp
// Date:        January 28, 2022,
// Version:     1.0
// Description:

#include <iostream>
#include "duelingJP.h"
#include "jumpPrime.h"
using namespace std;

duelingJP::duelingJP(int size, int nums[]) {
    cout << "CONSTRUCTOR!" << endl;
    createDueling(size, nums);
}

duelingJP::~duelingJP() {
    cout << "DESTRUCTOR!" << endl;
    for (int i = 0; i < size; i++) {
        delete group[i];
    }
    delete values;
    delete ups;
    delete downs;
    delete[] group;
}

duelingJP::duelingJP(const duelingJP &src) {
    cout << "COPY CONSTRUCTOR" << endl;
    copySource(src);
}

duelingJP duelingJP::operator=(const duelingJP &src) {
    cout << "COPY = OPERATOR" << endl;
    copySource(src);
    return *this;
}

duelingJP::duelingJP(duelingJP &&src){
    cout << "MOVE CONSTRUCTOR" << endl;
    moveSource(src);
    voidSource(src);
}

duelingJP duelingJP::operator=(duelingJP &&src){
    cout << "MOVE = OPERATOR" << endl;
    if (this != &src) {
        moveSource(src);
        voidSource(src);
    }
    return *this;
}

void duelingJP::setCollisions() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (i < j && ups[i] == ups[j]) {
                count++;
            }
        }
    }
    this->collisions = count;
}

void duelingJP::setInversions() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if ( i != j && ups[i] == downs[j]) {
                count++;
            }
        }
    }
    this->inversions = count;
}

int duelingJP::getCollisions() const {
    return this->collisions;
}

int duelingJP::getInversions() const {
    return this->inversions;
}

void duelingJP::createDueling(int size, int nums[]) {
    this->size = size;
    group = new jumpPrime*[size];
    values = new int[size];
    ups = new int[size];
    downs = new int[size];
    for (int i = 0; i < size; i++) {
        group[i] = new jumpPrime(nums[i]);
        values[i] = nums[i];
        ups[i] = group[i]->up();
        downs[i] = group[i]->down();
    }
    setCollisions();
    setInversions();
}

void duelingJP::copySource(const duelingJP &src) {
    createDueling(src.size, src.values);
}

void duelingJP::voidSource(duelingJP &src) {
    for (int i = 0; i < src.size; i++) {
        src.group[i] = nullptr;
    }
    src.size = 0;
    src.inversions = 0;
    src.collisions = 0;
    src.group = nullptr;
    src.values = nullptr;
    src.ups = nullptr;
    src.downs = nullptr;
}

void duelingJP::moveSource(duelingJP &src) {
    size = src.size;
    values = src.values;
    ups = src.ups;
    downs = src.downs;
    collisions = src.collisions;
    inversions = src.inversions;
    group = src.group;
    for (int i = 0; i < src.size; i++) {
        group[i] = src.group[i];
    }
}