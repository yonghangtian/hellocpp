#include "chapter10.h"
#include "../chapter7/chapter7.h"

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

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    cout << "After sort: " << endl;
    rangeForVector(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    // auto end_unique = unique(words.begin(), words.end());
    // cout << "After unique: " << endl;
    // rangeForVector(words);
    // erase non-unique elements
    // words.erase(end_unique, words.end());
}

int exercise10_9()
{
    vector<string> wds{"abc", "bcd", "def", "abc", "bcd", "def", "abc", "bcd", "def", "abc", "bcd", "def"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    elimDups(wds);

    cout << "After elimDups: " << endl;
    rangeForVector(wds);
    return 0;
}

int exercise10_10()
{
    return 0;
}

bool isShorter(const string &str1, const string &str2)
{
    return (str1.size() < str2.size()) ? true : false;
}

void elimDups_sort_shorter(vector<string> &words)
{
    sort(words.begin(), words.end(), isShorter);
    cout << "After sort shorter: " << endl;
    rangeForVector(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: " << endl;
    rangeForVector(words);
    // erase non-unique elements
    words.erase(end_unique, words.end());
}

void elimDups_stable_sort_shorter(vector<string> &words)
{
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "After stable sort shorter: " << endl;
    rangeForVector(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: " << endl;
    rangeForVector(words);
    // erase non-unique elements
    words.erase(end_unique, words.end());
}

int exercise10_11()
{
    vector<string> wds{"abdce", "bcd", "abd", "defhhaserahoh", "abc", "abc", "abd"};
    vector<string> wds_copy(wds);
    cout << "Original: " << endl;
    rangeForVector(wds);

    elimDups_sort_shorter(wds);

    cout << "After sort shorter elimDups: " << endl;
    rangeForVector(wds);

    elimDups_stable_sort_shorter(wds_copy);

    cout << "After stable sort shorter elimDups: " << endl;
    rangeForVector(wds_copy);

    return 0;
}

int exercise10_12()
{
    Sales_data a("9", 10, 1.1);
    Sales_data b("A", 20, 2.2);
    Sales_data c("a", 30, 3.2);

    vector<Sales_data> vecSD{a, c, b};

    cout << "Before sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    sort(vecSD.begin(), vecSD.end(), compareIsbn);

    cout << "After sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    return 0;
}

bool atLeast5Chars(const string &a)
{
    return (a.size() >= 5) ? true : false;
}

int exercise10_13()
{

    vector<string> wds{"abdce", "bcd", "abd", "defhhaserahoh", "abc", "abc", "abd"};

    auto itWds = partition(wds.begin(), wds.end(), atLeast5Chars);

    cout << "true items:" << endl;
    for (auto temp = wds.begin(); temp != itWds; ++temp)
    {
        cout << *temp << ",";
    }

    cout << endl
         << "false items: " << endl;

    for (auto temp = itWds; temp != wds.end(); ++temp)
    {
        cout << *temp << ",";
    }

    return 0;
}

int exercise10_14()
{

    auto f1 = [](int a, int b) -> int
    { return a + b; };

    cout << f1(1, 2) << endl;

    return 0;
}

int exercise10_15()
{
    int sz = 100;

    auto f1 = [sz](int a) -> int
    { return a + sz; };

    cout << f1(1) << endl;

    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);

    auto isShorterLambda = [](const string &str1, const string &str2) -> bool
    {
        return (str1.size() < str2.size()) ? true : false;
    };

    stable_sort(words.begin(), words.end(), isShorterLambda);

    auto it = std::find_if(words.begin(), words.end(), [wordSize](string &word)
                           { return (wordSize <= word.size()) ? true : false; });

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_16()
{

    vector<string> wds{"bcded", "defhhaserahoh", "abc", "abdc"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggies(wds, wds.size());
    return 0;
}

int exercise10_17()
{
    Sales_data a("9", 10, 1.1);
    Sales_data b("A", 20, 2.2);
    Sales_data c("a", 30, 3.2);

    vector<Sales_data> vecSD{b, c, a};

    cout << "Before sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    auto compareIsbnLambda = [](const Sales_data &a, const Sales_data &b) -> bool
    {
        return (a.isbn() < b.isbn()) ? true : false;
    };

    sort(vecSD.begin(), vecSD.end(), compareIsbnLambda);

    cout << "After sort : " << endl;
    for (auto temp = vecSD.begin(); temp != vecSD.end(); ++temp)
    {
        print(cout, *temp);
        cout << endl;
    }

    return 0;
}

void biggiesPartition(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);

    auto isShorterLambda = [](const string &str1, const string &str2) -> bool
    {
        return (str1.size() < str2.size()) ? true : false;
    };

    stable_sort(words.begin(), words.end(), isShorterLambda);

    auto it = partition(words.begin(), words.end(), [wordSize](string &word)
                        { return (word.size() < wordSize) ? true : false; });

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_18()
{
    // vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    vector<string> wds{"apple", "banana", "orange", "banana", "apple"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggiesPartition(wds, wds.size());
    return 0;
}

void biggiesStablePartition(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);

    auto isShorterLambda = [](const string &str1, const string &str2) -> bool
    {
        return (str1.size() < str2.size()) ? true : false;
    };

    stable_sort(words.begin(), words.end(), isShorterLambda);

    auto it = stable_partition(words.begin(), words.end(), [wordSize](string &word)
                               { return (word.size() < wordSize) ? true : false; });

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_19()
{
    // Actually,
    // vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    vector<string> wds{"apple", "banana", "orange", "banana", "apple"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggiesStablePartition(wds, wds.size());

    return 0;
}

int compare_sort_and_stable_sort()
{
    // Create a vector of pairs with first element as integer and second element as string
    std::vector<std::pair<int, std::string>> vec = {
        {3, "Three"},
        {1, "One"},
        {2, "Two"},
        {3, "Another Three"},
        {2, "Another Two"},
        {1, "Another One"}};

    // Copy the vector to perform two separate sorts
    std::vector<std::pair<int, std::string>> vec_sort = vec;
    std::vector<std::pair<int, std::string>> vec_stable_sort = vec;

    // Time measurement
    auto start_sort = std::chrono::steady_clock::now();
    sort(vec_sort.begin(), vec_sort.end());
    auto end_sort = std::chrono::steady_clock::now();

    auto start_stable_sort = std::chrono::steady_clock::now();
    stable_sort(vec_stable_sort.begin(), vec_stable_sort.end());
    auto end_stable_sort = std::chrono::steady_clock::now();

    // Output sorted vectors
    cout << "sort result:" << endl;
    for (const auto &elem : vec_sort)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << endl;

    cout << "stable_sort result:" << endl;
    for (const auto &elem : vec_stable_sort)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << endl;

    // Output time taken
    cout << "sort time: " << std::chrono::duration<double>(end_sort - start_sort).count() << " seconds" << endl;
    cout << "stable_sort time: " << std::chrono::duration<double>(end_stable_sort - start_stable_sort).count() << " seconds" << endl;

    return 0;
}

int exercise10_20()
{
    string::size_type length = 5;
    vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    rangeForVector(wds);

    auto f1 = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() <= len)
            return false;
        else
            return true;
    };
    // bind argument(实参) to the second parameter(形参).
    auto f2 = std::bind(f1, _1, length);

    auto result = std::count_if(wds.cbegin(), wds.cend(), f2);

    cout << "Words that have length more than " << length << " are: " << result << endl;

    return 0;
}

int exercise10_21()
{
    int t = 0;
    cin >> t;
    cout << "Input int is: " << t << endl;

    auto f1 = [&t]() -> bool
    {
        while (t > 0)
        {
            --t;
        }
        if (t == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool result = f1();
    cout << "current int is " << t << endl;
    cout << "Is the result of f1 equal to zero ? " << result << endl;

    return 0;
}

int exercise10_22()
{
    string::size_type length = 6;
    vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    rangeForVector(wds);

    auto f1 = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() <= len)
            return true;
        else
            return false;
    };
    // bind argument(实参) to the second parameter(形参).
    auto f2 = std::bind(f1, _1, length);

    auto result = std::count_if(wds.cbegin(), wds.cend(), f2);

    cout << "Words that have length less than or equal " << length << " are: " << result << endl;

    return 0;
}

int exercise10_23()
{
    return 0;
}

int exercise10_24()
{
    auto check_size = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() >= len)
            return true;
        else
            return false;
    };

    vector<int> intV{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -100};
    string sample("wds");

    auto f2 = bind(check_size, sample, _1);

    auto itInt = find_if(intV.cbegin(), intV.cend(), f2);

    cout << *itInt << endl;

    return 0;
}

void biggiesUsingBind(vector<string> &words, vector<string>::size_type wordSize)
{
    elimDups(words);
    auto check_size = [](const string &str, string::size_type len) -> bool
    {
        if (str.size() < len)
            return true;
        else
            return false;
    };
    auto f2 = bind(check_size, _1, wordSize);
    auto it = stable_partition(words.begin(), words.end(), f2);

    if (it != words.end())
    {
        cout << "Biggies found: ";
        while (it != words.end())
        {
            cout << *(it++) << " ";
        }
    }
    else
    {
        cout << "Biggies not found. ";
    }
    cout << endl;
}

int exercise10_25()
{
    vector<string> wds{"bcdede", "defhhaserahoh", "abc", "abdc", "bcdade"};
    // vector<string> wds{"apple", "banana", "orange", "banana", "apple"};
    cout << "Original: " << endl;
    rangeForVector(wds);

    biggiesUsingBind(wds, wds.size());

    return 0;
}

int exercise10_26()
{
    return 0;
}

int exercise10_27()
{
    list<string> wds{"abdce", "bcd", "abd", "defhhaserahoh", "abc", "abc", "abd"};
    rangeForContainer(wds);
    list<string> wds_u1, wds_u2, wds_u3;

    cout << "use inserter" << endl;
    unique_copy(wds.begin(), wds.end(), std::inserter(wds_u1, wds_u1.end()));
    rangeForContainer(wds_u1);

    cout << "use back inserter" << endl;
    unique_copy(wds.begin(), wds.end(), std::back_inserter(wds_u2));
    rangeForContainer(wds_u2);

    // cout << "use front inserter" << endl;
    // vector and string container have NO push_front method.

    cout << "use front inserter" << endl;
    unique_copy(wds.begin(), wds.end(), std::front_inserter(wds_u3));
    rangeForContainer(wds_u3);

    return 0;
}

int exercise10_28()
{
    vector<int> wds{1, 2, 3, 4, 5, 6, 7, 8, 9};
    rangeForContainer(wds);
    vector<int> wds_u1, wds_u2, wds_u3;

    cout << "use inserter" << endl;
    unique_copy(wds.begin(), wds.end(), std::inserter(wds_u1, wds_u1.end()));
    rangeForContainer(wds_u1);

    cout << "use back inserter" << endl;
    unique_copy(wds.begin(), wds.end(), std::back_inserter(wds_u2));
    rangeForContainer(wds_u2);

    // cout << "use front inserter" << endl;
    // vector and string container have NO push_front method.
    return 0;
}

int exercise10_29()
{
    std::istream_iterator<string> it_cin(cin), it_eof;

    vector<string> wds(it_cin, it_eof);

    rangeForContainer(wds);

    return 0;
}

int exercise10_30()
{

    std::istream_iterator<int> it_cin(cin), it_eof;
    std::ostream_iterator<int> it_cout(cout, " , ");

    vector<int> wds(it_cin, it_eof);

    cout << "Before sort: " << endl;
    rangeForContainer(wds);

    sort(wds.begin(), wds.end());
    cout << "After sort: " << endl;
    // rangeForContainer(wds);

    copy(wds.begin(), wds.end(), it_cout);

    return 0;
}

int exercise10_31()
{

    std::istream_iterator<int> it_cin(cin), it_eof;
    std::ostream_iterator<int> it_cout(cout, " , ");

    vector<int> wds(it_cin, it_eof);

    cout << "Before sort: " << endl;
    rangeForContainer(wds);

    sort(wds.begin(), wds.end());

    // rangeForContainer(wds);
    cout << "After sort and unique: " << endl;
    unique_copy(wds.begin(), wds.end(), it_cout);

    return 0;
}

int exercise10_32()
{
    // Example input:
    // 11-11 30 10.09
    // 11-11 1 9.99
    // 11-22 30 9.88
    // 2222-1 50 1.11

    std::istream_iterator<Sales_data> it_cin(cin), it_eof;
    std::ostream_iterator<Sales_data> it_cout(cout, " || ");

    vector<Sales_data> sds(it_cin, it_eof);

    // instead of rangeForContainer method.
    copy(sds.begin(), sds.end(), it_cout);

    sort(sds.begin(), sds.end(), compareIsbn);

    // instead of rangeForContainer method.
    copy(sds.begin(), sds.end(), it_cout);

    auto it = find_if(sds.begin(), sds.end(), [](Sales_data &a)
                      { return (a.avg_price() > 10.00) ? true : false; });

    cout << "First sales data that has avg price > 10 is :" << *it << endl;

    Sales_data target("2222-1", 50, 1.11); // this constructor cout 2.
    auto it2 = find(sds.begin(), sds.end(), target);

    cout << "First sales data that equal with target is :" << *it2 << endl;

    auto sum = accumulate(sds.begin(), sds.end(), 0.0, [](double a, Sales_data &b)
                          { return a + b.avg_price(); });

    cout << sum << endl;

    return 0;
}

int exercise10_33()
{
    string prefix("/home/tianyh/projects/hellocpp/CppPrimer5th/chapter10/data/");
    string inFile("in10_33"), out1File("out1_10_33"), out2File("out2_10_33");

    ifstream ins(prefix + inFile);
    ofstream out1s(prefix + out1File), out2s(prefix + out2File);

    std::istream_iterator<int> it_ins(ins), it_eof;
    std::ostream_iterator<int> it_out1(out1s, " | "), it_out2(out2s, " || ");

    vector<int> vec_int(it_ins, it_eof);

    partition_copy(vec_int.begin(), vec_int.end(), it_out1, it_out2, [](int a)
                   { return a % 2; });

    return 0;
}

int exercise10_34()
{
    vector<int> wds{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = wds.crbegin(); it != wds.crend(); ++it)
    {
        cout << *it << ", ";
    }

    return 0;
}

int exercise10_35()
{
    vector<int> wds{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = wds.end(); it > wds.begin();)
    {
        cout << *(--it) << ", ";
    }

    return 0;
}
int exercise10_36()
{
    vector<int> wds{1, 2, 0, 4, 5, 6, 0, 8, 9};
    std::ostream_iterator<int> it_cout(cout, " || ");
    auto it1 = find(wds.rbegin(), wds.rend(), 0);

    cout << "From tail to it1: " << endl;
    std::copy(wds.rbegin(), it1, it_cout);

    cout << "From begin to it1: " << endl;
    std::copy(wds.begin(), it1.base(), it_cout);

    return 0;
}

int exercise10_37()
{
    vector<int> wds{1, 2, 0, 4, 5, 6, 0, 8, 9, 10};

    std::ostream_iterator<int> it_cout(cout, " || ");

    list<int> t_list(wds.rbegin() + 2, wds.rbegin() + 7);

    copy(t_list.cbegin(), t_list.cend(), it_cout);

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
    vector<int> wds{1, 2, 0, 4, 5, 6, 0, 8, 9, 10};
    vector<int> wds1(wds), wds2(wds);

    std::ostream_iterator<int> it_cout(cout, " || ");

    copy(wds.cbegin(), wds.cend(), it_cout);
    cout << endl
         << " replace(beg, end, old_val, new_val); \t\t";
    std::replace(wds.begin(), wds.end(), 0, 1111);
    copy(wds.cbegin(), wds.cend(), it_cout);

    cout << endl
         << "replace_if(beg, end, pred, new_val); \t\t";
    auto f1 = [](int val)
    { return val == 0; };
    std::replace_if(wds1.begin(), wds1.end(), f1, 1111);
    copy(wds1.cbegin(), wds1.cend(), it_cout);

    cout << endl
         << "replace_copy(beg, end, dest, old_val, new_val); ";
    vector<int> wds3(wds2.size());

    std::replace_copy(wds2.begin(), wds2.end(), wds3.begin(), 0, 1111);
    copy(wds3.cbegin(), wds3.cend(), it_cout);

    cout << endl
         << "replace_copy_if(beg, end, dest, pred, new_val); ";
    vector<int> wds4(wds2.size());

    std::replace_copy_if(wds2.begin(), wds2.end(), wds4.begin(), f1, 1111);
    copy(wds4.cbegin(), wds4.cend(), it_cout);

    cout << endl;
    return 0;
}

void elimDupsList(list<string> &words)
{
    std::ostream_iterator<string> it_cout(cout, " || ");

    cout << "Before sort: " << endl;
    copy(words.cbegin(), words.cend(), it_cout);

    // sort words alphabetically so we can find the duplicates
    words.sort();
    cout << endl << "After sort: " << endl;
    copy(words.cbegin(), words.cend(), it_cout);

    // unique words and erase non-unique elements
    words.unique();
    cout << endl << "After unique: " << endl;
    copy(words.cbegin(), words.cend(), it_cout);
    cout << endl;
}

int exercise10_42()
{
    list<string> wds{"abdce", "bcd", "abd", "defhhaserahoh", "abc", "abc", "abd"};

    elimDupsList(wds);

    return 0;
}
