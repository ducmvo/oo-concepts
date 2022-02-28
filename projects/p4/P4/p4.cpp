// Author:      Duc Vo
// Filename:    p4.cpp
// Date:        February 25, 2022.
// Version:     1.0
// Description: This program tests the overloaded operators
//              for jumpPrime and duelingJP classes
// Input:       none
// Process:     The program creates multiple object with different states and
//              use the provided public overloaded operator methods to test
//              against client expected result values
// Output:      none

#include <iostream>
#include <string>
#include "jumpPrime.h"
#include "duelingJP.h"
using namespace std;

// Name:        testDuelingJP
// Input:       none
// Process:     This function calls testJumpPrimeComparison,
//              testJumpPrimeNonDestructive and testJumpPrimeDestructive
//              to test each category for the JumpPrime overloaded operators
// Output:      none
void testJumpPrime();

// Name:        testDuelingJP
// Input:       none
// Process:     This function calls testDuelingJPComparison,
//              testDuelingJPNonDestructive and testDuelingJPDestructive
//              to test each category for the JumpPrime overloaded operators
// Output:      none
void testDuelingJP();

// Name:        testJumpPrimeComparison
// Input:       none
// Process:     This function calls create multiple jumpPrime objects with the same
//              and different input and test the comparison type operators of the objects
// Output:      none
void testJumpPrimeComparison();

// Name:        testJumpPrimeNonDestructive
// Input:       none
// Process:     This function calls create multiple jumpPrime objects with the same
//              and different input and test the non-destructive type operators of the objects
// Output:      none
void testJumpPrimeNonDestructive();

// Name:        testJumpPrimeDestructive
// Input:       none
// Process:     This function calls create multiple jumpPrime objects with the same
//              and different input and test the destructive type operators of the objects
// Output:      none
void testJumpPrimeDestructive();


// Name:        testDuelingJPComparison
// Input:       none
// Process:     This function calls create multiple duelingJP objects with the same
//              and different input and test the comparison type operators of the objects
// Output:      none
void testDuelingJPComparison();

// Name:        testDuelingJPNonDestructive
// Input:       none
// Process:     This function calls create multiple duelingJP objects with the same
//              and different input and test the non-destructive type operators of the objects
// Output:      none
void testDuelingJPNonDestructive();

// Name:        testDuelingJPDestructive
// Input:       none
// Process:     This function calls create multiple duelingJP objects with the same
//              and different input and test the destructive type operators of the objects
// Output:      none
void testDuelingJPDestructive();

// Name:        printTest
// Input:       result, expected, description
// Process:     This function compare the result with expected and print
//              description and "PASS" or "FAIL" to the console
// Output:      none
void printTest(bool, bool, string);

// Name:        generateValues
// Input:       integer array, size of array, min and max range
// Process:     This function generate random values within input range and
//              fill in the provided array
// Output:      none
void generateValues(int[], int , int , int );

// This main method calls testJumpPrime and testDuelingJP methods where they
// run test on various aspects of the testing classes
// Input:       none
// Process:     calls testJumpPrime and testDuelingJP
// Output:      none
int main() {
    testJumpPrime();
    testDuelingJP();
    return 0;
}

void testDuelingJP() {
    testDuelingJPComparison();
    testDuelingJPNonDestructive();
    testDuelingJPDestructive();

}

void testJumpPrime()
{
    testJumpPrimeComparison();
    testJumpPrimeNonDestructive();
    testJumpPrimeDestructive();
}

void testJumpPrimeComparison()
{
    const int MAX_VAL = 1000000;
    const int MIN_VAL = 100;
    int num1 = rand() % MAX_VAL + MIN_VAL;
    int num2 = rand() % MAX_VAL + MIN_VAL;
    jumpPrime jp1(num1);
    jumpPrime jp2(num2);
    cout << "\ncompare two jumpPrime objects" << endl;
    cout << "jp1("<< num1 << ") | jp2(" << num2 << ")" << endl;
    string desc = "Test operator < ";
    printTest(jp1 < jp2, num1 < num2, desc);

    desc = "Test operator <=";
    printTest(jp1 <= jp2, num1 <= num2, desc);

    desc = "Test operator ==";
    printTest(jp1 == jp2, num1 == num2, desc);

    desc = "Test operator !=";
    printTest(jp1 != jp2, num1 != num2, desc);

    desc = "Test operator > ";
    printTest(jp1 > jp2, num1 > num2, desc);

    desc = "Test operator >=";
    printTest(jp1 >= jp2, num1 >= num2, desc);

    int num3 = rand() % MAX_VAL + MAX_VAL;
    jumpPrime jp3(num3);
    jumpPrime jp4(num3);
    cout << "\ncompare two jumpPrime objects" << endl;
    cout << "jp3("<< num3 << ") | jp4(" << num3 << ")" << endl;
    desc = "Test operator <=";
    printTest(jp3 <= jp4, true, desc);
    desc = "Test operator ==";
    printTest(jp3 == jp4, true, desc);
    desc = "Test operator >=";
    printTest(jp3 >= jp4, true, desc);
}

void testJumpPrimeNonDestructive()
{
    const int MAX_VAL = 10000;
    const int MIN_VAL = 100;
    int num1 = rand() % MAX_VAL + MIN_VAL;
    int num2 = rand() % MAX_VAL + MIN_VAL;
    jumpPrime jp1(num1);
    jumpPrime jp2(num2);
    jumpPrime jp3;

    string desc = "Test add two jumpPrimes";
    cout << "\njp1("<< num1 << ") | jp2(" << num2 << ")" << endl;
    jp3 = jp1 + jp2;
    jumpPrime jp4(num1 + num2);
    cout << "jp3 = jp1 + jp2 == jp4(" << num1 + num2 << ")" << endl;
    printTest(jp3 == jp4, true, desc);

    desc = "Test subtract two jumpPrimes";
    cout << "jp3 = jp2 - jp1 == jp5(" << num1 + num2 << ")" << endl;
    jp3 = jp2 - jp1;
    jumpPrime jp5(num2 - num1);
    printTest(jp3 == jp5, true, desc);

    desc = "Test multiply two jumpPrimes";
    cout << "jp3 = jp1 * jp2 == jp5(" << num1 * num2 << ")" << endl;
    jp3 = jp2 * jp1;
    jumpPrime jp6(num2 * num1);
    printTest(jp3 == jp6, true, desc);


    desc = "Test divide two jumpPrimes";
    cout << "jp3 = jp2 / jp1 == jp7(" << num2 / num1 << ")" << endl;
    jp3 = jp2 / jp1;
    jumpPrime jp7(num2 / num1);
    printTest(jp3 == jp7, true, desc);

    desc = "Test add a jumpPrime with a random number";
    cout << "\njp1("<< num1 << ") | number: " << num2 << endl;
    jp3 = jp1 + num2;
    jumpPrime jp8(num1 + num2);
    cout << "jp3 = jp1 + " << num2 << " == jp8(" << num1 + num2 << ")" << endl;
    printTest(jp3 == jp8, true, desc);

    desc = "Test subtract a jumpPrime with a random number";
    cout << "\njp1("<< num1 << ") | number: " << num2 << endl;
    jp3 = jp1 - num2;
    jumpPrime jp9(num1 - num2);
    cout << "jp3 = jp1 - " << num2 << " == jp4(" << num1 - num2 << ")" << endl;
    printTest(jp3 == jp9, true, desc);

    desc = "Test multiply a jumpPrime with a random number";
    cout << "\njp1("<< num1 << ") | number: " << num2 << endl;
    jp3 = jp1 * num2;
    jumpPrime jp10(num1 * num2);
    cout << "jp3 = jp1 * " << num2 << " == jp10(" << num1 * num2 << ")" << endl;
    printTest(jp3 == jp10, true, desc);

    desc = "Test divide a jumpPrime with a random number";
    cout << "\njp1("<< num1 << ") | number: " << num2 << endl;
    jp3 = jp1 / num2;
    jumpPrime jp11(num1 / num2);
    cout << "jp3 = jp1 / " << num2 << " == jp10(" << num1 / num2 << ")" << endl;
    printTest(jp3 == jp11, true, desc);

}

void testJumpPrimeDestructive()
{
    const int MAX_VAL = 10000;
    const int MIN_VAL = 100;
    int num1 = rand() % MAX_VAL + MIN_VAL;
    int num2 = rand() % MAX_VAL + MIN_VAL;
    int num3 = rand() % MAX_VAL + MIN_VAL;
    jumpPrime jp1(num1);
    jumpPrime jp2(num2);
    jumpPrime jp3(num3);

    string desc = "Test operator = another jumpPrime";
    cout << "\njp3("<< num3 << ") = jp1(" << num1 << ")" << endl;
    jp3 = jp1;
    cout << "jp3 == jp1(" << num1 << ")" << endl;
    printTest(jp3 == jp1, true, desc);

    desc = "Test operator += with another jumpPrime";
    cout << "\njp2("<< num2 << ") += jp1(" << num1 << ")" << endl;
    jp2 += jp1;
    jumpPrime jp4(num2 + num1);
    cout << "jp2 == jp4(" << num2 + num1 << ")" << endl;
    printTest(jp2 == jp4, true, desc);

    num2 += num1;
    desc = "Test operator -= with another jumpPrime";
    cout << "\njp2("<<  num2 << ") -= jp1(" << num1 << ")" << endl;
    jp2 -= jp1;
    jumpPrime jp5(num2 - num1);
    cout << "jp2 == jp5(" << num2 - num1 << ")" << endl;
    printTest(jp2 == jp5, true, desc);

    num2 -= num1;
    desc = "Test operator *= with another jumpPrime";
    cout << "\njp2("<<  num2 << ") *= jp1(" << num1 << ")" << endl;
    jp2 *= jp1;
    jumpPrime jp6(num2 * num1);
    cout << "jp2 == jp6(" << num2 * num1 << ")" << endl;
    printTest(jp2 == jp6, true, desc);

    num2 *= num1;
    desc = "Test operator /= with another jumpPrime";
    cout << "\njp2("<<  num2 << ") /= jp1(" << num1 << ")" << endl;
    jp2 /= jp1;
    jumpPrime jp7(num2 / num1);
    cout << "jp2 == jp7(" << num2 / num1 << ")" << endl;
    printTest(jp2 == jp7, true, desc);

    num2 /= num1;
    desc = "Test operator ++ (post)";
    cout << "\njp2("<<  num2 << ")" << endl;
    jumpPrime jp8(++num2);
    cout << "jp2++ != jp8(" << num2 << ")" << endl;
    printTest(jp2++ != jp8, true, desc);

    desc = "Test operator -- (post)";
    cout << "\njp2("<<  num2 << ")" << endl;
    jumpPrime jp9(--num2);
    cout << "jp2-- != jp9(" << num2 << ")" << endl;
    printTest(jp2-- != jp9, true, desc);

    desc = "Test operator ++ (pre)";
    jumpPrime jp10(++num2);
    cout << "\njp2("<<  num2 << ")" << endl;
    cout << "++jp2 == jp10(" << num2 << ")" << endl;
    printTest(++jp2 == jp10, true, desc);

    desc = "Test operator -- (pre)";
    cout << "\njp2("<<  num2 << ")--" << endl;
    jumpPrime jp11(--num2);
    cout << "--jp2 == jp11(" << num2 << ")" << endl;
    printTest(--jp2 == jp11, true, desc);

}

void testDuelingJPComparison() {
    const int SIZE = 100;
    const int MIN = 100;
    const int MAX = 100000;
    int values[SIZE];

    generateValues(values, SIZE, MIN, MAX);
    duelingJP djp1(SIZE, values);
    int temp = values[0];
    generateValues(values, SIZE, MIN, MAX);
    values[0] = temp + 1;
    duelingJP djp2(SIZE, values);

    cout << "\ncompare two not equal duelingJP objects" << endl;

    string desc = "Test operator ==";
    printTest(djp1 == djp2, false, desc);

    desc = "Test operator !=";
    printTest(djp1 != djp2, true, desc);


    generateValues(values, SIZE, MIN, MAX);
    duelingJP djp5(SIZE, values);
    generateValues(values, SIZE + 1, MIN, MAX);
    duelingJP djp6(SIZE, values);
    desc = "Test operator ==";
    printTest(djp5 == djp6, false, desc);

    desc = "Test operator !=";
    printTest(djp5 != djp6, true, desc);

    generateValues(values, SIZE, MIN, MAX);
    duelingJP djp3(SIZE, values);
    duelingJP djp4(SIZE, values);

    cout << "\ncompare two equal duelingJP objects" << endl;
    desc = "Test operator ==";
    printTest(djp3 == djp4, true, desc);
    desc = "Test operator !=";
    printTest(djp3 != djp4, false, desc);

}

void testDuelingJPNonDestructive()
{
    const int SIZE = 100;
    const int MIN = 100;
    const int MAX = 100000;
    int values[SIZE];
    int testValues[SIZE*2];
    int testValues2[SIZE*2 + 1];

    int num = rand() % MAX + MIN;
    jumpPrime jp(num);

    generateValues(values, SIZE, MIN, MAX);
    duelingJP djp1(SIZE, values);
    for (int i = 0; i < SIZE; i++)
        testValues[i] = values[i];

    generateValues(values, SIZE, MIN, MAX);
    for (int i = SIZE; i < 2*SIZE; i++)
        testValues[i] = values[i-SIZE];

    for (int i = 0; i < 2 * SIZE; i++)
        testValues2[i] = testValues[i];

    testValues2[2 * SIZE] = num;

    duelingJP djp2(SIZE, values);
    duelingJP djp3(SIZE*2, testValues);
    duelingJP djp4(SIZE*2 + 1, testValues2);


    string desc = "Test add two duelingJP object";
    cout << "djp4 = djp1 + djp2" << endl;
    printTest(djp3 == djp1 + djp2, true, desc);

    desc = "Test add a jumpPrime to duelingJP object";
    cout << "djp4 == djp3 + jp" << endl;
    printTest(djp4 == djp3 + jp, true, desc);


}

void testDuelingJPDestructive()
{
    const int SIZE = 100;
    const int MIN = 100;
    const int MAX = 100000;
    int values[SIZE];
    int testValues[SIZE*2];
    int testValues2[SIZE*2 + 1];

    int num = rand() % MAX + MIN;
    jumpPrime jp(num);

    generateValues(values, SIZE, MIN, MAX);
    duelingJP djp1(SIZE, values);
    for (int i = 0; i < SIZE; i++)
        testValues[i] = values[i];

    generateValues(values, SIZE, MIN, MAX);
    for (int i = SIZE; i < 2*SIZE; i++)
        testValues[i] = values[i-SIZE];

    for (int i = 0; i < 2 * SIZE; i++)
        testValues2[i] = testValues[i];

    testValues2[2 * SIZE] = num;

    duelingJP djp2(SIZE, values);
    duelingJP djp3(SIZE*2, testValues);
    duelingJP djp4(SIZE*2 + 1, testValues2);

    string desc = "Test operator += with a duelingJP object";
    cout << "djp3 == (djp1 += djp2)" << endl;
    djp1 += djp2;
    printTest(djp3 == djp1, true, desc);

    desc = "Test operator += with a jumpPrime object";
    cout << "djp4 == (djp3 += jp)" << endl;
    djp3 += jp;
    printTest(djp4 == djp3, true, desc);

}

void generateValues(int values[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        int value = rand() % (max - min + 1) + min;
        values[i] = value;
    }
}

void printTest(bool res, bool exp, string desc = "") {
    cout << desc << " | ";
    cout << (res == exp ? "PASS" : "FAIL") << endl;
}

