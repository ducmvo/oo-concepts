// Author:      Duc Vo
// Filename:    jumpPrime.cpp
// Date:        February 25, 2022,
// Version:     2.0
// Description: Implementation for jumpPrime class used to generate upper
//              and lower prime of an encapsulated integer that at least 3 digits.

#include "jumpPrime.h"
#include <math.h>
#include <limits.h>

jumpPrime::jumpPrime(int num)
{
    if (num >= MIN_NUM && num < INT_MAX)
        value = num;
    else
        value = MIN_NUM;
    jCount = 0;
    qCount = 0;
    active = true;
    dead = false;
    setPrimes();
}

bool jumpPrime::revive()
{
    if (dead)
        return false;
    if (active)
        dead = true;
    if (!active)
    {
        jCount = 0;
        qCount = 0;
    }
    active = !active;
    return active;
}

bool jumpPrime::reset()
{
    if (!active || dead)
        return false;
    qCount = 0;
    return true;
}

int jumpPrime::up()
{
    bool success = updateQuery();
    return success ? upperPrime : -1;
}

int jumpPrime::down()
{
    bool success = updateQuery();
    return success ? lowerPrime : -1;
}

bool jumpPrime::isActive() const { return active; }

bool jumpPrime::isDead() const { return dead; }

bool jumpPrime::updateQuery()
{
    if (!active || dead)
        return false;

    qCount++;

    if (qCount > maxQueries)
    {
        jCount++;
        qCount = 0;
        if (value >= INT_MAX - 1)
            value = MIN_NUM;
        else
            value = upperPrime + 1;
        setPrimes();
    }

    if (jCount > MAX_JUMPS)
        active = false;

    return true;
}

void jumpPrime::setPrimes()
{
    upperPrime = getUpperPrime();
    lowerPrime = getLowerPrime();
    maxQueries = upperPrime - lowerPrime;
}

int jumpPrime::getLowerPrime()
{
    for (int num = value - 1; num > 0; num--)
    {
        if (checkPrime(num))
            return num;
    }
    return 1;
}

int jumpPrime::getUpperPrime()
{

    int num = value + 1;
    while (!checkPrime(num))
    {
        num++;
    }
    return num;
}

bool jumpPrime::checkPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void jumpPrime::copySource(const jumpPrime &src)
{
    if (this == &src || dead)
        return;

    value = src.value;
    active = src.active;
    dead = src.dead;
    qCount = src.qCount;
    jCount = src.jCount;
    upperPrime = src.upperPrime;
    lowerPrime = src.lowerPrime;
    maxQueries = src.maxQueries;

    if (value < MIN_NUM)
    {
        value = MIN_NUM;
    }

    if (value > upperPrime || value < lowerPrime)
    {
        setPrimes();
    }
}

// COMPARISON
bool jumpPrime::operator==(const jumpPrime &src)
{
    return value == src.value;
}

bool jumpPrime::operator<(const jumpPrime &src)
{
    return value < src.value;
}

bool jumpPrime::operator<=(const jumpPrime &src)
{
    return value <= src.value;
}

bool jumpPrime::operator!=(const jumpPrime &src)
{
    return value != src.value;
}

bool jumpPrime::operator>(const jumpPrime &src)
{
    return value > src.value;
}

bool jumpPrime::operator>=(const jumpPrime &src)
{
    return value >= src.value;
}

// NON-DESTRUCTIVE
// MATHEMATICAL OVERLOADED WITH ANOTHER JUMPPRIME
const jumpPrime jumpPrime::operator+(const jumpPrime &src)
{
    int newValue = value + src.value;
    jumpPrime local(newValue);
    return local;
}

const jumpPrime jumpPrime::operator-(const jumpPrime &src)
{
    int newValue = value - src.value;
    jumpPrime local(newValue);
    return local;
}

const jumpPrime jumpPrime::operator*(const jumpPrime &src)
{
    int newValue = value * src.value;
    jumpPrime local(newValue);
    return local;
}

const jumpPrime jumpPrime::operator/(const jumpPrime &src)
{
    int newValue = value / src.value;
    jumpPrime local(newValue);
    return local;
}

const jumpPrime jumpPrime::operator+(int increment)
{
    int newValue = value + increment;
    jumpPrime local(newValue);
    return local;
}

// MATHEMATICAL OVERLOADED WITH INTEGER
const jumpPrime jumpPrime::operator-(int decrement)
{
    int newValue = value - decrement;
    jumpPrime local(newValue);
    return local;
}

const jumpPrime jumpPrime::operator*(int multiplier)
{
    int newValue = value * multiplier;
    jumpPrime local(newValue);
    return local;
}

const jumpPrime jumpPrime::operator/(int divider)
{
    int newValue = value / divider;
    jumpPrime local(newValue);
    return local;
}

// Change current value to the input integer
// postcondition: objects states replaced of source data
const jumpPrime& jumpPrime::operator=(int val) {
    jumpPrime local(val);
    *this = local;
    return *this;
}

// Change current value to sum of instance value and input integer
// precondition:  object is not dead
// postcondition: current value set to sum of value and input integer
//                primes, and maxQueries maybe recalculated
const jumpPrime& jumpPrime::operator+=(int increment) {
    jumpPrime local(value + increment);
    *this = local;
    return *this;
}

// Change current value to subtraction of instance value and input integer
// precondition:  object is not dead
// postcondition: current value set to subtraction of value and input integer
//                primes, and maxQueries maybe recalculated
const jumpPrime& jumpPrime::operator-=(int decrement) {
    jumpPrime local(value - decrement);
    *this = local;
    return *this;
}

// Change current value to product of instance value and input integer
// precondition:  object is not dead
// postcondition: current value set to product of value and input integer
//                primes, and maxQueries maybe recalculated
const jumpPrime& jumpPrime::operator*=(int mul) {
    jumpPrime local(value * mul);
    *this = local;
    return *this;
}

// Change current value to quotient of instance value and input integer
// precondition:  object is not dead
// postcondition: current value set to quotient of value and input integer
//                primes, and maxQueries maybe recalculated
const jumpPrime& jumpPrime::operator/=(int div) {
    jumpPrime local(value / div);
    *this = local;
    return *this;
}

// GLOBAL OVERLOADED OPERATOR
const jumpPrime operator+(int increment, jumpPrime &src)
{
    return src + increment;
}

const jumpPrime operator*(int multiplier, jumpPrime &src)
{
    return src * multiplier;
}

// DESTRUCTIVE
const jumpPrime &jumpPrime::operator=(const jumpPrime &src)
{
    copySource(src);
    return *this;
}

const jumpPrime &jumpPrime::operator+=(const jumpPrime &src)
{
    copySource(*this + src);
    return *this;
}

const jumpPrime &jumpPrime::operator-=(const jumpPrime &src)
{
    copySource(*this - src);
    return *this;
}
const jumpPrime &jumpPrime::operator*=(const jumpPrime &src)
{

    copySource(*this * src);
    return *this;
}
const jumpPrime &jumpPrime::operator/=(const jumpPrime &src)
{
    copySource(*this / src);
    return *this;
}

jumpPrime &jumpPrime::operator++()
{
    if (!dead) *this += 1;
    return *this;
}

jumpPrime jumpPrime::operator++(int)
{
    if (dead) return *this;
    jumpPrime oldState = *this;
    *this += 1;
    return oldState;
}

jumpPrime &jumpPrime::operator--()
{
    if (!dead)
        *this += -1;
    return *this;
}

jumpPrime jumpPrime::operator--(int)
{
    if (dead) return *this;
    jumpPrime oldState = *this;
    *this += -1;
    return oldState;
}
