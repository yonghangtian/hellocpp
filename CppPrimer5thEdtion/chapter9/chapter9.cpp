#include "chapter9.h"

int exercise9_1() { return 0; }
int exercise9_2()
{
    deque<int> a{1, 2, 3, 4, 6, 5};
    list<deque<int>> b{a, {7, 9, 8}};

    // First method: range for
    cout << "// First method: range for" << endl;
    for (const auto &intDeque : b)
    {
        for (const auto &num : intDeque)
        {
            cout << num;
        }
        cout << endl;
    }

    // Second method: iterator
    cout << "// Second method: iterator" << endl;
    for (auto it1 = b.begin(); it1 != b.end(); ++it1)
    {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2)
        {
            cout << *it2;
        }
        cout << endl;
    }

    // Third method: range for and iterator
    cout << "// Third method: range for and iterator" << endl;
    for (const auto &intDeque : b)
    {
        for (auto it2 = intDeque.begin(); it2 != intDeque.end(); ++it2)
        {
            cout << *it2;
        }
        cout << endl;
    }

    return 0;
}

int exercise9_3()
{

    return 0;
}

bool findValInVector(vector<int>::iterator bi, vector<int>::iterator ei, int target)
{
    for (auto &start = bi; start != ei; ++start)
    {
        if (*start == target)
            return true;
    }

    return false;
}

int exercise9_4()
{

    vector<int> a{1, 2, 3, 4, 6, 5};
    cout << findValInVector(a.begin(), a.end(), 5) << endl;

    return 0;
}

vector<int>::iterator findInteratorInVector(vector<int>::iterator bi, vector<int>::iterator ei, int target)
{
    for (auto &start = bi; start != ei; ++start)
    {
        if (*start == target)
            return start;
    }

    return ei;
}

int exercise9_5()
{

    vector<int> a{1, 2, 3, 4, 6, 5};

    vector<int> b{5, 7};

    for (auto &num : b)
    {
        vector<int>::iterator result = findInteratorInVector(a.begin(), a.end(), num);
        if (result != a.end())
            cout << "Find num: " << num << endl;
        else
            cout << "No num: " << num << endl;
    }

    return 0;

    return 0;
}

int exercise9_6()
{
    list<int> lst1{3, 2, 1, 6, 5};
    list<int>::iterator iter1 = lst1.begin(),
                        iter2 = lst1.end();

    while (iter1 != iter2)
    {
        cout << *iter1 << endl;
        ++iter1;
    }

    return 0;
}

int exercise9_7()
{

    return 0;
}

int exercise9_8()
{
    list<string> lst1{"char", "string"};

    list<string>::value_type a = *(lst1.begin());

    cout << a << endl;

    lst1.push_back(a + "123");

    lst1.push_front("123456");

    for (const auto &val : lst1)
    {
        cout << val << endl;
    }

    return 0;
}
int exercise9_9() { return 0; }

int exercise9_10()
{
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin();

    auto it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();

    return 0;
}

int exercise9_11()
{
    vector<int> vec1{3, 2, 1, 6, 5};
    vector<int> vec2(10, 0);
    vector<int> vec3;
    vector<int> vec4(vec1.begin() + 1, vec1.begin() + 4);
    vector<int> vec5(vec1);
    vector<int> vec6(11);

    return 0;
}
int exercise9_12()
{

    list<int> lst1{3, 2, 1, 6, 5};

    vector<int> vec1(lst1.begin(), lst1.end());

    rangeForVector(vec1);

    list<int>::iterator start = lst1.begin();
    ++start;
    ++start;
    vector<int> vec2(start, lst1.end());
    rangeForVector(vec2);

    list<const char *> lst2{"abc", "def", "hqe"};

    vector<string> vec3(lst2.begin(), lst2.end());

    rangeForVector(vec3);

    return 0;
}

int exercise9_13()
{

    list<int> lst1{3, 2, 1, 6, 5};
    vector<int> vec1{1, 6, 5};

    vector<double> vec2(lst1.begin(), lst1.end());
    vector<double> vec3(vec1.begin(), vec1.end());

    rangeForVector(vec2);
    rangeForVector(vec3);

    return 0;
}

int exercise9_14()
{

    list<const char *> lst2{"abc", "def", "hqe"};

    vector<string> vec3(lst2.begin(), lst2.end());

    rangeForVector(vec3);

    return 0;
}

int exercise9_15()
{

    list<int> lst1{3, 2, 1, 6, 5};
    vector<int> vec1{1, 6, 5};

    vector<double> vec2(lst1.begin(), lst1.end());
    vector<double> vec3(vec1.begin(), vec1.end());

    cout << "vec2 == vec3? " << (vec2 == vec3) << endl;

    vector<double> vec4{1, 6, 7};

    cout << "vec3 < vec4? " << (vec3 < vec4) << endl;

    vector<double> vec5{1, 6, 5};
    cout << "vec5 == vec3? " << (vec5 == vec3) << endl;

    return 0;
}

int exercise9_16()
{

    list<int> lst1{3, 2, 1, 6, 5};
    vector<int> vec1{1, 6, 5};

    // no match for ‘operator==’ (operand types are ‘std::__cxx11::list<int>’ and ‘std::vector<int>’)
    // cout << "lst1 == vec1? " << (lst1 == vec1) << endl;

    return 0;
}

int exercise9_17() {
    
     return 0; }
int exercise9_18() { return 0; }
int exercise9_19() { return 0; }
int exercise9_20() { return 0; }
int exercise9_21() { return 0; }
int exercise9_22() { return 0; }
int exercise9_23() { return 0; }
int exercise9_24() { return 0; }
int exercise9_25() { return 0; }
int exercise9_26() { return 0; }
int exercise9_27() { return 0; }
int exercise9_28() { return 0; }
int exercise9_29() { return 0; }
int exercise9_30() { return 0; }
int exercise9_31() { return 0; }
int exercise9_32() { return 0; }
int exercise9_33() { return 0; }
int exercise9_34() { return 0; }
int exercise9_35() { return 0; }
int exercise9_36() { return 0; }
int exercise9_37() { return 0; }
int exercise9_38() { return 0; }
int exercise9_39() { return 0; }
int exercise9_40() { return 0; }
int exercise9_41() { return 0; }
int exercise9_42() { return 0; }
int exercise9_43() { return 0; }
int exercise9_44() { return 0; }
int exercise9_45() { return 0; }
int exercise9_46() { return 0; }
int exercise9_47() { return 0; }
int exercise9_48() { return 0; }
int exercise9_49() { return 0; }
int exercise9_50() { return 0; }
int exercise9_51() { return 0; }
int exercise9_52() { return 0; }
