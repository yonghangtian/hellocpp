#include "chapter18.h"

double up(double x) { return 2.0 * x; }
void r1(const double &rx) { cout << "const double & rx\n"; }
void r2(double &rx) { cout << "double &rx \n"; }
void r3(double &&rx) { cout << "double && rx\n"; }
int review_1()
{
    double w = 10.0;
    r1(w);
    r2(w);
    r1(w + 1);
    r1(up(w));
    // r2(w+1); // error: cannot bind non-const lvalue reference of type ‘double&’ to an rvalue of type ‘double’
    // r2(up(w)); // error: cannot bind non-const lvalue reference of type ‘double&’ to an rvalue of type ‘double’
    // r3(w); // error: cannot bind rvalue reference of type ‘double&&’ to lvalue of type ‘double’
    r3(w + 1);
    r3(up(w));
    return 0;
}

template <typename T>
void sum(std::array<double, 5> a, T &fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
    {
        fp(*pt);
    }
}

int review_2()
{
    double total = 0.0;
    auto adder = [&total](int a)
    { total += a; };
    std::array<double, 5> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    // std::for_each(temp_c.begin(), temp_c.end(), adder);
    sum(temp_c, adder);
    std::cout << "total: " << total << '\n';
    return 0;
}

template <typename T>
T average_list(std::initializer_list<T> ilist)
{
    T total = 0;
    for (const T &val : ilist)
    {
        total += val;
    }
    return total / ilist.size();
}

int chapter18_1()
{
    // list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;

    // list of int deduced from list contents
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;

    // forced list of double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}

int chapter18_2()
{

    Cpmv a("q1", "z1");
    Cpmv b("q2", "z2");

    Cpmv c = a + b;
    c.Display();
    c.ShowObject();

    Cpmv d;
    d = std::move(c); // Move assignment
    d.Display();
    d.ShowObject();

    Cpmv e(std::move(d)); // Move constructor
    e.Display();
    e.ShowObject();

    return 0;
}

// Base case: when there are no more arguments to add
long double sum_values() {
    return 0.0;
}

// Recursive case: add the current argument to the sum of the rest
template <typename T, typename... Rest>
long double sum_values(T val, Rest... rest) {
    return static_cast<long double>(val) + sum_values(rest...);
}

int chapter18_3() {
    // Test the sum_values function with various types of arguments
    int a = 5;
    double b = 3.14159;
    float c = 2.71828;
    
    long double result = sum_values(a, b, c, 10, 20.5);
    
    std::cout << "Sum of values: " << result << std::endl;
    
    return 0;
}

// 没有找到对应的这个程序清单16.5哎。。。。可能题目都有问题
int chapter18_4() { return 0; }

// 20230912 我终于把CppPrimerPlus给做完了！！！！奖励自己的TUDOR 1926 36mm白盘哈哈哈