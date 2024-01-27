#ifndef CPPPRIMER5THCHAPTER9
#define CPPPRIMER5THCHAPTER9
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cctype>
#include <forward_list>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ostream;
using std::size_t;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::forward_list;
// #define NDEBUG

typedef string::size_type pos;


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


// Exercise 9.1: Which is the most appropriate—a vector, a deque, or a
// list—for the following program tasks? Explain the rationale for your choice.
// If there is no reason to prefer one or another container, explain why not.
// (a) Read a fixed number of words, inserting them in the container
// alphabetically as they are entered. We’ll see in the next chapter that
// associative containers are better suited to this problem.
// (b) Read an unknown number of words. Always insert new words at the
// back. Remove the next value from the front.
// (c) Read an unknown number of integers from a file. Sort the numbers and
// then print them to standard output.
// Answer: (a) list, as task need random write. (b) deque, as task need write/delete on the head and the tail;
// (c) vector, as task dont have special read and write requirements.
int exercise9_1();
// Exercise 9.2: Define a list that holds elements that are deques that hold ints.
int exercise9_2();
// Exercise 9.3: What are the constraints on the iterators that form iterator ranges?
// Answer: an iterator range is denoted by a pair of iterators each of which refers to an
// element, or to one past the last element, in the same container. These two iterators,
// often referred to as begin and end—or (somewhat misleadingly) as first and
// last—mark a range of elements from the container.
// The name last, although commonly used, is a bit misleading, because the second
// iterator never refers to the last element of the range. Instead, it refers to a point one
// past the last element. The elements in the range include the element denoted by
// first and every element from first up to but not including last.
// This element range is called a left-inclusive interval. The standard mathematical
// notation for such a range is [ begin, end)
// indicating that the range begins with begin and ends with, but does not include,
// end. The iterators begin and end must refer to the same container. The iterator end
// may be equal to begin but must not refer to an element before the one denoted by
// begin.
int exercise9_3();
// Exercise 9.4: Write a function that takes a pair of iterators to a
// vector<int> and an int value. Look for that value in the range and return
// a bool indicating whether it was found.
int exercise9_4();
// Exercise 9.5: Rewrite the previous program to return an iterator to the
// requested element. Note that the program must handle the case where the
// element is not found.
int exercise9_5();
// Exercise 9.6: What is wrong with the following program? How might you
// correct it?
// list<int> lst1;
// list<int>::iterator iter1 = lst1.begin(),
//  iter2 = lst1.end();
// while (iter1 < iter2) /* ... */
int exercise9_6();
// Exercise 9.7: What type should be used as the index into a vector of ints?
// Answer: vector<int>::size_type
int exercise9_7();
// Exercise 9.8: What type should be used to read elements in a list of
// strings? To write them?
// Answer: to read, use list<string>::value_type; to write, use string or char *;
int exercise9_8();

// Exercise 9.9: What is the difference between the begin and cbegin
// functions?
// Answer: if the object is const object, then begin func returns const iterator; 
// else if the object is non-const object, then begin func returns non-const iterator;
// No matter whether the object is const or non-const, cbegin func returns const iterator.
int exercise9_9();
// Exercise 9.10: What are the types of the following four objects?
// vector<int> v1; const vector<int> v2;
// auto it1 = v1.begin(), it2 = v2.begin();
// auto it3 = v1.cbegin(), it4 = v2.cbegin();
int exercise9_10();
// Exercise 9.11: Show an example of each of the six ways to create and
// initialize a vector. Explain what values each vector contains.
int exercise9_11();
// Exercise 9.12: Explain the differences between the constructor that takes a
// container to copy and the constructor that takes two iterators.
// Answer: To create a container as a copy of another container, the container and element
// types must match. When we pass iterators, there is no requirement that the container
// types be identical. Moreover, the element types in the new and original containers can
// differ as long as it is possible to convert (§ 4.11, p. 159) the elements we’re copying
// to the element type of the container we are initializing:
int exercise9_12();
// Exercise 9.13: How would you initialize a vector<double> from a
// list<int>? From a vector<int>? Write code to check your answers.
int exercise9_13();
// Exercise 9.14: Write a program to assign the elements from a list of
// char* pointers to C-style character strings to a vector of strings.
int exercise9_14();
// Exercise 9.15: Write a program to determine whether two vector<int>s
// are equal.
int exercise9_15();
// Exercise 9.16: Repeat the previous program, but compare elements in a
// list<int> to a vector<int>.
int exercise9_16();
// Exercise 9.17: Assuming c1 and c2 are containers, what (if any)
// constraints does the following usage place on the types of c1 and c2?
// if (c1 < c2)
// Answer: (1) c1 and c2 should be the same type; (2) type of c1 and c2 should define operator < .
int exercise9_17();

// Exercises Section 9.3.1
// Exercise 9.18: Write a program to read a sequence of strings from the
// standard input into a deque. Use iterators to write a loop to print the
// elements in the deque.
int exercise9_18();
// Exercise 9.19: Rewrite the program from the previous exercise to use a list. 
// List the changes you needed to make.
int exercise9_19();
// Exercise 9.20: Write a program to copy elements from a list<int> into
// two deques. The even-valued elements should go into one deque and the
// odd ones into the other.
int exercise9_20();

// Exercise 9.21: Explain how the loop from page 345 that used the return
// from insert to add elements to a list would work if we inserted into a
// vector instead.
int exercise9_21();

// Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the
// following program? How might you correct the problem(s)?
    // vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    // while (iter != mid)
    //     if (*iter == some_val)
    //         iv.insert(iter, 2 * some_val);
int exercise9_22();

// Exercise 9.23: In the first program in this section on page 346, what would
// the values of val, val2, val3, and val4 be if c.size() is 1?
int exercise9_23();

// Exercise 9.24: Write a program that fetches the first element in a vector
// using at, the subscript operator, front, and begin. Test your program on
// an empty vector.
int exercise9_24();

// Exercise 9.25: In the program on page 349 that erased a range of
// elements, what happens if elem1 and elem2 are equal? What if elem2 or
// both elem1 and elem2 are the off-the-end iterator?
int exercise9_25();

// Exercise 9.26: Using the following definition of ia, copy ia into a vector
// and into a list. Use the single-iterator form of erase to remove the
// elements with odd values from your list and the even values from your
// vector.
// int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
int exercise9_26();

// Exercise 9.27: Write a program to find and remove the odd-valued
// elements in a forward_list<int>.
int exercise9_27();

// Exercise 9.28: Write a function that takes a forward_list<string> and
// two additional string arguments. The function should find the first string
// and insert the second immediately following the first. If the first string is
// not found, then insert the second string at the end of the list.
int exercise9_28();

// Exercise 9.29: Given that vec holds 25 elements, what does
// vec.resize(100) do? What if we next wrote vec.resize(10)?
int exercise9_29();

// Exercise 9.30: What, if any, restrictions does using the version of resize
// that takes a single argument place on the element type?
// Answer: 如果存储的是 类 元素，那么这个类必须提供默认构造函数。
int exercise9_30();

int exercise9_31();
int exercise9_32(); 
int exercise9_33();
int exercise9_34();
int exercise9_35();
int exercise9_36();
int exercise9_37();
int exercise9_38();
int exercise9_39();
int exercise9_40();
int exercise9_41();
int exercise9_42();
int exercise9_43();
int exercise9_44();
int exercise9_45();
int exercise9_46();
int exercise9_47();
int exercise9_48();
int exercise9_49();
int exercise9_50();
int exercise9_51();
int exercise9_52();


#endif