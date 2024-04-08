#include "chapter14.h"

int exercise14_1()
{
    return 0;
}

int exercise14_2()
{
    // 2
    // 2
    // sales data destoryed.
    // pride 30 277.5 9.25
    // pride 50 455.1 9.102
    // sales data destoryed.
    // sales data destoryed.
    // sales data destoryed.
    Sales_data a("pride", 10, 9.99);
    Sales_data b("pride", 20, 8.88);
    Sales_data c;

    c = a + b;
    cout << c << "\n";

    c += b;
    cout << c << "\n";

    return 0;
}

int exercise14_3()
{
    vector<string> svec1, svec2;
    svec1.push_back("cobble");
    svec2.push_back("stone");

    cout << " svec1[0] == svec2[0] : operator==(svec1[0],svec2[0])  " << operator==(svec1[0], svec2[0]);
    cout << "\n svec1 == svec2 : operator==(svec1,svec2)   " << operator==(svec1, svec2);
    cout << "\n svec1[0] == \"stone\" : operator==(svec1[0], \"stone\")  " << operator==(svec1[0], "stone");
    cout << "\n \"cobble\" == \"stone\" : operator==(string(\"cobble\"), string(\"stone\"))  " << operator==(string("cobble"), string("stone"));
    cout << "\n";
    return 0;
}

int exercise14_4()
{
    return 0;
}

int exercise14_5()
{
    return 0;
}

int exercise14_6()
{
    return 0;
}

int exercise14_7()
{
    return 0;
}

int exercise14_8()
{
    return 0;
}

int exercise14_9()
{
    return 0;
}

int exercise14_10()
{
    // 0-201-99999-9 10 249.5 24.95
    // 10 24 22.8 0.95
    // sales data destoryed.
    // 0 0 0
    // sales data destoryed.
    // sales data destoryed.
    // sales data destoryed.
    string a("0-201-99999-9 10 24.95"), b("10 24.95 0-210-99999-9"), e("testcase (***) **811 ");
    std::istringstream iss(a);
    Sales_data c, d, f;
    iss >> c;
    cout << c << "\n";

    iss.clear();
    iss.str(b);
    iss >> d;
    cout << d << "\n";

    iss.clear();
    iss.str(e);
    iss >> f;
    cout << f << "\n";
    return 0;
}

int exercise14_11()
{
    // Active the wrong version of operator>> in chapter7.cpp
    // 0-201-99999-9 10 249.5 24.95
    // 10 24 22.8 0.95
    // testcase 0 0 0
    // sales data destoryed.
    // sales data destoryed.
    // sales data destoryed.
    string a("0-201-99999-9 10 24.95"), b("10 24.95 0-210-99999-9"), e("testcase (***) **811 ");
    std::istringstream iss(a);
    Sales_data c, d, f;
    iss >> c;
    cout << c << "\n";

    iss.clear();
    iss.str(b);
    iss >> d;
    cout << d << "\n";

    iss.clear();
    iss.str(e);
    iss >> f;
    cout << f << "\n";
    return 0;
}

int exercise14_12()
{
    return 0;
}

int exercise14_13()
{
    return 0;
}

int exercise14_14()
{
    return 0;
}

int exercise14_15()
{
    return 0;
}

int exercise14_16()
{

    string t1("temp str"), t2("temp str2"), t3("temp str3");
    StrVec a{t1, t2, t3}, b{t1, t2, t3};

    if (a==b)
        cout << "StrVec a == b \n"; 
    else
        cout << "StrVec a != b \n"; 

    char *temp = "this is";
    SelfDefinedStr c(temp);

    SelfDefinedStr d;
    d.push_back('t');
    d.push_back('h');
    d.push_back('i');
    d.push_back('s');
    d.push_back(' ');
    d.push_back('i');
    d.push_back('s');

    
    if (c==d)
        cout << "SelfDefinedStr c == d \n"; 
    else
        cout << "SelfDefinedStr c != d \n"; 

    return 0;
}

int exercise14_17()
{
    return 0;
}

int exercise14_18()
{
    return 0;
}

int exercise14_19()
{
    return 0;
}

int exercise14_20()
{
    return 0;
}

int exercise14_21()
{
    return 0;
}

int exercise14_22()
{
    return 0;
}

int exercise14_23()
{
    return 0;
}

int exercise14_24()
{
    return 0;
}

int exercise14_25()
{
    return 0;
}

int exercise14_26()
{
    return 0;
}

int exercise14_27()
{
    return 0;
}

int exercise14_28()
{
    return 0;
}

int exercise14_29()
{
    return 0;
}

int exercise14_30()
{
    return 0;
}

int exercise14_31()
{
    return 0;
}

int exercise14_32()
{
    return 0;
}

int exercise14_33()
{
    return 0;
}

int exercise14_34()
{
    return 0;
}

int exercise14_35()
{
    return 0;
}

int exercise14_36()
{
    return 0;
}

int exercise14_37()
{
    return 0;
}

int exercise14_38()
{
    return 0;
}

int exercise14_39()
{
    return 0;
}

int exercise14_40()
{
    return 0;
}

int exercise14_41()
{
    return 0;
}

int exercise14_42()
{
    return 0;
}

int exercise14_43()
{
    return 0;
}

int exercise14_44()
{
    return 0;
}

int exercise14_45()
{
    return 0;
}

int exercise14_46()
{
    return 0;
}

int exercise14_47()
{
    return 0;
}

int exercise14_48()
{
    return 0;
}

int exercise14_49()
{
    return 0;
}

int exercise14_50()
{
    return 0;
}

int exercise14_51()
{
    return 0;
}

int exercise14_52()
{
    return 0;
}

int exercise14_53()
{
    return 0;
}
