#include "chapter6.h"

int absInt(int a)
{
    return abs(a);
}

int exercise6_5()
{
    int b = 0;
    cout << "Please input an integer:" << endl;
    cin >> b;
    cout << "current value is: " << b << endl;

    b = abs(b);

    cout << "abs is: " << b << endl;

    return 0;
}

size_t count_calls(int b)
{
    size_t a = 10;
    cout << "local variable: " << a << endl;
    cout << "parameter: " << b << endl;
    cout << "static variable: ";
    static size_t ctr = 0; // value will persist across calls
    return ++ctr;
}

int exercise6_6()
{
    for (int d = 0; d != 10; ++d)
    {
        cout << count_calls(d) << endl;
    }

    return 0;
}

size_t count_calls_zero()
{
    static size_t ctr = 0;
    return ctr++;
}

int exercise6_7()
{
    for (int d = 0; d != 10; ++d)
    {
        cout << count_calls_zero();
    }

    return 0;
}
int exercise6_8() { return 0; }

int exercise6_9() { return 0; }

void swapIntPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int exercise6_10()
{
    int c = 3, d = 5;
    cout << "Before C: " << c << " D: " << d << endl;
    swapIntPointer(&c, &d);
    cout << "After C: " << c << " D: " << d << endl;
    return 0;
}

void resetInt(int &a)
{
    a = 10000;
}

int exercise6_11()
{

    int a = 2;
    cout << a << endl;
    resetInt(a);
    cout << "Reset: " << a << endl;

    return 0;
}

void swapIntRef(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int exercise6_12()
{

    int c = 3, d = 5;
    cout << "Before C: " << c << " D: " << d << endl;
    swapIntRef(c, d);
    cout << "After C: " << c << " D: " << d << endl;
    return 0;
}

void increateInt(int a)
{
    ++a;
}

void increateIntRef(int &a)
{
    ++a;
}

int exercise6_13()
{
    int b = 10;
    cout << "Before: " << b << endl;
    increateInt(b);
    cout << "increateInt: " << b << endl;
    increateIntRef(b);
    cout << "increateIntRef: " << b << endl;

    return 0;
}
int exercise6_14() { return 0; }
int exercise6_15() { return 0; }

bool is_empty(const string &s) { return s.empty(); }

int exercise6_16()
{

    string a("abc");
    const string b("abcd");

    cout << is_empty(a) << endl;
    cout << is_empty(b) << endl;

    return 0;
}

bool findCapLetter(const string &s)
{
    auto bIt = s.begin(), eIt = s.end();

    while (bIt != eIt)
    {
        if (isupper(*bIt++))
            return true;
    }

    return false;
}

void convertToLower(string &s)
{
    auto bIt = s.begin(), eIt = s.end();

    while (bIt != eIt)
    {
        *bIt = tolower(*bIt);
        ++bIt;
    }
}

int exercise6_17()
{

    string a("abcdeFj");

    cout << a << " is there uppper case char ? " << findCapLetter(a) << endl;

    convertToLower(a);
    cout << "convert to lower case: " << a << endl;

    return 0;
}
int exercise6_18() { return 0; }
int exercise6_19() { return 0; }
int exercise6_20() { return 0; }

int largerInt(int a, const int *const b)
{
    return (a <= *b) ? *b : a;
}

int exercise6_21()
{
    int c = 9, d = 10;

    cout << largerInt(c, &d) << endl;

    return 0;
}

void swapPointers(int *&ptr1, int *&ptr2)
{
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int exercise6_22()
{
    int a = 5;
    int b = 10;
    int *ptr1 = &a;
    int *ptr2 = &b;

    std::cout << "Before swapping:" << std::endl;
    std::cout << "ptr1 points to: " << *ptr1 << std::endl;
    std::cout << "ptr2 points to: " << *ptr2 << std::endl;

    swapPointers(ptr1, ptr2);

    std::cout << "After swapping:" << std::endl;
    std::cout << "ptr1 points to: " << *ptr1 << std::endl;
    std::cout << "ptr2 points to: " << *ptr2 << std::endl;

    return 0;
}

// more print func in CppPrimer5thEdtion/examples/6/printFcns.h
void print(const int (&a)[2])
{
    for (auto item : a)
    {
        cout << item << endl;
    }
}

void print(const int a)
{
    cout << a << endl;
}

int exercise6_23()
{
    int i = 1, j[2] = {3, 4};
    print(i);
    print(j);
    return 0;
}

void print(const int (&a)[10])
{
    for (size_t i = 0; i != 10; ++i)
    {
        cout << a[i] << endl;
    }
}

int exercise6_24()
{
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(b);
    return 0;
}

int exercise6_25(int argc, char **argv)
{

    string a;

    for (size_t i = 1; i < argc; ++i)
    {
        a += argv[i];
    }

    cout << a << endl;

    return 0;
}
int exercise6_26(int argc, char **argv)
{

    for (size_t i = 1; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }

    return 0;
}

size_t sumOfInputs(std::initializer_list<size_t> params)
{

    size_t sum = 0;
    for (auto param : params)
    {
        sum += param;
    }
    return sum;
}

int exercise6_27()
{
    cout << sumOfInputs({6, 20, 100}) << endl;
    return 0;
}

void error_msg(string e, std::initializer_list<string> il)
{
    cout << e << ": ";
    for (const string &elem : il)
        cout << elem << " ";
    cout << endl;
}

int exercise6_28()
{

    string err("this is an error!");
    error_msg(err, {"haha", "I'm ", "kidding!"});
    return 0;
}

int exercise6_29() { return 0; }

bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2; // ok: == returns bool
    // find the size of the smaller string; conditional operator, see § 4.7 (p. 151)

    auto size = (str1.size() < str2.size())
                    ? str1.size()
                    : str2.size();
    // look at each element up to the size of the smaller string

    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return false; // error #1: no return value; compiler should detect this error
    }
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error
    return false; // tian: my complier doesnt get this missing return.
}

int exercise6_30()
{
    string s1("this"), s2("is");
    cout << str_subrange(s1, s2) << endl;

    return 0;
}

int exercise6_31() { return 0; }

int &get(int *arry, int index) { return arry[index]; }

int exercise6_32()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;

    auto bIt = std::begin(ia), eIt = std::end(ia);
    while (bIt != eIt)
    {
        cout << *bIt++;
    }

    return 0;
}

bool recursivePrintVector(vector<size_t> a)
{
    static auto bIt = a.begin();
    static auto eIt = a.end();

    if (bIt == eIt)
        return false;

    cout << *bIt++;

    return true;
}

int exercise6_33()
{
    vector<size_t> arr{0, 12, 34, 5, 6, 100, 9999};

    while (recursivePrintVector(arr))
        cout << endl;

    return 0;
}

// recursive version of factorial:
// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val != 0)
        return factorial(val - 1) * val;
    return 1;
}

int exercise6_34()
{
    cout << factorial(0) << endl;
    cout << factorial(1) << endl;
    cout << factorial(2) << endl;
    return 0;
}

int exercise6_35() { return 0; }

string (&arrFunc(string str))[10]
{
    // must be static!!!!!
    static string resultA[10];
    for (int i = 0; i != 10; ++i)
    {
        string temp(str);
        for (int j = 0; j != i; ++j)
        {
            temp += str;
        }
        resultA[i] = temp;
    }
    return resultA;
}

auto arrFunc2(string str) -> string (&)[10]
{
    // must be static!!!!!
    static string resultB[10];
    for (int i = 0; i != 10; ++i)
    {
        string temp(str);
        for (int j = 0; j != i; ++j)
            temp += str;

        resultB[i] = temp;
    }

    return resultB;
}

decltype(result) &arrFunc3(string str)
{
    // must be static!!!!!
    static string resultC[10];
    for (int i = 0; i != 10; ++i)
    {
        string temp(str);
        for (int j = 0; j != i; ++j)
            temp += str;

        resultC[i] = temp;
    }

    return resultC;
}

arrT &arrFunc4(string str)
{
    // must be static!!!!!
    static string resultD[10];
    for (int i = 0; i != 10; ++i)
    {
        string temp(str);
        for (int j = 0; j != i; ++j)
            temp += str;

        resultD[i] = temp;
    }

    return resultD;
}

int exercise6_36()
{
    string str1("a ");
    string(&arr)[10] = arrFunc(str1);

    for (int i = 0; i != 10; ++i)
        cout << arr[i] << endl;

    return 0;
}
int exercise6_37()
{
    string str2("b "), str3("c "), str4("d ");
    string(&arr2)[10] = arrFunc2(str2);
    string(&arr3)[10] = arrFunc3(str3);
    string(&arr4)[10] = arrFunc4(str4);

    for (int i = 0; i != 10; ++i)
        cout << arr2[i] << endl;

    for (int i = 0; i != 10; ++i)
        cout << arr3[i] << endl;

    for (int i = 0; i != 10; ++i)
        cout << arr4[i] << endl;

    return 0;
}

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
// returns a reference to an array of five int elements
int (&arrRef(int i))[5]
{
    return (i % 2) ? odd : even;
}

int exercise6_38()
{
    int(&arr)[5] = arrRef(10);
    for (int i = 0; i != 5; ++i)
        cout << arr[i] << endl;
    return 0;
}

int exercise6_39() { return 0; }
int exercise6_40() { return 0; }

const char *init(int ht, int wd, char bckgrnd)
{
    const char *start = "abc";

    cout << ht << endl;
    cout << wd << endl;
    cout << bckgrnd << endl;

    return start;
}

int exercise6_41()
{
    // init();  // invalid
    init(24, 10);
    init(14, '*');

    return 0;
}
int exercise6_42()
{

    cout << make_plural(10, "failure") << endl;
    cout << make_plural(10, "success") << endl;

    return 0;
}
int exercise6_43() { return 0; }
int exercise6_44()
{
    string s1("abc"), s2("abccd");
    cout << shorterString(s1, s2) << endl;
    return 0;
}

int exercise6_45() { return 0; }
int exercise6_46() { return 0; }

bool recursivePrintVectorWithDebug(vector<size_t> a)
{
    static auto bIt = a.begin();
    static auto eIt = a.end();
// defined NDEBUG in chapter6.h
#ifndef NDEBUG
    cout << "This is debug info: " << a.size() << endl;
#endif

    if (bIt == eIt)
        return false;

    cout << *bIt++;

    return true;
}

int exercise6_47()
{
    vector<size_t> arr{0, 12, 34, 5, 6, 100, 9999};

    while (recursivePrintVectorWithDebug(arr))
        cout << endl;

    return 0;
}

int exercise6_48()
{
    string s, sought("abc");
    while (cin >> s && s != sought)
    {
        assert(!cin);
        cout << s << endl;
    } // empty body

    return 0;
}
int exercise6_49() { return 0; }

void f() { cout << "f()" << endl; }
void f(int) { cout << "f(int)" << endl; }
void f(int, int) { cout << "f(int,int)" << endl; }
void f(double, double) { cout << "f(double,double)" << endl; }
int exercise6_50() { return 0; }

int exercise6_51()
{
    // f(2.56, 42); ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}

int sumOfInt(int a, int b)
{
    return a + b;
}

int exercise6_52()
{

    double a = 3.14;
    double val = 44.4;
    cout << sumOfInt(a, val) << endl;
    return 0;
}

int exercise6_53() { return 0; }

int addInt(int a, int b) { return a + b; }
int subtractInt(int a, int b) { return a - b; }
int multiplyInt(int a, int b) { return a * b; }
int divideInt(int a, int b)
{
    if (b == 0)
        return 0;
    return a / b;
}

int exercise6_54()
{
    using PF = int (*)(int, int);
    vector<PF> funcVector;

    funcVector.push_back(&addInt);
    funcVector.push_back(&subtractInt);
    funcVector.push_back(&multiplyInt);
    funcVector.push_back(&divideInt);

    int a = 4, b = 2;

    for (auto func : funcVector)
    {
        cout << (*func)(a, b) << endl;
    }

    return 0;
}
int exercise6_55()
{
    vector<int (*)(int, int)> funcVector;

    funcVector.push_back(&addInt);
    funcVector.push_back(&subtractInt);
    funcVector.push_back(&multiplyInt);
    funcVector.push_back(&divideInt);

    int a = 4, b = 2;

    for (auto func : funcVector)
    {
        cout << (*func)(a, b) << endl;
    }

    return 0;
}
int exercise6_56() { return 0; }
