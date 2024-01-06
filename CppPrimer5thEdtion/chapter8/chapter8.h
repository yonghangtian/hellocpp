#ifndef CPPPRIMER5THCHAPTER8
#define CPPPRIMER5THCHAPTER8
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ostream;
using std::size_t;
using std::string;
using std::vector;
// #define NDEBUG

typedef string::size_type pos;

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

// members are public by default
struct PersonInfo { 
	string name;
	vector<string> phones;
};



// Exercise 8.1: Write a function that takes and returns an istream&. The
// function should read the stream until it hits end-of-file. The function should
// print what it reads to the standard output. Reset the stream so that it is valid
// before returning the stream.
int exercise8_1();
// Exercise 8.2: Test your function by calling it, passing cin as an argument.
// Answer: already done in exercise8_1
int exercise8_2();
// Exercise 8.3: What causes the following while to terminate?
// while (cin >> i) /* ... */
// Answer: when cin hits EOF, or cin read sth that cannot convert to tye of i implicitly or explicitly.
int exercise8_3();
// Exercise 8.4: Write a function to open a file for input and read its contents
// into a vector of strings, storing each line as a separate element in the vector.
int exercise8_4();
// Exercise 8.5: Rewrite the previous program to store each word in a separate element.
int exercise8_5();
// Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read
// its transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).
int exercise8_6(int argc, char **argv);
// Exercise 8.7: Revise the bookstore program from the previous section to
// write its output to a file. Pass the name of that file as a second argument to main.
int exercise8_7(int argc, char **argv);
// Exercise 8.8: Revise the program from the previous exercise to append its
// output to its given file. Run the program on the same output file at least
// twice to ensure that the data are preserved.
// Answer: same with exercise8_7
int exercise8_8();
// Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2 (p.
// 314) to print the contents of an istringstream object.
int exercise8_9();
// Exercise 8.10: Write a program to store each line from a file in a
// vector<string>. Now use an istringstream to read each element from the vector a word at a time.
// Answer: same with exercise8_5
int exercise8_10();
// Exercise 8.11: The program in this section defined its istringstream
// object inside the outer while loop. What changes would you need to make if
// record were defined outside that loop? Rewrite the program, moving the
// definition of  record outside the while, and see whether you thought of all
// the changes that are needed.
int exercise8_11();
// Exercise 8.12: Why didn’t we use in-class initializers in PersonInfo?
// we dont provide default value for PersonInfo class.
// 然而，你给出的代码示例中并没有使用这个特性，所以如果你想在创建PersonInfo的实例时为其成员变量提供初始值，你需要使用构造函数或者在类定义中直接进行初始化。
int exercise8_12();
// Exercise 8.13: Rewrite the phone number program from this section to read
// from a named file rather than from cin.
// Answer: same with exercise8_11
int exercise8_13();
// Exercise 8.14: Why did we declare entry and nums as const auto &?
// Answer: (1) we dont want to copy entry and nums, that's why we use &;
// (2) we dont want to modify entry and nums in our logic, that's why we use const;
// (3) we dont want to specify the type of entry and nums, that's why we use auto.
int exercise8_14();

#endif