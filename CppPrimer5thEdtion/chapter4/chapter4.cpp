#include "chapter4.h"

int exercise4_1()
{
    int a = 9;
    int b = -9;

    int c = b >> 2;
    int d = a >> 2;

    return 0;
}

int exercise4_9()
{
    const char *cp = "Hello World";
    if (cp && *cp)
        cout << cp << endl;

    return 0;
}

int exercise4_10()
{
    int temp;

    while ((cin >> temp) && (temp != 42))
        ;

    cout << temp << endl;
    return 0;
}

int exercise4_11()
{
    int a, b, c, d;

    while (cin >> a >> b >> c >> d)
    {
        if ((a > b) && (b > c) && (c > d))
        {

            cout << "a: " << a << " is greater than "
                 << "b: " << b
                 << ", which is greater than c: " << c << " , which is greater than d: " << d << endl;
            break;
        }
        else
        {
            cout << "please ensures that a is greater than b, which is greater than c, which is greater than d." << endl;
        }
    }

    return 0;
}

int exercise4_12()
{
    int i, j, k;

    while (cin >> i >> j >> k)
    {
        bool temp = i != j < k;
        bool temp1 = (i != j) < k;
        bool temp2 = i != (j < k);

        cout << "i != j < k: " << temp << endl;
        cout << "(i != j) < k: " << temp1 << endl;
        cout << "i != (j < k): " << temp2 << endl;
    }

    // 1 2 3
    // i != j < k: 0
    // (i != j) < k: 1
    // i != (j < k): 0
    // 0 1 2
    // i != j < k: 1
    // (i != j) < k: 1
    // i != (j < k): 1
    // 1 1 2
    // i != j < k: 0
    // (i != j) < k: 1
    // i != (j < k): 0

    return 0;
}

int exercise4_21()
{
    vector<int> temp{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rangeForVector(temp);
    for (auto &a : temp)
    {
        a = (a % 2 == 1) ? a * a : a;
    }

    rangeForVector(temp);

    return 0;
}

int exercise4_22()
{
    vector<int> grades{59, 61, 76, 90, 91};

    rangeForVector(grades);
    // fully conditional operator
    for (const auto &grade : grades)
    {
        string finalgrade = (grade > 90)   ? "high pass"
                            : (grade > 75) ? "low pass"
                            : (grade > 60) ? "pass"
                                           : "fail";

        cout << grade << " : " << finalgrade << endl;
    }

    // fully if statement
    for (const auto &grade : grades)
    {
        string finalgrade;
        if (grade > 90)
        {
            finalgrade = "high pass";
        }
        else if (grade > 75)
        {
            finalgrade = "low pass";
        }
        else if (grade > 60)
        {
            finalgrade = "pass";
        }
        else
        {
            finalgrade = "fail";
        }
        cout << grade << " : " << finalgrade << endl;
    }

    // conditional operator is better.
    return 0;
}

int exercise4_23()
{
    string s = "word";
    string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
    cout << pl << endl;
    return 0;
}

int exercise4_24()
{
    // ((grade > 90)? "high pass": (grade > 60)) ? "pass": "fail";
    return 0;
}

int exercise4_25()
{
    char temp = 'q';

    std::bitset<32> bc(temp);
    // 00000000000000000000000001110001
    cout << bc << endl;
    auto result1 = (~temp) << 8;

    std::bitset<32> bt(result1);
    // 11111111111111111000111000000000
    cout << bt << endl;

    auto result2 = ~(temp << 8);

    std::bitset<32> bt2(result2);
    // 11111111111111111000111011111111
    cout << bt2 << endl;
    return 0;
}

int exercise4_27()
{
    unsigned long ul1 = 3, ul2 = 7;
    std::bitset<32> bul1(ul1);
    std::bitset<32> bul2(ul2);
    auto a = ul1 & ul2;
    std::bitset<32> ba(a);
    auto b = ul1 | ul2;
    std::bitset<32> bb(b);
    auto c = ul1 && ul2;
    std::bitset<32> bc(c);
    auto d = ul1 || ul2;
    std::bitset<32> bd(d);

    cout << "1: " << bul1 << endl;
    cout << "2: " << bul2 << endl;
    cout << "3: " << ba << endl;
    cout << "4: " << bb << endl;
    cout << "5: " << bc << endl;
    cout << "6: " << bd << endl;

    return 0;
}

int exercise4_28()
{
    std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of short int: " << sizeof(short int) << " bytes" << std::endl;
    std::cout << "Size of long int: " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "Size of long long int: " << sizeof(long long int) << " bytes" << std::endl;
    std::cout << "Size of unsigned char: " << sizeof(unsigned char) << " byte" << std::endl;
    std::cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "Size of unsigned short int: " << sizeof(unsigned short int) << " bytes" << std::endl;
    std::cout << "Size of unsigned long int: " << sizeof(unsigned long int) << " bytes" << std::endl;
    std::cout << "Size of unsigned long long int: " << sizeof(unsigned long long int) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " byte" << std::endl;
    std::cout << "Size of wchar_t: " << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "Size of char16_t: " << sizeof(char16_t) << " bytes" << std::endl;
    std::cout << "Size of char32_t: " << sizeof(char32_t) << " bytes" << std::endl;
    return 0;
}

int exercise4_29()
{
    int x[10] = {1, 1, 1, 1, 11, 1, 1, 11, 1, 1}; // x is a pointer point an int array
    int *p = x;                                   // p is a pointer point to x[10]'s first value.
    cout << sizeof(x) / sizeof(*x) << endl;       // should be 10
    cout << sizeof(p) / sizeof(*p) << endl;       // should be the length of a pointer devide the length of a int
    cout << sizeof(x) << " " << x << endl;
    cout << sizeof(*x) << " " << *x << endl;
    cout << sizeof(*p) << " " << *p << endl;
    cout << sizeof(p) << " " << p << endl;
    return 0;
}

int exercise4_30()
{
    int x = 0, y = 1;
    auto a = sizeof x + y;
    auto b = sizeof(x + y);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}

int exercise4_34()
{
    return 0;
}

int exercise4_35()
{
    return 0;
}

int exercise4_36()
{
    int i = 20;
    double d = 2.22;

    i *= static_cast<int>(d);

    cout << i << endl;
    return 0;
}

int exercise4_37()
{
    int i = 0;
    double d = 1.2;
    const string *ps;
    char *pc;
    void *pv;
    pv = static_cast<void *>(const_cast<std::string *>(ps));
    i = static_cast<int>(*pc);
    pv = &d;
    pc = static_cast<char *>(pv);
    
    return 0;
}

int exercise4_38()
{
    int j = 3, i = 2;

    double slope = static_cast<double>(j / i);

    cout << slope << endl;

    return 0;
}
