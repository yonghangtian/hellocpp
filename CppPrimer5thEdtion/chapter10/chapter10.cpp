#include "chapter10.h"

int exercise10_1()
{
    vector<int> vint;

    int temp = 0, target = 10, count = 0;

    cout << "Target is " << target << endl;
    while (cin >> temp)
    {
        vint.push_back(temp);
    }
    rangeForVector(vint);

    auto a = find(vint.cbegin(), vint.cend(), target);

    cout << "The target" << (a == vint.cend() ? " is not present" : " is present") << endl;

    while (a != vint.cend())
    {
        if (count == 0)
        {
            ++count;
        }
        else
        {
            //  REMEMBER: find returns the iterator that match the target!!!!
            a = find(a + 1, vint.cend(), target);
            count += (a == vint.cend()) ? 0 : 1;
        }
    }

    cout << "The target appears " << count << " times." << endl;
    return 0;
}

int exercise10_2()
{

    vector<string> vstr;

    string temp, target = "target";
    int count = 0;

    cout << "Target is " << target << endl;
    while (getline(cin, temp))
    {
        vstr.push_back(temp);
    }
    rangeForVector(vstr);

    auto a = find(vstr.cbegin(), vstr.cend(), target);

    cout << "The target" << (a == vstr.cend() ? " is not present" : " is present") << " at position " << (a - vstr.cbegin()) << endl;

    while (a != vstr.cend())
    {
        if (count == 0)
        {
            ++count;
        }
        else
        {
            //  REMEMBER: find returns the iterator that match the target!!!!
            a = find(a + 1, vstr.cend(), target);
            count += (a == vstr.cend()) ? 0 : 1;
        }
    }

    cout << "The target appears " << count << " times." << endl;
    return 0;
}
int exercise10_3()
{
    vector<int> vint;

    int temp = 0, target = 0;
    while (cin >> temp)
    {
        vint.push_back(temp);
    }
    rangeForVector(vint);

    target = accumulate(vint.cbegin(), vint.cend(), target);

    cout << "Sum of this vector is " << target << endl;

    return 0;
}

int exercise10_4()
{

    vector<double> vd;

    double temp, target;
    while (cin >> temp)
    {
        vd.push_back(temp);
    }
    rangeForVector(vd);

    // Answer: 0 is not type of double, but maybe the compiler will do the implicit conversion.
    target = accumulate(vd.cbegin(), vd.cend(), 0);

    cout << "Sum of this vector is " << target << endl;

    return 0;
}

int exercise10_5()
{
    // vector<char *> roster1{"abc", "def", "xyz"};
    // vector<char *> roster2{"abc", "def", "xyz"};

    // 在C++中，std::equal算法是用来比较两个序列是否相等的。
    // 当你使用std::equal来比较两个std::vector<char*>时，它实际上是在比较两个序列中的每一对指针是否相等，而不是比较它们所指向的字符串内容是否相等。
    // 这里roster1和roster2是两个不同的std::vector对象，但它们包含了相同的字符串字面量的指针。
    // 在C++中，字符串字面量通常存储在程序的只读内存段中，并且相同的字符串字面量往往会被合并，使得多个相同的字符串字面量实际上指向内存中的同一个位置。这是一种称为字符串字面量池化的优化。

    // cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

    return 0;
}

int exercise10_6()
{
    vector<int> vint;

    int temp = 0, target = 0;
    while (cin >> temp)
    {
        vint.push_back(temp);
    }
    rangeForVector(vint);

    fill_n(vint.begin(), vint.size(), 0);

    rangeForVector(vint);

    return 0;
}
int exercise10_7()
{

    list<int> lst;
    int i;
    while (cin >> i)
    {
        lst.push_back(i);
    }
    vector<int> vec1(lst.size());
    copy(lst.cbegin(), lst.cend(), vec1.begin());
    rangeForVector(vec1);

    vector<int> vec2(10, 2);
    rangeForVector(vec2);
    fill_n(vec2.begin(), 10, 0);
    rangeForVector(vec2);
    return 0;
}

int exercise10_8()
{
    return 0;
}
int exercise10_9()
{
    return 0;
}
int exercise10_10()
{
    return 0;
}
int exercise10_11()
{
    return 0;
}
int exercise10_12()
{
    return 0;
}
int exercise10_13()
{
    return 0;
}
int exercise10_14()
{
    return 0;
}
int exercise10_15()
{
    return 0;
}
int exercise10_16()
{
    return 0;
}
int exercise10_17()
{
    return 0;
}
int exercise10_18()
{
    return 0;
}
int exercise10_19()
{
    return 0;
}
int exercise10_20()
{
    return 0;
}
int exercise10_21()
{
    return 0;
}
int exercise10_22()
{
    return 0;
}
int exercise10_23()
{
    return 0;
}
int exercise10_24()
{
    return 0;
}
int exercise10_25()
{
    return 0;
}
int exercise10_26()
{
    return 0;
}
int exercise10_27()
{
    return 0;
}
int exercise10_28()
{
    return 0;
}
int exercise10_29()
{
    return 0;
}
int exercise10_30()
{
    return 0;
}
int exercise10_31()
{
    return 0;
}
int exercise10_32()
{
    return 0;
}
int exercise10_33()
{
    return 0;
}
int exercise10_34()
{
    return 0;
}
int exercise10_35()
{
    return 0;
}
int exercise10_36()
{
    return 0;
}
int exercise10_37()
{
    return 0;
}
int exercise10_38()
{
    return 0;
}
int exercise10_39()
{
    return 0;
}
int exercise10_40()
{
    return 0;
}
int exercise10_41()
{
    return 0;
}
int exercise10_42()
{
    return 0;
}
