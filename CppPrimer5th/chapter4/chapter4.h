#ifndef CPPPRIMER5THCHAPTER4
#define CPPPRIMER5THCHAPTER4
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

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

int exercise4_1();

// Exercise 4.9: Explain the behavior of the condition in the following if:
// const char *cp = "Hello World";
// if (cp && *cp)
int exercise4_9();

// Exercise 4.10: Write the condition for a while loop that would read ints
// from the standard input and stop when the value read is equal to 42
int exercise4_10();

// Exercise 4.11: Write an expression that tests four values, a, b, c, and d,
// and ensures that a is greater than b, which is greater than c, which is
// greater than d.
int exercise4_11();

// Exercise 4.12: Assuming i, j, and k are all ints, explain what i != j <
// k means.
int exercise4_12();

// Exercise 4.21: Write a program to use a conditional operator to find the
// elements in a vector<int> that have odd value and double the value of
// each such element.
int exercise4_21();

// Exercise 4.22: Extend the program that assigned high pass, pass, and fail
// grades to also assign low pass for grades between 60 and 75 inclusive. Write
// two versions: One version that uses only conditional operators; the other
// should use one or more if statements. Which version do you think is easier
// to understand and why?
int exercise4_22();

// Exercise 4.23: The following expression fails to compile due to operator
// precedence. Using Table 4.12 (p. 166), explain why it fails. How would you
// fix it?
// string s = "word";
// string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
int exercise4_23();

// Exercise 4.24: Our program that distinguished between high pass, pass,
// and fail depended on the fact that the conditional operator is right
// associative. Describe how that operator would be evaluated if the operator
// were left associative.
int exercise4_24();

// Exercise 4.25: What is the value of ~'q' << 6 on a machine with 32-bit
// ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the
// bit pattern 01110001?
// tianyh@tian-mb13:~$ getconf -a | grep -i bit
// CHAR_BIT                           8  char is 8-bits
// LONG_BIT                           64 long int is 64-bits
// WORD_BIT                           32 int is 32-bits
// FILESIZEBITS                       64
int exercise4_25();

// Exercise 4.27: What is the result of each of these expressions?
// unsigned long ul1 = 3, ul2 = 7;
// (a) ul1 & ul2
// (b) ul1 | ul2
// (c) ul1 && ul2
// (d) ul1 || ul2
int exercise4_27();

// Exercise 4.28: Write a program to print the size of each of the built-in
// types.
int exercise4_28();

// Exercise 4.29: Predict the output of the following code and explain your
// reasoning. Now run the program. Is the output what you expected? If not,
// figure out why.
// int x[10]; int *p = x;
// cout << sizeof(x)/sizeof(*x) << endl;
// cout << sizeof(p)/sizeof(*p) << endl;
int exercise4_29();

// Exercise 4.30: Using Table 4.12 (p. 166), parenthesize the following
// expressions to match the default evaluation:
// (a) sizeof x + y
// (b) sizeof p->mem[i]
// (c) sizeof a < b
// (d) sizeof f()
int exercise4_30();

// Exercise 4.34: Given the variable definitions in this section, explain what
// conversions take place in the following expressions:
// (a) if (fval)   convert fval to bool
// (b) dval = fval + ival; convert ival to float, then convert the sum to double
// (c) dval + ival * cval; convert cval to int, then convert int to double
// Remember that you may need to consider the associativity of the operators.
int exercise4_34();

// Exercise 4.35: Given the following definitions,
// char cval; int ival; unsigned int ui;
// float fval; double dval;
// identify the implicit type conversions, if any, taking place:
// (a) cval = 'a' + 3;  'a' promoted to int, then the result convert to char
// (b) fval = ui - ival * 1.0; ival convert to double, ui convert to float.
// (c) dval = ui * fval; ui convert to float, then covert to double.
// (d) cval = ival + fval + dval; int convrt to float, float convert to double
int exercise4_35();

// Exercise 4.36: Assuming i is an int and d is a double write the
// expression i *= d so that it does integral, rather than floating-point,
// multiplication.
int exercise4_36();

// Exercise 4.37: Rewrite each of the following old-style casts to use a named
// cast:
// int i; double d; const string *ps; char *pc; void *pv;
// (a) pv = (void*)ps;
// (b) i = int(*pc);
// (c) pv = &d;
// (d) pc = (char*) pv;
int exercise4_37();

// Exercise 4.38: Explain the following expression:
// double slope = static_cast<double>(j/i);
// compute the int division between j and i, then convert the result to double
int exercise4_38();

#endif