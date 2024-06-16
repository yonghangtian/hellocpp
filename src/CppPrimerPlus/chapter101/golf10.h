// golf.h -- for pe10-1.cpp
#include <cstring>
#include <iostream>


class Golf {
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;

public:
    Golf();  // #1
    // #2 带默认参数的构造函数不能将所有变量都设置默认函数，否则会被编译器告警，认为这个构造函数也是默认构造函数
    // 比如：Golf(const char * fn = "tian", const int hc = 1); 
    Golf(const char * fn, const int hc = 1); 
    // non-interactive version:
    // function sets golf structure to provided name, handicap
    // using values passed as arguments to the function
    void setGolf(const char * name, int hc);
    // interactive version:
    // function solicits name and handicap from user
    // and sets the members of g to the values entered
    // returns 1 if name is entered, 0 if name is empty string
    int setGolf();

    // copy value from another golf object 
    int setGolf(Golf & anotherGolf);
    // function resets handicap to new value
    void resetHandicap(int hc);
    // function displays contents of golf structure
    void showgolf() const;
};