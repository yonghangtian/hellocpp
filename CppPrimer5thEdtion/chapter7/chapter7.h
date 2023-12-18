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

class Screen
{
public:
    typedef string::size_type pos;

    Screen(pos h, pos w, pos c, char cts) : height(h), width(w), cursor(c), contents(h * w, cts) {}
    Screen(pos h, pos w) : Screen(h, w, 0, ' ') {}
    Screen(pos h, pos w, char cts) : Screen(h, w, 0, cts) {}
    Screen() : Screen(10, 10, 0, '*') {}
    void show() const;

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
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);

    // operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
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

int exercise7_27();
int exercise7_28();
int exercise7_29();
int exercise7_30();
int exercise7_31();
int exercise7_32();
int exercise7_33();
int exercise7_34();
int exercise7_35();
int exercise7_36();
int exercise7_37();
int exercise7_38();
int exercise7_39();
int exercise7_40();
int exercise7_41();
int exercise7_42();
int exercise7_43();
int exercise7_44();
int exercise7_45();
int exercise7_46();
int exercise7_47();
int exercise7_48();
int exercise7_49();
int exercise7_50();
int exercise7_51();
int exercise7_52();
int exercise7_53();
int exercise7_54();
int exercise7_55();
int exercise7_56();
int exercise7_57();
int exercise7_58();


int testThreads();
#endif