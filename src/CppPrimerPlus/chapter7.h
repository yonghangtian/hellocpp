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

const int SLEN = 30;
const int Max = 10;
const int Seasons = 4;

int chapter7_1();
int chapter7_2();
int chapter7_3();
int chapter7_4();
int chapter7_5();
int chapter7_6();
int chapter7_7();
int chapter7_8_a();
int chapter7_8_b();
int chapter7_9();
int chapter7_10();


struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

struct season_expense {
    double s_expenses[Seasons];
};