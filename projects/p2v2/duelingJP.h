// Author:      Duc Vo
// Filename:    duelingJP.h
// Date:        January 28, 2022,
// Version:     1.0
// Description: Specification file for duellingJP class used to
//              encapsulate and manage some number of distinct jumpPrime objects;
//              Class Invariant:
//              PURPOSE:
//                  The key functionality of a duelingJP object is
//                  to manage the jumpPrime sub-objects
//                  and answer client queries as to the number of
//                  ‘collisions’ and ‘inversions’.
//              COLLIDE:
//                  Two jumpPrime objects are said to ‘collide’
//                  if they produce the same prime number upon an up (or down) request.
//                  e.g. If active jumpPrime object j1 encapsulates 2222,
//                  and jumpPrime object j2 encapsulates 2233,
//                  they both will produce 2221 for down()and 2237 for up().
//              INVERSIONS:
//                  Two jumpPrime objects are said to be ‘inversions’
//                  if they produce the same prime number for complementary requests
//                  e.g. If active jumpPrime object j3 encapsulates 3519,
//                  and active jumpPrime object j4 encapsulates 3528,
//                  j4 produces 3527 for down() and j3 produces 3527 for up().

#ifndef P2_DUELINGJP_H
#define P2_DUELINGJP_H

#include "jumpPrime.h"

class duelingJP {
    // Each duelingJP object encapsulates some number of distinct jumpPrime objects;
    // the cardinality of jumpPrime sub-objects varies across duelingJP objects.

public:
    duelingJP(int, int[]);
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

    const duelingJP &operator=(const duelingJP &);
    // Overload = operator
    // precondition:
    // postcondition:

    duelingJP(duelingJP &&);
    // Constructor: Move constructor
    // precondition:
    // postcondition:

    const duelingJP &operator=(duelingJP &&);
    // Overload = operator: Move overloaded = operator
    // precondition:
    // postcondition:

    int getCollisions() const;
    // Get number of collisions with the current encapsulated jumpPrimes
    // precondition:
    // postcondition:

    int getInversions() const;
    // Get number of inversions with the current encapsulated jumpPrimes
    // precondition:
    // postcondition:

private:
    jumpPrime* group;           // Array to hold the jumpPrime objects
    int size;                   // Hold number of jumpPrime objects

    void moveSource(duelingJP &);
    // Use with move constructor and move overloaded = operator
    // to move heap data to the new container and nullify source data
    // precondition: source object ref is not equal to the copy object ref
    // postcondition: source object data move to new container

    void copySource(const duelingJP &);
    // Deep copy source object data into new instance of duelingJP
    // precondition: source object ref is not equal to the copy object ref
    // postcondition: source object data copied to new duelingJP instance

    void createDueling(int, int[]);
    // Create a new duelingJP object
    // precondition: input size must be greater than 0
    // postcondition: new duelingJP encapsulated numbers random jumpPrime objects
};


#endif //P2_DUELINGJP_H
