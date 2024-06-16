#ifndef _COORDIN_H
    #define _COORDIN_H
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <array>
    #include <cctype>
    #include <cstdlib>
    #include <ctime> 
    using std::cout;
    using std::cin;
    using std::ostream;
    using std::istream;
#endif

class Cow {
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const; // display all cow data
};



class String
{
private:
    char * str;             // pointer to string
    int len;                // length of string
    static int num_strings; // number of objects
    static const int CINLIM = 80;  // cin input limit
public:
// constructors and other methods
    String(const char * s); // constructor
    String();               // default constructor
    String(const String &); // copy constructor
    ~String();              // destructor
    int length () const { return len; }
    void stringlower();
    void stringupper();
    int has(const char a) const;
// overloaded operator methods    
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
// overloaded operator friends
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    // overloaded operator + friend
    friend String operator+(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
// static function
    static int HowMany();
};

class Stock
{
private:
    char * company;             // pointer to string
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const char * co, long n = 0, double pr = 0.0);
    ~Stock();       // destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price); 
    void show()const;
    const Stock & topval(const Stock & s) const;
    // friend method
    friend ostream & operator<<(ostream & os, const Stock & st);
};


// stack.h -- class declaration for the stack ADT
struct customer 
{
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Item * pitems;      // holds stack items
    int size;           // number of elements in stack
    int top;            // index for top stack item
public:
    Stack(int n = MAX); // creates stack with n elements
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
    Stack & operator=(const Stack & st);
};

// This queue will contain Customer2 items
class Customer2
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer2() : arrive(0), processtime (0){}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer2 Item2;

class Queue
{
private:
// class scope definitions
    // Node is a nested structure definition local to this class
    struct Node { Item2 item; struct Node * next;};
    enum {Q_SIZE = 10};
// private class members
    Node * front;       // pointer to front of Queue
    Node * rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue & q) : qsize(0) { }
    Queue & operator=(const Queue & q) { return *this;}
public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item2 &item); // add item to end
    bool dequeue(Item2 &item);       // remove item from front
};


int chapter12_1();
int chapter12_2();
int chapter12_3();
int chapter12_4();
int chapter12_5();
int chapter12_6();