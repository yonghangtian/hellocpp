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
    return 0;
}

int exercise11_13()
{
    return 0;
}

int exercise11_14()
{
    return 0;
}

int exercise11_15()
{
    return 0;
}

int exercise11_16()
{
    return 0;
}

int exercise11_17()
{
    return 0;
}

int exercise11_18()
{
    return 0;
}

int exercise11_19()
{
    return 0;
}

int exercise11_20()
{
    return 0;
}

int exercise11_21()
{
    return 0;
}

int exercise11_22()
{
    return 0;
}

int exercise11_23()
{
    return 0;
}

int exercise11_24()
{
    return 0;
}

int exercise11_25()
{
    return 0;
}

int exercise11_26()
{
    return 0;
}

int exercise11_27()
{
    return 0;
}

int exercise11_28()
{
    return 0;
}

int exercise11_29()
{
    return 0;
}

int exercise11_30()
{
    return 0;
}

int exercise11_31()
{
    return 0;
}

int exercise11_32()
{
    return 0;
}

int exercise11_33()
{
    return 0;
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

int exercise11_38()
{
    return 0;
}
