#include "chapter3.h"

int exercise3_2()
{
    string a;
    cout << "Please input strings by line: (Press Ctrl + Z to quit.)" << endl;
    while (getline(cin, a))
    {
        cout << a << endl;
    }

    return 0;
}

int exercise3_3()
{
    string a;
    cout << "Please input strings by line: (cin will refresh once Enter, Press Ctrl + Z to quit.)" << endl;
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
