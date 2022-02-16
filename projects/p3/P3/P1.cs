using System;

namespace P3
{
    public class P1
    {
        // This class is a test driver for the jumpPrime class

        // This main method calls other methods where they create random objects
        // in different states and run test the jumpPrime class. 
        public static void testJumpPrime()
        {
            testContructor();
            testRevive();
            testJump();
            testReset();
            testUp();
            testDown();
        }

        // This testContructor method create four random objects 
        // with no input, random integer less than 1000, and
        // random integer input greater than 100 and maximum integer input 
        // and expected result is to have object successfully created.
        // The object with no input, input less than 1000, and maximum integer input 
        // will have the value set to 1000 by the jumpPrime class
        static void testContructor()
        {
            int MIN_NUM = 1000;
            int MAX_NUM = int.MaxValue;
            Random random = new Random();

            Console.WriteLine("\n========= TEST CONTRUCTOR =========");

            string description = "Create object with default contructor";
            jumpPrime jp = new jumpPrime();
            printTest(jp, true, false, description);

            description = "Create object with value less than " + MIN_NUM;
            int num = random.Next(MIN_NUM);
            jumpPrime jp1 = new jumpPrime(num);
            printTest(jp1, true, false, description);

            description = "Create object with value greater than " + MIN_NUM;
            num = random.Next() + MIN_NUM;
            jumpPrime jp2 = new jumpPrime(num);
            printTest(jp2, true, false, description);

            description = "Create object with value equals max integer " + MAX_NUM;
            Console.WriteLine("> Expect value to be reset to 1000");
            jumpPrime jp3 = new jumpPrime(MAX_NUM);
            printTest(jp3, true, false, description);
        }

        // This testRevive will create an object in an inactive state then revive it and
        // then attempt to revive the object in the active state. The expected result
        // Is the object become active when revive in inactive state and become dead when
        // revive in active state
        static void testRevive()
        {
            Random random = new Random();

            Console.WriteLine("\n========= TEST REVIVE =========");

            int num = random.Next();
            jumpPrime jp = new jumpPrime(num);

            while (jp.isActive())
            {
                executeRandomQuery(jp);
            }
            string description = "Create an alive and inactive object";
            printTest(jp, false, false, description);

            description = "Revive an inactive object";
            jp.revive();
            printTest(jp, true, false, description);

            description = "Revive an active object";
            jp.revive();
            printTest(jp, false, true, description);
        }

        // This testJump method will create an object and query it until it reaches
        // maximum query then execute and additional query to jump the original value.
        // The expected result is new primes number will be calculated based on the new
        // jumped value
        static void testJump()
        {
            Console.WriteLine("\n========= TEST JUMP =========");

            Random random = new Random();
            int num = random.Next();
            jumpPrime jp = new jumpPrime(num);
            int upperPrime = jp.up();
            int lowerPrime = jp.down();
            int maxQueries = upperPrime - lowerPrime;
            executeRandomQuery(jp, maxQueries - 2);
            Console.WriteLine("> Expect the upperPrime and lowerPrime to be DIFFERENT");
            Console.WriteLine("> Queried {0} times (Max Queries)", maxQueries);
            Console.WriteLine("> Executed addional query to JUMP");
            Console.WriteLine("OLD lowerPrime {0} | NEW lowerPrime {1}", lowerPrime, jp.down());
            Console.WriteLine("OLD upperPrime {0} | NEW upperPrime {1}", upperPrime, jp.up());
            Console.WriteLine("> New Max Queries {0}", jp.up() - jp.down());
        }

        // This testReset method will create an object and query it until it reaches
        // maximum query then reset right before the object jump the original value
        // if additional query added. The expected result is the object can be 
        // queried with the value and it's nearby primes retained
        static void testReset()
        {
            Console.WriteLine("\n========= TEST RESET =========");

            Random random = new Random();
            int num = random.Next() + 1000;
            jumpPrime jp = new jumpPrime(num);

            int upperPrime = jp.up();
            int lowerPrime = jp.down();
            int maxQueries = upperPrime - lowerPrime;
            executeRandomQuery(jp, maxQueries - 2);
            Console.WriteLine("> Queried {0} times (Max Queries)", maxQueries);
            Console.WriteLine("> Reset Before JUMP");
            jp.reset();
            Console.WriteLine("> Expect the upperPrime and lowerPrime to be the SAME");
            Console.WriteLine("OLD lowerPrime {0} | NEW lowerPrime {1}", lowerPrime, jp.down());
            Console.WriteLine("OLD upperPrime {0} | NEW upperPrime {1}", upperPrime, jp.up());
            Console.WriteLine("> New Max Queries {0}", jp.up() - jp.down());
        }

        // This testUp method create a random jumpPrime object and an object with
        // the maximum integer value and query the upperPrimes.
        // Expect result to have the correct upperPrime for the random object and
        // the value to be reset to 1000 for the object with max integer value.
        static void testUp()
        {
            int MAX_NUM = int.MaxValue;
            Random random = new Random();

            Console.WriteLine("\n========= TEST UP =========");

            int num = random.Next();
            jumpPrime jp = new jumpPrime(num);
            Console.WriteLine("> Test UP on random object");
            Console.WriteLine("INPUT NUMBER: {0} | upperPrime {1}", num, jp.up());

            Console.WriteLine("> Test UP on object with value equals max integer {0}", MAX_NUM);
            Console.WriteLine("> Expect value to be reset to 1000");
            jumpPrime jp1 = new jumpPrime(MAX_NUM);
            Console.WriteLine("INPUT NUMBER: {0} | upperPrime {1}", MAX_NUM, jp1.up());
        }

        // This testDown method create a random jumpPrime object and an object with
        // the maximum integer value and query the lowerPrimes.
        // Expect result to have the correct lowerPrime for the random object and
        // the value to be reset to 1000 for the object with max integer value.
        static void testDown()
        {
            int MAX_NUM = int.MaxValue;
            Random random = new Random();

            Console.WriteLine("\n========= TEST DOWN =========");

            int num = random.Next();
            jumpPrime jp = new jumpPrime(num);
            Console.WriteLine("> Test DOWN on random object");
            Console.WriteLine("INPUT NUMBER: {0} | lowerPrime {1}", num, jp.down());

            Console.WriteLine("> Test DOWN on object with value equals max integer {0}", MAX_NUM);
            Console.WriteLine("> Expect value to be reset to 1000");
            jumpPrime jp1 = new jumpPrime(MAX_NUM);
            Console.WriteLine("INPUT NUMBER: {0} | lowerPrime {1}", MAX_NUM, jp1.down());
        }

        // This printTest helper function takes in the jumpPrime object, the user
        // expected object states, and description and print out the formatted comparison
        static void printTest(jumpPrime jp, bool isActive, bool isDead, string description)
        {
            Console.WriteLine("> {0} - actual/expected", description);
            Console.WriteLine("active {0}/{1} | dead {2}/{3}",
                            jp.isActive(), isActive,
                            jp.isDead(), isDead);
        }

        // This executeRandomQuery helper function take in a jumpPrime object and
        // the number of times user want to query the object, then randomly call
        // up or down query on the object for that amount of times.
        static void executeRandomQuery(jumpPrime jp, int times = 1)
        {
            Random random = new Random();
            while (times != 0)
            {
                if (random.Next(2) == 0)
                    jp.up();
                else jp.down();
                times--;
            }
        }
    }

}
