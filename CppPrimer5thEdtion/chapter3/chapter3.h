#ifndef CPPPRIMER5THCHAPTER3
#define CPPPRIMER5THCHAPTER3
#include <iostream>
#include <typeinfo>
#include <string>
#include <cctype>
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

#endif