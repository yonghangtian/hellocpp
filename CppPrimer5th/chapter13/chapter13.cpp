#include "chapter13.h"

// Initialize the static counter to 0
int numbered::serialNumberCounter = 0;
int employee::serialNumberCounter = 0;

ostream &operator<<(ostream &os, const HasPtr &hp)
{
    os << "ps point to " << *hp.ps << " , i is " << hp.i << " , ps is " << hp.ps << "\n";
    return os;
}

ostream &operator<<(ostream &os, const PlHasPtr &hp)
{
    os << "ps point to " << *hp.ps << " , i is " << hp.i << " , refCnt is " << hp.refCnt << "\n";
    return os;
}

ostream &operator<<(ostream &os, const TreeNode &tn)
{
    os << "string " << tn.value << " , count is " << tn.count << " , left addr is " << tn.left << " , right addr is " << tn.right << " , refCnt is " << *tn.refCnt << "\n";
    return os;
}

int exercise13_1()
{
    return 0;
}

int exercise13_2()
{
    return 0;
}

int exercise13_3()
{
    StrBlob a({"abc", "def"});
    StrBlob b = a;

    a.show_data();
    b.show_data();

    StrBlobPtr c = a.begin();
    cout << c.deref() << "\n";
    StrBlobPtr d = c;
    d.incr();
    cout << d.deref() << "\n";

    return 0;
}

int exercise13_4()
{
    // Point global;
    // Point foo_bar(Point arg) //函数参数Point arg的初始化。
    // {
    //     Point local = arg, *heap = new Point(global);//(1)局部变量Point local的初始化;(2)new Point(global)使用拷贝构造函数创建了一个新的Point对象在堆上，这是第三个使用
    //     *heap = local;// 是赋值操作（可能调用了赋值运算符）
    //     // 在C++中，当使用初始化列表来初始化数组时，如果提供的初始化器数量少于数组的元素数量，
    //     // 那么剩余的元素会使用该类型的默认构造函数进行初始化。如果类型没有默认构造函数，则代码将不会编译通过。
    //     Point pa[4] = {local, *heap};//初始化数组pa时，local和*heap都是通过拷贝构造函数初始化的，这是第四和第五个使用
    //     return *heap; // 这里返回*heap时，通常会通过拷贝构造函数来创建返回的临时对象（如果是按值返回）
    // }

    return 0;
}

int exercise13_5()
{
    HasPtr a("this is a HasPtr");

    HasPtr b(a);
    // use complier's debug, we can see that a.ps 's address is : 0x5555555792f0
    // while, b.ps 's address is 0x555555579340. We have achieved the target(copy string, not the pointer.)
    return 0;
}

int exercise13_6()
{
    return 0;
}

int exercise13_7()
{
    StrBlob a({"abc", "def"});
    StrBlob b({"lxy", "tyh"});
    StrBlobPtr c = a.begin();
    StrBlobPtr d = b.begin();
    a.show_data();
    b.show_data();
    cout << c.deref() << "\n";
    cout << d.deref() << "\n";

    d = c;

    b = a;
    b.show_data();
    d.incr();
    cout << d.deref() << "\n";
    return 0;
}

int exercise13_8()
{
    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");

    cout << a << b;
    a = b;

    cout << a;
    return 0;
}

int exercise13_9()
{
    return 0;
}

int exercise13_10()
{
    return 0;
}

int exercise13_11()
{
    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");

    cout << a << b;
    a = b;

    cout << a;
    return 0;
}

bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}

int exercise13_12()
{
    Sales_data a("pride", 10, 9.99);
    Sales_data b("pride", 20, 8.88);

    Sales_data *c = &a;

    cout << fcn(c, b) << "\n";

    cout << b << "\n";

    return 0;
}

int exercise13_13()
{
    // (HasPtr) HasPtr()
    // (HasPtr) HasPtr()
    // ps point to this is a HasPtr , i is 0
    // ps point to second hasptr , i is 0
    // (operator=) HasPtr &operator=(const HasPtr &)
    // ps point to second hasptr , i is 0
    // (HasPtr) HasPtr()
    // (HasPtr) HasPtr(const HasPtr &)
    // (HasPtr) HasPtr(const HasPtr &)
    // (HasPtr) HasPtr(const HasPtr &)
    // ps point to second hasptr , i is 0
    // ps point to second hasptr , i is 0
    // ps point to let's try , i is 0
    // (~HasPtr) ~HasPtr()
    // String "let's try" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed

    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");
    cout << a << b;
    a = b;
    cout << a;
    HasPtr *c = new HasPtr("let's try");
    HasPtr d[3] = {a, b, *c};
    cout << d[0] << d[1] << d[2];
    delete c;
    return 0;
}

void f(numbered s) { cout << s.getSerialNumber() << endl; }

void f_const(const numbered &s) { cout << s.getSerialNumber() << endl; }

int exercise13_14()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}

int exercise13_15()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}

int exercise13_16()
{
    numbered a, b = a, c = b;
    cout << a.getSerialNumber() << "\n";
    f(a);
    cout << b.getSerialNumber() << "\n";
    f(b);
    cout << c.getSerialNumber() << "\n";
    f(c);
    return 0;
}

int exercise13_17()
{
    return 0;
}

int exercise13_18()
{
    employee a;
    employee b = a, c = b;

    a.getEmployeeInfo();
    b.getEmployeeInfo();
    c.getEmployeeInfo();

    return 0;
}

int exercise13_19()
{
    employee a;
    employee b = a, c = b;
    b.setName("tian");
    c.setName("yonghang");
    a.getEmployeeInfo();
    b.getEmployeeInfo();
    c.getEmployeeInfo();

    return 0;
}

int exercise13_20()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        TextQuery tq(inFile);
        QueryResult qr = tq.query("//");
        print(cout, qr) << endl;

        TextQuery tq2 = tq;
        QueryResult qr2 = qr;
        print(cout, qr2) << endl;
        qr2 = tq2.query("program");
        print(cout, qr2) << endl;
    }

    inFile.close();
    return 0;
}

int exercise13_21()
{
    return 0;
}

int exercise13_22()
{
    return 0;
}

int exercise13_23()
{
    exercise13_13();
    return 0;
}

int exercise13_24()
{
    return 0;
}

int exercise13_25()
{
    return 0;
}

int exercise13_26()
{
    StrBlob a({"abc", "def"});
    StrBlob b;
    a.show_data();
    b.show_data();

    // Before assignment, data use count 1
    // After assignment, data use count 2
    // temp also point to the shared pointer.
    b = a;
    //     Current data use count 1
    // abc , def ,
    // temp was destoryed.
    b.show_data();
    // Current data use count 1
    // abc , def ,
    a.show_data();
    return 0;
}

int exercise13_27()
{
    PlHasPtr a("this is a HasPtr", 2);
    PlHasPtr b("second hasptr", 5);
    cout << a << b;
    a = b;
    cout << a;
    PlHasPtr *c = new PlHasPtr("let's try");
    PlHasPtr d[3] = {a, b, *c};
    cout << d[0] << d[1] << d[2];
    delete c;
    return 0;
}

int exercise13_28()
{
    TreeNode root("root", 10);
    TreeNode leftLeaf("leftLeaf", 4);
    TreeNode rightLeaf("rightLeaf", 6);

    root.setLeft(&leftLeaf);
    root.setRight(&rightLeaf);

    cout << root;

    TreeNode cpRoot;
    cpRoot = root;

    cout << cpRoot;

    cpRoot.setLeft(new TreeNode("newleft", 5));
    cpRoot.setRight(new TreeNode("newright", 7));
    cout << cpRoot;

    delete cpRoot.getLeft();
    delete cpRoot.getRight();
    return 0;
}

int exercise13_29()
{
    // inline void swap(HasPtr &lhs, HasPtr &rhs)
    // {
    //  using std::swap;
    //  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    //  swap(lhs.i, rhs.i); // swap the int members
    // }
    return 0;
}

int exercise13_30()
{
    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");
    cout << a << b;
    swap(a, b);
    cout << a << b;
    return 0;
}

int exercise13_31()
{

    HasPtr a("this is a HasPtr", 1);
    HasPtr b("second hasptr", 100);
    HasPtr c("third hasptr", 2);
    cout << "a < b : " << (a < b) << "\n";
    cout << "b < a : " << (b < a) << "\n";

    vector<HasPtr> vec{a,b,c};

    for (const auto & item : vec)
    {
        cout << item << "\n";
    }

    // we're using copy and swap version of operator=
    std::sort(vec.begin(),vec.end());
    cout << "After sort \n";
    for (const auto & item : vec)
    {
        cout << item << "\n";
    }
// ps point to this is a HasPtr , i is 1 , ps is 0x1f776b0
// ps point to second hasptr , i is 100 , ps is 0x1f776d0
// ps point to third hasptr , i is 2 , ps is 0x1f776f0
// swap called 
// swap called 
// swap called 
// After sort 
// ps point to this is a HasPtr , i is 1 , ps is 0x1f776b0
// ps point to third hasptr , i is 2 , ps is 0x1f776f0
// ps point to second hasptr , i is 100 , ps is 0x1f776d0

    return 0;
}

int exercise13_32()
{
    exercise13_27();
    return 0;
}

int exercise13_33()
{
    return 0;
}

int exercise13_34()
{
    return 0;
}

int exercise13_35()
{
    return 0;
}

int exercise13_36()
{
    return 0;
}

int exercise13_37()
{
    return 0;
}

int exercise13_38()
{
    return 0;
}

int exercise13_39()
{
    return 0;
}

int exercise13_40()
{
    return 0;
}

int exercise13_41()
{
    return 0;
}

int exercise13_42()
{
    return 0;
}

int exercise13_43()
{
    return 0;
}

int exercise13_44()
{
    return 0;
}

int exercise13_45()
{
    return 0;
}

int exercise13_46()
{
    return 0;
}

int exercise13_47()
{
    return 0;
}

int exercise13_48()
{
    return 0;
}

int exercise13_49()
{
    return 0;
}

int exercise13_50()
{
    return 0;
}

int exercise13_51()
{
    return 0;
}

int exercise13_52()
{
    return 0;
}

int exercise13_53()
{
    return 0;
}

int exercise13_54()
{
    return 0;
}

int exercise13_55()
{
    return 0;
}

int exercise13_56()
{
    return 0;
}

int exercise13_57()
{
    return 0;
}

int exercise13_58()
{
    return 0;
}
