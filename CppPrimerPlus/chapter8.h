#ifndef _COORDIN_H
    #define _COORDIN_H
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <array>
    #include <cctype>
    using namespace std;
#endif

const int SLEN = 30;

int chapter8_1();
int chapter8_2();
int chapter8_3();
int chapter8_4();
int chapter8_5();
int chapter8_6();
int chapter8_7();


struct CandyBar {
    char fullname[SLEN];
    float weight;
    int calories;
};

struct stringy {
    char * str;     // points to a string
    int ct;         // length of string (not counting '\0')
};

template <typename T>
T max5(const T (&arr)[5])
{   
    T max = arr[0];

    for(int i = 1; i < 5; i ++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

// 注意不要在T 前面再加const，否则会与下方的const char* 显式具体化冲突
template <typename T>
T maxn(T* arr, int size = 1);

template <>
const char* maxn<const char*>(const char* arr[], int size);


struct debts
{
    char name[50];
    double amount;
};


template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T * arr[], int n);
