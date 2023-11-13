#ifndef CPPPRIMER5THCHAPTER3
#define CPPPRIMER5THCHAPTER3
#include <iostream>
#include <typeinfo>
#include <string>
#include <cctype>
#include <vector>
#include <cerrno>
using namespace std;

// Exercise 3.2: Write a program to read the standard input a line at a time.
int exercise3_2();
// Exercise 3.2-part2: Modify your program to read a word at a time.
int exercise3_3(); 
// Exercise 3.4: Write a program to read two strings and report whether the
// strings are equal. If not, report which of the two is larger. Now, change
// the program to report whether the strings have the same length, and if
// not, report which is longer.
int exercise3_4();
// Exercise 3.5: Write a program to read strings from the starnard input, 
// concatenating what is read into one large string. Print the concatenated
// string. Next, change the program to separate adjacent input strings by a
// space.
int exercise3_5();
// Exercise 3.6: Use a range for to change all the characters in a string to x.
int exercise3_6();
// Exercise 3.7: What would happen if you define the loop control variable in
// the previous exercise as type char? Predict the results and then change your
// program to use a char to see if you were right.
int exercise3_7();
// Exercise 3.8: Rewrite the program in the first exercise(Exercise 3.6), first using a while
// and again using a traditional for loop. Which of the three approaches do
// you prefer and why?
int exercise3_8();
// Exercise 3.9: What does the following program do? Is it valid? If not, why
// not?
// string s;
// cout << s[0] << endl;
int exercise3_9();
// Exercise 3.10: Write a program that reads a string of characters including
// punctuation and writes what was read but with the punctuation removed.
int exercise3_10();
// Exercise 3.11: Is the following range for legal? If so, what is the type of
// c?
// const string s = "Keep out!"; 
// for (auto &c : s) {/* ... */ }
int exercise3_11();
// Exercise 3.12: Which, if any, of the following vector definitions are in
// error? For those that are legal, explain what the definition does. For those
// that are not legal, explain why they are illegal.
// (a) vector<vector<int>> ivec;
// (b) vector<string> svec = ivec;
// (c) vector<string> svec(10, "null");
int exercise3_12();
// Exercise 3.13: How many elements are there in each of the following
// vectors? What are the values of the elements?
// (a) vector<int> v1;
// (b) vector<int> v2(10);
// (c) vector<int> v3(10, 42);
// (d) vector<int> v4{10};
// (e) vector<int> v5{10, 42};
// (f) vector<string> v6{10};
// (g) vector<string> v7{10, "hi"};
int exercise3_13();

template<typename T>
int rangeForVector(vector<T> a)
{
    for (auto b : a){
        cout << b << ",";
    }
    cout << endl;
    return 0;
}

// Exercise 3.14: Write a program to read a sequence of ints from cin and
// store those values in a vector.
int exercise3_14();
// Exercise 3.15: Repeat Exercise 3.14 but read strings this time.
int exercise3_15();
// Exercise 3.16: Write a program to print the size and contents of the
// vectors from exercise 3.13. Check whether your answers to that exercise
// were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you
// were wrong.
// Same as exercise 3.13.
int exercise3_16();
// Exercise 3.17: Read a sequence of words from cin and store the values a
// vector. After you’ve read all the words, process the vector and change
// each word to uppercase. Print the transformed elements, eight words to a
// line
int exercise3_17();
// Exercise 3.18: Is the following program legal? If not, how might you fix it?
// vector<int>
// ivec[0] = 42;
//  ivec;
int exercise3_18();
// Exercise 3.19: List three ways to define a vector and give it ten elements,
// each with the value 42. Indicate whether there is a preferred way to do so
// and why.
int exercise3_19();
// Exercise 3.20: Read a set of integers into a vector. Print the sum of each
// pair of adjacent elements. Change your program so that it prints the sum of
// the first and last elements, followed by the sum of the second and second-tolast, and so on.
int exercise3_20();

// Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.
// actually I dont know what to to, exercise 3.16 is too redundant.
int exercise3_21();

// Exercise 3.22: Revise the loop that printed the first paragraph in text to
// instead change the elements in text that correspond to the first paragraph
// to all uppercase. After you’ve updated text, print its contents.
int exercise3_22();

// Exercise 3.23: Write a program to create a vector with ten int elements.
// Using an iterator, assign each element a value that is twice its current value.
// Test your program by printing the vector.
int exercise3_23();

// Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.
// redo 3.20
int exercise3_24();

// Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104)
// using iterators instead of subscripts.
int exercise3_25();

// Exercise 3.26: In the binary search program on page 112, why did we write
// mid = beg + (end - beg) / 2; instead of mid = (beg + end)/2;?
// Answer : we dont have operator + between two iterator. We only have operator in Table 3.7
int exercise3_26();

#endif