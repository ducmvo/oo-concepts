// Author:      Duc Vo
// Filename:    duelingJP.cpp
// Date:        January 28, 2022,
// Version:     1.0
// Description:

#include <iostream>
#include "duelingJP.h"
#include "jumpPrime.h"
using namespace std;

duelingJP::duelingJP(int size) {
    createDueling(size);
}

duelingJP::~duelingJP() {
    delete[] group;
}

duelingJP::duelingJP(const duelingJP &src) {
    copySource(src);
}

const duelingJP &duelingJP::operator=(const duelingJP &src) {
    copySource(src);
    return *this;
}

duelingJP::duelingJP(duelingJP &&src){
    moveSource(src);
}

const duelingJP &duelingJP::operator=(duelingJP &&src){
    moveSource(src);
    return *this;
}

int duelingJP::getCollisions() const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
//            if (!group[i].isActive()) group[i].revive();
//            if (!group[j].isActive()) group[j].revive();
            if (i < j && group[i].up() == group[j].up()) {
                count++;
            }

            group[i].reset();
            group[j].reset();
        }
    }
    return count;
}

int duelingJP::getInversions() const {
    int count = 0;
    for (int i = 0; i < size; i++) {

    }
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
//            if (!group[i].isActive()) group[i].revive();
//            if (!group[j].isActive()) group[j].revive();
            if ( i != j && group[i].up() == group[j].down()) {
                count++;
            }

            group[i].reset();
            group[j].reset();
        }
    }
    return count;
}

void duelingJP::createDueling(int size) {
    int MIN = 1000;
    int MAX = 1040;
    this->size = size;
    group = new jumpPrime[size];
    for (int i = 0; i < size; i++) {
        int value = rand() % (MAX - MIN + 1) + MIN;
        jumpPrime jp(value);
        group[i] = jp;
    }
}

void duelingJP::copySource(const duelingJP &src) {
    size = src.size;
    group = new jumpPrime[size];
    for (int i = 0; i < size; i++) {
        group[i] = src.group[i];
    }
}

void duelingJP::moveSource(duelingJP &src) {
    size = src.size;
    group = src.group;

    src.size = 0;
    src.group = nullptr;
}