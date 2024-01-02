#ifndef CPPPRIMER5THCHAPTER7
#define CPPPRIMER5THCHAPTER7
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <cstddef>
#include <initializer_list>
#include <cassert>
#include <thread>
#include <chrono>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::size_t;
using std::string;
using std::vector;
// #define NDEBUG

typedef string::size_type pos;

class TestStatic
{
public:
    static double rate() { return interestRate; }
    static double rateTwo() { return interestRateTwo; }
    // static void rate(double);
    static void rateTwo(double);

private:
    static constexpr double initRate() { return 0.0225; };
    static const double interestRate; // static data member can be const
    static double interestRateTwo;
    // static double initRate() const { return 0.0225; }; //static member function ‘static double TestStatic::initRate()’ cannot have cv-qualifier
    // static constexpr double interestRate;  // ‘constexpr’ static data member ‘interestRate’ must have an initializer
};

class Screen;

class Window_mgr
{
public:
    Window_mgr(pos h, pos w, char cts, size_t a);
    void clear(size_t a);
    void show(std::ostream &os) const;

private:
    vector<Screen> screens;
};

class Screen
{
    friend void Window_mgr::clear(size_t);

public:
    Screen(pos h, pos w, pos c, char cts) : height(h), width(w), cursor(c), contents(h * w, cts) {}
    Screen(pos h, pos w) : Screen(h, w, 0, ' ') {}
    Screen(pos h, pos w, char cts) : Screen(h, w, 0, cts) {}
    Screen() : Screen(10, 10, 0, '*') {}
    void show(std::ostream &os) const;
    inline pos size() const { return height * width; }
    Screen &move(pos row = 0, pos col = 0);
    Screen &set(pos row, pos col, char var);
    Screen &set(char var);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    // constructors
    Sales_data() = default;

    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { cout << 2 << endl; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { cout << 1 << endl; }
    Sales_data(unsigned n, std::istream &is = cin);

    // operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    // Sales_data &combine(Sales_data);
    // Sales_data &combine(const Sales_data&) const;


    double avg_price() const { return units_sold ? revenue / units_sold : 0; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

typedef double Type;
Type initVal();
class Exercise
{
public:
    Type setVal(Type);
    Type initVal();
    Exercise(string str = "example") : valStr(str) {}
    Exercise(istream &in = cin) { cin >> valStr; }

private:
    int val;
    string valStr;
};

class NoDefault
{
public:
    NoDefault(int value) : val(value) {}

private:
    int val;
};

class C
{
public:
    C() : noDefaultObj(0) {}

private:
    NoDefault noDefaultObj; // Member of type NoDefault
};

class Debug {
public:
	constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o): 
	                                hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	constexpr bool hardware() { return hw || io; }
	constexpr bool app() { return other; }

	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }
private:
	bool hw;    // hardware errors other than IO errors
	bool io;    // IO errors
	bool other; // other errors
};

class Account {
public:
	Account() = default;
	Account(const std::string &s, double amt):
		owner(s), amount(amt) { }

    void calculate() { amount += amount * interestRate; }
    double balance() { return amount; }
public:
    static double rate() { return interestRate; }
    static void rate(double);   
private:
    std::string owner; 
    double amount = 0.0;
    static double interestRate; 
    static double initRate() { return .0225; }
    static const std::string accountType;
    static constexpr int period = 30;// period is a constant expression
    double daily_tbl[period];
};


// example.h
class Example {
public:
 static double rate; 
 static const int vecSize = 20; 
 static vector<double> vec;
};
// // example.C
// #include "example.h"

//  test static
int exercise7_1();

// Exercise 7.23: Write your own version of the Screen class.
int exercise7_23();
// Exercise 7.24: Give your Screen class three constructors: a default
// constructor; a constructor that takes values for height and width and
// initializes the contents to hold the given number of blanks; and a constructor
// that takes values for height, width, and a character to use as the contents of
// the screen.
int exercise7_24();
// Exercise 7.25: Can Screen safely rely on the default versions of copy and
// assignment? If so, why? If not, why not?
// Yes, as all the data memebers in Screen has there copy and assignment method, and the complier will generate a copy constructor and = operator to Screen.
int exercise7_25();
// Exercise 7.26: Define Sales_data::avg_price as an inline function.
int exercise7_26();

// Exercise 7.27: Add the move, set, and display operations to your
// version of Screen. Test your class by executing the following code:
int exercise7_27();

// Exercise 7.28: What would happen in the previous exercise if the return
// type of move, set, and display was Screen rather than Screen&?
// Answer: if the return type is Screen, then the other operation after move, set or display will operate on a temp object(copied from Screen).
int exercise7_28();

// Exercise 7.29: Revise your Screen class so that move, set, and display
// functions return Screen and check your prediction from the previous exercise.
// Answer: actually no need to try.
int exercise7_29();

// Exercise 7.30: It is legal but redundant to refer to members through the
// this pointer. Discuss the pros and cons of explicitly using the this pointer
// to access members.
int exercise7_30();

// Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to
// Y, and Y has an object of type X.
int exercise7_31();

// Exercise 7.32: Define your own versions of Screen and Window_mgr in
// which clear is a member of Window_mgr and a friend of Screen.
int exercise7_32();

// Exercise 7.33: What would happen if we gave Screen a size member
// defined as follows? Fix any problems you identify.
int exercise7_33();

// Exercise 7.34: What would happen if we put the typedef of pos in the
// Screen class on page 285 as the last line in the class?
// Answer: the class will compile wrong as other method cannot find pos, when we define them.
int exercise7_34();
// Exercise 7.35: Explain the following code, indicating which definition of
// Type or initVal is used for each use of those names. Say how you would
// fix any errors.
int exercise7_35();
// Exercise 7.36: The following initializer is in error. Identify and fix the problem.
int exercise7_36();

// Exercise 7.37: Using the version of Sales_data from this section,
// determine which constructor is used to initialize each of the following
// variables and list the values of the data members in each object:
int exercise7_37();

// Exercise 7.38: We might want to supply cin as a default argument to the
// constructor that takes an istream&. Write the constructor declaration that
// uses cin as a default argument
int exercise7_38();

// Exercise 7.39: Would it be legal for both the constructor that takes a
// string and the one that takes an istream& to have default arguments? If
// not, why not?
// 会有歧义
// call of overloaded ‘Exercise()’ is ambiguous
// candidate: ‘Exercise::Exercise(std::istream&)’
// candidate: ‘Exercise::Exercise(std::string)’
int exercise7_39();

// Exercise 7.40: Choose one of the following abstractions (or an abstraction
// of your own choosing). Determine what data are needed in the class. Provide
// an appropriate set of constructors. Explain your decisions.
// (a) Book
// (b) Date
// (c) Employee
// (d) Vehicle
// (e) Object
// (f) Tree
//  No need to do this exercise.
int exercise7_40();

// Exercise 7.41: Rewrite your own version of the Sales_data class to use
// delegating constructors. Add a statement to the body of each of the
// constructors that prints a message whenever it is executed. Write
// declarations to construct a Sales_data object in every way possible. Study
// the output until you are certain you understand the order of execution among
// delegating constructors.
int exercise7_41();

// Exercise 7.42: For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291),
// decide whether any of the constructors might use delegation. If so, write the
// delegating constructor(s) for your class. If not, look at the list of abstractions
// and choose one that you think would use a delegating constructor. Write the
// class definition for that abstraction.
// No need to do this exercise.
int exercise7_42();

// Exercise 7.43: Assume we have a class named NoDefault that has a
// constructor that takes an int, but has no default constructor. Define a class
// C that has a member of type NoDefault. Define the default constructor for
// C.
int exercise7_43();

// Exercise 7.44: Is the following declaration legal? If not, why not?
// vector<NoDefault> vec(10);
// Illegal, as NoDefault has no default constructor.
int exercise7_44();

// Exercise 7.45: What if we defined the vector in the previous execercise to
// hold objects of type C?
int exercise7_45();

// Exercise 7.46: Which, if any, of the following statements are untrue? Why?
// (a) A class must provide at least one constructor. --Yes
// (b) A default constructor is a constructor with an empty parameter list. --Yes
// (c) If there are no meaningful default values for a class, the class should not
// provide a default constructor.
// 这个陈述可能不太准确。尽管对于某些类可能没有有意义的默认值，但提供默认构造函数仍然是有意义的，特别是当你想确保类的对象始终被适当地初始化时。
// 即使没有有意义的默认值，也可以提供一个默认构造函数，例如将其设置为抛出异常或使用某种默认初始化策略。
// (d) If a class does not define a default constructor, the compiler generates
// one that initializes each data member to the default value of its associated
// type.
// 这个陈述也是正确的。如果一个类没有定义默认构造函数，编译器确实会为其生成一个。
// 该默认构造函数将初始化每个数据成员为其关联类型的默认值。
int exercise7_46();

// Exercise 7.47: Explain whether the Sales_data constructor that takes a
// string should be explicit. What are the benefits of making the
// constructor explicit? What are the drawbacks?
// Answer： should be explicit, in case the programmer make a mistake.
int exercise7_47();

// Exercise 7.48: Assuming the Sales_data constructors are not explicit,
// what operations happen during the following definitions
// string null_isbn("9-999-99999-9");
// Sales_data item1(null_isbn);
// Sales_data item2("9-999-99999-9");
// What happens if the Sales_data constructors are explicit?
int exercise7_48();

// Exercise 7.49: For each of the three following declarations of combine,
// explain what happens if we call i.combine(s), where i is a Sales_data
// and s is a string: 
// (a) Sales_data &combine(Sales_data);  Sales_data &Sales_data::combine(const Sales_data &rhs)
// (b) Sales_data &combine(Sales_data&); Sales_data &Sales_data::combine(const Sales_data rhs)
// (c) Sales_data &combine(const Sales_data&) const;

// call of overloaded ‘combine(const Sales_data&)’ is ambiguous
int exercise7_49();
// Exercise 7.50: Determine whether any of your Person class constructors
// should be explicit.
// No need to do.
int exercise7_50();

// Exercise 7.51: Why do you think vector defines its single-argument
// constructor as explicit, but string does not?
int exercise7_51();
// Exercise 7.52: Using our first version of Sales_data from § 2.6.1 (p. 72),
// explain the following initialization. Identify and fix any problems.
// Sales_data item = {"978-0590353403", 25, 15.99};
int exercise7_52();

// Exercise 7.53: Define your own version of Debug.
int exercise7_53();

// Exercise 7.54: Should the members of Debug that begin with set_ be
// declared as constexpr? If not, why not?
// Answer: shouldn't, as set_ funcs changed the value of arguments(data member).
// The constexpr specifier implies that the function can be evaluated at compile time if its arguments are constant expressions. However, in the case of set_io, set_hw, and set_other, these functions modify the state of the object (Debug) by changing the values of its member variables (io, hw, other). 
// This involves altering the object's state, which is not a compile-time operation and cannot be evaluated at compile time.
int exercise7_54();

// Exercise 7.55: Is the Data class from § 7.5.5 (p. 298) a literal class? If
// not, why not? If so, explain why it is literal.
// Answer: Yes, data class is a aggregate class, which natually is a literal class.
int exercise7_55();

// Exercise 7.56: What is a static class member? What are the advantages
// of static members? How do they differ from ordinary members?
// Answer: static class members aren't bind with any object, so it can be used in all object in that class.
// and these members are defined inside class, which aviod using global static members.
int exercise7_56();

// Exercise 7.57: Write your own version of the Account class.
int exercise7_57();
// Exercise 7.58: Which, if any, of the following static data member
// declarations and definitions are errors? Explain why.
// // example.h
// class Example {
// public:
//  static double rate = 6.5; static const int vecSize = 20; static vector<double> vec(vecSize);
// };
// // example.C
// #include "example.h"
// double Example::rate;
// vector<double> Example::vec;

int exercise7_58();

int testThreads();
#endif