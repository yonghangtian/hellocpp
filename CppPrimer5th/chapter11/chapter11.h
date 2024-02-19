#ifndef CPPPRIMER5THCHAPTER11
#define CPPPRIMER5THCHAPTER11
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <cctype>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <algorithm>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
// #define NDEBUG

// Exercise 11.1: Describe the differences between a map and a vector.
// Answer: (1) vector is kind of key-value pair with it's key are integers(value's position, starting from 0 to n); 
// (2) map is also key-value pair while map's key is not strictly integers.  Values in a map are found by a key rather than
// by their position. Given a map of names to phone numbers, we’d use a person’s name
// as a subscript to fetch that person’s phone number.
int exercise11_1();

// Exercise 11.2: Give an example of when each of list, vector, deque,
// map, and set might be most useful.
int exercise11_2();

// Exercise 11.3: Write your own version of the word-counting program.
int exercise11_3();

// Exercise 11.4: Extend your program to ignore case and punctuation. For
// example, “example.” “example,” and “Example” should all increment the same
// counter.
int exercise11_4();

// Exercises Section 11.2.1
// Exercise 11.5: Explain the difference between a map and a set. When
// might you use one or the other?
// Answer: ask chatgpt.
int exercise11_5();

// Exercise 11.6: Explain the difference between a set and a list. When
// might you use one or the other?
// Answer: ask chatgpt.
int exercise11_6();

// Exercise 11.7: Define a map for which the key is the family’s last name and
// the value is a vector of the children’s names. Write code to add new
// families and to add new children to an existing family.
int exercise11_7();

// Exercise 11.8: Write a program that stores the excluded words in a vector
// instead of in a set. What are the advantages to using a set?
// Answer: not easy to find whether a word is a vector or not;
//  not easy to check whether vector contains duplicates words or not.
int exercise11_8();

// Exercises Section 11.2.2
// Exercise 11.9: Define a map that associates words with a list of line
// numbers on which the word might occur.
// Answer: meanless question, same with 11.7.
int exercise11_9();

// Exercise 11.10: Could we define a map from vector<int>::iterator to
// int? What about from list<int>::iterator to int? In each case, if
// not, why not?
// Answer: gengerated by chatgpt.
// In C++, you cannot directly define a map from `vector<int>::iterator` to `int` or from `list<int>::iterator` to `int`. This is because `vector<int>::iterator` and `list<int>::iterator` are not pointers, but rather iterator objects that may be invalidated when elements are added or removed from the respective containers (`vector` or `list`). 
// For example, if you were to create a map from `vector<int>::iterator` to `int`, and then you added or removed elements from the vector, the iterators would be invalidated, leading to undefined behavior when you try to access them. Similarly, for `list`, iterators could be invalidated due to insertions and deletions.
// Regarding the "strict weak ordering" requirement for the keys of a map in C++, `vector<int>::iterator` does satisfy this requirement. According to the C++ standard library, the `std::map` requires its keys to meet the requirements of "LessThanComparable" and "Strict Weak Ordering", which essentially means that the keys must have a defined order and that this order is consistent and transitive.
// Since `vector<int>::iterator` provides the necessary comparison operators (`<`, `>`, `<=`, `>=`) for iterators and ensures a well-defined order, it satisfies the requirements for being used as keys in a `std::map`. However, as mentioned earlier, it's not practical to directly use iterators as keys due to potential invalidation issues. Instead, you would typically use the values pointed to by the iterators as keys.
int exercise11_10();

// Exercise 11.11: Redefine bookstore without using decltype.
int exercise11_11();

// Exercises Section 11.2.3
// Exercise 11.12: Write a program to read a sequence of strings and ints,
// storing each into a pair. Store the pairs in a vector.
int exercise11_12();

// Exercise 11.13: There are at least three ways to create the pairs in the
// program for the previous exercise. Write three versions of that program,
// creating the pairs in each way. Explain which form you think is easiest to
// write and understand, and why.
int exercise11_13();

// Exercise 11.14: Extend the map of children to their family name that you
// wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
// pair that holds a child’s name and birthday.
int exercise11_14();

// Exercises Section 11.3.1
// Exercise 11.15: What are the mapped_type, key_type, and
// value_type of a map from int to vector<int>?
int exercise11_15();

// Exercise 11.16: Using a map iterator write an expression that assigns a
// value to an element.
int exercise11_16();

// Exercise 11.17: Assuming c is a multiset of strings and v is a vector
// of strings, explain the following calls. Indicate whether each call is legal:
// copy(v.begin(), v.end(), inserter(c, c.end()));
// copy(v.begin(), v.end(), back_inserter(c));
// copy(c.begin(), c.end(), inserter(v, v.end()));
// copy(c.begin(), c.end(), back_inserter(v));
int exercise11_17();

// Exercise 11.18: Write the type of map_it from the loop on page 430
// without using auto or decltype.
int exercise11_18();

// Exercise 11.19: Define a variable that you initialize by calling begin() on
// the multiset named bookstore from § 11.2.2 (p. 425). Write the
// variable’s type without using auto or decltype.
int exercise11_19();

// Exercises Section 11.3.2
// Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to
// use insert instead of subscripting. Which program do you think is easier to
// write and read? Explain your reasoning.
int exercise11_20();

// Exercise 11.21: Assuming word_count is a map from string to size_t
// and word is a string, explain the following loop:
// while (cin >> word) 
// ++word_count.insert({word, 0}).first->second;
int exercise11_21();

// Exercise 11.22: Given a map<string, vector<int>>, write the types
// used as an argument and as the return value for the version of insert that
// inserts one element.
int exercise11_22();

// Exercise 11.23: Rewrite the map that stored vectors of children’s names
// with a key that is the family last name for the exercises in § 11.2.1 (p. 424)
// to use a multimap
int exercise11_23();

// Exercises Section 11.3.4
// Exercise 11.24: What does the following program do?
// map<int, int> m;
// m[0] = 1;
int exercise11_24();

// Exercise 11.25: Contrast the following program with the one in the previous
// exercise
// vector<int> v;
// v[0] = 1;
int exercise11_25();

// Exercise 11.26: What type can be used to subscript a map? What type does
// the subscript operator return? Give a concrete example—that is, define a map
// and then write the types that can be used to subscript the map and the type
// that would be returned from the subscript operator.
int exercise11_26();

// Exercises Section 11.3.5
// Exercise 11.27: What kinds of problems would you use count to solve?
// When might you use find instead?
int exercise11_27();

// Exercise 11.28: Define and initialize a variable to hold the result of calling
// find on a map from string to vector of int.
int exercise11_28();

// Exercise 11.29: What do upper_bound, lower_bound, and
// equal_range return when you pass them a key that is not in the container?
int exercise11_29();

// Exercise 11.30:  Explain the meaning of the operand pos.first->second
// used in the output expression of the final program in this section.
int exercise11_30();

// Exercise 11.31: Write a program that defines a multimap of authors and
// their works. Use find to find an element in the multimap and erase that
// element. Be sure your program works correctly if the element you look for is
// not in the map.
int exercise11_31();

// Exercise 11.32: Using the multimap from the previous exercise, write a
// program to print the list of authors and their works alphabetically.
int exercise11_32();

// Exercises Section 11.3.6
// Exercise 11.33: Implement your own version of the word-transformation
// program.
int exercise11_33();

// Exercise 11.34: What would happen if we used the subscript operator
// instead of find in the transform function?
int exercise11_34();

// Exercise 11.35: In buildMap, what effect, if any, would there be from
// rewriting
// trans_map[key] = value.substr(1);
// as trans_map.insert({key, value.substr(1)})?
int exercise11_35();

// Exercise 11.36: Our program does no checking on the validity of either
// input file. In particular, it assumes that the rules in the transformation file are
// all sensible. What would happen if a line in that file has a key, one space,
// and then the end of the line? Predict the behavior and then check it against
// your version of the program.
int exercise11_36();

// Exercises Section 11.4
// Exercise 11.37: What are the advantages of an unordered container as
// compared to the ordered version of that container? What are the advantages
// of the ordered version?
int exercise11_37();

// Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and word-transformation (§ 11.3.6, p. 440) programs to use an unordered_map.
int exercise11_38();
#endif