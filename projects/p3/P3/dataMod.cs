// Author:      Duc Vo
// Filename:    dataMod.cs
// Date:        February 15, 2022,
// Version:     1.0
// Description: This file contains the dataMod class which is a derived class
//              of dataFilter used to encapsulate a prime number
//              and a sequence of integers and provide overrided and private
//              functionalities on the sequence
namespace P3
{
    // The dataMod class is a derived class of dataFilter where each object
    // encapsulates a prime number p and provides the functionality to filter
    // and to scramble an integer sequence
    public class dataMod : dataFilter
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
        // - Scramble method ecapsulates the modified input sequence
        // - Prime number will be set to default if contructor input is not a prime

        // Contructor create a dataMod instance with input data
        // preconditions: p is a prime number
        // postconditions: dataMod object created with encapsulated data
        public dataMod(int p, bool mode = true)
            : base(p, mode) { }

        // Filter the current sequence (refer to dataFilter for filter logic)
        // then increments each value when in ‘large’ mode; otherwise, decrements
        // preconditions: sequence is not null
        // postconditions: none
        public override int[] filter()
        {
            int[] newSeq = base.filter();
            for (int i = 0; i < newSeq.Length; i++)
                newSeq[i] += mode ? 1 : -1;
            return newSeq;
        }

        // Replaces all prime numbers with ‘2’ before scrambling
        // (refer to the dataFilter scramble for scrambling logic)
        // preconditions: input sequence not null
        // postconditions: object's encapsulated sequence replaced
        public override int[] scramble(int[] seq)
        {
            int[] newSeq = copy(seq);
            for (int i = 0; i < newSeq.Length; i++)
                if (checkPrime(newSeq[i])) newSeq[i] = 2;
            return base.scramble(newSeq);
        }
    }
}
