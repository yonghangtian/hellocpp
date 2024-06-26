#ifndef CPPPRIMER5THCHAPTER13
#define CPPPRIMER5THCHAPTER13
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
#include <new>
#include <map>
#include <set>
#include <stdexcept>
#include <boost/iterator/reverse_iterator.hpp>
#include <initializer_list>
#include "../chapter7/chapter7.h"
#include "../chapter12/chapter12.h"
#include "../chapter12/StrBlob.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

// #define NDEBUG

// below part for mysqlcppconn1.1.12, installed on project root downloaded from oracle official website.
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

// below part for mysqlcppconn8.3.0, installed on project root downloaded from oracle official website.
// Guide: https://mp.weixin.qq.com/s/5gFwZU7mHkXHsa6m8houzg
// #include "mysql/jdbc.h"

// This is a value like HasPtr
class HasPtr
{
public:
    // friend classes
    friend ostream &operator<<(ostream &os, const HasPtr &hp);
    friend inline void swap(HasPtr &lhs, HasPtr &rhs)
    {
        cout << "swap called \n";
        using std::swap;
        swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
        swap(lhs.i, rhs.i);   // swap the int members
    }
    // constructors
    HasPtr(const std::string &s = std::string(), const int m = 0) : ps(new std::string(s)), i(m)
    {
        cout << "(" << __FUNCTION__ << ")"
             << " HasPtr()\n";
    }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i)
    {
        cout << "(" << __FUNCTION__ << ")"
             << " HasPtr(const HasPtr &)\n";
    }

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
    {
        cout << "HasPtr(HasPtr &&p) noexcept \n";
        p.ps = nullptr;
    }

    ~HasPtr()
    {
        cout << "(" << __FUNCTION__ << ")"
             << " ~HasPtr()\n";
        if (ps)
        {
            cout << "String \"" << *ps << "\" is destoryed, address: " << ps << "\n";
        }
        delete ps;
    }
    // overloaded operators
    inline bool operator<(const HasPtr &hp) const
    {
        return (i < hp.i);
    }
    inline bool operator==(const HasPtr &hp) const
    {
        return (ps == hp.ps) && (i == hp.i);
    }

    // (1) const ref verion of operator=
    // In exercise13_53, use this one and comment (2)
    inline HasPtr &operator=(const HasPtr &hp)
    {
        if (*this == hp)
        {
            return *this;
        }
        string *temp = new string(*hp.ps);
        delete ps;
        ps = temp;
        i = hp.i;
        cout << "(" << __FUNCTION__ << ")"
             << " HasPtr &operator=(const HasPtr &)\n";
        return *this;
    }

    // (2) copy and swap verion of operator=, this verion is automatically exception safe and correctly handle self-assignment.
    // // When define a move constructor, then this "copy and swap" assignment will act move assignment.
    // // In exercise13_52 and exercise13_54, use this one and comment (1)
    // inline HasPtr &operator=(HasPtr hp)
    // {
    //     cout << "(" << __FUNCTION__ << ")"
    //          << " HasPtr &operator=(HasPtr &)\n";
    //     swap(*this, hp);
    //     return *this;
    // }

    inline HasPtr &operator=(HasPtr &&hp)
    {
        cout << "(" << __FUNCTION__ << ")"
             << " HasPtr &operator=(HasPtr &&)\n";
        if (this != &hp)
        {
            swap(*this, hp);
        }
        return *this;
    }

private:
    std::string *ps;
    int i;
};

// This is a pointer like HasPtr
class PlHasPtr
{
public:
    // friend funcs
    friend ostream &operator<<(ostream &os, const PlHasPtr &hp);
    friend inline void swap(PlHasPtr &lhs, PlHasPtr &rhs)
    {
        cout << "PlHasPtr swap called \n";
        using std::swap;
        swap(lhs.ps, rhs.ps);         // swap the pointers, not the string data
        swap(lhs.refCnt, rhs.refCnt); // swap the pointers, not the refCnt data
        swap(lhs.i, rhs.i);           // swap the int members
    }

    // constructors
    PlHasPtr(const std::string &s = std::string(), const int m = 0) : ps(new std::string(s)), i(m), refCnt(new int(1))
    {
        cout << "(" << __FUNCTION__ << ")"
             << " PlHasPtr()\n";
    }

    PlHasPtr(const PlHasPtr &hp) : ps(hp.ps), i(hp.i), refCnt(hp.refCnt)
    {
        ++*refCnt;
        cout << "(" << __FUNCTION__ << ")"
             << " PlHasPtr(const PlHasPtr &)\n";
    }

    ~PlHasPtr()
    {
        if (--*refCnt == 0)
        {
            delete ps;
            delete refCnt;
        }
        cout << "(" << __FUNCTION__ << ")"
             << " ~PlHasPtr()\n";
    }

    inline bool operator==(const PlHasPtr &hp)
    {
        return (ps == hp.ps) && (i == hp.i);
    }

    // (1) const ref verion of operator=
    // inline PlHasPtr &operator=(const PlHasPtr &hp)
    // {
    //     cout << "(" << __FUNCTION__ << ")"
    //          << " PlHasPtr &operator=(const PlHasPtr &)\n";
    //     if (*this == hp)
    //     {
    //         return *this;
    //     }
    //     if (--*refCnt == 0)
    //     {
    //         delete ps;
    //         delete refCnt;
    //     }
    //     ps = hp.ps;
    //     i = hp.i;
    //     refCnt = hp.refCnt;
    //     ++*refCnt;
    //     return *this;
    // }

    // (2) copy and swap verion of operator=, this verion is automatically  exception safe and correctly handle self-assignment.
    inline PlHasPtr &operator=(PlHasPtr hp)
    {
        swap(*this, hp);
        cout << "(" << __FUNCTION__ << ")"
             << " PlHasPtr &operator=(PlHasPtr)\n";
        return *this;
    }

private:
    std::string *ps;
    int i;
    int *refCnt;
};

class numbered
{
private:
    static int serialNumberCounter; // Static counter for generating unique serial numbers
    int mysn;                       // Data member to store the unique serial number

public:
    // Default constructor
    numbered()
    {
        // Increment the static counter to generate a unique serial number
        mysn = ++serialNumberCounter;

        // Optional: Print the generated serial number to the console
        cout << "Object created with serial number: " << mysn << endl;
    }

    numbered(const numbered &)
    {
        mysn = ++serialNumberCounter;
        cout << "(" << __FUNCTION__ << ")"
             << " numbered(const numbered &)\n";
    }

    // Getter function to retrieve the serial number
    int getSerialNumber() const
    {
        return mysn;
    }
};

class employee
{
private:
    static int serialNumberCounter; // Static counter for generating unique serial numbers
    int employeeNum;
    string name; // Data member to store the unique serial number

public:
    // Default constructor
    employee(const string &str = string(""))
    {
        // Increment the static counter to generate a unique serial number
        employeeNum = ++serialNumberCounter;
        name = str;
        // Optional: Print the generated serial number to the console
        cout << "Employ number: " << employeeNum << endl;
    }

    employee(const employee &temp)
    {
        employeeNum = ++serialNumberCounter;
        name = temp.name;
        cout << "(" << __FUNCTION__ << ")"
             << " employee(const employee &)\n";
    }

    void getEmployeeInfo() const
    {
        cout << "Employee number: " << employeeNum << " name: " << name << "\n";
    }

    void setName(const string &str)
    {
        name = str;
    }
};

class TreeNode
{
public:
    // friend func
    friend ostream &operator<<(ostream &os, const TreeNode &tn);
    // constructors
    TreeNode(const std::string a = "temp", const int i = 10) : value(a), count(i), left(nullptr), right(nullptr), refCnt(new int(1)){};
    TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right), refCnt(tn.refCnt) { ++*refCnt; };
    inline bool operator==(const TreeNode &tn)
    {
        return (value == tn.value) && (count == tn.count) && (left == tn.left) && (right == tn.right);
    }

    TreeNode &operator=(const TreeNode &tn)
    {
        if (*this == tn)
        {
            return *this;
        }
        if (--*refCnt == 0)
        {
            delete left;
            delete right;
        }
        value = tn.value;
        count = tn.count;
        left = tn.left;
        right = tn.right;
        refCnt = tn.refCnt;
        ++*refCnt;
        return *this;
    }
    ~TreeNode()
    {
        cout << *this;
        if ((--*refCnt) == 0)
        {
            delete refCnt;
        }
    }
    void setLeft(TreeNode *tn)
    {
        left = tn;
    }
    void setRight(TreeNode *tn)
    {
        right = tn;
    }
    TreeNode *getLeft()
    {
        return left;
    }
    TreeNode *getRight()
    {
        return right;
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
    int *refCnt;
};

class BinStrTree
{
private:
    TreeNode *root;
};

class PlFolder;
class MessageForPlFolder
{
public:
    friend class PlFolder;
    friend ostream &operator<<(ostream &os, const MessageForPlFolder &m);

    // folders is implicitly initialized to the empty set
    explicit MessageForPlFolder(const std::string &str = "") : contents(str) {}

    // copy control to manage pointers to this Message
    MessageForPlFolder(const MessageForPlFolder &);            // copy constructor
    MessageForPlFolder &operator=(const MessageForPlFolder &); // copy assignment
    ~MessageForPlFolder();                                     // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(PlFolder &);
    void remove(PlFolder &);

private:
    std::string contents;         // actual message text
    std::set<PlFolder *> folders; // PlFolders that have this Message.
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const MessageForPlFolder &);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};

class PlFolder
{
public:
    friend ostream &operator<<(ostream &os, const PlFolder &f);

    PlFolder() = default;
    PlFolder(const PlFolder &f) : spMessages(f.spMessages){}; // Folder should act like pointers
    PlFolder &operator=(const PlFolder &);                    // copy assignment
    ~PlFolder();                                              // Folder need to ask every messages to clean their folder set, then Folder clean it's messages set.
    void addMsg(MessageForPlFolder *);
    void remMsg(MessageForPlFolder *);

private:
    std::shared_ptr<std::set<MessageForPlFolder *>> spMessages;
};

class Folder;
class Message
{
public:
    friend class Folder;
    friend ostream &operator<<(ostream &os, const Message &m);

    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) {}

    // copy control to manage pointers to this Message
    Message(const Message &);            // copy constructor
    Message &operator=(const Message &); // copy assignment
    ~Message();                          // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;       // actual message text
    std::set<Folder *> folders; // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message &);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
    void addFolder(Folder *);
    void remFolder(Folder *);
};

class Folder
{
public:
    friend class Message;
    friend ostream &operator<<(ostream &os, const Folder &f);

    Folder() = default;
    Folder(const Folder &f);           // Copy the set and make each message in that set point to me.
    Folder &operator=(const Folder &); // copy assignment
    ~Folder();                         // Folder need to ask every messages to clean their folder set, then Folder clean it's messages set.

private:
    std::set<Message *> messages;
    void addMsg(Message *);
    void remMsg(Message *);
    void remove_from_Messages();
    void add_to_Messages(const Folder &);
};

class StrVec
{
public:
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);

    // copy control members
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &);            // copy constructor
    StrVec &operator=(const StrVec &); // copy assignment
    StrVec &operator=(std::initializer_list<std::string>);

    StrVec(StrVec &&) noexcept;            // move constructor
    StrVec &operator=(StrVec &&) noexcept; // move assignment

    ~StrVec() noexcept; // destructor

    StrVec(std::initializer_list<std::string>);

    void push_back(const std::string &); // copy the element
    void push_back(std::string &&);      // move the element

    // add elements
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    // iterator interface
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    // [] function
    std::string &operator[](size_t i);

    // const [] function
    const std::string &operator[](size_t i) const;

    // at function
    std::string at(size_t i) const;

private:
    static std::allocator<std::string> alloc; // allocates the elements

    // utility functions:
    //  used by members that add elements to the StrVec
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    // used by the copy constructor, assignment operator, and destructor
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();             // destroy the elements and free the space
    void reallocate();       // get more space and copy the existing elements
    std::string *elements;   // pointer to the first element in the array
    std::string *first_free; // pointer to the first free element in the array
    std::string *cap;        // pointer to one past the end of the array
};

class QueryResultUseStrVec;
class TextQueryUseStrVec
{
public:
    TextQueryUseStrVec(std::ifstream &in_file);
    QueryResultUseStrVec query(const string &word);

private:
    // contents: index is line number, string is line content.
    std::shared_ptr<StrVec> contents;
    // words_map: string is word, and set<int> is a set of line number in which word appears at least once.
    std::shared_ptr<std::map<string, std::set<int>>> words_map;
    // word_count: string is word, and int is the frequency of word.
    std::shared_ptr<std::map<string, int>> word_count;
};

class QueryResultUseStrVec
{
    friend std::ostream &print(std::ostream &os, QueryResultUseStrVec result);

public:
    QueryResultUseStrVec(const string w, int f,
                         std::shared_ptr<StrVec> c,
                         std::shared_ptr<std::set<int>> l) : word(w), frequency(f), contents(c), line_nums(l) {}

    inline std::set<int>::iterator begin() { return line_nums->begin(); }
    inline std::set<int>::iterator end() { return line_nums->end(); }
    inline std::shared_ptr<StrVec> get_file() { return contents; }

private:
    std::shared_ptr<StrVec> contents;
    string word;
    int frequency;
    std::shared_ptr<std::set<int>> line_nums;
};

class SelfDefinedStr
{
public:
    friend ostream &operator<<(ostream &, const SelfDefinedStr &);
    friend bool operator==(const SelfDefinedStr &, const SelfDefinedStr &);
    friend bool operator!=(const SelfDefinedStr &, const SelfDefinedStr &);
    // copy control members
    SelfDefinedStr() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    SelfDefinedStr(const SelfDefinedStr &);                // copy constructor
    SelfDefinedStr &operator=(const SelfDefinedStr &);     // copy assignment
    SelfDefinedStr(SelfDefinedStr &&) noexcept;            // move constructor
    SelfDefinedStr &operator=(SelfDefinedStr &&) noexcept; // move assignment

    ~SelfDefinedStr() noexcept; // destructor

    SelfDefinedStr(const char *); // constructor takes c-type string

    void push_back(const char); // copy the element
    // void push_back(std::string&&);       // move the element

    // add elements
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    // iterator interface
    char *begin() const { return elements; }
    char *end() const { return first_free; }

    // [] function
    char operator[](size_t i) const;

    // at function
    char at(size_t i) const;

private:
    static std::allocator<char> alloc;

    // utility functions:
    //  used by members that add elements to the StrVec
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    // used by the copy constructor, assignment operator, and destructor
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();       // destroy the elements and free the space
    void reallocate(); // get more space and copy the existing elements
    char *elements;    // pointer to the first element in the array
    char *first_free;  // pointer to the first free element in the array
    char *cap;         // pointer to one past the end of the array
};

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
    vector<int> data;
};

// Exercises Section 13.1.1
// Exercise 13.1: What is a copy constructor? When is it used?
// Answer: (1)When we use copy initialization, we are asking the compiler to copy
// the right-hand operand into the object being created, converting that operand if
// necessary (§ 7.5.4, p. 294).
// (2) Copy initialization happens not only when we define variables using an =, but also when we
// • Pass an object as an argument to a parameter of nonreference type
// • Return an object from a function that has a nonreference return type
// • Brace initialize the elements in an array or the members of an aggregate class
// (§ 7.5.5, p. 298)
int exercise13_1();

// Exercise 13.2 : Explain why the following declaration is illegal :
// Sales_data::Sales_data(Sales_data rhs);
// Answer: The fact that the copy constructor is used to initialize nonreference parameters of
// class type explains why the copy constructor’s own parameter must be a reference. If
// that parameter were not a reference, then the call would never succeed—to call the
// copy constructor, we’d need to use the copy constructor to copy the argument, but to
// copy the argument, we’d need to call the copy constructor, and so on indefinitely.
int exercise13_2();

// Exercise 13.3 : What happens when we copy a StrBlob ? What about StrBlobPtrs?
// Answer: copy works, as the complier generate synthesized copy constructor.
int exercise13_3();

// Exercise 13.4: Assuming Point is a class type with a public copy constructor,
// identify each use of the copy constructor in this program fragment:
// Point global;
// Point foo_bar(Point arg)
// {
//  Point local = arg, *heap = new Point(global); *heap = local; Point pa[ 4 ] = { local, *heap };
//  return *heap;
// }
int exercise13_4();

// Exercise 13.5: Given the following sketch of a class, write a copy
// constructor that copies all the members. Your constructor should dynamically
// allocate a new string (§ 12.1.2, p.458) and copy the object to which ps
// points, rather than copying ps itself.
// class HasPtr {
// public:
//  HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
// private:
//  std::string *ps;
//  int i;
// };
int exercise13_5();

// Exercises Section 13.1.2
// Exercise 13.6: What is a copy-assignment operator? When is this operator
// used? What does the synthesized copy-assignment operator do? When is it
// synthesized?
// Answer: (1) & (2) when we assign one initialized item to another initialized item, copy-assignment requries.
// (3) it assigns each nonstatic
// member of the right-hand object to the corresponding member of the left-hand object
// using the copy-assignment operator for the type of that member. Array members are
// assigned by assigning each element of the array. The synthesized copy-assignment
// operator returns a reference to its left-hand object.
int exercise13_6();

// Exercise 13.7: What happens when we assign one StrBlob to another?
// What about StrBlobPtrs?
int exercise13_7();

// Exercise 13.8: Write the assignment operator for the HasPtr class from
// exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your
// assignment operator should copy the object to which ps points.
int exercise13_8();

// Exercises Section 13.1.3
// Exercise 13.9 : What is a destructor ? What does the synthesized destructor do ? When is a destructor synthesized ?
// Answer: (1) The destructor operates inversely to the constructors: Constructors initialize the
// nonstatic data members of an object and may do other work; destructors do
// whatever work is needed to free the resources used by an object and destroy the
// nonstatic data members of the object.
// (2)  a destructor has a function body and a destruction part. In a destructor, the function body is executed
// first and then the members are destroyed. Members are destroyed in reverse order
// from the order in which they were initialized.
int exercise13_9();

// Exercise 13.10 : What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
// Answer: (1) when StrBlob is destoryed, the reference counter decrease;
// (2) when StrBlobPtr is destoryed, the weak-ptr is destoryed directly.
int exercise13_10();

// Exercise 13.11 : Add a destructor to your HasPtr class from the previous exercises.
int exercise13_11();

// Exercise 13.12 : How many destructor calls occur in the following code fragment?
//  bool fcn(const Sales_data *trans, Sales_data accum)
// {
//     Sales_data item1(*trans), item2(accum);
//     return item1.isbn() != item2.isbn();
// }
int exercise13_12();

// Exercise 13.13: A good way to understand copy-control members and
// constructors is to define a simple class with these members in which each
// member prints its name:
// struct X { X() {std::cout << "X()" << std::endl;} X(const X&) {std::cout << "X(const X&)" <<
// std::endl;}};
// Add the copy-assignment operator and destructor to X and write a program using
// X objects in various ways: Pass them as nonreference and reference parameters;
// dynamically allocate them; put them in containers; and so forth. Study the output
// until you are certain you understand when and why each copy-control member is
// used. As you read the output, remember that the compiler can omit calls to the
// copy constructor.
int exercise13_13();

// Exercises Section 13.1.4
// Exercise 13.14: Assume that numbered is a class with a default constructor
// that generates a unique serial number for each object, which is stored in a
// data member named mysn. Assuming numbered uses the synthesized copy-control members and given the following function:
// void f (numbered s) { cout << s.mysn << endl; }
// numbered a, b = a, c = b;
// f(a); f(b); f(c);
// what output does the following code produce?
// Answer: in the end , a == b == c, therefore, f(a); f(b); f(c) will output a.mysn three times.
int exercise13_14();

// Exercise 13.15: Assume numbered has a copy constructor that generates a
// new serial number. Does that change the output of the calls in the previous
// exercise? If so, why? What output gets generated?
int exercise13_15();

// Exercise 13.16: What if the parameter in f were const numbered&?
// Does that change the output? If so, why? What output gets generated?
int exercise13_16();

// Exercise 13.17: Write versions of numbered and f corresponding to the
// previous three exercises and check whether you correctly predicted the
// output.
int exercise13_17();

// Exercises Section 13.1.6
// Exercise 13.18: Define an Employee class that contains an employee name
// and a unique employee identifier. Give the class a default constructor and a
// constructor that takes a string representing the employee’s name. Each
// constructor should generate a unique ID by incrementing a static data member.
// Answer: static number are separate from class's instances,
// no matter how many instances one class have, it only have one static number.
// Therefore, synthesized copy constructor does not copy or modify static number.
int exercise13_18();

// Exercise 13.19: Does your Employee class need to define its own versions
// of the copy-control members? If so, why? If not, why not? Implement
// whatever copy-control members you think Employee needs.
// Answer: (1) yes, it need, as no two employee have same employee number;
int exercise13_19();

// Exercise 13.20: Explain what happens when we copy, assign, or destroy
// objects of our TextQuery and QueryResult classes from § 12.3 (p. 484).
int exercise13_20();

// Exercise 13.21: Do you think the TextQuery and QueryResult classes
// need to define their own versions of the copy-control members? If so, why?
// If not, why not? Implement whichever copy-control operations you think
// these classes require.
// Answer: no need to implement, as all element in TextQuery and QueryReuslt are shared_ptr or string or int.
int exercise13_21();

// Exercises Section 13.2
// Exercise 13.22: Assume that we want HasPtr to behave like a value. That
// is, each object should have its own copy of the string to which the objects
// point. We’ll show the definitions of the copy-control members in the next
// section. However, you already know everything you need to know to
// implement these members. Write the HasPtr copy constructor and copy-assignment operator before reading on.
int exercise13_22();

// Exercises Section 13.2.1
// Exercise 13.23: Compare the copy-control members that you wrote for the
// solutions to the previous section’s exercises to the code presented here. Be
// sure you understand the differences, if any, between your code and ours.
// Answer: of cource yes.
int exercise13_23();

// Exercise 13.24: What would happen if the version of HasPtr in this section
// didn’t define a destructor? What if HasPtr didn’t define the copy constructor?
// Answer: (1) If no destructor, memory leaks;
// (2) If no copy constructor, then pointer will be copied directly, not the string that the pointer points to.
int exercise13_24();

// Exercise 13.25: Assume we want to define a version of StrBlob that acts
// like a value. Also assume that we want to continue to use a shared_ptr so
// that our StrBlobPtr class can still use a weak_ptr to the vector. Your
// revised class will need a copy constructor and copy-assignment operator but
// will not need a destructor. Explain what the copy constructor and copy-assignment
// operators must do. Explain why the class does not need a destructor.
int exercise13_25();

// Exercise 13.26: Write your own version of the StrBlob class described in
// the previous exercise.
int exercise13_26();

// Exercises Section 13.2.2
// Exercise 13.27 : Define your own reference - counted version of HasPtr.
int exercise13_27();

// Exercise 13.28: Given the following classes, implement a default constructor
// and the necessary copy-control members.
// (a)
// class TreeNode {
//     private:
//  std::string value;
//  int count;
//  TreeNode *left; TreeNode *right;};
//  (b)
// class BinStrTree {
//     private: TreeNode *root; };
int exercise13_28();

// Exercises Section 13.3
// Exercise 13.29: Explain why the calls to swap inside swap(HasPtr&,
// HasPtr&) do not cause a recursion loop.
// Answer: string pointer and int member have std swap func.
int exercise13_29();

// Exercise 13.30: Write and test a swap function for your valuelike version of
// HasPtr. Give your swap a print statement that notes when it is executed.
int exercise13_30();

// Exercise 13.31: Give your class a < operator and define a vector of
// HasPtrs. Give that vector some elements and then sort the vector.
// Note when swap is called.
int exercise13_31();

// Exercise 13.32: Would the pointerlike version of HasPtr benefit from
// defining a swap function? If so, what is the benefit? If not, why not?
// Answer: yes.
// Using the "copy and swap" idiom for implementing the copy assignment operator (operator=) can often be a good practice,
// especially when dealing with self-defined classes that manage resources like dynamic memory.
// However, whether it's the best approach depends on the specific requirements and characteristics of your class.
int exercise13_32();

// Exercises Section 13.4
// Exercise 13.33: Why is the parameter to the save and remove members
// of Message a Folder&? Why didn’t we define that parameter as Folder?
// Or const Folder&?
// Answer: we need to call the folder's member func and modity the folder's data member.
int exercise13_33();

// Exercise 13.34: Write the Message class as described in this section.
int exercise13_34();

// Exercise 13.35: What would happen if Message used the synthesized
// versions of the copy-control members?
// Answer: if so, message cannot control the relation with Folder any more.
int exercise13_35();

// Exercise 13.36: Design and implement the corresponding Folder class.
// That class should hold a set that points to the Messages in that Folder.
// Answer: done, I implement it in two ways: one works like pointer, one works like value.
int exercise13_36();

// Exercise 13.37: Add members to the Message class to insert or remove a
// given Folder* into folders. These members are analogous to Folder’s
// addMsg and remMsg operations.
// Answer: done.
int exercise13_37();

// Exercise 13.38: We did not use copy and swap to define the Message
// assignment operator. Why do you suppose this is so?
// Answer: we want to not only swap the value, but also need to modify the value we swapped.
int exercise13_38();

// Exercises Section 13.5
// Exercise 13.39: Write your own version of StrVec, including versions of
// reserve, capacity (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).
int exercise13_39();

// Exercise 13.40: Add a constructor that takes an initializer_list<string> to your StrVec class.
int exercise13_40();

// Exercise 13.41: Why did we use postfix increment in the call to
// construct inside push_back? What would happen if it used the prefix increment?
// Answer: prefix increment will make first_free be a pointer point to the last element in our vector,
// not a pointer point to the first free element.
int exercise13_41();

// Exercise 13.42: Test your StrVec class by using it in place of the
// vector<string> in your TextQuery and QueryResult classes (§ 12.3, p. 484).
int exercise13_42();

// Exercise 13.43: Rewrite the free member to use for_each and a lambda
// (§ 10.3.2, p. 388) in place of the for loop to destroy the elements. Which
// implementation do you prefer, and why?
// Answer: iterator and lambda is more suitable, as we dont need to maintain the in/decrement of pointer.
int exercise13_43();

// Exercise 13.44: Write a class named String that is a simplified version of
// the library string class. Your class should have at least a default
// constructor and a constructor that takes a pointer to a C-style string. Use an
// allocator to allocate memory that your String class uses.
int exercise13_44();

// Exercises Section 13.6.1
// Exercise 13.45: Distinguish between an rvalue reference and an lvalue reference.
// Answer: rvalue references have the important property that they may be bound only to an object that
// is about to be destroyed. As a result, we are free to “move” resources from an rvalue
// reference to another object.
int exercise13_45();

// Exercise 13.46: Which kind of reference can be bound to the following initializers?
// int f();
// vector<int> vi(100);
// int? r1 = f();
// int? r2 = vi[0];
// int? r3 = r1;
// int? r4 = vi[0] * f();
int exercise13_46();

// Exercise 13.47: Give the copy constructor and copy-assignment operator in
// your String class from exercise 13.44 in § 13.5 (p. 531) a statement that
// prints a message each time the function is executed.
int exercise13_47();

// Exercise 13.48: Define a vector<String> and call push_back several
// times on that vector. Run your program and see how often Strings are
// copied.
int exercise13_48();

// Exercises Section 13.6.2
// Exercise 13.49: Add a move constructor and move-assignment operator to
// your StrVec, String, and Message classes.
int exercise13_49();

// Exercise 13.50: Put print statements in the move operations in your
// String class and rerun the program from exercise 13.48 in § 13.6.1 (p.
// 534) that used a vector<String> to see when the copies are avoided.
int exercise13_50();

// Exercise 13.51: Although unique_ptrs cannot be copied, in § 12.1.5 (p.
// 471) we wrote a clone function that returned a unique_ptr by value.
// Explain why that function is legal and how it works.
// Answer: there must be a mechanism that take care of rvalue unqiue_ptr.
int exercise13_51();

// Exercise 13.52: Explain in detail what happens in the assignments of the
// HasPtr objects on page 541. In particular, describe step by step what
// happens to values of hp, hp2, and of the rhs parameter in the HasPtr
// assignment operator.
int exercise13_52();

// Exercise 13.53: As a matter of low-level efficiency, the HasPtr assignment
// operator is not ideal. Explain why. Implement a copy-assignment and move-assignment operator for HasPtr and compare the operations executed in
// your new move-assignment operator versus the copy-and-swap version.
int exercise13_53();

// Exercise 13.54: What would happen if we defined a HasPtr move-assignment operator but did not change the copy-and-swap operator? Write
// code to test your answer.
int exercise13_54();

// Exercises Section 13.6.3
// Exercise 13.55: Add an rvalue reference version of push_back to your StrBlob.
int exercise13_55();

// Exercise 13.56: What would happen if we defined sorted as:
// Foo Foo::sorted() const & {
//  Foo ret(*this);
//  return ret.sorted();
// }
int exercise13_56();

// Exercise 13.57: What if we defined sorted as:
// Foo Foo::sorted() const & { return Foo(*this).sorted(); }
int exercise13_57();

// Exercise 13.58: Write versions of class Foo with print statements in their
// sorted functions to test your answers to the previous two exercises.
int exercise13_58();

#endif