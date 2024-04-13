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

    if (a == b)
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

    if (c == d)
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
    Sales_data c("pride", 20, 8.88);

    cout << c << "\n";
    string temp("let's see!");
    c = temp;
    cout << c << "\n";

    return 0;
}

int exercise14_23()
{
    // StrVec a == b
    string t1("temp str"), t2("temp str2"), t3("temp str3"), t4("temp str4");
    StrVec a{t1, t2, t3, t4}, b{t2, t1};

    b = {t1, t2, t3, t4};
    if (a == b)
        cout << "StrVec a == b \n";
    else
        cout << "StrVec a != b \n";

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
    // test StrVec's [] operator: temp str4 temp str
    // test SelfDefinedStr's [] operator: s h
    // test StrBlob's [] operator: temp str3 test StrBlobPtr's [] operator: m
    string t1("temp str"), t2("temp str2"), t3("temp str3"), t4("temp str4");
    StrVec a{t1, t2, t3, t4}, b{t2, t1};

    cout << "test StrVec's [] operator: " << a[3] << " " << b[1] << "\n";
    char *temp = "this is";
    SelfDefinedStr c(temp);

    cout << "test SelfDefinedStr's [] operator: " << c[3] << " " << c[1] << "\n";

    StrBlob e{t1, t2, t3, t4};
    StrBlobPtr f(e, 2);

    cout << "test StrBlob's [] operator: " << e[2] << " test StrBlobPtr's [] operator: " << f[2] << "\n";
    return 0;
}

int exercise14_27()
{
    string t1("temp str"), t2("temp str2"), t3("temp str3"), t4("temp str4");
    StrBlob e{t1, t2, t3, t4};
    StrBlobPtr f(e, 2);

    cout << "curr: " << *f << "\n";
    cout << "prefix++: " << *(++f) << "\n";
    cout << "prefix--: " << *(--f) << "\n";
    cout << "postfix++: " << *(f++) << " ,f is " << *f << "\n";
    cout << "postfix--: " << *(f--) << " ,f is " << *f << "\n";

    return 0;
}

int exercise14_28()
{
    // curr: temp str3
    // f + 1: temp str4
    // f - 1: temp str2
    // terminate called after throwing an instance of 'std::out_of_range'
    //   what():  decrement past begin of StrBlobPtr
    // Aborted
    string t1("temp str"), t2("temp str2"), t3("temp str3"), t4("temp str4");
    StrBlob e{t1, t2, t3, t4};
    StrBlobPtr f(e, 2);

    cout << "curr: " << *f << "\n";
    cout << "f + 1: " << *(f + 1) << "\n";
    cout << "f - 1: " << *(f - 1) << "\n";
    cout << "f - 3: " << *(f - 3) << "\n";
    return 0;
}

int exercise14_29()
{
    return 0;
}

int exercise14_30()
{
    string t1("temp str"), t2("temp str2"), t3("temp str3"), t4("temp str4");
    StrBlob e{t1, t2, t3, t4};
    StrBlobPtr f(e, 2);
    ConstStrBlobPtr h(e, 1);

    cout << "StrBlobPtr.operator*(): " << *f << "\n";
    cout << "*(StrBlobPtr.operator->()): " << f->c_str() << "\n";
    cout << "StrBlobPtr.decr(): " << *(f.decr()) << "\n";

    cout << "ConstStrBlobPtr.operator*(): " << *h << "\n";
    cout << "*(ConstStrBlobPtr.operator->()): " << h->c_str() << "\n";
    cout << "ConstStrBlobPtr.incr(): " << *(h.incr()) << "\n";

    f.incr();
    cout << "StrBlobPtr.operator*(): " << *f << "\n";
    *f = "update string";
    cout << "After update, StrBlobPtr.operator*(): " << *f << "\n";
    cout << "ConstStrBlobPtr.operator*(): " << *h << "\n";

    // *h = "again string";
    // cout << "After update, ConstStrBlobPtr.operator*(): " << *h << "\n";
    return 0;
}

int exercise14_31()
{
    return 0;
}

int exercise14_32()
{
    string t1("temp str"), t2("temp str2"), t3("temp str3"), t4("temp str4");
    StrBlob e{t1, t2, t3, t4};
    StrBlobPtr f(e, 2);

    PtrToStrBlobPtr a(f);

    cout << "StrBlobPtr.operator*(): " << *f << "\n";
    cout << "a->c_str(), will call: PtrToStrBlobPtr.operator->(), then call StrBlobPtr.operator->(), then we'll get a string : " << a->c_str() << "\n";

    return 0;
}

int exercise14_33()
{
    return 0;
}

int exercise14_34()
{
    class fielseif
    {
    public:
        int operator()(bool test, int a, int b)
        {
            if (test)
                return a;
            else
                return b;
        }
    };
    fielseif f;
    cout << f(false, 10, 5);

    return 0;
}

// Linux 中 ctrl + d：输入EOF信号 ； ctrl + z ：将前台程序转为后台并停止，使用jobs命令查看后台暂停的程序，然后使用“fg 序号”将命令带到前台继续执行
int exercise14_35()
{
    readString obj(cin);

    cout << obj() << endl;

    return 0;
}

int exercise14_36()
{
    readString obj(cin);

    vector<string> temp;

    while (cin)
    {
        temp.push_back(obj());
    }

    rangeForContainer(temp);
    return 0;
}

int exercise14_37()
{
    class EqualTo
    {
    public:
        EqualTo(int value) : value_(value) {}

        bool operator()(int x) const
        {
            return x == value_;
        }

    private:
        int value_;
    };

    // Create a vector of integers
    std::vector<int> numbers = {1, 2, 3, 2, 5, 2, 7};

    // Create an EqualTo object to test for equality with the value 2
    EqualTo equal_to_2(2);

    // Replace all instances of the value 2 with the value 99
    std::replace_if(numbers.begin(), numbers.end(), equal_to_2, 99);

    // Print the modified vector
    rangeForContainer(numbers);

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
