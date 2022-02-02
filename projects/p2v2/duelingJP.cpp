// Author:      Duc Vo
// Filename:    duelingJP.cpp
// Date:        January 28, 2022,
// Version:     1.0
// Description: Implementation for duelingJP class used to
//              encapsulate and manage some number of distinct jumpPrime sub-objects
//              and answer client queries of ‘collisions’ and ‘inversions’.

#include "duelingJP.h"
#include "jumpPrime.h"

duelingJP::duelingJP(int size, int values[]) {
    createDueling(size, values);
}

duelingJP::~duelingJP() {
    delete[] group;
}

duelingJP::duelingJP(const duelingJP &src) {
    copySource(src);
}

const duelingJP &duelingJP::operator=(const duelingJP &src) {
    if (this != &src) {
        copySource(src);
    }
    return *this;
}

duelingJP::duelingJP(duelingJP &&src){
    moveSource(src);
}

const duelingJP &duelingJP::operator=(duelingJP &&src){
    if (this != &src) {
        moveSource(src);
    }
    return *this;
}

int duelingJP::query(bool isCollision) const {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        if (!group[i].isActive())
            group[i].revive();
        int up = group[i].up();
        for (int j = i + 1; j < size; j++) {
            if (!group[j].isActive())
                group[j].revive();
            if ((isCollision && up == group[j].up())
                || (!isCollision && up == group[j].down())) {
                count++;
            }
        }
    }
    return count;
}

int duelingJP::getCollisions() const {
    return query(true);
}

int duelingJP::getInversions() const {
    return query(false);
}

void duelingJP::createDueling(int size, int values[]) {
    this->size = size;
    group = new jumpPrime[size];
    for (int i = 0; i < size; i++) {
        jumpPrime jp(values[i]);
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