using System;
// Author:      Duc Vo
// Filename:    P3.cs
// Date:        February 11, 2022,
// Version:     1.0
// Description: This file contains the test drivers for dataFilter class
//              and its derived classes (dataMod and dataCut).

namespace P3
{
    // This class is a test driver for the DataFilter, DataMod, and DataCut classes
    public class P3
    {
        // This main method calls cest classes static test methods
        // where they create testing instances in different states
        // and run test on base and derived dataFilter classes functionalities
        // Input:       none
        // Process:     Run test on each test classes DatafilterTest, DataModTest,
        //              DataCutTest and DataCollectionTest
        // Output:      none
        static void Main()
        {
            DataFilterTest.run();
            DataModTest.run();
            DataCutTest.run();
            DataCollectionTest.run();
        }
    }
   
    // This class test the dataFilter class
    public class DataFilterTest
    {
        // Execute the main test run
        // Input:       none
        // Process:     Create dataFilter objects with small and large mode then
        //              run the scramble and filter function. Expected run result
        //              equals to the expected result
        // Output:      none
        public static void run()
        {
            const int PRIME = 3;
            // Create log instance use to display different test result
            Log log = new Log();
            // Use to inject a sequence
            int[] testSequence = new int[] { 1, 2, 3, 4, 5, 6 };
            // Use for testing scramble on object with injected sequence (replace sequence) LARGE mode
            int[] testSequence2 = new int[] { 6, 1, 5, 2, 4, 3 }; 
            // Use for testing scramble on object with injected sequence (replace sequence) SMALL mode
            int[] testSequence3 = new int[] { 1, 6, 2, 5, 3, 4 }; 
            int[] expected; // To hold expected test result for comparison
            bool result; // To hold actual test result 
            dataFilter obj;

            log.print("==================================");
            log.print("=     TEST DATAFILTER CLASS      =");
            log.print("==================================");

            // Test filter method on DataFilter
            log.print("===== TEST FILTER =====");

            // Test filter on empty sequence
            log.print("Test filter on empty sequence");
            obj = new dataFilter(PRIME);
            expected = new int[] { 3 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);

            obj.scramble(testSequence); // Inject sequence

            // Test filter with injected sequence on LARGE mode
            log.print("Test filter with injected sequence on LARGE mode");
            expected = new int[] { 4, 5, 6 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);

            // Test filter with injected sequence on SMALL mode
            log.print("Test filter with injected sequence on SMALL mode");
            obj.setMode(false);
            expected = new int[] { 1, 2 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);


            // Test scramble method on DataFilter
            log.print("===== TEST SCRAMBLE =====");

            // Test scramble on no sequence object (inject sequence) LARGE mode
            obj = new dataFilter(PRIME);
            log.print("Test scramble on no sequence object (inject sequence) LARGE mode");
            expected = new int[] { 4, 5, 6, 1, 2, 3 };
            result = Test.testScramble(obj, expected, testSequence);
            log.printResult(result);

            // Test scramble on object with injected sequence (replace sequence) LARGE mode
            log.print("Test scramble on object with injected sequence (replace sequence) LARGE mode");
            
            expected = new int[] { 6, 4, 5, 2, 1, 3 };
            result = Test.testScramble(obj, expected, testSequence2);
            log.printResult(result);


            // Test scramble on no sequence object (inject sequence) SMALL mode
            log.print("Test scramble on no sequence object (inject sequence) SMALL mode");
            obj = new dataFilter(PRIME, false);
            
            expected = new int[] { 2, 1, 3, 6, 4, 5 };
            result = Test.testScramble(obj, expected, testSequence2);
            log.printResult(result);

            // Test scramble on object with injected sequence (replace sequence) SMALL mode
            log.print("Test scramble on object with injected sequence (replace sequence) SMALL mode");
            expected = new int[] { 1, 3, 2, 5, 6, 4 };
            result = Test.testScramble(obj, expected, testSequence3);
            log.printResult(result);
        }
    }

    // This class test the dataMod class
    public class DataModTest
    {
        // Execute the main test run
        // Input:       none
        // Process:     Create dataMod objects with small and large mode then
        //              run the scramble and filter function. Expected run result
        //              equals to the expected result
        // Output:      none
        public static void run()
        {
            const int PRIME = 3;
            // Create log instance use to display different test result
            Log log = new Log(); 
            // Use to inject a sequence
            int[] testSequence = new int[] { 1, 2, 3, 4, 5, 6 };
            // Use for testing scramble on object with injected sequence (replace sequence) LARGE mode
            int[] testSequence2 = new int[] { 6, 1, 5, 2, 4, 3 };
            // Use for testing scramble on object with injected sequence (replace sequence) SMALL mode
            int[] testSequence3 = new int[] { 1, 6, 2, 5, 3, 4 };
            int[] expected; // To hold expected test result for comparison
            bool result; // To hold actual test result 
            dataMod obj;

            log.print("==================================");
            log.print("=       TEST DATAMOD CLASS       =");
            log.print("==================================");

            // Test filter method on DataMod
            log.print("===== TEST FILTER =====");

            // Test filter on empty sequence
            log.print("Test filter on empty sequence");
            obj = new dataMod(PRIME);
            expected = new int[] { 4 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);

            // Test filter with injected sequence on LARGE mode
            log.print("Test filter with injected sequence on LARGE mode");
            obj.scramble(testSequence);// Inject sequence
            expected = new int[] { 5, 7 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);

            // Test filter with injected sequence on SMALL mode
            log.print("Test filter with injected sequence on SMALL mode");
            obj.setMode(false);
            expected = new int[] { 0, 1, 1, 1 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);


            // Test scramble method on DataMod
            log.print("===== TEST SCRAMBLE =====");

            // Test scramble on no sequence object (inject sequence) LARGE mode
            obj = new dataMod(PRIME);
            log.print("Test scramble on no sequence object (inject sequence) LARGE mode");
            expected = new int[] { 4, 2, 6, 1, 2, 2 };
            result = Test.testScramble(obj, expected, testSequence);
            log.printResult(result);

            // Test scramble on object with injected sequence (replace sequence) LARGE mode
            log.print("Test scramble on object with injected sequence (replace sequence) LARGE mode");
          
            expected = new int[] { 6, 4, 2, 2, 1, 2 };
            result = Test.testScramble(obj, expected, testSequence2);
            log.printResult(result);

            // Test scramble on no sequence object (inject sequence) SMALL mode
            log.print("Test scramble on no sequence object (inject sequence) SMALL mode");
            obj = new dataMod(PRIME, false);
            expected = new int[] { 2, 1, 2, 6, 4, 2 };
            result = Test.testScramble(obj, expected, testSequence2);
            log.printResult(result);

            // Test scramble on object with injected sequence (replace sequence) SMALL mode
            log.print("Test scramble on object with injected sequence (replace sequence) SMALL mode");
            expected = new int[] { 1, 2, 2, 2, 6, 4 };
            result = Test.testScramble(obj, expected, testSequence3);
            log.printResult(result);
        }
    }

    // This class test the dataCut class
    public class DataCutTest
    {
        // Execute the main test run
        // Input:       none
        // Process:     Create dataCut objects with small and large mode then
        //              run the scramble and filter function. Expected run result
        //              equals to the expected result
        // Output:      none
        public static void run()
        {
            const int PRIME = 3;
            // Create log instance use to display different test result
            Log log = new Log(); 
            // Use to inject a sequence
            int[] testSequence = new int[] { 1, 2, 3, 4, 5, 6 };
            // Use for testing scramble on object with injected sequence (replace sequence) LARGE mode
            int[] testSequence2 = new int[] { 6, 1, 5, 2, 4, 3, 7, 8, 9 }; 
            // Use for testing scramble on object with injected sequence (replace sequence) SMALL mode
            int[] testSequence3 = new int[] { 6, 3, 7, 8, 9, 12, 10, 11 }; 
            int[] expected;
            bool result;
            dataCut obj;

            log.print("==================================");
            log.print("=       TEST DATACUT CLASS       =");
            log.print("==================================");

            // Test filter method on DataMod
            log.print("===== TEST FILTER =====");

            // Test filter on empty sequence
            log.print("Test filter on empty sequence");
            obj = new dataCut(PRIME);
            expected = new int[] { };
            result = Test.testFilter(obj, expected);
            log.printResult(result);


            // Test filter with injected sequence on LARGE mode
            log.print("Test filter with injected sequence on LARGE mode");
            obj.scramble(testSequence);// Inject sequence
            expected = new int[] { 4, 5 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);

            // Test filter with injected sequence on SMALL mode
            log.print("Test filter with injected sequence on SMALL mode");
            obj.setMode(false);
            expected = new int[] { 2 };
            result = Test.testFilter(obj, expected);
            log.printResult(result);


            // Test scramble method on DataCut
            log.print("===== TEST SCRAMBLE =====");

            // Test scramble on no sequence object (inject sequence) LARGE mode
            obj = new dataCut(PRIME);
            log.print("Test scramble on no sequence object (inject sequence) LARGE mode");
            expected = new int[] { 4, 5, 6, 1, 2, 3 };
            result = Test.testScramble(obj, expected, testSequence);
            log.printResult(result);

            // Test scramble on object with injected sequence (replace sequence) LARGE mode
            log.print("Test scramble on object with injected sequence (replace sequence) LARGE mode");
            expected = new int[] { 8, 7, 9 };
            result = Test.testScramble(obj, expected, testSequence2);
            log.printResult(result);


            // Test scramble on no sequence object (inject sequence) SMALL mode
            log.print("Test scramble on no sequence object (inject sequence) SMALL mode");
            obj = new dataCut(PRIME, false);
            expected = new int[] { 4, 1, 5, 2, 6, 3, 7, 8, 9 };
            result = Test.testScramble(obj, expected, testSequence2);
            log.printResult(result);

            // Test scramble on object with injected sequence (replace sequence) SMALL mode
            log.print("Test scramble on object with injected sequence (replace sequence) SMALL mode");
            expected = new int[] { 10, 12, 11 };
            result = Test.testScramble(obj, expected, testSequence3);
            log.printResult(result);

        }
    }

    // This class test heterogeneous collection of dataFilter and the collective functionalities
    public class DataCollectionTest
    {
        // Create log instance use to display different test result
        private static Log log = new Log();

        // Execute the main test run
        // Input:       none
        // Process:     Create heterogeneous collection of dataFilter then 
        //              test the functionalities of the collection objects that
        //              create different results
        // Output:      none
        public static void run()
        {
            const int SIZE = 3;
            const int PRIME = 3;
            int[] testSequence = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            bool result;

            log.print("=============================================");
            log.print("=       TEST HETEROGENEOUS COLLECTION       =");
            log.print("=============================================");

            dataFilter[] collection = new dataFilter[SIZE];

            log.print("CREATE A HETEROGENEOUS COLLECTION OF DATAFILTER OBJECTS");
            for (int i = 0; i < SIZE; i++)
            {
                collection[i] = createInstance(i, PRIME);
                Console.WriteLine("collection[{0}]: {1}", i,
                    i == 0 ? "DataFilter" : i == 1 ? "DataMod" : "DataCut");
            }

            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("collection[{0}]", i);
                log.print("Scrambled: ");
                int[] sb = collection[i].scramble(testSequence);
                log.printArray(sb);
                log.print("Filtered: ");
                Console.Write("  Large Mode: ");
                int[] fl = collection[i].filter();
                log.printArray(fl);
                collection[i].setMode(false);
                Console.Write("  Small Mode: "); ;
                fl = collection[i].filter();
                log.printArray(fl);
                log.newLine();
            }

            for (int i = 0; i < SIZE - 1; i++)
            {
                for (int j = i + 1; j < SIZE; j++)
                {
                    Console.WriteLine("==================================");
                    Console.WriteLine("collection[{0}] VS collection[{1}]", i, j);
                    Console.Write("{0} VS ", i == 0 ? "DataFilter" : i == 1 ? "DataMod" : "DataCut");
                    Console.WriteLine(j == 0 ? "DataFilter" : j == 1 ? "DataMod" : "DataCut");

                    Console.WriteLine("== TEST SCRAMBLE ==\n(expected different filter results)");
                    Console.WriteLine("MODE: LARGE");
                    collection[i] = createInstance(i, PRIME);
                    collection[j] = createInstance(j, PRIME);
                    collection[i].scramble(testSequence); // Inject sequence
                    collection[j].scramble(testSequence); // Inject sequence
                    int[] scramble1 = collection[i].scramble(testSequence); // Replace sequence
                    int[] scramble2 = collection[j].scramble(testSequence); // Replace sequence
                    result = compare(scramble1, scramble2);
                    log.printArray(scramble1);
                    log.printArray(scramble2);
                
                    log.printResult(!result);

                    Console.WriteLine("MODE: SMALL");
                    collection[i] = createInstance(i, PRIME);
                    collection[j] = createInstance(j, PRIME);
                    collection[i].setMode(false); // Set SMALL mode
                    collection[j].setMode(false); // Set SMALL mode
                    collection[i].scramble(testSequence); // Inject sequence
                    collection[j].scramble(testSequence); // Inject sequence
                    scramble1 = collection[i].scramble(testSequence); // Replace sequence
                    scramble2 = collection[j].scramble(testSequence); // Replace sequence
                    result = compare(scramble1, scramble2);
                    log.printArray(scramble1);
                    log.printArray(scramble2);
                    log.printResult(!result);

                    Console.WriteLine("== TEST FILTER ==\n(expected different filter results)");

                    Console.WriteLine("MODE: LARGE");
                    collection[i] = createInstance(i, PRIME);
                    collection[j] = createInstance(j, PRIME);
                    collection[i].scramble(testSequence); // Inject sequence
                    collection[j].scramble(testSequence); // Inject sequence
                    int[] filter1 = collection[i].filter();
                    int[] filter2 = collection[j].filter();
                    result = compare(filter1, filter2);
                    log.printArray(filter1);
                    log.printArray(filter2);
                    log.printResult(!result);

                    Console.WriteLine("MODE: SMALL");
                    collection[i] = createInstance(i, PRIME);
                    collection[j] = createInstance(j, PRIME);
                    collection[i].setMode(false); // Set SMALL mode
                    collection[j].setMode(false); // Set SMALL mode
                    collection[i].scramble(testSequence); // Inject sequence
                    collection[j].scramble(testSequence); // Inject sequence
                    filter1 = collection[i].filter();
                    filter2 = collection[j].filter();
                    result = compare(filter1, filter2);
                    log.printArray(filter1);
                    log.printArray(filter2);
                    log.printResult(!result);
                }
            }
        }

        // This method create an instance dataFilter or dataMod or dataCut
        // Input:       number option for type of object creation, PRIME number
        // Process:     Check the input option then create and return the correct
        //              type:
        //               0: dataFilter object
        //               1: dataMod object
        //               2: dataCut object
        // Output:      return the newly created instance with provided option for type
        public static dataFilter createInstance(int num, int PRIME)
        {
            switch (num)
            {
                case 0: return new dataFilter(PRIME);
                case 1: return new dataMod(PRIME);
                case 2: return new dataCut(PRIME);
                default: return new dataFilter(PRIME);
            }
        }


        // This method compare the content of result and expected array
        // Input:       result and expected array
        // Process:     loop though the array and compare each element
        // Output:      True if two array are equal, False otherwise
        public static bool compare(int[] expected, int[] result)
        {
            
            if (expected != null && result != null && result.Length == expected.Length)
            {
                for (int i = 0; i < result.Length; i++)
                    if (result[i] != expected[i]) return false;
                return true;
            }
            return false;
        }
    }

    // This class test provide static methods to test dataFilter object
    public class Test
    {
        // This method test the dataFilter filter method
        // Input:       dataFilter object, expected result
        // Process:     Call filter methods on the object and compare to the expected result
        // Output:      True if result equal expected, False otherwise
        public static bool testFilter(dataFilter obj, int[] expected)
        {
            int[] result = obj.filter();
            return compare(expected, result);
        }

        // This method test the dataFilter scramble method
        // Input:       dataFilter object, expected result, input testSequence
        // Process:     Call scramble methods on the object and compare to the expected result
        // Output:      True if result equal expected, False otherwise
        public static bool testScramble(dataFilter obj, int[] expected, int[] testSequence)
        {
            int[] result = obj.scramble(testSequence);
            return compare(expected, result);
        }

        // This method compare the content of result and expected array
        // Input:       result and expected array
        // Process:     loop though the array and compare each element
        // Output:      True if two array are equal, False otherwise
        public static bool compare(int[] expected, int[] result)
        {
            // Create log instance use to display different test result
            Log log = new Log();
            log.printData(result, expected);
            if (expected != null && result != null && result.Length == expected.Length)
            {
                for (int i = 0; i < result.Length; i++)
                    if (result[i] != expected[i]) return false;
                return true;
            }
            return false;
        }
    }

    // This class is a general purpose printing class where you can print out
    // a variety of input content
    public class Log
    {
        // Print an array content to the console
        // Input:       Array of integers
        // Process:     loop though the array print out the item content
        // Output:      none
        public void printArray(int[] arr)
        {
            Console.Write("[ ");
            for (int i = 0; i < arr.Length; i++)
                Console.Write("{0}{1}", arr[i], i == arr.Length - 1 ? "" : ", ");

            Console.WriteLine(" ]");
        }

        // Print the result and expected array content to the console
        // Input:       2 array of integers
        // Process:     loop though the arrays and print out the contents
        // Output:      none
        public void printData(int[] result, int[] expected)
        {
            Console.Write("Result: ");
            printArray(result);
            Console.Write("Expected: ");
            printArray(expected);
        }

        // Wrapper for Console.Writeline
        // Input:       string of test
        // Process:     call Console.WriteLine on the input text
        // Output:      none
        public void print(String text)
        {
            Console.WriteLine(text);
        }

        // Create a new line
        // Input:       none
        // Process:     call Console.WriteLine() to print an empty line
        // Output:      none
        public void newLine() { Console.WriteLine(); }

        // Print Passed or Failed base on the input boolean
        // Input:       boolean
        // Process:     Check if input true, print "PASSED", otherwise print "FAILED"
        // Output:      none
        public void printResult(bool passed)
        {
            Console.Write("Status: ");
            Console.WriteLine(passed ? "PASSED" : "FAILED");
            newLine();
        }
        
    }
  
}
