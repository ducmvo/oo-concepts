using System;
// Author:      Duc Vo
// Filename:    dataFilter.cs
// Date:        February 15, 2022,
// Version:     1.0
// Description: This file contains the dataFilter class used to encapsulate a prime number
//              and a sequence of integers and provide functionalities on the sequence
namespace P3
{
    // The dataFilter class where each object encapsulates a prime number p and
    // provides the functionality to filter and to scramble an integer sequence
    public class dataFilter
    {
        // CLASS INVARIANT:
        //  - Encapsulated prime number is not changing though object lifetime

        //INTERFACE INVARIANT:
        //  - Input is a prime number or set to default prime value
        //  - Default mode is large if not provided with constructor
        //  - Sequence not initialized until calling scramble
        //  - Default mode set to true (Large mode) if not provided with constructor

        //IMPLEMENTATION INVARIANT:
        // - Sequence is initialized to properly use filter method
        // - Scramble method ecapsulates the original input sequence
        // - Prime number will be set to default if contructor input is not a prime

        // Default prime number used when input is not a prime
        private static int DEFAULT_PRIME = 3;

        // Encapsulated prime number
        protected int p;

        // Bool to hold the provided mode.
        //    True: large mode,
        //    False: small mode
        protected bool mode;

        // Encapsulated integer sequence
        protected int[] seq;


        // Contructor create a datafilter instance with input data
        // preconditions: p is a prime number
        // postconditions: dataFilter object created with encapsulated data
        public dataFilter(int p, bool mode = true)
        {
            if (!checkPrime(p))
                this.p = DEFAULT_PRIME;
            this.p = p;
            this.mode = mode;
        }

        // Get a subset of an encapsulated integer sequence, as follows:
        // If current sequence is null,
        //    return one element array of current ecapsulated prime number
        // Else
        //    LARGE mode: array of integers larger than prime number
        //    LARGE mode: array of integers smaller than prime number
        // preconditions: sequence is not null
        // postconditions: none
        public virtual int[] filter()
        {
            if (seq == null) return new int[] { p };

            int count = 0;
            for (int i = 0; i < seq.Length; i++)
               if (mode && seq[i] > p || !mode && seq[i] < p)
                    count++;

            int[] newSeq = new int[count];

            if (count != 0)
                for (int i = seq.Length - 1; i >= 0; i--)
                    if (mode && seq[i] > p || !mode && seq[i] < p)
                        newSeq[--count] = seq[i];

            return newSeq;
        }

        // Replace the current encapsulated sequence.
        // Scramble the provided sequence base on the current mode
        // Pair index and index + mid sequence values
        //   LARGE mode: swap values if value at index less than value at index + mid
        //   SMALL mode: swap values if value at index greater than value at index + mid
        // Return the scrambled sequence
        // preconditions: input sequence not null
        // postconditions: object's encapsulated sequence replaced
        public virtual int[] scramble(int[] seq)
        {
            if (seq == null) return seq;
            this.seq = seq;

            int[] newSeq = copy(this.seq);

            int mid = newSeq.Length / 2;
            for (int i = 0; i < mid; i++)
                if (mode && newSeq[i] < newSeq[i + mid] ||
                    !mode && newSeq[i] > newSeq[i + mid])
                    swap(newSeq, i, i + mid);
            
            return newSeq;
        }

        // Setter for mode
        // True: Large mode, False: Small mode
        // preconditions: none
        // postconditions: mode is set to the input mode
        public void setMode(bool mode){ this.mode = mode; }

        // Helper function to swap values two index position in a sequence
        // preconditions: index 1 and index 2 within sequence length
        // postconditions: values at input sequence indexes swapped
        protected void swap(int[] seq, int idx1, int idx2)
        {
            if (seq.Length < idx1 || seq.Length < idx2) return;
            int temp = seq[idx1];
            seq[idx1] = seq[idx2];
            seq[idx2] = temp;
        }

        // Helper function to create a copy of input sequence
        // preconditions: input sequence not null
        // postconditions: none
        protected int[] copy(int[] seq)
        {
            if (seq == null) return seq;
            int[] newSeq = new int[seq.Length];
            for (int i = 0; i < seq.Length; i++)
                newSeq[i] = seq[i];
            return newSeq;
        }

        // Helper function to check if a number is a prime number
        // preconditions: none
        // postconditions: none
        protected bool checkPrime(int num)
        {
            if (num < 2) return false;
            for (int i = 2; i <= Math.Sqrt(num); i++)
                if (num % i == 0) return false;
            return true;
        }
    }
}

