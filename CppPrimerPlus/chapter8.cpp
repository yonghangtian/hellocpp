#include "chapter8.h"


// create a 
inline void print_str(const char * str, int n=1)
{ 
    while( *str != '\0')
    {
        cout << *str;
        str ++;
    }
    cout << "default value of N is " << n;
    cout << endl;
}

int chapter8_1()
{ 
    // 必须用双引号
    char stra[] = "This is a C type String";
    print_str(stra);

    print_str(stra);

    print_str(stra);
    
    return 0;
}

void modify_candybar(CandyBar & candy, const char * name = "Millennium Munch", const float weight = 2.85, const int calories = 350)
{
    strcpy(candy.fullname, name);
    candy.weight = weight;
    candy.calories = calories;
}

void show_candybar(const CandyBar & candy)
{
    cout << candy.fullname << endl;
    cout << candy.weight << endl;
    cout << candy.calories << endl;
}

// 使用结构体的引用调用
int chapter8_2()
{ 
    CandyBar candy = {"toffee", 20.23, 500};
    // 尝试使用默认值
    modify_candybar(candy);
    show_candybar(candy);

    modify_candybar(candy, "Super good", 1.0, 500);
    show_candybar(candy);
    return 0;
}

// 将String中的字母全部转换为大写
void uppercase_string(string & str)
{
    for (char & c : str) 
    {
        c = toupper(c);
    }
} 

int chapter8_3()
{ 
    string str = "this is a upper case string!";
    uppercase_string(str);
    cout << str << endl;
    return 0;
}

void set(stringy & beany, const char * cstring = "no input")
{
    int length = strlen(cstring);
    char * str = new char[length + 1];
    strcpy(str, cstring);
    beany.str = str;
    beany.ct = length;
}

void show (const stringy & beany, const int i = 1)
{
    for(int j = 0; j < i; j++)
    {
        cout << beany.str << ", " << beany.ct << endl;
    }
}

void show (const char * testing, const int i = 1)
{
    while (*testing != '\0')
    {
        cout << *testing;
        testing++;
    }
    cout << endl;
}

int chapter8_4()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing); // first argument is a reference,
        // allocates space to hold copy of testing,
        // sets str member of beany to point to the
        // new block, copies testing to new block,
        // and sets ct member of beany
    show(beany);      // prints member string once
    show(beany, 2);   // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);    // prints testing string once
    show(testing, 3); // prints testing string thrice
    show("Done!");
    return 0;
}


int chapter8_5()
{ 
    int a[5] = {1,2,3,5,4};
    double b[5] = {1.0, 2.0, 3.0, 5.8, 4.1};   

    cout << max5(a) << endl;
    cout << max5(b) << endl;

    return 0;
}


// 注意不要在T 前面再加const，否则会与下方的const char* 显式具体化冲突
template <typename T>
T maxn(T * arr, int size)
{   
    T max = arr[0];

    for (int i = 1; i < size; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

template <>
const char* maxn<const char*>(const char* arr[], int size)
{
    const char * max = arr[0];

    for (int i = 1; i < size; i++) {
        if(strlen(arr[i]) > strlen(max)){
            max = arr[i];
        }
    }

    return max;
}



int chapter8_6()
{ 
    int a[6] = {1,2,3,5,4,7};
    double b[5] = {1.0, 2.0, 3.0, 5.8, 4.1};   

    const char * arr[] = {"one","two","three","four","five"};

    cout << maxn(a, sizeof(a)/sizeof(int)) << endl;
    cout << maxn(b, sizeof(b)/sizeof(double)) << endl;
    //     cout << sizeof(a)/sizeof(int)<< endl;
    // cout << sizeof(b)/sizeof(double) << endl;
    cout << sizeof(arr[1]) << ", "<< sizeof(arr[2]) << endl;
    cout << maxn(arr, sizeof(arr)/sizeof(arr[0]));


    return 0;
}


template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
    cout << "template B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T total;
    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}

template <typename T>
T SumArray(T * arr[], int n)
{
    T total;
    for (int i = 0; i < n; i++)
        total += *arr[i];

    return total;
}

int chapter8_7()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];

    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    cout << "Listing Mr. E's counts of things:\n";
    ShowArray(things, 6);
    cout << "Total things:\n";
    cout << SumArray(things, 6) << endl;

    cout << "\nListing Mr. E's debts:\n";
    ShowArray(pd, 3);
    cout << "Total debts:\n";
    cout << SumArray(pd, 3) << endl;

    return 0;
}

