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
    ReadString obj(cin);

    cout << obj() << endl;

    return 0;
}

int exercise14_36()
{
    ReadString obj(cin);

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
    std::ifstream fin("/home/tian/projects/hellocpp/CppPrimer5th/chapter14/data/input_StrBlob");

    string temp;
    vector<string> vec;
    while (getline(fin, temp))
    {
        std::istringstream isin(temp);

        string word;
        while (isin >> word)
        {
            vec.push_back(word);
        }
    }

    vector<size_t> counter(10, 0);
    for (size_t i = 0; i < 10; ++i)
    {
        CheckLen checkLen(i);
        counter[i] = std::count_if(vec.begin(), vec.end(), checkLen);
        cout << "There are " << counter[i] << " words that has len " << i << " .\n";
    }

    return 0;
}

int exercise14_39()
{
    std::ifstream fin("/home/tian/projects/hellocpp/CppPrimer5th/chapter14/data/input_StrBlob");

    string temp;
    vector<string> vec;
    while (getline(fin, temp))
    {
        std::istringstream isin(temp);

        string word;
        while (isin >> word)
        {
            vec.push_back(word);
        }
    }

    vector<size_t> counter(2, 0);
    for (size_t i = 0; i < 20; ++i)
    {
        CheckLen checkLen(i);
        size_t t = std::count_if(vec.begin(), vec.end(), checkLen);
        if (i < 10)
            counter[0] += t;
        else
            counter[1] += t;
    }

    cout << "There are " << counter[0] << " words that has len less than 10.\n";
    cout << "There are " << counter[1] << " words that has len more than or equal to 10.\n";
    return 0;
}

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    cout << "After sort: " << endl;
    rangeForContainer(words);
    // unique words
    // The elements beyond that enc_unique still exist, but we don’t know what values they have
    // (MEANS: unique function may change the VALUE!!!).
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: " << endl;
    rangeForContainer(words);
    // erase non-unique elements
    words.erase(end_unique, words.end());
}

void biggiesUsingClass(vector<string> &words, vector<string>::size_type wordSize)
{
    CompareLen compareLen(wordSize);
    IsShorter isShorter;
    elimDups(words);

    stable_sort(words.begin(), words.end(), isShorter);

    auto it = std::find_if(words.begin(), words.end(), compareLen);

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

int exercise14_40()
{
    vector<string> wds{"bcded", "defhhaserahoh", "abc", "abdc"};
    cout << "Original: " << endl;
    rangeForContainer(wds);

    biggiesUsingClass(wds, wds.size());
    return 0;
}

int exercise14_41()
{
    return 0;
}

int exercise14_42()
{
    vector<int> intVec{1024, 1023, 1025, 2016};
    std::greater<int> gt1024;
    auto f = std::bind(gt1024, _1, 1024);
    size_t it = std::count_if(intVec.begin(), intVec.end(), f);
    cout << it << "\n";

    vector<string> strVec{"pool", "pool", "Pool", "POOL"};
    std::not_equal_to<string> not_pool;
    auto f2 = std::bind(not_pool, _1, "pool");
    auto it2 = std::find_if(strVec.begin(), strVec.end(), f2);
    cout << *it2 << "\n";

    std::multiplies<int> multp2;
    auto f3 = std::bind(multp2, _1, 2);
    std::transform(intVec.begin(), intVec.end(), intVec.begin(), f3);
    rangeForContainer(intVec);
    return 0;
}

int exercise14_43()
{
    vector<int> intVec{1024, 1023, 1025, 2016};
    std::modulus<int> modulus3;
    auto f = std::bind(modulus3, _1, 3);

    auto it = find_if(intVec.begin(), intVec.end(), [&](int i)
                      { return f(i) != 0; });

    if (it != intVec.end())
    {
        cout << *it << "\n";
    }

    return 0;
}

int exercise14_44()
{
    std::plus<int> p;
    std::minus<int> mi;
    std::divides<int> di;
    std::function<int(int, int)> f1 = std::multiplies<int>();
    std::function<int(int, int)> f2 = std::modulus<int>();

    std::map<string, std::function<int(int, int)>> funcMap;
    funcMap.insert({"*", f1});
    funcMap.insert({"+", p});
    funcMap.insert({"-", mi});
    funcMap.insert({"/", di});
    funcMap.insert({"%", f2});

    int a = 0, b = 0;
    string temp;
    cout << "请输入一个整数接空格, 再输入运算符接空格, 再输入下一个操作数。在wsl中输入CTRL+D即可标识EOF,以结束程序\n";
    while (cin >> a >> temp >> b)
    {
        cout << a << temp << b << "=" << funcMap.at(temp)(a, b) << "\n";
    }

    return 0;
}

int exercise14_45()
{
    Sales_data a("pride", 10, 9.99);

    cout << static_cast<string>(a) << "\n";
    cout << static_cast<double>(a) << "\n";

    return 0;
}

int exercise14_46()
{
    return 0;
}

int exercise14_47()
{
    struct Integral
    {
        operator const int() { return 1; };
        operator int() const { return 1; };
    };

    Integral i;
    const int a = i; // 使用转换运算符
    // a = 10;  // 错误，因为a是const expression must be a modifiable lvalue

    const Integral ci;
    const int b = ci;
    //  When we comment "operator int() const",会有错误，因为不能在const对象上调用非const成员函数 no suitable conversion function from "const Integral" to "const int" exists

    return 0;
}

int exercise14_48()
{
    return 0;
}

int exercise14_49()
{
    Sales_data a("pride", 10, 9.99);
    Sales_data b("pride", 12, 9.99);

    if (a)
    {
        cout << "a have revenue > 100 \n";
    }

    if (b)
    {
        cout << "b have revenue > 100 \n";
    }

    return 0;
}

class SmallInt
{
public:
    friend SmallInt operator+(const SmallInt &, const SmallInt &);
    SmallInt(int m = 0) : val(m){};      // conversion from int
    operator int() const { return val; } // conversion to int
private:
    std::size_t val;
};

struct LongDouble
{
    LongDouble(double = 0.0){};
    operator double()
    {
        cout << "double \n";
        return 0.99;
    };
    operator float()
    {
        cout << "float \n";
        return 0.98f;
    };
    // member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt &);
};

SmallInt operator+(const SmallInt &, const SmallInt &)
{
    cout << "SmallInt operator+(const SmallInt &, const SmallInt &) \n";
    return SmallInt(15);
}

LongDouble operator+(LongDouble &, double)
{
    cout << "LongDouble operator+(LongDouble &, double) \n";
    return LongDouble(2.2);
}

LongDouble operator+(LongDouble &, int)
{
    cout << "LongDouble operator+(LongDouble &, int) \n";
    return LongDouble(2.2);
}

int exercise14_50()
{
    LongDouble ldObj;
    // int ex1 = ldObj; // both double and float suits.
    // float ex2 = ldObj; // only float

    return 0;
}

void calc(int)
{
    cout << "void calc(int) \n";
}

void calc(LongDouble)
{
    cout << "void calc(LongDouble) \n";
}

int exercise14_51()
{
    // Answer: see chapter 6, section 6.1, (convertion from double to int) has higher priority than (double to self-defined class(LongDoule))
    double dval;
    calc(dval); // which calc? void calc(int)
    return 0;
}

int exercise14_52()
{

    SmallInt si;
    LongDouble ld;

    // ambiguous overload for ‘operator+’ (operand types are ‘SmallInt’ and ‘LongDouble’)
    // candidates are:
    // operator+(int, double) <built-in>
    // operator+(int, float) <built-in>
    // more than one conversion function from "LongDouble" to a built-in type applies:
    // function "LongDouble::operator double()" (declared at line 678)
    // function "LongDouble::operator float()" (declared at line 683)
    // ld = si + ld;

    // ld = ld + si; // undefined reference to `LongDouble::operator+(SmallInt const&)'
    // ld + si; // undefined reference to `LongDouble::operator+(SmallInt const&)'

    return 0;
}

int exercise14_53()
{
    SmallInt s1;
    double d = static_cast<int>(s1) + 3.14;

    cout << d << "\n";

    return 0;
}
