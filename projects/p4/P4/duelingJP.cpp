// Author:      Duc Vo
// Filename:    duelingJP.cpp
// Date:        February 25, 2022,
// Version:     1.0
// Description: Implementation for duelingJP class used to
//              encapsulate and manage some number of distinct jumpPrime sub-objects
//              and answer client queries of ‘collisions’ and ‘inversions’.

#include "duelingJP.h"
#include "jumpPrime.h"

duelingJP::duelingJP(): size(0), group(nullptr) { }

duelingJP::duelingJP(unsigned size, int values[]) {
    createDueling(size, values);
}

duelingJP::~duelingJP() {
    delete[] group;
}

duelingJP::duelingJP(const duelingJP &src) {
    copySource(src);
}

const duelingJP &duelingJP::operator=(const duelingJP &src) {
    if (this != &src)
        copySource(src);
    return *this;
}

duelingJP::duelingJP(duelingJP &&src){
    moveSource(src);
}

const duelingJP &duelingJP::operator=(duelingJP &&src){
    if (this != &src)
        moveSource(src);
    return *this;
}

int duelingJP::query(bool isCollision) const {
    if (group == nullptr) return -1;
    int count = 0;
    for (unsigned i = 0; i < size - 1; i++) {
        if (!group[i].isActive()) group[i].revive();
        int up = group[i].up();
        for (int j = i + 1; j < size; j++) {
            if (!group[j].isActive()) group[j].revive();
            if (isCollision && up == group[j].up()) count++;
            if (!isCollision && up == group[j].down()) count++;
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

void duelingJP::createDueling(unsigned size, int values[]) {
    this->size = size;
    group = new jumpPrime[size];
    for (unsigned i = 0; i < size; i++) {
        jumpPrime jp(values[i]);
        group[i] = jp;
    }
}

void duelingJP::copySource(const duelingJP &src) {
    size = src.size;
    delete [] group;
    group = new jumpPrime[size];
    for (unsigned i = 0; i < size; i++) {
        group[i] = src.group[i];
    }
}

void duelingJP::moveSource(duelingJP &src) {
    size = src.size;
    delete [] group;
    group = src.group;

    src.size = 0;
    src.group = nullptr;
}

bool duelingJP::operator==(const duelingJP &src) {
    if (size != src.size) return false;
    for (unsigned i = 0; i < size; i++)
        if(group[i] != src.group[i])
            return false;
    return true;
}

bool duelingJP::operator!=(const duelingJP &src) {
    return !(*this == src);
}

// NON DESTRUCTIVE
const duelingJP duelingJP::operator+(const duelingJP &src) {
    int newSize = size + src.size;
    duelingJP local;
    local.size = newSize;
    local.group = new jumpPrime[newSize];
    for (unsigned i = 0; i < size; i++)
        local.group[i] = group[i];
    for (unsigned i = 0; i < src.size; i++)
        local.group[size + i] = src.group[i];
    return local;
}


const duelingJP duelingJP::operator+(const jumpPrime &src) {
    duelingJP local;
    int newSize = size + 1;
    local.size = newSize;
    local.group = new jumpPrime[newSize];
    for (unsigned i = 0; i < size; i++)
        local.group[i] = group[i];
    local.group[size] = src;
    return local;
}


// GLOBAL OVERLOADED OPERATOR
const duelingJP operator+(jumpPrime obj, duelingJP &src) {
    return src + obj;
}

// DESTRUCTIVE
const duelingJP& duelingJP::operator+=(const duelingJP &src) {
    if (this != &src) *this = *this + src;
    return *this;
}

const duelingJP& duelingJP::operator+=(const jumpPrime &obj) {
    *this = *this + obj;
    return *this;
}
