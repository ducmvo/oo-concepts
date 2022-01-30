// Author:      Duc Vo
// Filename:    jumpPrime.h
// Date:        January 28, 2022,
// Version:     1.0
// Description: Specification file for jumpPrime class used to generate upper
//              and lower prime of an encapsulated integer that at least 4 digits.
//              The clients can query the nearest prime number either above or below.
//              After a set amount of queries, the value will change its
//              upper prime number plus 1.
//              Class Invariant:
//                The encapsulated value in range 1000 - 2147483647.
//                If not, 1000 will be used
//              States:
//               active: if true, any query return valid prime. return -1 of false
//               dead: the object is permanently inactive and cannot be revived
//               An object cannot be dead and active
//              Query count can only be reset if object is active
//              Inactive object can be revived, then jump count and query count reset
//              Reviving an active object will change it states to dead and inactive
//              Jump count won't be affected after a reset.

#ifndef P2_JUMPPRIME_H
#define P2_JUMPPRIME_H

class jumpPrime {
public:
    jumpPrime(int num = MIN_NUM);
    // Constructor:   Initialize object states with default values.
    // precondition:  Input number is greater than 1000.
    //                Input number is less than 2147483647
    // postcondition: If input number is not in range 1000 -> 2147483647 inclusive
    //                1000 will be used as default

    bool revive();
    // Revive and inactive object.
    // precondition:  The object is not dead
    // postcondition: The object becomes active if revive in inactive state
    //                The object becomes dead if revive in an active state
    //                Returns true if successfully revive, false otherwise

    bool reset();
    // Reset query count to zero.
    // precondition:  The object is not dead and in active state
    // postcondition: The jump count reset to zero
    //                Returns true if successfully reset, false otherwise

    int up();
    // Get the nearest prime that higher than the encapsulated value
    // precondition:  The object is not dead and in active state
    // postcondition: The encapsulated value jumps if query count > maxQueries
    //                Returns -1 if object inactive or dead


    int down();
    // Get the nearest prime that lower than the encapsulated value.
    // precondition:  The object is not dead and in active state
    // postcondition: The encapsulated value jumps if query count > maxQueries
    //                Returns -1 if object inactive or dead

    bool isActive() const;
    // Get the object active status.
    // precondition:  none
    // postcondition: returns active status

    bool isDead() const;
    // Get the object dead status.
    // precondition:  none
    // postcondition: returns dead status

private:
    int MAX_JUMPS = 5;          //  The maximum allowed number of jumps
    int value;                  //  The encapsulated number with default value
    int jCount;                 //  The count of jumps
    int qCount;                 //  The count of queries
    int maxQueries;             //  The maximum number of queries before starting jump
    int upperPrime;             //  The nearest prime number higher than the current value
    int lowerPrime;             //  The nearest prime number lower than the current value
    bool active;                //  The boolean to track active/inactive state
    bool dead;                  //  The boolean to tract permanent deactivation state
    const static int MIN_NUM = 1000;

    bool updateQuery();
    // Increase query count then do the following operations:
    //     1. Check if current value is out of range to reset to 1000
    //     2. If query count > max queries, increase jump count,
    //        reset query count set value to the current upperPrime + 1 and
    //        call setPrimes method to update the primes and maxQueries
    //     3. Set object to inactive if jump count > MAX_JUMP
    // precondition:  none
    // postcondition: return false if object is inactive or dead, true otherwise

    void setPrimes();
    // Generate and set upperPrime, lowerPrime and maxQueries based on
    // the current encapsulated value
    // precondition:  none
    // postcondition: upperPrime, lowerPrime and maxQueries are generated and set

    int getLowerPrime();
    // Generate the nearest prime that lower than the encapsulated value
    // precondition: encapsulated value is at least 4 digits long
    // postcondition: returns the nearest lower prime


    int getUpperPrime();
    // Generate the nearest prime that higher than the encapsulated value
    // precondition:  encapsulated value is at least 4 digits long
    // postcondition: returns the nearest upper prime

    bool checkPrime(int);
    // Helper function to check if a number is a prime number
    // precondition:  passed in number greater than 1
    // postcondition: returns true is number is prime


    // Implementation Invariant:
    //     The encapsulated value at least 4 digits long.
    //     If not, 1000 will be used
};


#endif //P2_JUMPPRIME_H
