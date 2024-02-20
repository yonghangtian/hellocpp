#include "chapter11.h"
#include "../chapter7/chapter7.h"

int exercise11_1()
{
    return 0;
}

int exercise11_2()
{
    vector<string> vecStr{"i", "am ", "a vector"};
    std::list<string> listStr(vecStr.begin(), vecStr.end());
    std::deque<string> dequeStr(vecStr.begin(), vecStr.end());
    std::set<string> setStr(vecStr.begin(), vecStr.end());
    std::map<int, string> mapStr;

    std::ostream_iterator<string> it_cout(cout, " || ");

    for (int temp = 0; temp != vecStr.size(); ++temp)
    {
        mapStr[temp] = vecStr[temp];
    }

    cout << "vector: ";
    std::copy(vecStr.begin(), vecStr.end(), it_cout);
    cout << endl
         << "list: ";
    std::copy(listStr.begin(), listStr.end(), it_cout);
    cout << endl
         << "deque: ";
    std::copy(dequeStr.begin(), dequeStr.end(), it_cout);
    cout << endl
         << "set: ";
    std::copy(setStr.begin(), setStr.end(), it_cout);
    cout << endl
         << "map: ";

    for (auto &it : mapStr)
    {
        cout << it.first << ", " << it.second;
    }
    cout << endl;
    return 0;
}

int exercise11_3()
{
    // example.  example,  Example tian yonghang yonghang
    std::map<string, int> wordsCnt;

    string word;

    while (cin >> word)
    {
        ++wordsCnt[word];
    }

    for (auto &it : wordsCnt)
    {
        cout << "Word " << it.first << " has been seen " << it.second << " times." << endl;
    }

    return 0;
}

string simply_word(const string &word)
{

    string temp;
    // 方法1： 预先分配足够的空间
    // temp.resize(word.size());
    // 将大写字母转换为小写
    // std::transform(word.begin(), word.end(), temp.begin(),
    //     [](unsigned char c) { return std::tolower(c); });

    // 方法2： 使用back_inserter
    auto it = std::back_inserter(temp);

    // 将大写字母转换为小写
    std::transform(word.begin(), word.end(), it,
                   [](unsigned char c)
                   { return std::tolower(c); });

    // 移除除字母以外的所有字符
    temp.erase(std::remove_if(temp.begin(), temp.end(),
                              [](char c)
                              { return !std::isalpha(c); }),
               temp.end());

    return temp;
}

int exercise11_4()
{
    // cin inputs:  example.  example,  Example tian yonghang yonghang
    std::map<string, int> wordsCnt;

    string word;

    while (cin >> word)
    {
        string simplyWord = simply_word(word);
        ++wordsCnt[simplyWord];
    }

    for (auto &it : wordsCnt)
    {
        cout << "Word " << it.first << " has been seen " << it.second << " times." << endl;
    }

    return 0;
}

int exercise11_5()
{
    return 0;
}

int exercise11_6()
{
    return 0;
}

int exercise11_7()
{
    // How many family you want to input: 3
    // Input family name and children's name in a line split with space: tian yonghang xinyi hah
    // Input family name and children's name in a line split with space: li xinyi xinyi1 xinyi2 xinyi3
    // Input family name and children's name in a line split with space: zhnag yongjun hahh hhuhasdfs this is
    // Family name li has 4 children.
    // Family name tian has 3 children.
    // Family name zhnag has 5 children.

    std::map<string, vector<string>> names;
    int num;
    string faimlyName, childrenNames;

    cout << "How many family you want to input: ";
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        cout << "Input family name and children's name in a line split with space: ";
        cin >> faimlyName;

        std::getline(cin, childrenNames);
        //
        if (childrenNames.size() > 0)
        {
            std::istringstream iss(childrenNames);
            std::istream_iterator<string> it_cin(iss), it_eof;
            vector<string> cNameVec(it_cin, it_eof);

            // Add familyName and children names to map.
            names[faimlyName] = cNameVec;
        }
        else
        {
            cout << "Invalid children's name." << endl;
            return -1;
        }
    }

    for (auto &it : names)
    {
        cout << "Family name " << it.first << " has " << it.second.size() << " children." << endl;
    }

    return 0;
}

int exercise11_8()
{
    // cin inputs:  example.  example, the fuck hello this is  Example tian yonghang yonghang
    std::map<string, int> wordsCnt;
    // std::set<string> excludes{"and", "this", "the", "what", "fuck"};
    std::vector<string> exclude{"and", "this", "the", "what", "fuck"};
    string word;

    while (cin >> word)
    {
        string simplyWord = simply_word(word);
        // if (excludes.find(simplyWord) == excludes.end())
        //  {++wordsCnt[simplyWord];}
        if (find(exclude.begin(), exclude.end(), simplyWord) == exclude.end())
        {
            ++wordsCnt[simplyWord];
        }
    }

    for (auto &it : wordsCnt)
    {
        cout << "Word " << it.first << " has been seen " << it.second << " times." << endl;
    }

    return 0;
}

int exercise11_9()
{
    return 0;
}

int exercise11_10()
{
    vector<int> vecInt{3, 2, 2, 1, 5, 8};
    std::map<decltype(vecInt.begin()), int> test1;
    std::map<int, decltype(vecInt.begin())> test2;

    for (auto it = vecInt.begin(); it != vecInt.end(); ++it)
    {
        test1[it] = *it;
        test2[*it] = it;
    }
    // We can add or remove below line to see what happened.
    // vecInt.push_back(10);

    for (auto item : test1)
    {
        cout << "key: " << *(item.first) << " and value: " << item.second << endl;
    }

    for (auto item2 : test2)
    {
        cout << "key: " << item2.first << " and value: " << *(item2.second) << endl;
    }

    return 0;
}

int exercise11_11()
{
    bool (*pf)(const Sales_data &a, const Sales_data &b);

    pf = compareIsbn;
    // std::multiset<Sales_data, decltype(pf)> bookstore(compareIsbn);
    // std::multiset的第二个模板参数应该是一个类型，而不是一个变量
    std::multiset<Sales_data, bool (*)(const Sales_data &a, const Sales_data &b)> bookstore(pf);

    Sales_data a("9", 10, 1.1);
    Sales_data b("A", 20, 2.2);
    Sales_data c("a", 30, 3.2);

    bookstore.insert(a);
    bookstore.insert(b);
    bookstore.insert(c);

    for (auto bit = bookstore.begin(); bit != bookstore.end(); ++bit)
    {
        cout << *bit << endl;
    }

    return 0;
}

int exercise11_12()
{
    // How many pair you want to input: 3
    // Please input your string and number, split with space
    // tian 2
    // Please input your string and number, split with space
    // yonghang 1
    // Please input your string and number, split with space
    // lixinyi 3
    // str: tian and int: 2
    // str: yonghang and int: 1
    // str: lixinyi and int: 3

    vector<std::pair<string, int>> pairVec;
    int num = 0;
    cout << "How many pair you want to input: ";
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        string tStr;
        int tInt;
        cout << "Please input your string and number, split with space" << endl;
        cin >> tStr >> tInt;

        pairVec.push_back(std::make_pair(tStr, tInt));
    }

    for (const auto &item : pairVec)
    {
        cout << "str: " << item.first << " and int: " << item.second << endl;
    }

    return 0;
}

int exercise11_13()
{
    string tStr("yonghang");
    int tInt(5);
    // method 1
    auto pair1 = std::make_pair(tStr, tInt);
    // method 2
    std::pair<string, int> pair2{tStr + "1", tInt};
    // method 3
    std::pair<string, int> pair3;
    pair3.first = tStr + "2";
    pair3.second = tInt;

    cout << "str: " << pair1.first << " and int: " << pair1.second << endl;
    cout << "str: " << pair2.first << " and int: " << pair2.second << endl;
    cout << "str: " << pair3.first << " and int: " << pair3.second << endl;

    return 0;
}

int exercise11_14()
{
    // How many family you want to input: 3
    // Input family name and children's name in a line split with space: tian yonghang xinyi hah
    // Input family name and children's name in a line split with space: li xinyi xinyi1 xinyi2 xinyi3
    // Input family name and children's name in a line split with space: zhnag yongjun hahh hhuhasdfs this is
    // Family name li has 4 children.
    // Family name tian has 3 children.
    // Family name zhnag has 5 children.

    std::map<string, vector<std::pair<string, string>>> names;
    unsigned int num1, num2;
    string faimlyName, childrenName, childrenBirthday;

    cout << "How many family you want to input: ";
    cin >> num1;

    if (num1 == 0 || num1 > 5)
    {
        cout << "Plase input at most 4 family names";
        return -1;
    }

    for (int i = 0; i < num1; ++i)
    {
        cout << "Input family name: ";
        cin >> faimlyName;

        cout << "How many children you want to input: ";
        cin >> num2;

        if (num2 == 0 || num2 > 5)
        {
            cout << "Plase input at most 4 children";
            return -1;
        }

        vector<std::pair<string, string>> childrenVec;
        for (int j = 0; j < num2; ++j)
        {
            cout << "Input children's first name and birthday(yyyy-mm-dd format): ";
            cin >> childrenName >> childrenBirthday;

            childrenVec.push_back(std::make_pair(childrenName, childrenBirthday));
        }
        // Add familyName and vector of childrens to map.
        names[faimlyName] = childrenVec;
    }

    for (auto &it : names)
    {
        cout << "Family name " << it.first << " has " << it.second.size() << " children." << endl;

        for (auto &it1 : it.second)
        {
            cout << " Children name " << it1.first << " children birthday " << it1.second;
        }
        cout << endl;
    }

    return 0;
}

int exercise11_15()
{
    std::map<int, vector<int>> test;

    decltype(test)::key_type num = 1;
    decltype(test)::mapped_type vecInt{1, 2, 3};
    decltype(test)::value_type pair1(num, vecInt);

    std::ostream_iterator<int> it_cout(cout, " || ");

    cout << num << endl;

    copy(vecInt.begin(), vecInt.end(), it_cout);

    cout << endl
         << pair1.first << " " << pair1.second.size() << endl;

    return 0;
}

int exercise11_16()
{
    std::map<int, vector<int>> test;

    decltype(test)::key_type num = 1;
    decltype(test)::mapped_type vecInt{1, 2, 3};
    decltype(test)::value_type pair1(num, vecInt);

    std::ostream_iterator<int> it_cout(cout, " || ");

    test[num] = vecInt;

    for (auto &pair1 : test)
    {
        if (pair1.first == 1)
        {
            pair1.second.push_back(4);
        }
    }

    for (auto &pair1 : test)
    {
        cout << pair1.first << " " << pair1.second.size() << endl;
        copy(pair1.second.begin(), pair1.second.end(), it_cout);
    }

    return 0;
}

int exercise11_17()
{
    vector<string> v{"tian", "yonghang", "hahhah", "tian", "yonghang", "hahhah"};

    std::multiset<string> c{"t", "y", "h"};
    // works
    // copy(v.begin(), v.end(), inserter(c, c.end()));

    // Not working. ‘class std::multiset<std::__cxx11::basic_string<char> >’ has no member named ‘push_back’
    // copy(v.begin(), v.end(), back_inserter(c));

    // works
    // copy(c.begin(), c.end(), inserter(v, v.end()));

    // works
    copy(c.begin(), c.end(), back_inserter(v));

    for (auto &item : c)
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto &item1 : v)
    {
        cout << item1 << " ";
    }

    return 0;
}

int exercise11_18()
{

    std::map<int, vector<int>> test;

    decltype(test)::key_type num = 1;
    decltype(test)::mapped_type vecInt{1, 2, 3};
    decltype(test)::value_type pair1(num, vecInt);

    std::ostream_iterator<int> it_cout(cout, " || ");

    test[num] = vecInt;

    for (const std::pair<int, vector<int>> &pair1 : test)
    {
        cout << pair1.first << " " << pair1.second.size() << endl;
        copy(pair1.second.begin(), pair1.second.end(), it_cout);
    }

    return 0;
}

int exercise11_19()
{
    bool (*pf)(const Sales_data &a, const Sales_data &b);

    pf = compareIsbn;
    // std::multiset<Sales_data, decltype(pf)> bookstore(compareIsbn);
    // std::multiset的第二个模板参数应该是一个类型，而不是一个变量
    std::multiset<Sales_data, bool (*)(const Sales_data &a, const Sales_data &b)> bookstore(pf);

    Sales_data a("9", 10, 1.1);
    Sales_data b("A", 20, 2.2);
    Sales_data c("a", 30, 3.2);

    bookstore.insert(a);
    bookstore.insert(b);
    bookstore.insert(c);

    // for (auto bit = bookstore.begin(); bit != bookstore.end(); ++bit)
    // {
    //     cout << *bit << endl;
    // }

    std::multiset<Sales_data, bool (*)(const Sales_data &a, const Sales_data &b)>::iterator test = bookstore.begin();

    cout << *test << endl;

    return 0;
}

int exercise11_20()
{
    // example.  example,  Example tian yonghang yonghang
    std::map<string, int> wordsCnt;
    string word;

    while (cin >> word)
    {
        std::pair<std::map<string, int>::iterator, bool> item = wordsCnt.insert({word, 1});

        if (!item.second)
        {
            ++(item.first->second);
        }
    }

    for (auto &it : wordsCnt)
    {
        cout << "Word " << it.first << " has been seen " << it.second << " times." << endl;
    }

    return 0;
}

int exercise11_21()
{
    // example.  example,  Example tian yonghang yonghang
    std::map<string, int> wordsCnt;
    string word;

    while (cin >> word)
    {
        ++(wordsCnt.insert({word, 0}).first->second);
    }

    for (auto &it : wordsCnt)
    {
        cout << "Word " << it.first << " has been seen " << it.second << " times." << endl;
    }

    return 0;
}

int exercise11_22()
{
    std::map<int, vector<int>> test;

    decltype(test)::key_type num = 1;
    decltype(test)::mapped_type vecInt{1, 2, 3};
    decltype(test)::value_type pair1(num, vecInt);

    std::ostream_iterator<int> it_cout(cout, " || ");

    test.insert(pair1);

    vecInt.push_back(4);
    ++num;

    std::pair<std::map<int, vector<int>>::iterator, bool> item = test.insert({num, vecInt});

    if (item.second)
    {
        cout << item.first->first << " " << (item.first->second).size() << endl;
        copy((item.first->second).begin(), (item.first->second).end(), it_cout);
    }

    return 0;
}

int exercise11_23()
{
    //     How many family you want to input: 3
    // Input family name: li
    // How many children you want to input: 1
    // Input children's first name and birthday(yyyy-mm-dd format): xinyi 1992-01-11
    // Input family name: li
    // How many children you want to input: 1
    // Input children's first name and birthday(yyyy-mm-dd format): yonghang 1993-03-11
    // Input family name: tian
    // How many children you want to input: 1
    // Input children's first name and birthday(yyyy-mm-dd format): yonghang 1996-09-19
    // Family name li has 1 children.
    //  Children name xinyi children birthday 1992-01-11
    // Family name li has 1 children.
    //  Children name yonghang children birthday 1993-03-11
    // Family name tian has 1 children.
    //  Children name yonghang children birthday 1996-09-19

    std::multimap<string, vector<std::pair<string, string>>> names;
    unsigned int num1, num2;
    string faimlyName, childrenName, childrenBirthday;

    cout << "How many family you want to input: ";
    cin >> num1;

    if (num1 == 0 || num1 > 5)
    {
        cout << "Plase input at most 4 family names";
        return -1;
    }

    for (int i = 0; i < num1; ++i)
    {
        cout << "Input family name: ";
        cin >> faimlyName;

        cout << "How many children you want to input: ";
        cin >> num2;

        if (num2 == 0 || num2 > 5)
        {
            cout << "Plase input at most 4 children";
            return -1;
        }

        vector<std::pair<string, string>> childrenVec;
        for (int j = 0; j < num2; ++j)
        {
            cout << "Input children's first name and birthday(yyyy-mm-dd format): ";
            cin >> childrenName >> childrenBirthday;

            childrenVec.push_back(std::make_pair(childrenName, childrenBirthday));
        }
        // Add familyName and vector of childrens to map.
        names.insert({faimlyName, childrenVec});
    }

    for (auto &it : names)
    {
        cout << "Family name " << it.first << " has " << it.second.size() << " children." << endl;

        for (auto &it1 : it.second)
        {
            cout << " Children name " << it1.first << " children birthday " << it1.second;
        }
        cout << endl;
    }

    return 0;
}

int exercise11_24()
{
    std::map<int, int> m;
    m[0] = 1;

    for (const auto &item : m)
    {
        cout << item.first << ", " << item.second;
    }

    return 0;
}

int exercise11_25()
{
    vector<int> v;
    v[0] = 1;

    for (const auto &item : v)
    {
        cout << item;
    }

    return 0;
}

int exercise11_26()
{
    std::map<string, string> test;

    test.insert({"thisiskey", "thisismappedvalue"});

    cout << test.at("thisiskey") << endl;
    cout << test["thisiskey"] << endl;

    string temp("thisisanotherkey");

    // terminate called after throwing an instance of 'std::out_of_range'
    // cout << test.at(temp) << endl;

    return 0;
}

int exercise11_27()
{
    return 0;
}

int exercise11_28()
{
    std::map<string, vector<int>> mapStr;
    vector<int> intVec{1, 2, 3, 4};

    string temp("time");

    mapStr.insert({temp + "1", intVec});
    intVec.push_back(5);
    mapStr.insert({temp + "2", intVec});
    intVec.push_back(6);
    mapStr.insert({temp + "3", intVec});

    std::map<string, vector<int>>::iterator it = mapStr.find(temp + "1");

    cout << it->first << "," << it->second.size() << endl;

    std::multimap<string, vector<int>> multiMapStr;

    intVec.push_back(7);
    multiMapStr.insert({temp, intVec});
    intVec.push_back(8);
    multiMapStr.insert({temp, intVec});
    intVec.push_back(9);
    multiMapStr.insert({temp, intVec});

    std::multimap<string, vector<int>>::iterator it2 = multiMapStr.find(temp);
    std::multimap<string, vector<int>>::size_type entries = multiMapStr.count(temp);

    while (entries != 0)
    {
        cout << it2->second.size() << endl;
        ++it2;
        --entries;
    }

    return 0;
}

int exercise11_29()
{
    std::map<string, vector<int>> mapStr;
    vector<int> intVec{1, 2, 3, 4};

    string temp("time");

    mapStr.insert({temp + "1", intVec});
    intVec.push_back(5);
    mapStr.insert({temp + "2", intVec});
    intVec.push_back(6);
    mapStr.insert({temp + "3", intVec});

    auto it1 = mapStr.find(temp);
    auto it2 = mapStr.lower_bound(temp);
    auto it3 = mapStr.upper_bound(temp);

    bool test = (it1 == mapStr.end()) && (it2 == it3);

    cout << test << endl;
    cout << it2->first << endl;

    return 0;
}

int exercise11_30()
{
    std::multimap<string, vector<int>> multiMapStr;
    vector<int> intVec{1, 2, 3, 4};
    string temp("time");

    intVec.push_back(7);
    multiMapStr.insert({temp, intVec});
    intVec.push_back(8);
    multiMapStr.insert({temp, intVec});
    intVec.push_back(9);
    multiMapStr.insert({temp, intVec});
    intVec.push_back(10);
    multiMapStr.insert({temp + "1", intVec});

    // pos is a pair of iterators that define the range of value whose key equal to temp(the searched item)
    for (auto pos = multiMapStr.equal_range(temp); pos.first != pos.second; ++pos.first)
        cout << (pos.first->second).size() << endl;

    return 0;
}

int exercise11_31()
{
    std::multimap<string, string> multiMapStr;
    string book("book"), author("author");

    multiMapStr.insert({author + "1", book + "1"});
    multiMapStr.insert({author + "2", book + "2"});
    multiMapStr.insert({author + "3", book + "3"});
    multiMapStr.insert({author, book + "4"});
    multiMapStr.insert({author, book + "5"});
    multiMapStr.insert({author + "1", book + "6"});

    // key: author DO exist.
    auto posPair = multiMapStr.equal_range(author);

    if (posPair.first != posPair.second)
    {
        multiMapStr.erase(posPair.first, posPair.second);
    }
    // key: author7 DOES NOT exist.
    auto posPair2 = multiMapStr.equal_range(author + "7");

    if (posPair2.first != posPair2.second)
    {
        multiMapStr.erase(posPair2.first, posPair2.second);
    }

    for (const auto &item : multiMapStr)
    {
        cout << item.first << "," << item.second << endl;
    }

    return 0;
}

int exercise11_32()
{
    return 0;
}

std::map<string, string> bulidMap(std::ifstream &map_file)
{
    std::map<string, string> translate;
    string temp;
    while (getline(map_file, temp))
    {
        std::istringstream iss(temp);
        string key, value;

        while (iss >> key && getline(iss, value))
        {

            // remove header space
            value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch)
                                                    { return !isspace(ch); }));
            if (value.size() > 1)
            {
                translate[key] = value;
            }
        }
    }

    return translate;
}

const string &transformWord(const string &s, std::map<string, string> &translate)
{
    auto it = translate.find(s);
    if (it == translate.end())
        return s;
    else
        return it->second;
}

int wordTransform(std::ifstream &map_file, std::ifstream &in_file, std::ofstream &out_file)
{
    std::map<string, string> translate = bulidMap(map_file);
    string temp;

    while (getline(in_file, temp))
    {
        std::istringstream iss(temp);
        string word;
        bool firstWord = true;
        while (iss >> word)
        {
            if (!firstWord)
            {
                out_file << " ";
            }
            else
            {
                firstWord = false;
            }
            out_file << transformWord(word, translate);
        }
        out_file << endl;
    }

    return 0;
}

int exercise11_33()
{
    string prefix("/home/tianyh/projects/hellocpp/CppPrimer5th/chapter11/data/");
    string mapFile("map11_33"), inFile("in11_33"), outFile("out11_33");

    std::ifstream mapIns(prefix + mapFile), dataIns(prefix + inFile);
    std::ofstream dataOuts(prefix + outFile);

    return wordTransform(mapIns, dataIns, dataOuts);
}

int exercise11_34()
{
    return 0;
}

int exercise11_35()
{
    return 0;
}

int exercise11_36()
{
    return 0;
}

int exercise11_37()
{
    return 0;
}

std::unordered_map<string, string> bulidMapUnordered(std::ifstream &map_file)
{
    std::unordered_map<string, string> translate;
    string temp;
    while (getline(map_file, temp))
    {
        std::istringstream iss(temp);
        string key, value;

        while (iss >> key && getline(iss, value))
        {

            // remove header space
            value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch)
                                                    { return !isspace(ch); }));
            if (value.size() > 1)
            {
                translate[key] = value;
            }
        }
    }

    return translate;
}

const string &transformWordUnordered(const string &s, std::unordered_map<string, string> &translate)
{
    auto it = translate.find(s);
    if (it == translate.end())
        return s;
    else
        return it->second;
}

int wordTransformUnordered(std::ifstream &map_file, std::ifstream &in_file, std::ofstream &out_file)
{
    std::unordered_map<string, string> translate = bulidMapUnordered(map_file);
    string temp;

    while (getline(in_file, temp))
    {
        std::istringstream iss(temp);
        string word;
        bool firstWord = true;
        while (iss >> word)
        {
            if (!firstWord)
            {
                out_file << " ";
            }
            else
            {
                firstWord = false;
            }
            out_file << transformWordUnordered(word, translate);
        }
        out_file << endl;
    }

    return 0;
}

int exercise11_38()
{    
    string prefix("/home/tianyh/projects/hellocpp/CppPrimer5th/chapter11/data/");
    string mapFile("map11_33"), inFile("in11_33"), outFile("out11_38");

    std::ifstream mapIns(prefix + mapFile), dataIns(prefix + inFile);
    std::ofstream dataOuts(prefix + outFile);

    return wordTransformUnordered(mapIns, dataIns, dataOuts);
}
