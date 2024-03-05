#ifndef CPPPRIMER5THCHAPTER12
#define CPPPRIMER5THCHAPTER12
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <utility> 
#include <iterator>
#include <algorithm>
#include <memory>
using std::cerr;
using std::cin; 
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
// #define NDEBUG

// below part for mysqlcppconn1.1.12, installed on ubuntu22.04 using apt-get.
// #include <mysql_connection.h>
// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>
// #include <cppconn/prepared_statement.h>

// below part for mysqlcppconn8.3.0, installed on project root downloaded from oracle official website.
// Guide: https://mp.weixin.qq.com/s/5gFwZU7mHkXHsa6m8houzg
#include "mysql/jdbc.h"


// Exercises Section 12.1.1
// Exercise 12.1: How many elements do b1 and b2 have at the end of this
// code?
// StrBlob b1;
// {
//  StrBlob b2 = {"a", "an", "the"}; b1 = b2; b2.push_back("about");
// }
int exercise12_1();

// Exercise 12.2: Write your own version of the StrBlob class including the
// const versions of front and back.
// Answer: I use ../examples/12/StrBlob.h instead;
int exercise12_2();

// Exercise 12.3: Does this class need const versions of push_back and
// pop_back? If so, add them. If not, why aren’t they needed?
// Answer: actually no need, as push_back and pop_back funcs both return void.
int exercise12_3();

// Exercise 12.4:  In our check function we didn’t check whether i was
// greater than zero. Why is it okay to omit that check? 
// Answer: i is of type "std::vector<std::string>::size_type ",
//  size_type is long unsigned int in gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) .
int exercise12_4();

// Exercise 12.5: We did not make the constructor that takes an
// initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and
// cons of this design choice.
// Answer: StrBlob class does not have funcs that beyond the capacity of string's vector.
// pros: alow two ways converation ( "=" or "{} init")
// Cons: there might be confusing( or unexpected ) converation. 
int exercise12_5();

// Exercises Section 12.1.2
// Exercise 12.6: Write a function that returns a dynamically allocated vector
// of ints. Pass that vector to another function that reads the standard input
// to give values to the elements. Pass the vector to another function to print
// the values that were read. Remember to delete the vector at the
// appropriate time.
int exercise12_6();

// Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
int exercise12_7();

// Exercise 12.8: Explain what if anything is wrong with the following function.
// bool
//  b() {
//     int* p = new int;
//     // ...
//     return p;
// }
// Answer: p is not of type bool.
int exercise12_8();

// Exercise 12.9: Explain what happens in the following code:
// int *q = new int(42), *r = new int(100);
// r = q;
// auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
// r2 = q2;
int exercise12_9();

void processSharedPointer(std::shared_ptr<int> ptr);

// Exercises Section 12.1.3
// Exercise 12.10: Explain whether the following call to the process function
// defined on page 464 is correct. If not, how would you correct the call?
// process(shared_ptr<int>(p));
//  p(new int(42));
int exercise12_10();

// Exercise 12.11: What would happen if we called process as follows?
// process(shared_ptr<int>(p.get()));
// Answer: We shouldn't init two unique shared ptr to the same memory.
int exercise12_11();

// Exercise 12.12: Using the declarations of p and sp explain each of the
// following calls to process. If the call is legal, explain what it does. If the call
// is illegal, explain why:
// auto p = new int();
// auto sp = make_shared<int>();
// (a) process(sp);   legal
// (b) process(new int()); illegal
// (c) process(p); illegal
// (d) process(shared_ptr<int>(p)); legal
int exercise12_12();

// Exercise 12.13: What happens if we execute the following code?
// auto sp = make_shared<int>();
// auto p = sp.get();
// delete p;
// Answer: double free or corruption (out) Aborted
int exercise12_13();

// Exercises Section 12.1.4
// Exercise 12.14: Write your own version of a function that uses a
// shared_ptr to manage a connection.
// Answer: let's create an mysql connection program, make our knowledge useful.
int exercise12_14();

// Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p.
// 388) in place of the end_connection function.
// Answer: same with 12_14.
int exercise12_15();

// Exercises Section 12.1.5
// Exercise 12.16: Compilers don’t always give easy-to-understand error
// messages if we attempt to copy or assign a unique_ptr. Write a program
// that contains these errors to see how your compiler diagnoses them.
int exercise12_16();

// Exercise 12.17: Which of the following unique_ptr declarations are illegal
// or likely to result in subsequent program error? Explain what the problem is
// with each one.
// typedef unique_ptr<int> IntP;
//  ix = 1024, *pi = &ix, *pi2 = new int(2048);
// (a) IntP p0(ix);
// (b) IntP p1(pi);
// (c) IntP p2(pi2);
// (d) IntP p3(&ix);
// (e) IntP p4(new int(2048));
// (f) IntP p5(p2.get());
int exercise12_17();

// Exercise 12.18: Why doesn’t shared_ptr have a release member?
// Answer: there might be multiple shared_ptr point to the same memory. 
// If shared_ptr has release member, one shared_ptr call release, then the ownership of the memory will be removed for all existing shared_ptr.
int exercise12_18();

// Exercises Section 12.1.6
// Exercise 12.19: Define your own version of StrBlobPtr and update your
// StrBlob class with the appropriate friend declaration and begin and end
// members.
// Answer: Just use example code, not necessary to duplicate those work.
int exercise12_19();

// Exercise 12.20: Write a program that reads an input file a line at a time
// into a StrBlob and uses a StrBlobPtr to print each element in that
// StrBlob.
int exercise12_20();

// Exercise 12.21: We could have written StrBlobPtr’s deref member as
// follows:
// std::string& deref() const
// { return (*check(curr, "dereference past end"))[curr]; }
// Which version do you think is better and why?
// Answer: I like two-line version of deref(), 
// as two-line version is easier to understand it's logic, and easier to debug when check func throw exception
int exercise12_21();

// Exercise 12.22: What changes would need to be made to StrBlobPtr to
// create a class that can be used with a const StrBlob? Define a class
// named ConstStrBlobPtr that can point to a const StrBlob.
int exercise12_22();

// Exercises Section 12.2.1
// Exercise 12.23: Write a program to concatenate two string literals, putting
// the result in a dynamically allocated array of char. Write a program to
// concatenate two library strings that have the same value as the literals
// used in the first program.
int exercise12_23();

// Exercise 12.24: Write a program that reads a string from the standard input
// into a dynamically allocated character array. Describe how your program
// handles varying size inputs. Test your program by giving it a string of data
// that is longer than the array size you’ve allocated.
int exercise12_24();

// Exercise 12.25: Given the following new expression, how would you
// delete pa?
// int *pa = new int[10];
int exercise12_25();

// Exercises Section 12.2.2
// Exercise 12.26: Rewrite the program on page 481 using an allocator.
int exercise12_26();

// Exercises Section 12.3.1
// Exercise 12.27: The TextQuery and QueryResult classes use only
// capabilities that we have already covered. Without looking ahead, write your
// own versions of these classes.
int exercise12_27();

// Exercise 12.28: Write a program to implement text queries without defining
// classes to manage the data. Your program should take a file and interact
// with a user to query for words in that file. Use vector, map, and set
// containers to hold the data for the file and to generate the results for the
// queries.
int exercise12_28();

// Exercise 12.29: We could have written the loop to manage the interaction
// with the user as a do while (§ 5.4.4, p. 189) loop. Rewrite the loop to use
// a do while. Explain which version you prefer and why.
int exercise12_29();

// Exercises Section 12.3.2
// Exercise 12.30: Define your own versions of the TextQuery and
// QueryResult classes and execute the runQueries function from § 12.3.1 (p. 486).
int exercise12_30();

// Exercise 12.31: What difference(s) would it make if we used a vector
// instead of a set to hold the line numbers? Which approach is better? Why?
int exercise12_31();

// Exercise 12.32: Rewrite the TextQuery and QueryResult classes to use
// a StrBlob instead of a vector<string> to hold the input file.
int exercise12_32();

// Exercise 12.33: In Chapter 15 we’ll extend our query system and will need
// some additional members in the QueryResult class. Add members named
// begin and end that return iterators into the set of line numbers returned
// by a given query, and a member named get_file that returns a
// shared_ptr to the file in the QueryResult object.
int exercise12_33();


#endif