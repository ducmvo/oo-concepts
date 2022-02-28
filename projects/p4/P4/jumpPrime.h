// Author:      Duc Vo
// Filename:    jumpPrime.h
// Date:        February 25, 2022,
// Version:     2.0
// Description: Specification file for jumpPrime class used to generate upper
//              and lower prime of an encapsulated integer that at least 3 digits.
//              The clients can query the nearest prime number either above or below.
//              After a set amount of queries, the encapsulated value will change

#ifndef P2_JUMPPRIME_H
#define P2_JUMPPRIME_H

// CLASS INVARIANT:
//    Prime generator yields upper or lower prime from encapsulated value upon request
//    Encapsulated value must be at least 3 digits long
//    Constructor set default value of MIN_NUM if input is invalid
//    Default value of MIN_NUM defined for encapsulated value
//    Default value of MAX_JUMPS defined
//    Encapsulated value may be changed after construction
//    STATES
//      active: controls return of valid prime
//      dead: the object is permanently disabled
//    Error processing
//      If prime request on inactive state, -1 return as an error code
//
// INTERFACE INVARIANT:
//     Client must track active state and dead state
//     Inactive object can be revived
//     Object becomes inactive if jumCount exceed MAX_JUMPS
//     Dead object states cannot be changed
//
// IMPLEMENTATION INVARIANT:
//     upper and lower primes generated during construction or after value changed
//     active state controls response to client requests
//     An object cannot be dead and active
//     Object becomes dead if reviving in an active state
//     jumpCount increase when total clients requests exceed maxQueries
//     jumpCount and queryCount reset after object revived
//     jumpCount not affected after a reset.
//     queryCount can only be reset if object is active
class jumpPrime {
public:
    // Constructor:   Initialize object states with default values.
    // precondition:  input is at least 3 digits long
    // postcondition: If input is not valid MIN_NUM will be used as default value
    //                value set to input (if valid)
    //                object is active, jumpCount and qCount set to 0,
    //                upperPrime, lowerPrime and maxQueries generated based on
    //                the encapsulated value
    jumpPrime(int num = MIN_NUM);

    // Revive and inactive object. 
    // Returns true if successfully revive, false otherwise
    // precondition:  The object is not dead
    // postcondition: The object becomes active if revive in inactive state
    //                The object becomes dead if revive in an active state
    bool revive();

    // Reset query count to zero.
    // Returns true if successfully reset, false otherwise
    // precondition:  The object is active
    // postcondition: jumpCount reset to zero
    bool reset();

    // Get the nearest prime that higher than the encapsulated value
    // Returns -1 as error code if object inactive or dead
    // precondition:  The object is active and queryCount not exceed maxQueries
    // postcondition: The encapsulated value jumps if queryCount exceeds maxQueries
    int up();

    // Get the nearest prime that lower than the encapsulated value.
    // Returns -1 as error code if object inactive or dead
    // precondition:  The object is active and queryCount not exceed maxQueries
    // postcondition: The encapsulated value jumps if queryCount exceeds maxQueries
    int down();

    // Get the object active status.
    // precondition:  none
    // postcondition: none
    bool isActive() const;

    // Get the object dead status.
    // precondition:  none
    // postcondition: none
    bool isDead() const;

    /* NON DESTRUCTIVE OVERLOADED OPERATORS */
    // == COMPARISON OPERATORS ==

    // Check if this instance encapsulated value less than source value
    // precondition:  none
    // postcondition: none
    bool operator<(const jumpPrime &);

    // Check if this instance encapsulated value less than or equal source value
    // precondition:  none
    // postcondition: none
    bool operator<=(const jumpPrime &);

    // Check if this instance encapsulated value equal source value
    // precondition:  none
    // postcondition: none
    bool operator==(const jumpPrime &);
    
    // Check if this instance encapsulated value different than source value
    // precondition:  none
    // postcondition: none
    bool operator!=(const jumpPrime &);
    
    // Check if this instance encapsulated value greater than source value
    // precondition:  none
    // postcondition: none
    bool operator>(const jumpPrime &);
    
    // Check if this instance encapsulated value greater than or equal source value
    // precondition:  none
    // postcondition: none
    bool operator>=(const jumpPrime &);

    // == MATHEMATICAL OPERATORS ==

    // Create a new instance with value equal to sum of two instances values
    // precondition:  none
    // postcondition: none
    const jumpPrime operator+(const jumpPrime &src);

    // Create a new instance with value equal to subtraction of two instances values
    // precondition:  none
    // postcondition: none
    const jumpPrime operator-(const jumpPrime &src);

    // Create a new instance with value equal to product of two instances values
    // precondition:  none
    // postcondition: none
    const jumpPrime operator*(const jumpPrime &src);

    // Create a new instance with value equal to quotient of two instances values
    // precondition:  none
    // postcondition: none
    const jumpPrime operator/(const jumpPrime &src);

    // Create a new instance with value equal to sum of instance value 
    // and provided integer input
    // precondition:  none
    // postcondition: none
    const jumpPrime operator+(int);

    // Create a new instance with value equal to sum subtraction of instance value 
    // and provided integer input
    // precondition:  none
    // postcondition: none
    const jumpPrime operator-(int);

    // Create a new instance with value equal to sum product of instance value 
    // and provided integer input
    // precondition:  none
    // postcondition: none
    const jumpPrime operator*(int);

    // Create a new instance with value equal to quotient of instance value 
    // and provided integer input
    // precondition:  none
    // postcondition: none
    const jumpPrime operator/(int);

    /* DESTRUCTIVE OVERLOADED OPERATORS */
    // == ARITHMETIC OPERATORS ==

    // Replace current instance data with of source data
    // precondition:  object is different from source object and not dead
    // postcondition: objects states replaced of source data
    const jumpPrime& operator=(const jumpPrime &);

    // Replace current instance data with of source data 
    // and change current value to sum of two instances values
    // precondition:  object is different from source object and not dead
    // postcondition: objects states replaced of source data.
    //                current value set to sum of two instances values
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator+=(const jumpPrime &);

    // Replace current instance data with of source data
    // and change current value to subtraction of two instances values 
    // precondition:  object is different from source object and not dead
    // postcondition: objects states replaced of source data.
    //                current value set to subtraction of two instances values
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator-=(const jumpPrime &);

    // Replace current instance data with of source data
    // and change current value to product of two instances values 
    // precondition:  object is different from source object and not dead
    // postcondition: objects states replaced of source data.
    //                current value set to product of two instances values
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator*=(const jumpPrime &);

    // Replace current instance data with of source data
    // and change current value to quotient of two instances values 
    // precondition:  object is different from source object and not dead
    // postcondition: objects states replaced of source data.
    //                current value set to quotient of two instances values
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator/=(const jumpPrime &);


    // Change current value to the input integer
    // postcondition: objects states replaced of source data
    const jumpPrime& operator=(int);

    // Change current value to sum of instance value and input integer
    // precondition:  object is not dead
    // postcondition: current value set to sum of value and input integer
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator+=(int);

    // Change current value to subtraction of instance value and input integer
    // precondition:  object is not dead
    // postcondition: current value set to subtraction of value and input integer
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator-=(int);

    // Change current value to product of instance value and input integer
    // precondition:  object is not dead
    // postcondition: current value set to product of value and input integer
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator*=(int);

    // Change current value to quotient of instance value and input integer
    // precondition:  object is not dead
    // postcondition: current value set to quotient of value and input integer
    //                primes, and maxQueries maybe recalculated
    const jumpPrime& operator/=(int);


    // == INCREMENT/DECREMENT OPERATORS ==

    // Increase current value by 1 (Post increment)
    // precondition:  Object is not dead
    // postcondition: current value increase by 1
    //                primes, and maxQueries maybe recalculated
    jumpPrime& operator++();
    // Decrease current value by 1 (Post decrement)
    // precondition:  Object is not dead
    // postcondition: current value decrease by 1
    //                primes, and maxQueries maybe recalculated
    jumpPrime& operator--();

    // Increase current value by 1 (Pre increment)
    // precondition:  Object is not dead
    // postcondition: current value increase by 1
    //                primes, and maxQueries maybe recalculated
    jumpPrime operator++(int);

    // Decrease current value by 1 (Pre decrement)
    // precondition:  Object is not dead
    // postcondition: current value decrease by 1
    //                primes, and maxQueries maybe recalculated
    jumpPrime operator--(int);

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
    const static int MIN_NUM = 100;

    // Increase query count make appropriate change in object states 
    // (refer to postcondition)
    // precondition:  none
    // postcondition: 
    //     1. Value reset to MIN_NUM if current value is invalid
    //     2. if queryCount exceed maxqueries, jumpCount increase by 1, 
    //        queryCount reset, value set to upperPrime + 1,
    //        upperPrime, lowerPrime and maxQueries updated with new value
    //     3. Object set to inactive if jumpCount exceed MAX_JUMPS
    bool updateQuery();

    // Generate and set upperPrime, lowerPrime and maxQueries based on
    // the current encapsulated value
    // precondition:  none
    // postcondition: upperPrime, lowerPrime and maxQueries are generated and set
    void setPrimes();

    // Generate the nearest prime that lower than the encapsulated value
    // precondition: encapsulated value is at least 3 digits long
    // postcondition: none
    int getLowerPrime();

    // Generate the nearest prime that higher than the encapsulated value
    // precondition:  encapsulated value is at least 3 digits long
    // postcondition: none
    int getUpperPrime();

    // Check if a number is a prime number
    // precondition:  passed in number greater than 1
    // postcondition: none
    bool checkPrime(int);

    // Copy content from source object
    // precondition: Source object is different from current object and is not dead
    // postcondition: all states replaced with source object states
    void copySource(const jumpPrime &);

};


#endif //P2_JUMPPRIME_H
