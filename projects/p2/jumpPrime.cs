using System;

// Author:      Duc Vo
// Filename:    jumpPrime.cs
// Version:     1.0
// Description: This class represents a prime generator that let user query
//              the closest prime numbers above and below an input integer
//              that at least 4-digits long.

namespace project1
{
    class jumpPrime
    {
        // This class encapsulated an integer that greater than 999. The clients can
        // query the nearest prime number either above or below. After a set amount
        // of queries, the value will change to the its upper prime number plus 1.
        //
        // Class Invariant:
        //   The encapsulated value in range 1000 - 2147483647.
        //   If not, 1000 will be used
        //
        // States:
        //  active: if true, any query return valid prime. return -1 of false 
        //  dead: the object is permanently inactive and cannot be revive
        //  An object cannot be dead and active
        //
        // Query count can only be reset if object is active
        // Inactive object can be revived, then jump count and query count reset
        // Reviving an active object will change it states to dead and inactive
        // Jump count won't be affected after a reset.

        //  The maximum allowed number of jumps
        private static int MAX_JUMPS = 5;
        //  The encapsulated number with default value
        private int value;
        //  The count of jumps
        private int jCount;
        //  The count of queries
        private int qCount;
        // The maximum number of queries before starting jump
        private int maxQueries;
        // The nearest prime number higher than the current value
        private int upperPrime;
        // The nearest prime number lower than the current value
        private int lowerPrime;
        //  The boolean to track active/inactive state
        private bool active;
        // The boolean to tract permanent deactivation state
        private bool dead;
        // Maximum number that have an upper prime that an integer can hold
        private const int MAX_NUM = 2147483647;
        // Default minimum value 
        private const int MIN_NUM = 1000;


        // Interface Invariant:
        //     The encapsulated value in range 1000 -> 2147483647.
        //     If not, 1000 will be used


        // Constructor
        //     Initialize object states with default values.
        // 
        // preconditions:
        //     input number is greater than 1000.
        //     input number is less than 2147483647
        // postconditions:    
        //      if input number is not in range 1000 -> 2147483647 inclusive
        //      1000 will be used as default
        public jumpPrime(int num = MIN_NUM)
        {
            if (num >= MIN_NUM && num < MAX_NUM)
                value = num;
            else
                value = MIN_NUM;
            jCount = 0;
            qCount = 0;
            active = true;
            dead = false;
            setPrimes();
        }

        // Revive and inactive object.
        // The object becomes dead if revive in an active state
        // Return the operation status: 
        //    True if successfully revive, false otherwise
        public bool revive()
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

        // Reset query count to zero.
        // Return the operation status:
        //     True if succesfully reset, false otherwise
        public bool reset()
        {
            if (!active || dead)
                return false;
            qCount = 0;
            return true;
        }

        // Get the nearest prime that higher
        // than the encapsulated value
        // Return -1 if updateQuery operation fail
        public int up()
        {
            bool success = updateQuery();
            return success ? upperPrime : -1;
        }

        // Get the nearest prime that lower
        // than the encapsulated value.
        // Return -1 if updateQuery operation fail
        public int down()
        {
            bool success = updateQuery();
            return success ? lowerPrime : -1;
        }

        // Getters for query count, jump count, and dead and alive state
        public bool isActive() { return active; }
        public bool isDead() { return dead; }


        // Increase query count then do the following operations:
        //     1. Check if current value is out of range to reset to 1000
        //     2. If query count > max queries, increase jump count, 
        //        reset query count set value to the current upperPrime + 1 and
        //        call setPrimes method to update the primes and maxQueries
        //     3. Set object to inactive if jump count > MAX_JUMP
        // Return false if object is inactive or dead, true otherwise
        //
        private bool updateQuery()
        {
            if (!active || dead)
                return false;

            qCount++;

            // Jump Condition
            if (qCount > maxQueries) {
                jCount++;
                qCount = 0; // reset query count when jump
                if (value >= MAX_NUM - 1)
                    value = 1000;
                else
                    value = upperPrime + 1;
                setPrimes();
            }

            if (jCount > MAX_JUMPS) 
                active = false;

            return true;
        }

        // Generate and set upperPrime, lowerPrime and maxQueries
        // based on the current encapsulated value
        private void setPrimes()
        {
            upperPrime = getUpperPrime();
            lowerPrime = getLowerPrime();
            maxQueries = upperPrime - lowerPrime;
        }

        // Generate the nearest prime that lower
        // than the encapsulated value
        private int getLowerPrime()
        {
            for (int num = value - 1; num > 0; num--)
            {
                if (checkPrime(num)) return num;
            }
            return 1;
        }

        // Generate the nearest prime that higher
        // than the encapsulated value
        private int getUpperPrime()
        {
           
            int num = value + 1;
            while (!checkPrime(num))
            {
                num++;
            }
            return num;
        }

        // Helper function to check if a number is a prime number
        private bool checkPrime(int num)
        {
            if (num < 2) return false;
            for (int i = 2; i < Math.Sqrt(num); i++)
            {
                if (num % i == 0) return false;
            }
            return true;
        }

        // Implementation Invariant:
        //     The encapsulated value in range 1000 -> 2147483647.
        //     If not, 1000 will be used

    }
}
