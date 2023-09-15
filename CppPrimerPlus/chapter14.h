#ifndef _COORDIN_H
#define _COORDIN_H
#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <valarray>
#include <random>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::strcpy;
using std::string;
using std::strchr;
#endif

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}
template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{   
private:    
    string label;
    int years; 
    PairArray bottles;

public:
    Wine(const string lab, int yrs);
    Wine(const string lab, int yrs, const int * y, const int * b);
    void GetBottles();
    void Show();
    const string & Label() const;
    int sum();
};

class Wine2: private string, private PairArray
{   
private:
    int years;
public:
    Wine2(const char * lab, int yrs);
    Wine2(const char * lab, int yrs, const int * y, const int * b);
    void GetBottles();
    void Show();
    const string & Label() const;
    int sum();
};

class Worker   // an abstract base class
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string & s, long n)
            : fullname(s), id(n) {}
    virtual ~Worker() = 0; // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0)
            : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0)
            : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
enum {other, alto, contralto, soprano,
                    bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char *pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other)
            : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other)
            : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter()  {}
    SingingWaiter(const std::string & s, long n, int p = 0,
                            int v = other)
            : Worker(s,n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
            : Worker(wk), Waiter(wk,p), Singer(wk,v) {}
    SingingWaiter(const Waiter & wt, int v = other)
            : Worker(wt),Waiter(wt), Singer(wt,v) {}
    SingingWaiter(const Singer & wt, int p = 0)
            : Worker(wt),Waiter(wt,p), Singer(wt) {}
    void Set();
    void Show() const; 
};

template <class T>
class QueueTP
{
private:
// class scope definitions
    // Node is a nested class definition local to this class
    class Node {
    public:
        T item;
        Node* next;

        Node(const T& value) : item(value), next(nullptr) {}
    };
    enum {Q_SIZE = 10};
// private class members
    Node * front;       // pointer to front of QueueTP
    Node * rear;        // pointer to rear of QueueTP
    int items;          // current number of items in QueueTP
    const int qsize;    // maximum number of items in QueueTP
    // preemptive definitions to prevent public copying
    QueueTP(const QueueTP & q) : qsize(0) { }
    QueueTP & operator=(const QueueTP & q) { return *this;}
public:
    QueueTP(int qs = Q_SIZE); // create queue with a qs limit
    ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T &item); // add item to end
    bool dequeue(T &item);       // remove item from front
};

// QueueTP methods
template <class T>
QueueTP<T>::QueueTP(int qs) : qsize(qs)
{
    front = rear = nullptr;    // or nullptr
    items = 0;  
}

template <class T>
QueueTP<T>::~QueueTP()
{
    Node * temp;
    while (front != nullptr)   // while queue is not yet empty
    {
        temp = front;       // save address of front item
        front = front->next;// reset pointer to next item
        delete temp;        // delete former front
    }
}

template <class T>
bool QueueTP<T>::isempty() const
{
    return items == 0;
}

template <class T>
bool QueueTP<T>::isfull() const
{
    return items == qsize;
}

template <class T>
int QueueTP<T>::queuecount() const
{
    return items;
}

// Add item to queue
template <class T>
bool QueueTP<T>::enqueue(const T & item)
{
    if (isfull())
        return false;
    Node * add = new Node(item);  // create node
// on failure, new throws std::bad_alloc exception
    items++;
    if (front == nullptr)      // if queue is empty,
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear
    rear = add;             // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
template <class T>
bool QueueTP<T>::dequeue(T & item)
{
    if (front == nullptr)
        return false;
    item = front->item;     // set item to first item in queue
    items--;
    Node * temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item
    if (items == 0)
        rear = nullptr;
    return true;
}

class Person   // an abstract base class
{
private:
    string firstname;
    string lastname;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Person() : firstname("no one"), lastname("else") {}
    Person(const string & s1, const string & s2)
            : firstname(s1), lastname(s2) {}
    virtual ~Person() = 0; // pure virtual function
	virtual void Set() = 0;
    virtual void Show() const = 0;
};

class GunSlinger : virtual public Person
{
private:
    double shootTime;
	int notches;
protected:
    void Data() const;
    void Get();
public:
    GunSlinger() : Person(), shootTime(1.0), notches(0) {}
    GunSlinger(const string & s1, string & s2, double p = 1.0, int n = 0)
            : Person(s1, s2), shootTime(p), notches(n) {}
    GunSlinger(const Person & ps, double p = 1.0, int n = 0)
            : Person(ps), shootTime(p), notches(n) {}
    void Set();
	void Show() const;
    void Draw() const;
};

class PokerPlayer : virtual public Person
{
protected:
    int randomInt;
    void Data() const;
    void Get(){ randomInt = std::rand() % 52; };
public:
    PokerPlayer() : Person() {}
    PokerPlayer(const string & s1, string & s2)
            : Person(s1, s2) {}
    PokerPlayer(const Person & ps)
            : Person(ps) {}
    void Set();
    void Show() const;
	void Draw() const;
};

// multiple inheritance
class BadDude : public GunSlinger, public PokerPlayer
{
protected:
    void Data() const;
    void Get();
public:
	BadDude(){}
    BadDude(const string & s1, string & s2, double p = 1.0, int n = 0)
            : Person(s1, s2), GunSlinger(s1, s2, p, n), PokerPlayer(s1, s2) {}
    BadDude(const Person & ps, double p = 1.0, int n = 0)
            : Person(ps), GunSlinger(ps,p,n), PokerPlayer(ps) {}
    BadDude(const GunSlinger & gs)
            : Person(gs), GunSlinger(gs), PokerPlayer(gs) {}
    BadDude(const PokerPlayer & pp, double p = 1.0, int n = 0)
            : Person(pp), GunSlinger(pp,p,n), PokerPlayer(pp) {}
    void Set();
    void Show() const; 
	void Gdraw() const;
	void Cdraw() const;
};

class abstr_emp
{
private:
    std::string fname;   // abstr_emp's first name
    std::string lname;   // abstr_emp's last name
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln,
             const std::string & j);
    virtual void ShowAll() const; // labels and shows all data
    virtual void SetAll();        // prompts user for values
    friend std::ostream &
             operator<<(std::ostream & os, const abstr_emp & e);
    // just displays first and last name
    virtual ~abstr_emp();     // virtual base class
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
             const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager: virtual public abstr_emp
{
private:
    int inchargeof; // number of abstr_emps managed
protected:
    int InChargeOf() const { return inchargeof; } // output
    int & InChargeOf(){ return inchargeof; }      // input
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink: virtual public abstr_emp
{
private:
    std::string reportsto; // to whom fink reports
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo(){ return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink: public manager, public fink // management fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
};


int chapter14_1();
int chapter14_2();
int chapter14_3();
int chapter14_4();
int chapter14_5();