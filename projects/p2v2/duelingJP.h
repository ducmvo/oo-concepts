// Author:      Duc Vo
// Filename:    duelingJP.h
// Date:        January 28, 2022,
// Version:     1.0
// Description: Specification file for duellingJP class used to
//              encapsulate and manage some number of distinct jumpPrime sub-objects
//              and answer client queries of ‘collisions’ and ‘inversions’.
//              COLLISIONS:
//                  Two jumpPrime objects are said to ‘collide’
//                  if they produce the same prime number upon an up (or down) request.
//              INVERSIONS:
//                  Two jumpPrime objects are said to be ‘inverse’
//                  if they produce the same prime number for complementary requests

#ifndef P2_DUELINGJP_H
#define P2_DUELINGJP_H

#include "jumpPrime.h"

class duelingJP {
    // Each duelingJP object encapsulates some number of distinct jumpPrime objects;
    // the cardinality of jumpPrime sub-objects varies across duelingJP objects.
    // CLASS INVARIANT: The number of jumpPrime objects remain unchanged.

public:
    duelingJP(int, int[]);
    // Constructor:   initialize group, size and create jumpPrime objects.
    // precondition:  input size equals to input array length.
    //                input size is greater than 0
    // postcondition: group of jumpPrime objects created with provided input

    ~duelingJP();
    // Destructor:    delete group array pointer
    // precondition:  none
    // postcondition: group heap memory deallocated

    duelingJP(const duelingJP &);
    // Constructor: copy constructor create a copy object from source
    // precondition: none
    // postcondition: copy object is created and assigned to destination

    const duelingJP &operator=(const duelingJP &);
    // Overload = operator: create a deep copy object from source
    // precondition: the assign object is different from source object
    // postcondition: copy object is created and assigned to destination

    duelingJP(duelingJP &&);
    // Constructor: move constructor
    // precondition: none
    // postcondition: data from source moved to newly created object
    //                the source object data is void

    const duelingJP &operator=(duelingJP &&);
    // Overload = operator: move overloaded = operator
    // precondition: the assign object is different from source object
    // postcondition: new object is created with data moved from source

    int getCollisions() const;
    // Get number of collisions with the current encapsulated jumpPrimes
    // precondition: none
    // postcondition: number of collisions generated from current encapsulated
    //                jumpPrime objects.

    int getInversions() const;
    // Get number of inversions with the current encapsulated jumpPrimes
    // precondition: none
    // postcondition: number of inversions generated from current encapsulated
    //                jumpPrime objects.

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

    int query(bool) const;
    // Helper function for get collisions and get inversions
    // precondition: input true if query collisions, false if query inversions
    // postcondition: return the number of collisions or inversions
};


#endif //P2_DUELINGJP_H
