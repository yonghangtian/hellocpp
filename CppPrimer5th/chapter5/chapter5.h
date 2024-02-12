#ifndef CPPPRIMER5THCHAPTER5
#define CPPPRIMER5THCHAPTER5
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

template <typename T>
int rangeForVector(vector<T> a)
{
    for (auto b : a)
    {
        cout << b << ",";
    }
    cout << endl;
    return 0;
}

template <typename T>
int rangeWhileVector(vector<T> a)
{
    auto startIt = a.begin(), endIt = a.end();
    while (startIt != endIt)
    {
        cout << *startIt++ << ", ";
    }
    cout << endl;
    return 0;
}


// Exercise 5.5: Using an if–else statement, write your own version of the
// program to generate the letter grade from a numeric grade.
int exercise5_5();

// Exercise 5.6: Rewrite your grading program to use the conditional operator
// (§ 4.7, p. 151) in place of the if–else statement.
int exercise5_6();

// Exercise 5.7: Correct the errors in each of the following code fragments:
int exercise5_7();

// Exercise 5.8: What is a “dangling else”? How are else clauses resolved in
// C++?
int exercise5_8();

// Exercise 5.9: Write a program using a series of if statements to count the
// number of vowels in text read from cin.
int exercise5_9();

// Exercise 5.10: There is one problem with our vowel-counting program as
// we’ve implemented it: It doesn’t count capital letters as vowels. Write a
// program that counts both lower- and uppercase letters as the appropriate
// vowel—that is, your program should count both 'a' and 'A' as part of
// aCnt, and so forth.
int exercise5_10();

// Exercise 5.11: Modify our vowel-counting program so that it also counts the
// number of blank spaces, tabs, and newlines read.
int exercise5_11();

// Exercise 5.12: Modify our vowel-counting program so that it counts the
// number of occurrences of the following two-character sequences: ff, fl,
// and fi.
int exercise5_12();

// Exercise 5.13: Each of the programs in the highlighted text on page 184
// contains a common programming error. Identify and correct each error.
int exercise5_13();

// Exercise 5.14: Write a program to read strings from standard input
// looking for duplicated words. The program should find places in the input
// where one word is followed immediately by itself. Keep track of the largest
// number of times a single repetition occurs and which word is repeated. Print
// the maximum number of duplicates, or else print a message saying that no
// word was repeated. For example, if the input is
// how now now now brown cow cow
// the output should indicate that the word now occurred three times.
int exercise5_14();

// Exercise 5.15: Explain each of the following loops. Correct any problems
// you detect.

int exercise5_15();

// Exercise 5.16: The while loop is particularly good at executing while some
// condition holds; for example, when we need to read values until end-of-file.
// The for loop is generally thought of as a step loop: An index steps through
// a range of values in a collection. Write an idiomatic use of each loop and
// then rewrite each using the other loop construct. If you could use only one
// loop, which would you choose? Why?
int exercise5_16();

// Exercise 5.17: Given two vectors of ints, write a program to determine
// whether one vector is a prefix of the other. For vectors of unequal
// length, compare the number of elements of the smaller vector. For
// example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
// 8, respectively your program should return true.
int exercise5_17();

// Exercise 5.18: Explain each of the following loops. Correct any problems
// you detect.
int exercise5_18();

// Exercise 5.19: Write a program that uses a do while loop to repetitively
// request two strings from the user and report which string is less than
// the other.
int exercise5_19();

// Exercise 5.20: Write a program to read a sequence of strings from the
// standard input until either the same word occurs twice in succession or all
// the words have been read. Use a while loop to read the text one word at a
// time. Use the break statement to terminate the loop if a word occurs twice
// in succession. Print the word if it occurs twice in succession, or else print a
// message saying that no word was repeated.
int exercise5_20();

// Exercise 5.21: Revise the program from the exercise in § 5.5.1 (p. 191) so
// that it looks only for duplicated words that start with an uppercase letter
int exercise5_21();

// Exercise 5.22: The last example in this section that jumped back to begin
// could be better written using a loop. Rewrite the code to eliminate the goto.
// begin:
//     int sz = get_size();
//     if (sz <= 0)
//     {
//         goto begin;
//     }
int exercise5_22();

// Exercise 5.23: Write a program that reads two integers from the standard
// input and prints the result of dividing the first number by the second.
int exercise5_23();

// Exercise 5.24: Revise your program to throw an exception if the second
// number is zero. Test your program with a zero input to see what happens on
// your system if you don’t catch an exception.
int exercise5_24();

// Exercise 5.25: Revise your program from the previous exercise to use a
// try block to catch the exception. The catch clause should print a message
// to the user and ask them to supply a new number and repeat the code inside
// the try.
int exercise5_25();

#endif