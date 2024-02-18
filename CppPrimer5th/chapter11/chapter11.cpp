#include "chapter11.h"

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
    return 0;
}

int exercise11_8()
{
    return 0;
}

int exercise11_9()
{
    return 0;
}

int exercise11_10()
{
    return 0;
}

int exercise11_11()
{
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
