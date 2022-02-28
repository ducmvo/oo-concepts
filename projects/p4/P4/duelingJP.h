// Author:      Duc Vo
// Filename:    duelingJP.h
// Date:        January 28, 2022,
// Version:     1.0
// Description: Specification file for duellingJP class used to
//              encapsulate and manage some number of distinct jumpPrime sub-objects
//              and answer client queries of ‘collisions’ and ‘inversions’.


#ifndef P2_DUELINGJP_H
#define P2_DUELINGJP_H

#include "jumpPrime.h"

// CLASS INVARIANT:
//    duelingJP encapsulates some number of distinct jumpPrime objects
//    The cardinality of jumpPrime sub-objects varies across duelingJP objects.
//    duelingJP generator yields number of inversions and collisions
//    Constructor may generate jumpPrime objects and initialize group
//    Empty duelingJP can be generated with no args constructor
//    Group of jumpPrimes may be initialized, replaced, or changed
//    Size reflects the number of jumpPrime objects in group
//
// INTERFACE INVARIANT:
//    Size of duelingJP may change
//    Client must keep tract of size of duelingJP jumpPrime objects
//     
// IMPLEMENTATION INVARIANT:
//    inversions and collisions is calculated at the time of client request
//    A duelingJP data can be assigned, copied, added from another duelingJP
//    A duelingJP data can be assigned, added from a jumpPrime object
//    Size is always set the correct number of jumpPrime objects in group
class duelingJP {
public:
    // Constructor:   default constructor (no args)
    // precondition:  none
    // postcondition: group is nullptr, size equals 0
    duelingJP();

    // Constructor:   initialize group, size and create jumpPrime objects.
    // precondition:  input size equals to input array length.
    //                input size is greater than 0
    // postcondition: group of jumpPrime objects created with provided input
    duelingJP(unsigned, int[]);

    // Destructor:    delete group array pointer
    // precondition:  none
    // postcondition: group heap memory deallocated
    ~duelingJP();

    // Constructor: copy constructor create a copy object from source
    // precondition: none
    // postcondition: copy object is created and assigned to destination
    duelingJP(const duelingJP &);

    // Overload = operator: create a deep copy object from source
    // precondition: the assign object is different from source object
    // postcondition: copy object is created and assigned to destination
    const duelingJP &operator=(const duelingJP &);

    // Constructor: move constructor
    // precondition: none
    // postcondition: data from source moved to newly created object
    //                the source object data is void
    duelingJP(duelingJP &&);

    // Overload = operator: move overloaded = operator
    // precondition: the assign object is different from source object
    // postcondition: new object is created with data moved from source
    const duelingJP &operator=(duelingJP &&);

    // Get number of collisions with the current encapsulated jumpPrimes
    // Two jumpPrime objects are ‘collide’ if they produce the 
    // same prime number upon an up (or down) request.
    // precondition: none
    // postcondition: number of collisions generated from current encapsulated
    //                jumpPrime objects.
    int getCollisions() const;

    // Get number of inversions with the current encapsulated jumpPrimes
    // Two jumpPrime objects are ‘inverse’ if they produce the 
    // same prime number for complementary requests 
    // precondition: none
    // postcondition: number of inversions generated from current encapsulated
    //                jumpPrime objects.
    int getInversions() const;



    /* NON DESTRUCTIVE OVERLOADED OPERATORS */
    // == COMPARISON OPERATORS ==

    // Check if this duelingJP instance data equal to source instance data.
    // All the encapsulated jumpPrime objects must be equal
    // precondition:  none
    // postcondition: none
    bool operator==(const duelingJP &);

    // Check if this duelingJP instance data different to source instance data.
    // Ether size different or the encapsulated jumpPrime objects are different
    // precondition:  none
    // postcondition: none
    bool operator!=(const duelingJP &);

    // == MATHEMATICAL OPERATORS ==

    // Create a new instance with group equal to concatenated of two instances groups
    // precondition:  none
    // postcondition: new instance created with concatenated group
    const duelingJP operator+(const duelingJP &src);

    // Create a new instance with group added with provided jumpPrime
    // precondition:  none
    // postcondition: new instance created with extended group with provided jumpPrime
    const duelingJP operator+(const jumpPrime &src);

    /* DESTRUCTIVE OVERLOADED OPERATORS */
    // == ARITHMETIC OPERATORS ==

    // Replace current instance data with combination of two instances data.
    // group will be replaced with the concatenation of two groups.
    // size will be the sum of two sized 
    // precondition:  none
    // postcondition: group replaced with the concatenation of two groups.
    //                size increased by 1
    const duelingJP& operator+=(const duelingJP &);
    
    // Replace current group with a new group with extra jumpPrime.
    // size will be increase by 1 
    // precondition:  none
    // postcondition: objects group replaced with new group with added jumpPrime
    //                size increased by 1
    const duelingJP& operator+=(const jumpPrime &);

private:
    unsigned size;              // Hold number of jumpPrime objects
    jumpPrime* group;           // Array to hold the jumpPrime objects

    // Use with move constructor and move overloaded = operator
    // to move heap data to the new container and nullify source data
    // precondition: source object ref is not equal to the copy object ref
    // postcondition: source object data move to new container
    void moveSource(duelingJP &);

    // Deep copy source object data into new instance of duelingJP
    // precondition: source object ref is not equal to the copy object ref
    // postcondition: source object data copied to new duelingJP instance
    void copySource(const duelingJP &);

    // Create a new duelingJP object
    // precondition: input size must be greater than 0
    // postcondition: new duelingJP encapsulated numbers random jumpPrime objects
    void createDueling(unsigned, int[]);

    // Helper function for getting collisions and inversions
    // precondition:  input true if query collisions, false if query inversions
    // postcondition: jumpPrime objects in group will be revived if inactive
    //                before querying.
    int query(bool) const;
};


#endif //P2_DUELINGJP_H
