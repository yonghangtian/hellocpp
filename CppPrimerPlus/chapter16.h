#ifndef _COORDIN_H
#define _COORDIN_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype> // For std::toupper
#include <string>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <queue>
#include <list>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::ios_base;
#endif

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

struct Review {
    std::string title;
    int rating;
    double price;
};

int chapter16_1();
int chapter16_2();
int chapter16_3();
int chapter16_4();
int chapter16_5();
int chapter16_6();
int chapter16_7();
int chapter16_8();
int chapter16_9();
int chapter16_10();