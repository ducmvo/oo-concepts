// Author:      Duc Vo
// Filename:    jumpPrime.cpp
// Date:        January 28, 2022,
// Version:     1.0
// Description: Implementation for jumpPrime class used to generate upper
//              and lower prime of an encapsulated integer that at least 4 digits.

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
    if (dead) return false;
    if (active) dead = true;
    if (!active) {
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

    if (qCount > maxQueries) {
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
        if (checkPrime(num)) return num;
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
    if (num < 2) return false;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}