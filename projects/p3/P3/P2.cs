using System;
namespace P3
{
    public class P2
    {
        // This class is a test driver for the duelingJP class

        // This main method calls other methods where they create random
        // duelingJP objects with differnt cadinality states and run test
        // the duelingJP class. 
        public static void testDuelingJP()
        {
            testContructor();
            testCollisions();
            testInversions();
            testQuery();
        }


        static void testContructor()
        {
            Console.WriteLine("\n========= TEST CONTRUCTOR =========");
            Random random = new Random();
            uint size = (uint)random.Next(1000);
            int[] values = generateValues(size);
            duelingJP djp = new duelingJP(values);
            Console.WriteLine("> Create duelingJP created with array of {0} integers" +
                "\ncollisions {1} | inversions {2}",
                size, djp.getCollisions(), djp.getInversions());


            string description = "Create duelingJP with empty array ";
            values = generateValues(0);
            djp = new duelingJP(values);
            printTest(djp, 0, 0, description);

            description = "Create dueling JP with one element array ";
            values = generateValues(1);
            djp = new duelingJP(values);
            printTest(djp, 0, 0, description);

        }

        // This testCollisions method create a random duelingJP object with
        // a random array of integers and call getCollisions on that object
        // Expect the methos to run without error
        static void testCollisions()
        {
            Console.WriteLine("\n========= TEST COLLISIONS =========");
            Random random = new Random();
            uint size = (uint)random.Next(1000);
            int[] values = generateValues(size, 1000, 2000);
            duelingJP djp = new duelingJP(values);
            Console.WriteLine("> Test get collisions on duelingJP created " +
                "with array of {0} integers", size);
            Console.WriteLine("> collisions {0}", djp.getCollisions());

            values = generateValues(0);
            djp = new duelingJP(values);
            Console.WriteLine("> Test get collisions on duelingJP created " +
                "with empty array - actual/expected");
            Console.WriteLine("> collisions {0} / 0", djp.getCollisions());

            values = generateValues(1);
            djp = new duelingJP(values);
            Console.WriteLine("> Test get collisions on duelingJP created " +
                "with empty array - actual/expected");
            Console.WriteLine("> collisions {0} / 0", djp.getCollisions());
        }

        // This testInversions method create a random duelingJP object with
        // a random array of integers and call getInversions on that object
        // Expect the methos to run without error
        static void testInversions()
        {
            Console.WriteLine("\n========= TEST INVERSIONS =========");
            Random random = new Random();
            uint size = (uint)random.Next(1000);
            int[] values = generateValues(size, 1000, 2000);
            duelingJP djp = new duelingJP(values);
            Console.WriteLine("> Test get inversions on duelingJP created " +
                "with array of {0} integers", size);
            Console.WriteLine("> inversions {0}", djp.getInversions());

            values = generateValues(0);
            djp = new duelingJP(values);
            Console.WriteLine("> Test get inversions on duelingJP created with" +
                " empty array - actual/expected");
            Console.WriteLine("> inversions {0} / 0", djp.getInversions());

            values = generateValues(1);
            djp = new duelingJP(values);
            Console.WriteLine("> Test get inversions on duelingJP created with " +
                "1 element array - actual/expected");
            Console.WriteLine("> inversions {0} / 0", djp.getInversions());
        }

        // This testInversions method create a random duelingJP object with
        // a random array of integers and randomly query it for random amount of times
        // Expect the method to run without error
        static void testQuery()
        {
            Console.WriteLine("\n========= TEST QUERY =========");
            Random random = new Random();
            int size = random.Next(100);
            int times = random.Next(1000);
            int[] values = generateValues((uint)size);
            duelingJP djp = new duelingJP(values);
            Console.WriteLine("> Test query {0} times on duelingJP created " +
                "with array of {1} integers", times, size);
            executeRandomQuery(djp, times);
            Console.WriteLine("> inversions {0}", djp.getInversions());
            Console.WriteLine("> collisions {0}", djp.getCollisions());
        }


        // This generateValues helper function generate an array of integer values
        // in the input range of min and max
        static int[] generateValues(uint size, int min = 1000, int max = 1040)
        {
            if (min > max)
            {
                int temp = min;
                min = max;
                max = temp;
            }
            Random random = new Random();
            int[] values = new int[size];
            for (int i = 0; i < size; i++)
            {
                values[i] = min + random.Next(max - min);
            }

            return values;
        }

        // This executeRandomQuery helper function take in a duelingJP object and
        // the number of times user want to query the object, then randomly call
        // getCollisions or getInversions query on the object for that amount of times.
        static void executeRandomQuery(duelingJP djp, int times = 1)
        {
            Random random = new Random();
            while (times != 0)
            {
                if (random.Next(2) == 0)
                    djp.getCollisions();
                else djp.getInversions();
                times--;
            }
        }

        // This printTest helper function takes in the duelingJP object, the user
        // expected object states, and description and print out the formatted comparison
        static void printTest(duelingJP djp, int collisions, int inversions, string description)
        {
            Console.WriteLine("> {0} - actual/expected", description);
            Console.WriteLine("collisions {0}/{1} | inversions {2}/{3}",
                            djp.getCollisions(), collisions,
                            djp.getInversions(), inversions);
        }
    }

}
