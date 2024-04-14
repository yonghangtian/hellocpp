#ifndef CPPPRIMER5THCHAPTER14
#define CPPPRIMER5THCHAPTER14
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <utility>
#include <functional>
#include "../chapter7/chapter7.h"
#include "../chapter13/chapter13.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using namespace std::placeholders;
// #define NDEBUG

template <typename T>
int rangeForContainer(T& a)
{
    for (auto b : a)
    {
        cout << b << ",";
    }
    cout << endl;
    return 0;
}

class ReadString
{
public:
    ReadString(istream &ist) : is(ist){};
    const string operator()()
    {
        string test;
        is >> test;
        if (!is)
            test = "empty string";

        return test;
    }

private:
    istream &is;
};

class CheckLen
{
public:
    CheckLen(size_t a) : _len(a){};
    bool operator()(const string & temp)
    {
        return (temp.size() == _len);
    }

private:
    size_t _len;
};

class CompareLen
{
public:
    CompareLen(size_t a) : _len(a){};
    bool operator()(const string & temp)
    {
        return (temp.size() > _len);
    }

private:
    size_t _len;
};

class IsShorter
{
public:
    IsShorter(){};
    bool operator()(const string & lhs, const string & rhs)
    {
        return (lhs.size() < rhs.size());
    }
};


// Exercises Section 14.1
// Exercise 14.1: In what ways does an overloaded operator differ from a
// built-in operator? In what ways are overloaded operators the same as the
// built-in operators?
// Answer: (1) Same parts: the way we use overloaded operator
// (2) Differ parts: the exact meaning of overloaded operator.
int exercise14_1();

// Exercise 14.2: Write declarations for the overloaded input, output, addition,
// and compound-assignment operators for Sales_data.
int exercise14_2();

// Exercise 14.3: Both string and vector define an overloaded == that can
// be used to compare objects of those types. Assuming svec1 and svec2 are
// vectors that hold strings, identify which version of == is applied in each
// of the following expressions:
// (a) "cobble" == "stone" : string's ==
// (b) svec1[0] == svec2[0]: string's ==
// (c) svec1 == svec2 : vector's ==
// (d) "svec1[0] == "stone", string's ==
int exercise14_3();

// Exercise 14.4: Explain how to decide whether the following should be class
// members:
// (a) % same with (e)
// (b) %=  The compound-assignment operators ordinarily ought to be members. However, unlike assignment, they are not required to be members.
// (c) ++ Operators that change the state of their object or that are closely tied to their
// given type—such as increment, decrement, and dereference—usually should be members.
// (d) ->  must be defined as members.
// (e) << Symmetric operators—those that might convert either operand,
//  such as the arithmetic, equality, relational, and bitwise operators—usually should be defined as ordinary nonmember functions.
// (f) && same with (e)
// (g) == same with (e)
// (h) ()  must be defined as members.
int exercise14_4();

// Exercise 14.5: In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of
// one of the following classes. Decide what, if any, overloaded operators your
// class should provide.
// (a) Book
// (b) Date
// (c) Employee
// (d) Vehicle
// (e) Object
// (f) Tree
// Answer: No need to do this exercise.
int exercise14_5();

// Exercises Section 14.2.1
// Exercise 14.6: Define an output operator for your Sales_data class.
// Answer: already done in Exercise 14.1
int exercise14_6();

// Exercise 14.7: Define an output operator for you String class you wrote
// for the exercises in § 13.5 (p. 531).
// Answer: already done in chapter13.h
int exercise14_7();

// Exercise 14.8: Define an output operator for the class you chose in exercise
// 7.40 from § 7.5.1 (p. 291).
// Answer: No need to do this exercise.
int exercise14_8();

// Exercises Section 14.2.2
// Exercise 14.9: Define an input operator for your Sales_data class.
// Answer: already done in Exercise 14.1
int exercise14_9();

// Exercise 14.10: Describe the behavior of the Sales_data input operator if
// given the following input:
// (a) 0-201-99999-9 10 24.95
// (b) 10 24.95 0-210-99999-9
int exercise14_10();

// Exercise 14.11: What, if anything, is wrong with the following Sales_data
// input operator? What would happen if we gave this operator the data in the
// previous exercise?
// istream& operator>>(istream& in, Sales_data& s)
// {
//  double price; in >> s.bookNo >> s.units_sold >> price; s.revenue = s.units_sold * price; return in;
// }
// Answer: this defination of input operator will not recovery Sales_data from bad input.
int exercise14_11();

// Exercise 14.12: Define an input operator for the class you used in exercise
// 7.40 from § 7.5.1 (p. 291). Be sure the operator handles input errors.
int exercise14_12();

// Exercises Section 14.3
// Exercise 14.13: Which other arithmetic operators (Table 4.1 (p. 139)), if
// any, do you think Sales_data ought to support? Define any you think the
// class should include.
// Answer: only add and add-assignment
int exercise14_13();

// Exercise 14.14: Why do you think it is more efficient to define operator+
// to call operator+= rather than the other way around?
// Answer: the logics are similiar, we can save energy maintaining only one main logic.
int exercise14_14();

// Exercise 14.15: Should the class you chose for exercise 7.40 from § 7.5.1
// (p. 291) define any of the arithmetic operators? If so, implement them. If
// not, explain why not.
int exercise14_15();

// Exercise 14.16: Define equality and inequality operators for your StrBlob
// (§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p.
// 526), and String (§ 13.5, p. 531) classes.
int exercise14_16();

// Exercise 14.17: Should the class you chose for exercise 7.40 from § 7.5.1
// (p. 291) define the equality operators? If so, implement them. If not, explain
// why not.
// Answer: meanless.
int exercise14_17();

// Exercises Section 14.3.2
// Exercise 14.18: Define relational operators for your StrBlob,
// StrBlobPtr, StrVec, and String classes.
// Answer: actually no need.
int exercise14_18();

// Exercise 14.19: Should the class you chose for exercise 7.40 from § 7.5.1
// (p. 291) define the relational operators? If so, implement them. If not,
// explain why not.
// Answer: meanless.
int exercise14_19();

// Exercises Section 14.4
// Exercise 14.20: Define the addition and compound-assignment operators
// for your Sales_data class.
// Answer: already done in 14.1
int exercise14_20();

// Exercise 14.21: Write the Sales_data operators so that + does the actual
// addition and += calls +. Discuss the disadvantages of this approach compared
// to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p.
// 564).
// Answer: the logics are similiar, we can save energy maintaining only one main logic.
int exercise14_21();

// Exercise 14.22: Define a version of the assignment operator that can assign
// a string representing an ISBN to a Sales_data.
int exercise14_22();

// Exercise 14.23: Define an initializer_list assignment operator for
// your version of the StrVec class.
int exercise14_23();

// Exercise 14.24: Decide whether the class you used in exercise 7.40 from §
// 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define
// those operators.
// Answer: no need to do.
int exercise14_24();

// Exercise 14.25: Implement any other assignment operators your class
// should define. Explain which types should be used as operands and why.
// Answer: no need to do.
int exercise14_25();

// Exercises Section 14.5
// Exercise 14.26: Define subscript operators for your StrVec, String,
// StrBlob, and StrBlobPtr classes.
int exercise14_26();

// Exercises Section 14.6
// Exercise 14.27: Add increment and decrement operators to your
// StrBlobPtr class.
int exercise14_27();

// Exercise 14.28: Define addition and subtraction for StrBlobPtr so that
// these operators implement pointer arithmetic (§ 3.5.3, p. 119).
int exercise14_28();

// Exercise 14.29: We did not define a const version of the increment and
// decrement operators. Why not?
// Answer: We dont define const version in order to be consistent with the built-in operators.
int exercise14_29();

// Exercises Section 14.7
// Exercise 14.30: Add dereference and arrow operators to your StrBlobPtr
// class and to the ConstStrBlobPtr class that you defined in exercise 12.22
// from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must
// return const references because the data member in constStrBlobPtr
// points to a const vector.
int exercise14_30();

// Exercise 14.31: Our StrBlobPtr class does not define the copy
// constructor, assignment operator, or a destructor. Why is that okay?
// Answer: the compilier generates default version of copy-control funcs.
int exercise14_31();

// Exercise 14.32: Define a class that holds a pointer to a StrBlobPtr.
// Define the overloaded arrow operator for that class.
int exercise14_32();

// Exercises Section 14.8
// Exercise 14.33: How many operands may an overloaded function-call
// operator take?
// Answer: In C++, the overloaded function-call operator operator()
// can take any number of operands. The function-call operator is a special type of operator
// that allows an object to be called like a function.
// It can be overloaded to accept any number of arguments, just like a regular function.
int exercise14_33();

// Exercise 14.34: Define a function-object class to perform an if-then-else
// operation: The call operator for this class should take three parameters. It
// should test its first parameter and if that test succeeds, it should return its
// second parameter; otherwise, it should return its third parameter.
int exercise14_34();

// Exercise 14.35: Write a class like PrintString that reads a line of input
// from an istream and returns a string representing what was read. If the
// read fails, return the empty string.
int exercise14_35();

// Exercise 14.36: Use the class from the previous exercise to read the
// standard input, storing each line as an element in a vector.
int exercise14_36();

// Exercise 14.37: Write a class that tests whether two values are equal. Use
// that object and the library algorithms to write a program to replace all
// instances of a given value in a sequence.
int exercise14_37();

// Exercises Section 14.8.1
// Exercise 14.38: Write a class that tests whether the length of a given
// string matches a given bound. Use that object to write a program to report
// how many words in an input file are of sizes 1 through 10 inclusive.
int exercise14_38();

// Exercise 14.39: Revise the previous program to report the count of words
// that are sizes 1 through 9 and 10 or more.
int exercise14_39();

// Exercise 14.40: Rewrite the biggies function from § 10.3.2 (p. 391) to
// use function-object classes in place of lambdas.
int exercise14_40();

// Exercise 14.41: Why do you suppose the new standard added lambdas?
// Explain when you would use a lambda and when you would write a class
// instead.
// Answer: it much easier to use lambda than class, as class need declaration, definition and (Instantiation and Member Function Call),
// it's heavy and need to remeber two much points.
int exercise14_41();

// Exercises Section 14.8.2
// Exercise 14.42: Using library function objects and adaptors, define an
// expression to
// (a) Count the number of values that are greater than 1024
// (b) Find the first string that is not equal to pooh
// (c) Multiply all values by 2
int exercise14_42();

// Exercise 14.43: Using library function objects, determine whether a given
// int value is divisible by any element in a container of ints.
int exercise14_43();

// Exercises Section 14.8.3
// Exercise 14.44: Write your own version of a simple desk calculator that can
// handle binary operations.
int exercise14_44();

// Exercises Section 14.9.1
// Exercise 14.45: Write conversion operators to convert a Sales_data to
// string and to double. What values do you think these operators should
// return?
int exercise14_45();

// Exercise 14.46: Explain whether defining these Sales_data conversion
// operators is a good idea and whether they should be explicit.
int exercise14_46();

// Exercise 14.47: Explain the difference between these two conversion
// operators:
// struct Integral { operator const int(); operator int() const;
// };
int exercise14_47();

// Exercise 14.48: Determine whether the class you used in exercise 7.40 from
// § 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and
// explain whether the operator should be explicit. If not, explain why not.
int exercise14_48();

// Exercise 14.49: Regardless of whether it is a good idea to do so, define a
// conversion to bool for the class from the previous exercise.
int exercise14_49();

// Exercises Section 14.9.2
// Exercise 14.50: Show the possible class-type conversion sequences for the
// initializations of ex1 and ex2. Explain whether the initializations are legal or
// not.
// struct LongDouble{
//  LongDouble(double = 0.0);
//  operator double();
//  operator float();
// };
// LongDouble ldObj;
// int ex1 = ldObj;
// float ex2 = ldObj;
int exercise14_50();

// Exercise 14.51: Show the conversion sequences (if any) needed to call each
// version of calc and explain why the best viable function is selected.
// void calc(int);
// void calc(LongDouble);
// double dval;
// calc(dval); // which calc?
int exercise14_51();

// Exercises Section 14.9.3
// Exercise 14.52: Which operator+, if any, is selected for each of the
// addition expressions? List the candidate functions, the viable functions, and
// the type conversions on the arguments for each viable function:
// struct LongDouble {
//  // member operator+ for illustration purposes; + is usually a nonmember
//  LongDouble operator+(const SmallInt&);
//  // other members as in § 14.9.2 (p. 587)
// };
// LongDouble operator+(LongDouble&, double);
// SmallInt si;
// LongDouble ld;
// ld = si + ld;
// ld = ld + si;
int exercise14_52();

// Exercise 14.53: Given the definition of SmallInt on page 588, determine
// whether the following addition expression is legal. If so, what addition
// operator is used? If not, how might you change the code to make it legal?
// SmallInt s1;
// double d = s1 + 3.14;
int exercise14_53();

#endif