// Author:      Duc Vo
// Filename:    duelingJP.h
// Date:        January 28, 2022,
// Version:     1.0
// Description:

#ifndef P2_DUELINGJP_H
#define P2_DUELINGJP_H

#include "jumpPrime.h"


class duelingJP {
    // Each duelingJP object encapsulates some number of distinct jumpPrime objects;
    // the cardinality of jumpPrime sub-objects varies across duelingJP objects.

    // PURPOSE:
    // The key functionality of a duelingJP object is
    // to manage the jumpPrime sub-objects
    // and answer client queries as to the number of
    // ‘collisions’ and ‘inversions’.

    // COLLIDE:
    // Two jumpPrime objects are said to ‘collide’
    // if they produce the same prime number upon an up (or down) request.
    // e.g. If active jumpPrime object j1 encapsulates 2222,
    // and jumpPrime object j2 encapsulates 2233,
    // they both will produce 2221 for down()and 2237 for up().

    // INVERSIONS:
    // Two jumpPrime objects are said to be ‘inversions’
    // if they produce the same prime number for complementary requests
    // e.g. If active jumpPrime object j3 encapsulates 3519,
    // and active jumpPrime object j4 encapsulates 3528,
    // j4 produces 3527 for down() and j3 produces 3527 for up().

public:
    duelingJP(int);
    // Constructor
    // precondition:
    // postcondition:

    ~duelingJP();
    // Destructor
    // precondition:
    // postcondition:

    duelingJP(const duelingJP &);
    // Constructor: Copy constructor
    // precondition:
    // postcondition:

    duelingJP operator=(const duelingJP &);
    // Overload = operator
    // precondition:
    // postcondition:

    duelingJP(duelingJP &&);
    // Constructor: Move
    // precondition:
    // postcondition:

    duelingJP operator=(duelingJP &&);
    // Overload = operator: Move
    // precondition:
    // postcondition:

private:
    jumpPrime* group;
    int size;
    int inversions;
    int collisions;


};


#endif //P2_DUELINGJP_H
