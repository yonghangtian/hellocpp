#ifndef CPPPRIMER5THCHAPTER6
#define CPPPRIMER5THCHAPTER6
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <cstddef>
#include <initializer_list>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::string;
using std::vector;

// #define NDEBUG

// Exercise 6.5: Write a function to return the absolute value of its argument.
int exercise6_5();

// Exercise 6.6: Explain the differences between a parameter, a local variable,
// and a local static variable. Give an example of a function in which each
// might be useful.
int exercise6_6();

// Exercise 6.7: Write a function that returns 0 when it is first called and then
// generates numbers in sequence each time it is called again.
int exercise6_7();

// Exercise 6.8: Write a header file named Chapter6.h that contains
// declarations for the functions you wrote for the exercises in § 6.1 (p. 205).
int exercise6_8();

// Exercise 6.9: Write your own versions of the fact.cc and factMain.cc
// files. These files should include your Chapter6.h from the exercises in the
// previous section. Use these files to understand how your compiler supports
// separate compilation.
// cc -c main.cpp
// cc -c /home/tian/projects/hellocpp/CppPrimer5th/chapter6/chapter6.h
// gcc main.o chapter6.o -o main -std=c++11 -lm -lstdc++
int exercise6_9();

// Exercise 6.10: Using pointers, write a function to swap the values of two
// ints. Test the function by calling it and printing the swapped values.
int exercise6_10();
// Exercise 6.11: Write and test your own version of reset that takes a
// reference.
int exercise6_11();
// Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
// to use references instead of pointers to swap the value of two ints. Which
// version do you think would be easier to use and why?
int exercise6_12();

// Exercise 6.13: Assuming T is the name of a type, explain the difference
// between a function declared as void f(T) and void f(T&).
// f(T) ask user to pass a copy of object T; f(T&) ask user to pass the reference of object T.
// f(T) cannot change the content of the object that pass to it as parameter, while f(T&) can.
int exercise6_13();
// Exercise 6.14: Give an example of when a parameter should be a reference
// type. Give an example of when a parameter should not be a reference.
int exercise6_14();
// Exercise 6.15: Explain the rationale for the type of each of find_char’s
// parameters In particular, why is s a reference to const but occurs is a
// plain reference?

// Because we dont want to modify s, and we do want to modify occurs.

// Why are these parameters references, but the char parameter c is not?
// Because 在C++中，基本数据类型（如int、char等）的传递方式默认为值传递。也就是说，当你直接传递一个char类型的变量时，函数会复制该变量的值，而不是引用。这意味着在函数内部对该变量进行的任何修改不会影响到原始变量。
// 然而，如果你传递一个char的引用，那么函数将会操作原始变量。如果你需要在函数内部修改原始变量，那么使用引用是合适的。否则，你并不需要使用引用来传递char类型的参数。

// What would happen if we made s a plain reference?

// we may modify s by accident, which is not the purpose of this function.

// What if we made occurs a reference to const?

// then we cannot use occurs to carry info outside the function(modify occurs).
int exercise6_15();

// Exercise 6.16: The following function, although legal, is less useful than it
// might be. Identify and correct the limitation on this function:
// bool is_empty(string& s) { return s.empty(); }
int exercise6_16();

// Exercise 6.17: Write a function to determine whether a string contains
// any capital letters. Write a function to change a string to all lowercase. Do
// the parameters you used in these functions have the same type? If so, why?
// If not, why not?
int exercise6_17();

int exercise6_18();
int exercise6_19();
int exercise6_20();

// Exercise 6.21: Write a function that takes an int and a pointer to an int
// and returns the larger of the int value or the value to which the pointer
// points. What type should you use for the pointer?
int exercise6_21();

// Exercise 6.22: Write a function to swap two int pointers.
int exercise6_22();

// Exercise 6.23: Write your own versions of each of the print functions
// presented in this section. Call each of these functions to print i and j
// defined as follows:
// int i = 0, j[2] = {0, 1};
int exercise6_23();

// Exercise 6.24: Explain the behavior of the following function. If there are
// problems in the code, explain what they are and how you might fix them.
// Answer: this method trying to pass an int array with 10 element to the function
//          but Arrays have two special properties that affect how we define and use functions that
//          operate on arrays: We cannot copy an array (§ 3.5.1, p. 114), and when we use an
//          array it is (usually) converted to a pointer (§ 3.5.3, p. 117). Because we cannot copy
//          an array, we cannot pass an array by value. Because arrays are converted to pointers,
//          when we pass an array to a function, we are actually passing a pointer to the array’s
//          first element.
int exercise6_24();

// Exercise 6.25: Write a main function that takes two arguments.
// Concatenate the supplied arguments and print the resulting string.
int exercise6_25(int argc, char **argv);

// Exercise 6.26: Write a program that accepts the options presented in this
// section. Print the values of the arguments passed to main.
int exercise6_26(int argc, char **argv);

// Exercise 6.27: Write a function that takes an initializer_list<int>
// and produces the sum of the elements in the list.
int exercise6_27();

// Exercise 6.28: In the second version of error_msg that has an ErrCode
// parameter, what is the type of elem in the for loop?
int exercise6_28();

// Exercise 6.29: When you use an initializer_list in a range for
// would you ever use a reference as the loop control variable? If so, why? If
// not, why not?

//  I'll use const reference, in this way, we dont need to copy each item to the loop control variable.
//  and we dont need to modify the value.
int exercise6_29();

// Exercise 6.30: Compile the version of str_subrange as presented on
// page 223 to see what your compiler does with the indicated errors.
int exercise6_30();

// Exercise 6.31: When is it valid to return a reference? A reference to
// const?

//  only if the object is not temp value, it's valid to return the object's reference.
int exercise6_31();

// Exercise 6.32: Indicate whether the following function is legal. If so, explain
// what it does; if not, correct any errors and then explain it.
int exercise6_32();

// Exercise 6.33: Write a recursive function to print the contents of a vector
int exercise6_33();

// Exercise 6.34: What would happen if the stopping condition in factorial
// were
// if (val != 0)
int exercise6_34();

// Exercise 6.35: In the call to fact, why did we pass val - 1 rather than
// val--?
// Answer: if we use val--, we'll get val at the first time, then val = val -1. That's not what we want.
int exercise6_35();

// Exercise 6.36: Write the declaration for a function that returns a reference
// to an array of ten strings, without using either a trailing return,
// decltype, or a type alias.
int exercise6_36();
// Exercise 6.37: Write three additional declarations for the function in the
// previous exercise. One should use a type alias, one should use a trailing
// return, and the third should use decltype. Which form do you prefer and
// why?
extern string result[10];
string (&arrFunc(string str))[10];
auto arrFunc2(string str) -> string (&)[10];
decltype(result) &arrFunc3(string str);
using arrT = string[10];
arrT &arrFunc4(string str);
int exercise6_37();
// Exercise 6.38: Revise the arrPtr function on to return a reference to the
// array.
int exercise6_38();

// Exercise 6.39: Explain the effect of the second declaration in each one of
// the following sets of declarations. Indicate which, if any, are illegal.
// (a) int calc(int, int);
// int calc(const int, const int);

// Illegal: A parameter that has a top-level const is indistinguishable from one without a top-level const:

// (b) int get();
// double get();

// Illegal: It is an error for two functions to differ only in terms of their return types. If the
// parameter lists of two functions match but the return types differ, then the second
// declaration is an error:

// (c) int *reset(int *);
// double *reset(double *);

// legal.
int exercise6_39();

// Exercise 6.40: Which, if either, of the following declarations are errors?
// Why?
// (a) int ff(int a, int b = 0, int c = 0);
// valid

// (b) char *init(int ht = 24, int wd, char bckgrnd);
// invalid, if a parameter has a default argument, all the parameters
// that follow it must also have default arguments. The default arguments are used for the
// trailing (right-most) arguments of a call.
int exercise6_40();
// Exercise 6.41: Which, if any, of the following calls are illegal? Why? Which,
// if any, are legal but unlikely to match the programmer’s intent? Why?
const char *init(int ht, int wd = 80, char bckgrnd = ' ');
// (a) init();
// (b) init(24,10); legal
// (c) init(14, '*'); legal, but not the original intent.
int exercise6_41();

// Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p.
// 224) a default argument of 's'. Test your program by printing singular and
// plural versions of the words success and failure.

inline string make_plural(size_t ctr, const string &word,
                          const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}
int exercise6_42();

// Exercise 6.43: Which one of the following declarations and definitions would
// you put in a header? In a source file? Explain why.
// (a) inline bool eq(const BigInt&, const BigInt&) {...}
//  (a) into header

// (b) void putValues(int *arr, int size);
//  (b) in source file
int exercise6_43();


inline const string &
shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
// Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be
// inline.
// inline version: find the shorter of two strings
int exercise6_44();

// Exercise 6.45: Review the programs you’ve written for the earlier exercises
// and decide whether they should be defined as inline. If so, do so. If not,
// explain why they should not be inline.
int exercise6_45();

// Exercise 6.46: Would it be possible to define isShorter as a constexpr?
// If so, do so. If not, explain why not.

// CANT, string is not a literal type.
int exercise6_46();

// Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p.
// 228) that used recursion to print the contents of a vector to conditionally
// print information about its execution. For example, you might print the size of
// the vector on each call. Compile and run the program with debugging
// turned on and again with it turned off.
// exercise 6.33
int exercise6_47();

// Exercise 6.48: Explain what this loop does and whether it is a good use of
// assert:
// string s;
// while (cin >> s && s != sought) { } // empty body
// assert(cin);
int exercise6_48();


// Exercise 6.49: What is a candidate function? What is a viable function?
// The first step of function matching identifies the set of overloaded functions
// considered for the call. The functions in this set are the candidate functions. A
// candidate function is a function with the same name as the called function and for
// which a declaration is visible at the point of the call. In this example, there are four
// candidate functions named f.
// The second step selects from the set of candidate functions those functions that can
// be called with the arguments in the given call. The selected functions are the viable
// functions. To be viable, a function must have the same number of parameters as
// there are arguments in the call, and the type of each argument must match—or be
// convertible to—the type of its corresponding parameter.
int exercise6_49();


void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

// Exercise 6.50: Given the declarations for f from page 242, list the viable
// functions, if any for each of the following calls. Indicate which function is the
// best match, or if the call is illegal whether there is no match or why the call
// is ambiguous.
// (a) f(2.56, 42)  ambiguous
// (b) f(42)        f(int)
// (c) f(42, 0)     f(int, int)
// (d) f(2.56, 3.14) f(double, double)
int exercise6_50();

// Exercise 6.51: Write all four versions of f. Each function should print a
// distinguishing message. Check your answers for the previous exercise. If your
// answers were incorrect, study this section until you understand why your
// answers were wrong.
int exercise6_51();

// Exercise 6.52: Given the following declarations,
// double dobj;
// void manip(int, int);
// what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?
// (a) manip('a', 'z'); //  Match through a promotion, level 3
// (b) manip(55.4, dobj); // Match through an arithmetic, level 4
int exercise6_52();

// Exercise 6.53: Explain the effect of the second declaration in each one of
// the following sets of declarations. Indicate which, if any, are illegal.
// (a) int calc(int&, int&);
// int calc(const int&, const int&);  // overloaded funcs, as const is low-level
// (b) int calc(char*, char*);
// int calc(const char*, const char*); // overloaded funcs, as const is low-level
// (c) int calc(char*, char*);
// int calc(char* const, char* const); // not-overloaded funcs, as const is top-level
int exercise6_53();

// Exercise 6.54: Write a declaration for a function that takes two int
// parameters and returns an int, and declare a vector whose elements have
// this function pointer type.
// Exercise 6.55: Write four functions that add, subtract, multiply, and divide
// two int values. Store pointers to these values in your vector from the
// previous exercise.
// Exercise 6.56: Call each element in the vector and print their result.
int exercise6_54();
int exercise6_55();
int exercise6_56();

#endif