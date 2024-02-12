#include "chapter3.h"

int exercise3_2()
{
    string a;
    cout << "Please input strings by line: (Press Ctrl + D to input EOF signal.)" << endl;
    while (getline(cin, a))
    {
        cout << a << endl;
    }

    return 0;
}

int exercise3_3()
{
    string a;
    cout << "Please input strings line by line: (cin will refresh once Enter, Press Ctrl + D to input EOF signal.)" << endl;
    while (cin >> a)
    {
        cout << a << endl;
    }

    return 0;
}

int exercise3_4()
{
    string a("Hello World!!"), b("Hillo!");
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "Let's compare two string using string's < operator :" << endl;

    if (a < b)
    {
        cout << "b is larger" << endl;
    }
    else if (a == b)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a is larger" << endl;
    }

    decltype(a.size()) lena = a.size(), lenb = b.size();
    cout << "Let's compare two string using string's size() function :" << endl;

    if (lena < lenb)
    {
        cout << "b is larger" << endl;
    }
    else if (lena == lenb)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a is larger" << endl;
    }

    return 0;
}

int exercise3_5()
{
    string result;
    cout << "Please input 5 lines:" << endl;
    for (int i = 0; i < 5; i++)
    {
        string temp;
        if (getline(cin, temp))
        {
            temp += " ";
            result += temp;
        }
        else
        {
            break;
        }
    }

    cout << result << endl;

    return 0;
}

int exercise3_6()
{
    string temp;
    if (getline(cin, temp))
    {
        for (auto &a : temp)
        {
            a = 'X';
        }
        cout << temp << endl;
    }

    return 0;
}

int exercise3_7()
{
    string temp;
    if (getline(cin, temp))
    {
        for (char &a : temp)
        {
            a = 'X';
        }
        cout << temp << endl;
    }

    return 0;
}

int exercise3_8()
{

    string temp;
    if (getline(cin, temp))
    {
        string temp1(temp), temp2(temp), temp3(temp);
        cout << "using range for loop:" << endl;
        for (auto &a : temp1)
        {
            a = 'X';
        }
        cout << temp1 << endl;

        cout << "using while loop:" << endl;
        decltype(temp2.size()) b = 0;
        while (b < temp2.size())
        {
            temp2[b] = 'X';
            ++b;
        }
        cout << temp2 << endl;

        cout << "using trational for loop:" << endl;
        for (decltype(temp3.size()) c = 0; c < temp3.size(); ++c)
        {
            temp3[c] = 'X';
        }
        cout << temp3 << endl;
    }

    return 0;
}

int exercise3_9()
{
    string s;
    // get empty.
    cout << s[0] << endl;
    return 0;
}

int exercise3_10()
{
    string temp;
    cout << "去除字符" << endl;
    if (getline(cin, temp))
    {
        string temp1;
        for (auto &a : temp)
        {
            if (!ispunct(a))
            {
                temp1 += a;
            }
        }
        cout << temp1 << endl;
    }
    return 0;
}

int exercise3_11()
{
    const string s = "Keep out!";
    for (auto &c : s)
    {
        // c = 'X'; // c is const char reference, is low-level const
    }

    return 0;
}

int exercise3_12()
{
    vector<vector<int>> ivec;
    // vector<string> svec = ivec;
    vector<string> svec(10, "null");
    return 0;
}

int exercise3_13()
{
    vector<int> v1;     // default init
    vector<int> v2(10); // 10 elements, value is default int(0)
    cout << "v2:    ";
    rangeForVector(v2);
    vector<int> v3(10, 42); // 10 elements, value is 42
    cout << "v3:    ";
    rangeForVector(v3);
    vector<int> v4{10}; // 1 element, value is 10
    cout << "v4:    ";
    rangeForVector(v4);
    vector<int> v5{10, 42}; // 2 elements, 10 and 42
    cout << "v5:    ";
    rangeForVector(v5);
    vector<string> v6{10}; // 10 elements, value is default string
    cout << "v6:    ";
    rangeForVector(v6);
    vector<string> v7{10, "hi"}; // 10 elements with same value, value is "hi"
    cout << "v7:    ";
    rangeForVector(v7);
    return 0;
}

int exercise3_14()
{
    int a, b;
    vector<int> c;
    cout << "Please input ints as many as you want. Input any char to terminate." << endl;
    while (cin >> a)
    {
        c.push_back(a);
    }

    rangeForVector(c);

    return 0;
}

int exercise3_15()
{
    string a;
    vector<string> c;
    // Linux 中 ctrl + d：输入EOF信号 ； ctrl + z ：将前台程序转为后台并停止，使用jobs命令查看后台暂停的程序，然后使用“fg 序号”将命令带到前台继续执行
    cout << "Please input string as many as you want. (Press Ctrl + D to input EOF signal.)" << endl;
    while (getline(cin, a))
    {
        c.push_back(a);
    }

    rangeForVector(c);

    return 0;
}

int exercise3_16()
{

    return 0;
}

int exercise3_17()
{
    vector<string> a;
    string b;

    cout << "Please input string as many as you want. (Press Ctrl + D to input EOF signal.)" << endl;
    while (getline(cin, b))
    {
        a.push_back(b);
    }
    rangeForVector(a);

    for (auto &c : a)
    {
        for (auto &d : c)
        {
            d = toupper(d);
        }
    }

    rangeForVector(a);

    return 0;
}

int exercise3_18()
{

    vector<int> ivec;
    ivec.push_back(1);
    rangeForVector(ivec);
    ivec[0] = 42;
    rangeForVector(ivec);

    return 0;
}

int exercise3_19()
{
    // method 1
    vector<int> ivec(10, 42);
    rangeForVector(ivec);

    // method 2
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    cout << ivec2.size() << endl;
    rangeForVector(ivec2);

    // method 3 is preferred as expands element in vector is faster
    vector<int> ivec3;
    for (int i = 0; i < 10; ++i)
    {
        ivec3.push_back(42);
    }
    rangeForVector(ivec3);
    // method4
    vector<int> ivec4(10);
    for (int j = 0; j < 10; ++j)
    {
        ivec4[j] = 42;
    }
    rangeForVector(ivec4);
    // method5
    vector<int> ivec5(10);
    for (auto &k : ivec5)
    {
        k = 42;
    }
    rangeForVector(ivec5);

    return 0;
}

int exercise3_20()
{
    const int k = 21;
    vector<int> ivec1(k);
    for (int j = 0; j < k; ++j)
    {
        ivec1[j] = j;
    }
    rangeForVector(ivec1);

    vector<int> ivec2;
    for (auto i = 1; i < k; ++i)
    {
        ivec2.push_back(ivec1[i - 1] + ivec1[i]);
    }
    cout << ivec2.size() << endl;
    rangeForVector(ivec2);

    vector<int> ivec3;
    for (auto j = 0; j < (k / 2 + 1); ++j)
    {
        ivec3.push_back(ivec1[j] + ivec1[k - 1 - j]);
    }
    cout << ivec3.size() << endl;
    rangeForVector(ivec3);

    return 0;
}

int exercise3_21()
{
    return 0;
}

int exercise3_22()
{
    vector<string> text;
    text.push_back("say we have some line of text, and all words in the first line are lowercase.");
    text.push_back("");
    text.push_back("THE THIRD LINE IS UPPERCASE!!!!");

    cout << "Before:" << endl;
    rangeForVector(text);

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            *it2 = toupper(*it2);
        }
    }

    cout << "After:" << endl;
    rangeForVector(text);

    return 0;
}

int exercise3_23()
{
    vector<int> a(10, 4);

    cout << "Before:" << endl;
    rangeForVector(a);

    for (auto it = a.begin(); it != a.end(); ++it)
    {
        (*it) *= (*it);
    }

    cout << "After:" << endl;
    rangeForVector(a);

    return 0;
}

int exercise3_24()
{
    const int k = 21;
    int i = 0;
    vector<int> ivec1(k);

    for (auto it = ivec1.begin(); it != ivec1.end(); ++it)
    {
        (*it) = ++i;
    }
    cout << "Before:" << endl;
    rangeForVector(ivec1);

    cout << "Add n and n+1:" << endl;
    for (auto it1 = ivec1.begin(); it1 < ivec1.end() - 1; ++it1)
    {
        cout << (*it1) + (*(it1 + 1)) << ",";
    }
    cout << endl;

    cout << "Add first and last, second and secondtolast:" << endl;
    for (auto it2 = ivec1.begin(); it2 < ivec1.begin() + ((ivec1.end() - ivec1.begin()) / 2 + 1); ++it2)
    {
        cout << (*it2) + (*(ivec1.begin() + ((ivec1.end() - it2) - 1))) << ",";
    }
    cout << endl;

    cout << ivec1.end() - ivec1.begin();

    return 0;
}

int exercise3_25()
{
    vector<unsigned> grades{9, 11, 22, 33, 44, 55, 66, 67, 88, 90, 99, 100};
    vector<unsigned> alt_scores(11, 0); // 11 buckets, all initially 0

    // for each grade in the input
    for (auto it = grades.begin(); it != grades.end(); ++it)
    {
        unsigned i = *it;
        // increment the counter for the current cluster
        ++(*(alt_scores.begin() + i / 10));
    }

    cout << "alt_scores.size = " << alt_scores.size() << endl;
    for (auto it = alt_scores.begin(); it != alt_scores.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}

int exercise3_26()
{
    return 0;
}

int exercise3_34()
{
    int arr[10];

    for (auto i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        arr[i] = i;
        cout << i << " : " << arr[i] << endl;
    }

    int *p1 = &arr[1];
    int *p2 = &arr[5];

    cout << "P1: " << *p1 << endl;
    cout << "P2: " << *p2 << endl;

    p1 += p2 - p1;

    cout << "after: ";
    cout << "P1: " << *p1 << endl;
    cout << "P2: " << *p2 << endl;

    // iterate an array using stl function
    int *st = begin(arr);
    int *ed = end(arr);

    for (auto temp = st; temp != ed; ++temp)
    {
        cout << *temp << endl;
    }

    return 0;
}

int exercise3_41()
{
    int arr[10];

    for (auto i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        arr[i] = i;
        cout << i << " : " << arr[i] << endl;
    }

    int *st = begin(arr);
    int *ed = end(arr);

    vector<int> tar(st, ed);

    rangeForVector(tar);

    return 0;
}

int exercise3_42()
{

    const int k = 21;
    int i = 0;
    vector<int> ivec1(k);

    for (auto it = ivec1.begin(); it != ivec1.end(); ++it)
    {
        (*it) = ++i;
    }
    rangeForVector(ivec1);

    // method 1: stl copy method
    int arr[k];
    std::copy(ivec1.begin(), ivec1.end(), arr);
    for (auto n : arr)
    {
        cout << n << ", ";
    }
    cout << endl;

    int arr1[k];
    int * st = begin(arr1);
    for (auto a = ivec1.begin(); a != ivec1.end(); ++a)
    {
        //  in vector's definition     typedef ptrdiff_t					difference_type;
        //  a - ivec1.begin() 's type is difference_type
        //  st is a pointer to the start of arr1
        // st add ptrdiff_t is legal the result is inside [ begin(arr1), end(arr1) ), otherwise, it's illegal.
        *(st + (a - ivec1.begin())) = *a;
    }

    for (auto n : arr1)
    {
        cout << n << ", ";
    }
    cout << endl;

    return 0;
}