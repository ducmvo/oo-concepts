using System;

// Author:      Duc Vo
// Filename:    P1.cs
// Version:     1.0
// Date:        01/17/2022
// Description: This program tests the jumpPrime class by generate random
//              object in different state and alter these objects state to yield
//              expected results

namespace p1
{
    public class P1
    {
        static void Main()
        {
            Random random = new Random();

            int num = random.Next(1000);
            testObject(num);
            num = random.Next() + 1000;
            testObject(num);
            num = 2147483646;
            testObject(num);

        }

        static int executeRandomQuery(jumpPrime jp, Random random)
        {
            return random.Next(2) == 0 ? jp.up() : jp.down();
        }

        static void testObject(int num)
        {
            jumpPrime jp = new jumpPrime(num);
            Random random = new Random();

            Console.WriteLine("RANDOM NUMBER {0}", num);
            Console.WriteLine("UPPER PRIME {0}", jp.up());
            Console.WriteLine("LOWER PRIME {0}\n", jp.down());
            Console.WriteLine("ACTIVE {0} | DEAD {1}", jp.isActive(), jp.isDead());

            Console.WriteLine("\nQUERY UNTIL OBJECT IS INACTIVE");
            while (jp.isActive())
            {
                executeRandomQuery(jp, random);
            }
            Console.WriteLine("QUERY COUNT: {0}", jp.getQueryCount());

            Console.WriteLine("ACTIVE {0} | DEAD {1}", jp.isActive(), jp.isDead());
            Console.WriteLine("\nQUERY INACTIVE OBJECT: {0}", executeRandomQuery(jp, random));

            Console.WriteLine("\n=== REVIVE INACTIVE OBJECT ===");
            jp.revive();
            Console.WriteLine("ACTIVE {0} | DEAD {1}", jp.isActive(), jp.isDead());

            Console.WriteLine("\n=== RESET OBJECT ===");
            jp.reset();
            Console.WriteLine("QUERY COUNT: {0}", jp.getQueryCount());

            Console.WriteLine("\n=== REVIVE ACTIVE OBJECT ===");
            jp.revive();
            Console.WriteLine("ACTIVE {0} | DEAD {1}", jp.isActive(), jp.isDead());


            Console.WriteLine("\n=== REVIVE DEAD OBJECT ===");
            jp.revive();
            Console.WriteLine("ACTIVE {0} | DEAD {1}", jp.isActive(), jp.isDead());

            Console.WriteLine("\nQUERY DEAD OBJECT: {0}", executeRandomQuery(jp, random));
        }
    }
}
