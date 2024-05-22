#include "chapter15.h"

int VirtualBase::getMemPublic()
{
    return priv_mem;
}

int VirtualBaseDerv::getMemPublic()
{
    return VirtualBase::getMemPublic() * 2;
}

int VirtualBaseDerv::getProtMem()
{
    return prot_mem;
}

int testAccessControl()
{
    Pub_Derv a;
    Prot_Derv b;
    Priv_Derv c;
    cout << "Pub derv, " << a.d() << ", " << a.f() << endl;
    cout << "Prot derv, " << b.d() << ", " << b.f() << endl;
    cout << "Priv derv, " << c.d() << ", " << c.f() << endl;

    Derived_from_Pub aa;
    Derived_from_Prot bb;
    Derived_from_Priv cc;

    cout << "Derived_from_Pub, " << aa.g() << ", " << aa.h() << endl;
    // [build] /home/tian/projects/hellocpp/CppPrimer5th/chapter15/chapter15.h:36:19: error: ‘int Base::pub_mem’ is inaccessible
    // [build]      int pub_mem = 1; // public member
    // [build]                    ^
    // [build] /home/tian/projects/hellocpp/CppPrimer5th/chapter15/chapter15.cpp:18:69: error: within this context
    // [build]      cout << "Derived_from_Prot, " << bb.g() << ", " << bb.h() << bb.pub_mem << "," << bb.prot_mem << endl;
    // [build]                                                                      ^
    // [build] In file included from /home/tian/projects/hellocpp/CppPrimer5th/chapter15/chapter15.cpp:1:0:
    // [build] /home/tian/projects/hellocpp/CppPrimer5th/chapter15/chapter15.h:38:20: error: ‘int Base::prot_mem’ is protected
    // [build]      int prot_mem = 2; // protected member
    // [build]                     ^
    // cout << "Derived_from_Prot, " << bb.g() << ", " << bb.h() << bb.pub_mem << "," << bb.prot_mem << endl;
    cout << "Derived_from_Prot, " << bb.g() << ", " << bb.h() << endl;
    // cout << "Derived_from_Priv, " << cc.g() << ", " << cc.h() << endl;

    return 0;
}

ostream &operator<<(ostream &os, Quote &q)
{
    os << q.isbn() << ", " << q.price << "\n";
    return os;
}

ostream &operator<<(ostream &os, Bulk_quote &bq)
{
    os << bq.isbn() << ", " << bq.price << ", 100:" << bq.net_price(100) << ", 20:" << bq.net_price(20) << "\n";
    return os;
}

ostream &operator<<(ostream &os, Spec_quote &bq)
{
    os << bq.isbn() << ", " << bq.price << ", 100:" << bq.net_price(100) << ", 20:" << bq.net_price(20) << "\n";
    return os;
}

int exercise15_1()
{
    VirtualBase a;
    VirtualBaseDerv b;
    cout << a.getMemPublic() << ", " << b.getMemPublic() << endl;
    return 0;
}

int exercise15_2()
{
    VirtualBase a;
    VirtualBaseDerv b;
    cout << a.getMemPublic() << ", " << b.getMemPublic() << ", " << b.getProtMem() << endl;

    cout << b.pub_mem << endl;
    // Error: uesr of driv class has no access to base class's protected mem.
    // cout << b.prot_mem << endl;

    return 0;
}

int exercise15_3()
{

    Quote item("abc", 1.12);                // object of base type
    Bulk_quote bulk1("abc", 1.12, 99, 0.7); // object of derived type
    Bulk_quote bulk2("efg", 3.11, 99, 0.4); // object of derived type

    cout << item << bulk1 << bulk2;

    return 0;
}
int exercise15_4()
{
    return 0;
}
int exercise15_5()
{
    return 0;
}
int exercise15_6()
{
    return 0;
}
int exercise15_7()
{
    Quote item("abc", 1.12);                // object of base type
    Bulk_quote bulk1("abc", 1.12, 99, 0.7); // object of derived type
    Spec_quote bulk2("efg", 3.11, 50, 0.4); // object of derived type

    cout << item << bulk1 << bulk2;

    return 0;
}

int exercise15_8()
{
    return 0;
}

int exercise15_9()
{

    Quote item("abc", 1.12);                // object of base type
    Bulk_quote bulk1("abc", 1.12, 99, 0.7); // object of derived type
    Bulk_quote bulk2("efg", 3.11, 99, 0.4); // object of derived type

    // Static type : Quote *; dynamic type: Bulk_quote *
    Quote *item2 = &bulk1;
    // Static type : Quote &; dynamic type: Bulk_quote
    Quote &item3 = bulk2;

    // Static type: Quote::net_Price; dynamic type: Bulk_quote::net_price
    cout << item.net_price(100) << ", " << item2->net_price(100) << ", " << item3.net_price(100) << "\n";

    return 0;
}

int exercise15_10()
{
    return 0;
}

int exercise15_11()
{
    Quote item("abc", 1.12);                // object of base type
    Bulk_quote bulk1("abc", 1.12, 99, 0.7); // object of derived type
    Spec_quote bulk2("efg", 3.11, 50, 0.4); // object of derived type

    // Static type : Quote *; dynamic type: Bulk_quote *
    Quote *item2 = &bulk1;
    // Static type : Quote &; dynamic type: Spec_quote
    Quote &item3 = bulk2;

    item.debug();
    cout << endl;
    item2->debug();
    cout << endl;
    item3.debug();
    cout << endl;

    return 0;
}

int exercise15_12()
{
    return 0;
}

int exercise15_13()
{
    base1 b1;
    b1.setName("no base name");
    cout << b1.name();
    derived d1;

    d1.setName("I have base name");

    b1.print(cout);
    d1.print(cout);

    return 0;
}

int exercise15_14()
{

    base1 bobj;
    bobj.setName("no base name");
    base1 *bp1 = &bobj;
    base1 &br1 = bobj;
    derived dobj;
    dobj.setName("I have base name");
    base1 *bp2 = &dobj;
    base1 &br2 = dobj;

    cout << "1:";
    bobj.print();
    cout << "\n 2:";
    dobj.print();
    cout << "\n 3:";
    cout << bp1->name();
    cout << "\n 4:";
    cout << bp2->name();
    cout << "\n 5:";
    br1.print();
    cout << "\n 6:";
    br2.print();

    return 0;
}

int exercise15_15()
{
    // see Bulk_quote_2 and Spec_quote_2
    return 0;
}

int exercise15_16()
{
    // see Bulk_quote_2 and Spec_quote_2
    return 0;
}

int exercise15_17()
{
    // error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
    //  because the following virtual functions are pure within ‘Disc_quote’:
    // virtual double Disc_quote::net_price(std::size_t) const
    // Disc_quote dq("no name",1.1, 100, 0.6);
    return 0;
}

int exercise15_18()
{
    // 只有公有继承才能将基类指针或引用绑定到派生类对象上。
    //     For any given point in your code, if a public member of the base class
    // would be accessible, then the derived-to-base conversion is also accessible,
    // and not otherwise.
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Pub dd1;
    Derived_from_Prot dd2;
    Derived_from_Priv dd3;
    Base *p = &d1; // d1 has type Pub_Derv, Legal
    cout << p->pub_mem << "\n";
    // p = &d2;       // d2 has type Priv_Derv. Illegal,  ‘Base’ is an inaccessible base of ‘Priv_Derv’
    // p = &d3;       // d3 has type Prot_Derv. Illegal,  error: ‘Base’ is an inaccessible base of ‘Prot_Derv’
    p = &dd1; // dd1 has type Derived_from_Public，
    cout << p->pub_mem << "\n";
    // p = &dd2;      // dd2 has type Derived_from_Private
    // p = &dd3;      // dd3 has type Derived_from_Protected
    return 0;
}

int exercise15_19()
{
    // done. only Derived_from_Priv have error.
    return 0;
}

int exercise15_20()
{
    return 0;
}

int exercise15_21()
{
    return 0;
}

int exercise15_22()
{
    return 0;
}

int exercise15_23()
{
    Base3 a, *e;
    D1 b;
    D2 c;

    e = &b;
    cout << a.fcn() << "\n"
         << b.fcn() << "\n"
         << c.fcn() << "\n"
         << e->fcn() << "\n";

    e = &c;
    cout << a.fcn() << "\n"
         << b.fcn() << "\n"
         << c.fcn() << "\n"
         << e->fcn() << "\n";

    return 0;
}

int exercise15_24()
{
    return 0;
}
int exercise15_25()
{
    return 0;
}
int exercise15_26()
{
    return 0;
}
int exercise15_27()
{
    return 0;
}
int exercise15_28()
{
    return 0;
}
int exercise15_29()
{
    return 0;
}
int exercise15_30()
{
    return 0;
}
int exercise15_31()
{
    return 0;
}
int exercise15_32()
{
    return 0;
}
int exercise15_33()
{
    return 0;
}
int exercise15_34()
{
    return 0;
}
int exercise15_35()
{
    return 0;
}
int exercise15_36()
{
    return 0;
}
int exercise15_37()
{
    return 0;
}
int exercise15_38()
{
    return 0;
}
int exercise15_39()
{
    return 0;
}
int exercise15_40()
{
    return 0;
}
int exercise15_41()
{
    return 0;
}
int exercise15_42()
{
    return 0;
}
