using System;
// Author:      Duc Vo
// Filename:    duelingJP.cs
// Date:        February 11, 2022,
// Version:     2.0
// Description: This file contains the duellingJP class used to encapsulate
//          and manage some number of distinct jumpPrime sub-objects
namespace P3
{
    // The duellingJP class used to encapsulate and manage some number
    // of distinct jumpPrime sub-objects and answer client queries of
    // ‘collisions’ and ‘inversions’. The cardinality of jumpPrime
    // sub-objects varies across duelingJP objects.
    // COLLISIONS:
    //   Two jumpPrime objects are said to ‘collide’
    //   if they produce the same prime number upon an up (or down) request.
    // INVERSIONS:
    //   Two jumpPrime objects are said to be ‘inverse’
    //   if they produce the same prime number for complementary requests
    //
    // CLASS INVARIANT: The number of jumpPrime objects remain unchanged.
    public class duelingJP
    {
        // Array to hold the jumpPrime objects
        private jumpPrime[] group;

        // Constructor:   initialize group, size and create jumpPrime objects.
        // precondition:  input size equals to input array length.
        // postcondition: group of jumpPrime objects created with provided input
        public duelingJP(int[] values)
        {
            group = new jumpPrime[values.Length];
            for (int i = 0; i < values.Length; i++)
            {
                jumpPrime jp = new jumpPrime(values[i]);
                group[i] = jp;
            }
        }

        // Helper function for getting collisions and inversions
        // precondition:  input true if query collisions, false if query inversions
        // postcondition: jumpPrime objects in group will be revived if inactive
        //                before querying.
        public int query(bool mode)
        {
            int count = 0;
            for (int i = 0; i < group.Length - 1; i++)
            {
                if (!group[i].isActive()) group[i].revive();
                int up = group[i].up();
                for (int j = i + 1; j < group.Length; j++)
                {
                    if (!group[j].isActive()) group[j].revive();
                    if (mode && up == group[j].up()) count++;
                    if (!mode && up == group[j].down()) count++;
                }
            }
            return count;
        }

        // Get number of collisions with the current encapsulated jumpPrimes
        // precondition: none
        // postcondition: jumpPrime objects in group will be revived if inactive
        //                before querying.
        public int getCollisions()
        {
            return query(true);
        }

        // Get number of inversions with the current encapsulated jumpPrimes
        // precondition: none
        // postcondition: jumpPrime objects in group will be revived if inactive
        //                before querying.
        public int getInversions()
        {
            return query(false);
        }
    }
}