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
protected:
    int prot_mem = 2; // protected member
private:
    int priv_mem = 3; // private member
};

class Pub_Derv : public Base // (The derivation access specifier has no effect on whether members (and friends) of a derived class may access the members of its own direct base class.)
{
public:
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
    // ok: base class public member still public in public derv
    int g() { return pub_mem; }
    // ok: base class protected member still protected in public derv
    int h() { return prot_mem; }
};

class Derived_from_Prot : public Prot_Derv
{
public:
    // ok: base class public member become protected in protected derv, 
    int g() { return pub_mem; }
     // ok: base class protected member still protected in protected derv
    int h() { return prot_mem; }
};

class Derived_from_Priv : public Priv_Derv
{
public:
    // error: base class public member become private in private derv
    // complier error: member "Base::pub_mem" (declared at line 36) is inaccessible
    // int g() { return pub_mem; }
    // error: base class public member become private in private derv
    // complier error: member "Base::prot_mem" (declared at line 38) is inaccessible
    // int h() { return prot_mem; }
};

int testAccessControl();
int exercise15_1();
int exercise15_2();
int exercise15_3();
int exercise15_4();
int exercise15_5();
int exercise15_6();
int exercise15_7();
int exercise15_8();
int exercise15_9();
int exercise15_10();
int exercise15_11();
int exercise15_12();
int exercise15_13();
int exercise15_14();
int exercise15_15();
int exercise15_16();
int exercise15_17();
int exercise15_18();
int exercise15_19();
int exercise15_20();
int exercise15_21();
int exercise15_22();
int exercise15_23();
int exercise15_24();
int exercise15_25();
int exercise15_26();
int exercise15_27();
int exercise15_28();
int exercise15_29();
int exercise15_30();
int exercise15_31();
int exercise15_32();
int exercise15_33();
int exercise15_34();
int exercise15_35();
int exercise15_36();
int exercise15_37();
int exercise15_38();
int exercise15_39();
int exercise15_40();
int exercise15_41();
int exercise15_42();

#endif