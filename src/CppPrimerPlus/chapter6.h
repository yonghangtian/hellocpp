#ifndef _COORDIN_H
    #define _COORDIN_H
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <array>
    #include <cctype>
    using namespace std;
#endif

#include <fstream>          // file I/O support
#include <cstdlib>          // support for exit()

const int strsize = 20;

int chapter6_1();
int chapter6_2();
int chapter6_3();
int chapter6_4();
int chapter6_5();
int chapter6_6();
int chapter6_7();
int chapter6_8();
int chapter6_9();

// Benevolent Order of Programmers name structure
struct bop {
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // 0 = fullname, 1 = title, 2 = bopname
};


struct donation {
    string fullname;  // real name
    double amount; //amount of donation
};