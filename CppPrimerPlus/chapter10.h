#ifndef _COORDIN_H
    #define _COORDIN_H
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <array>
    #include <cctype>
    using namespace std;
#endif

class Person {
    private:
        static const int LIMIT = 25;
        string lname;       // Person’s last name
        char fname[LIMIT];  // Person’s first name
    public:
        Person() {lname = ""; fname[0] = '\0'; }  // #1
        Person(const string & ln, const char * fn = "Heyyou");  // #2
        // the following methods display lname and fname
        void Show() const;        // firstname lastname format
        void FormalShow() const;  // lastname, firstname format
};

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
        Item items[MAX];    // holds stack items
        int top;            // index for top stack item
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        // push() returns false if stack already is full, true otherwise
        bool push(const Item & item);   // add item to stack
        // pop() returns false if stack already is empty, true otherwise
        bool pop(Item & item);          // pop top into item
};

class Move
{
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0); // sets x, y to a, b
        void showmove() const; // shows current x, y values
        Move add(const Move & m) const;
        // this function adds x of m to x of invoking object to get new x,
        // adds y of m to y of invoking object to get new y, creates a new
        // move object initialized to new x, y values and returns it
        void reset(double a = 0, double b = 0); // resets x,y to a, b
};

class Plorg
{
    private:
        enum {MAX = 20};
        char name[MAX];
        int ci;
    public:
        Plorg(){ci = 50; strncpy(name,"Plorga",MAX-1);}
        Plorg(const char * n, const int m = 50);
        void setPlorg(const char * n);
        void setCI(const int m);
        void showPlorg() const;
};

class ItemList {
    private:
        enum {MAX = 20};
        Item items[MAX];
        int count;

    public:
        ItemList();
        bool isEmpty() const;
        bool isFull() const;
        int itemCount() const;
        bool addItem(const Item & item);
        void visit(void (*pf)(Item &));
        void show() const;
};


// int chapter10_1();
int chapter10_2();
// int chapter10_3();
// int chapter10_4();
int chapter10_5();
int chapter10_6();
int chapter10_7();
int chapter10_8();
