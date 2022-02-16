// Author:      Duc Vo
// Filename:    dataCut.cs
// Date:        February 15, 2022,
// Version:     1.0
// Description: This file contains the dataCut class which is a derived class
//              of dataFilter used to encapsulate a prime number
//              and a sequence of integers and provide overrided and private
//              functionalities on the sequence
namespace P3
{
    // The dataCut class is a derived class of dataFilter where each object
    // encapsulates a prime number p and provides the functionality to filter
    // and to scramble an integer sequence
    public class dataCut : dataFilter
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

        // Contructor create a dataCut instance with input data
        // preconditions: p is a prime number
        // postconditions: dataCut object created with encapsulated data
        public dataCut(int p, bool mode = true)
            : base(p, mode) { }

        // Filter the current sequence (refer to dataFilter for filter logic)
        // then removes the maximum number when in ‘large’ mode;
        // otherwise, removes the minimum
        // preconditions: sequence is not null
        // postconditions: none
        public override int[] filter()
        {
            int[] newSeq = base.filter();

            if (seq != null)
                newSeq = removeValue(newSeq, getMinOrMax(newSeq));

            return newSeq;
        }
        // Remove any number that occurred int the previous scramble request
        // before scrambling (refer to the dataFilter scramble for scrambling logic)
        // preconditions: none
        // postconditions: Encapsulated sequence replaced with modified sequence
        public override int[] scramble(int[] seq)
        {
            if (this.seq == null) return base.scramble(seq);

            int[] newSeq = removeValues(seq, this.seq);

            return base.scramble(newSeq);
        }

        // Get min or max value from a provided sequence base on current mode
        // Return Max if in Large mode, Min otherwise
        // preconditions: sequence is not null or empty
        // postconditions: none
        private int getMinOrMax(int[] seq)
        {
            if (seq == null || seq.Length == 0) return 0;
            int val = seq[0];
            for (int i = 0; i < seq.Length; i++)
                if (mode && seq[i] > val || !mode && seq[i] < val)
                    val = seq[i];

            return val;
        }

        // Create a new sequence with a value removed from the original sequence
        // preconditions: sequence not null
        // postconditions: none
        private int[] removeValue(int[] seq, int val)
        {
            if (seq == null) return null;
            int count = 0;
            for (int i = 0; i < seq.Length; i++)
                if (seq[i] == val) count++;

            int[] newSeq = new int[seq.Length - count];
            int index = 0;
            for (int i = 0; i < seq.Length; i++)
                if (seq[i] != val) newSeq[index++] = seq[i];

            return newSeq;
        }

        // Create a new sequence with values from provided array removed
        // from the original sequence
        // preconditions: sequence not null
        // postconditions: none
        private int[] removeValues(int[] seq, int[] values)
        {
            if (seq == null || values == null)
                return null;

            int[] newSeq = copy(seq);
            if (values.Length != 0)
                for (int i = 0; i < values.Length; i++)
                    newSeq = removeValue(newSeq, values[i]);

            return newSeq;
        }
    }
}
