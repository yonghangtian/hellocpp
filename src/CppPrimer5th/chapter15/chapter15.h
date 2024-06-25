#ifndef CPPPRIMER5THCHAPTER15
#define CPPPRIMER5THCHAPTER15
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <utility>
#include <functional>
#include <cstring>
#include <openssl/evp.h>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using namespace std::placeholders;
// #define NDEBUG

#include "../../hello_log.h"

template <typename T>
int rangeForContainer(T &a)
{
    for (auto b : a)
    {
        cout << b << ",";
    }
    cout << endl;
    return 0;
}

class Base
{
public:
    int pub_mem = 1; // public member
    void memfcn(Base &b) { b = *this; }

protected:
    int prot_mem = 2; // protected member
private:
    int priv_mem = 3; // private member
};

class Pub_Derv : public Base // (The derivation access specifier has no effect on whether members (and friends) of a derived class may access the members of its own direct base class.)
{
public:
    void memfcn(Base &b) { b = *this; }
    // ok: derived classes can access protected members
    int d() { return pub_mem; }
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // error: private members are inaccessible to derived classes
    // int g() { return priv_mem; }
};

class Prot_Derv : protected Base // (The derivation access specifier has no effect on whether members (and friends) of a derived class may access the members of its own direct base class.)
{
public:
    void memfcn(Base &b) { b = *this; }
    // ok: derived classes can access protected members and
    int d() { return pub_mem; }
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // error: private members are inaccessible to derived classes
    //  int g() { return priv_mem; }
};

class Priv_Derv : private Base // (The derivation access specifier has no effect on whether members (and friends) of a derived class may access the members of its own direct base class.)
{
public:
    void memfcn(Base &b) { b = *this; }
    // ok: derived classes can access protected members
    int d() { return pub_mem; }
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // error: private members are inaccessible to derived classes
    //  int g() { return priv_mem; }
};

class Derived_from_Pub : public Pub_Derv
{
public:
    void memfcn(Base &b) { b = *this; }
    // ok: base class public member still public in public derv
    int g() { return pub_mem; }
    // ok: base class protected member still protected in public derv
    int h() { return prot_mem; }
};

class Derived_from_Prot : public Prot_Derv
{
public:
    void memfcn(Base &b) { b = *this; }
    // ok: base class public member become protected in protected derv,
    int g() { return pub_mem; }
    // ok: base class protected member still protected in protected derv
    int h() { return prot_mem; }
};

class Derived_from_Priv : public Priv_Derv
{
public:
    // Member functions and friends of classes derived from D may use
    // the derived-to-base conversion if D inherits from B using either public or protected. Such
    // code may not use the conversion if D inherits privately from B.
    // void memfcn(Base &b) { b = *this; }
    // error: base class public member become private in private derv
    // complier error: member "Base::pub_mem" (declared at line 36) is inaccessible
    // int g() { return pub_mem; }
    // error: base class public member become private in private derv
    // complier error: member "Base::prot_mem" (declared at line 38) is inaccessible
    // int h() { return prot_mem; }
};

class VirtualBase
{
public:
    virtual int getMemPublic();
    int pub_mem = 1; // public member
protected:
    int prot_mem = 2; // protected member
private:
    int priv_mem = 3; // private member
};

class VirtualBaseDerv : public VirtualBase
{
public:
    int getMemPublic() override;
    int getProtMem();
    // Error: driv class has no access to base class's private mem.
    // int getProtMem(){ return priv_mem;}
};

class Quote
{
public:
    friend ostream &operator<<(ostream &, Quote &);
    Quote() = default; // = default see § 7.1.4 (p. 264)
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual void debug() { cout << "Quote: bookno" << bookNo << ", price" << price; }

    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }
    virtual ~Quote() = default; // dynamic binding for the destructor
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};

// Bulk_quote inherits from Quote
class Bulk_quote : public Quote
{
public:
    friend ostream &operator<<(ostream &, Bulk_quote &);
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    virtual void debug() { cout << "Bulk_quote: min_qty" << min_qty << ", discount" << discount; }

    virtual ~Bulk_quote() = default;

private:
    std::size_t min_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0;   // fractional discount to apply
};

class Spec_quote : public Quote
{
public:
    friend ostream &operator<<(ostream &, Spec_quote &);
    Spec_quote() = default;
    Spec_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), max_qty(qty), discount(disc) {}
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= max_qty)
            return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
        else
            return cnt * (1 - discount) * price;
    }
    virtual void debug() { cout << "Spec_quote: max_qty" << max_qty << ", discount" << discount; }

    virtual ~Spec_quote() = default;

private:
    std::size_t max_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0;   // fractional discount to apply
};

class base1
{
public:
    string name() { return basename; }
    void setName(string a) { basename = a; }
    virtual void print(ostream &os = cout) { os << basename; }

private:
    string basename;
};

class derived : public base1
{
public:
    void print(ostream &os = cout) override
    {
        // I modified here.
        base1::print(os);
        os << " " << i;
    }

private:
    int i = 0;
};

// class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    // a class with pure virtual function is called Abstract Base Class
    virtual double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0; // purchase size for the discount to apply
    double discount = 0.0;    // fractional discount to apply
};

// the discount kicks in when a specified number of copies of the same book are sold
// the discount is expressed as a fraction to use to reduce the normal price
class Bulk_quote_2 : public Disc_quote
{
public:
    Bulk_quote_2() = default;
    Bulk_quote_2(const std::string &book, double price,
                 std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}

    // overrides the base version to implement the bulk purchase discount policy
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
};

class Spec_quote_2 : public Disc_quote
{
public:
    Spec_quote_2() = default;
    Spec_quote_2(const std::string &book, double price,
                 std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}

    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return quantity * (1 - discount) * price + (cnt - quantity) * price;
        else
            return cnt * (1 - discount) * price;
    }
};

class Base3
{
public:
    virtual int fcn() { return 1; }
};

class D1 : public Base3
{
public:
    int fcn() { return 2; };         // parameter list differs from fcn in Base
    virtual void f2() { cout << 4; }; // new virtual function that does not exist in Base
};

class D2 : public D1
{
public:
    int fcn(int);                    // nonvirtual function hides D1::fcn(int)
    int fcn() { return 3; }          // overrides virtual fcn from Base
    virtual void f2() { cout << 5; }; // overrides virtual f2 from D1
};

int testAccessControl();

int testSpdLog();

// base64编解码，使用openssl包
int testBase64EncodeDecode();

// Exercises Section 15.2.1
// Exercise 15.1: What is a virtual member?
// Answer: let's test virtual.
int exercise15_1();
// Exercise 15.2: How does the protected access specifier differ from
// private?
int exercise15_2();
// Exercise 15.3: Define your own versions of the Quote class and the
// print_total function.
// Answer: Let's copy.
int exercise15_3();
// Exercises Section 15.2.2
// Exercise 15.4: Which of the following declarations, if any, are incorrect?
// Explain why.
// class Base { ... };
// (a) class Derived : public Derived { ... };  // Wrong, class cant inherits itself.
// (b) class Derived : private Base { ... };    // Correct.
// (c) class Derived : public Base;             // Wrong, derivation list should not appear on class forward declarations
int exercise15_4();

// Exercise 15.5: Define your own version of the Bulk_quote class.
// Answer: see exercise15_3
int exercise15_5();

// Exercise 15.6: Test your print_total function from the exercises in §
// 15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that
// function.
// Answer: see exercise15_3
int exercise15_6();

// Exercise 15.7: Define a class that implements a limited discount strategy,
// which applies a discount to books purchased up to a given limit. If the
// number of copies exceeds that limit, the normal price applies to those
// purchased beyond the limit.
int exercise15_7();

// Exercises Section 15.2.3
// Exercise 15.8: Define static type and dynamic type.
// Answer:  the static type of a variable or other expression and the dynamic type of the object
// that expression represents. The static type of an expression is always known at
// compile time—it is the type with which a variable is declared or that an expression
// yields. The dynamic type is the type of the object in memory that the variable or
// expression represents. The dynamic type may not be known until run time.
int exercise15_8();

// Exercise 15.9: When is it possible for an expression’s static type to differ
// from its dynamic type? Give three examples in which the static and dynamic
// type differ.
int exercise15_9();

// Exercise 15.10: Recalling the discussion from §8.1 (p. 311), explain how
// the program on page 317 that passed an ifstream to the Sales_data
// read function works.
// Answer: simply, as ifstream inherits from istream,
// so ifstream has same interfaces and operations with istream.
int exercise15_10();

// Exercises Section 15.3
// Exercise 15.11: Add a virtual debug function to your Quote class hierarchy
// that displays the data members of the respective classes.
int exercise15_11();

// Exercise 15.12: Is it ever useful to declare a member function as both
// override and final? Why or why not?
// Answer: yes, very useful in some case.
// 在C++11中，将成员函数声明为override和final可以同时使用，并且在某些情况下是非常有用的。
// override关键字：这个关键字用于指示编译器该函数是一个重写的虚函数。这有助于编译器检查你是否正确地重写了基类中的虚函数。如果你误拼写了函数名或者函数的参数与基类中的虚函数不匹配，编译器将会报错。这增加了代码的安全性和可维护性。
// final关键字：这个关键字用于指示该函数是最终的，不能被任何派生类重写。这可以用来防止子类意外地重写某个特定的虚函数，从而改变基类的预期行为。
// 将成员函数同时声明为override和final的用处在于：
// 明确性：通过同时使用这两个关键字，你明确地向其他开发者表示，这个函数是一个重写的虚函数，并且不希望它被任何派生类进一步重写。
// 防止意外重写：通过声明函数为final，你确保了没有任何派生类能够重写这个函数，这有助于维护代码的稳定性和一致性。
// 编译器检查：override关键字让编译器帮助你检查是否正确地重写了基类中的虚函数，增加了代码的安全性。
// 因此，在某些情况下，将成员函数同时声明为override和final是非常有用的，特别是当你想要确保某个特定的虚函数在派生类中不再被重写时。
int exercise15_12();

// Exercise 15.13 : Given the following classes, explain each print function:
// If there is a problem in this code, how would you fix it?
// class base1
// {
// public:
//     string name() { return basename; }
//     virtual void print(ostream & os) { os << basename; }

// private:
//     string basename;
// };
// class derived : public base
// {
// public:
//     void print(ostream &os)
//     {
//         print(os);
//         os << " " << i;
//     }
// private:
//     int i;
// };
int exercise15_13();
// Exercise 15.14: Given the classes from the previous exercise and the
// following objects, determine which function is called at run time:
// base bobj; base *bp1 = &bobj; base &br1 = bobj;
// derived dobj; base *bp2 = &dobj; base &br2 = dobj;
// (a) bobj.print();
// (b) dobj.print();
// (c) bp1->name();
// (d) bp2->name();
// (e) br1.print();
// (f) br2.print();
int exercise15_14();

// Exercises Section 15.4
// Exercise 15.15: Define your own versions of Disc_quote and Bulk_quote.
int exercise15_15();

// Exercise 15.16: Rewrite the class representing a limited discount strategy,
// which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from
// Disc_quote.
int exercise15_16();

// Exercise 15.17: Try to define an object of type Disc_quote and see what errors you get from the compiler.
int exercise15_17();

// Exercises Section 15.5
// Exercise 15.18: Given the classes from page 612 and page 613, and
// assuming each object has the type specified in the comments, determine
// which of these assignments are legal. Explain why those that are illegal aren’t allowed:
// Base *p = &d1; // d1 has type Pub_Derv
// p = &d2; // d2 has type Priv_Derv
// p = &d3; // d3 has type Prot_Derv
// p = &dd1; // dd1 has type Derived_from_Public
// p = &dd2; // dd2 has type Derived_from_Private
// p = &dd3; // dd3 has type Derived_from_Protected
int exercise15_18();
// Exercise 15.19: Assume that each of the classes from page 612 and page
// 613 has a member function of the form:
// void memfcn(Base &b) { b = *this; }
// For each class, determine whether this function would be legal.
int exercise15_19();
// Exercise 15.20: Write code to test your answers to the previous two
// exercises.
int exercise15_20();
// Exercise 15.21: Choose one of the following general abstractions containing
// a family of types (or choose one of your own). Organize the types into an
// inheritance hierarchy:
// (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
// (b) Geometric primitives (such as box, circle, sphere, cone)
// (c) C++ language types (such as class, function, member function)
// Answer: honstly speeking, I have nothing to say.
int exercise15_21();
// Exercise 15.22: For the class you chose in the previous exercise, identify
// some of the likely virtual functions as well as public and protected members.
// Answer: honstly speeking, I have nothing to say.
int exercise15_22();
// Exercises Section 15.6
// Exercise 15.23: Assuming class D1 on page 620 had intended to override
// its inherited fcn function, how would you fix that class? Assuming you fixed
// the class so that fcn matched the definition in Base, how would the calls in
// that section be resolved?
int exercise15_23();
// Exercises Section 15.7.1
// Exercise 15.24: What kinds of classes need a virtual destructor? What
// operations must a virtual destructor perform?
int exercise15_24();
// Exercises Section 15.7.2
// Exercise 15.25: Why did we define a default constructor for Disc_quote?
// What effect, if any, would removing that constructor have on the behavior of
// Bulk_quote?
int exercise15_25();
// Exercises Section 15.7.3
// Exercise 15.26: Define the Quote and Bulk_quote copy-control members
// to do the same job as the synthesized versions. Give them and the other
// constructors print statements that identify which function is running. Write
// programs using these classes and predict what objects will be created and
// destroyed. Compare your predictions with the output and continue
// experimenting until your predictions are reliably correct.
int exercise15_26();
// Exercises Section 15.7.4
// Exercise 15.27: Redefine your Bulk_quote class to inherit its constructors.
int exercise15_27();
// Exercises Section 15.8
// Exercise 15.28: Define a vector to hold Quote objects but put
// Bulk_quote objects into that vector. Compute the total net_price of all
// the elements in the vector.
int exercise15_28();
// Exercise 15.29: Repeat your program, but this time store shared_ptrs to
// objects of type Quote. Explain any discrepancy in the sum generated by the
// this version and the previous program. If there is no discrepancy, explain why
// there isn’t one.
int exercise15_29();
// Exercises Section 15.8.1
// Exercise 15.30: Write your own version of the Basket class and use it to
// compute prices for the same transactions as you used in the previous
// exercises.
int exercise15_30();
// Exercises Section 15.9.1
// Exercise 15.31: Given that s1, s2, s3, and s4 are all strings, determine
// what objects are created in the following expressions:
// (a) Query(s1) | Query(s2) & ~ Query(s3);
// (b) Query(s1) | (Query(s2) & ~ Query(s3));
// (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
int exercise15_31();
// Exercises Section 15.9.2
// Exercise 15.32: What happens when an object of type Query is copied,
// moved, assigned, and destroyed?
int exercise15_32();
// Exercise 15.33: What about objects of type Query_base?
int exercise15_33();
// Exercises Section 15.9.3
// Exercise 15.34: For the expression built in Figure 15.3 (p. 638):
// (a) List the constructors executed in processing that expression.
// (b) List the calls to rep that are made from cout << q.
// (c) List the calls to eval made from q.eval().
int exercise15_34();
// Exercise 15.35: Implement the Query and Query_base classes, including
// a definition of rep but omitting the definition of eval.
int exercise15_35();
// Exercise 15.36: Put print statements in the constructors and rep members
// and run your code to check your answers to (a) and (b) from the first
// exercise.
int exercise15_36();
// Exercise 15.37: What changes would your classes need if the derived
// classes had members of type shared_ptr<Query_base> rather than of type Query?
int exercise15_37();
// Exercise 15.38: Are the following declarations legal? If not, why not? If so,
// explain what the declarations mean.
// BinaryQuery a = Query("fiery") & Query("bird");
// AndQuery b = Query("fiery") & Query("bird");
// OrQuery c = Query("fiery") & Query("bird");
int exercise15_38();
// Exercises Section 15.9.4
// Exercise 15.39: Implement the Query and Query_base classes. Test your
// application by evaluating and printing a query such as the one in Figure 15.3
// (p. 638).
int exercise15_39();
// Exercise 15.40: In the OrQuery eval function what would happen if its
// rhs member returned an empty set? What if its lhs member did so? What if
// both rhs and lhs returned empty sets?
int exercise15_40();
// Exercise 15.41: Reimplement your classes to use built-in pointers to
// Query_base rather than shared_ptrs. Remember that your classes will no
// longer be able to use the synthesized copy-control members.
int exercise15_41();
// Exercise 15.42: Design and implement one of the following enhancements:
// (a) Print words only once per sentence rather than once per line.
// (b) Introduce a history system in which the user can refer to a previous
// query by number, possibly adding to it or combining it with another.
// (c) Allow the user to limit the results so that only matches in a given range
// of lines are displayed.
int exercise15_42();

#endif