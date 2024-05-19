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
int exercise15_4() { return 0; }
int exercise15_5() { return 0; }
int exercise15_6() { return 0; }
int exercise15_7()
{
    Quote item("abc", 1.12);                // object of base type
    Bulk_quote bulk1("abc", 1.12, 99, 0.7); // object of derived type
    Spec_quote bulk2("efg", 3.11, 50, 0.4); // object of derived type

    cout << item << bulk1 << bulk2;

    return 0;
}
int exercise15_8() { return 0; }
int exercise15_9() { return 0; }
int exercise15_10() { return 0; }
int exercise15_11() { return 0; }
int exercise15_12() { return 0; }
int exercise15_13() { return 0; }
int exercise15_14() { return 0; }
int exercise15_15() { return 0; }
int exercise15_16() { return 0; }
int exercise15_17() { return 0; }
int exercise15_18() { return 0; }
int exercise15_19() { return 0; }
int exercise15_20() { return 0; }
int exercise15_21() { return 0; }
int exercise15_22() { return 0; }
int exercise15_23() { return 0; }
int exercise15_24() { return 0; }
int exercise15_25() { return 0; }
int exercise15_26() { return 0; }
int exercise15_27() { return 0; }
int exercise15_28() { return 0; }
int exercise15_29() { return 0; }
int exercise15_30() { return 0; }
int exercise15_31() { return 0; }
int exercise15_32() { return 0; }
int exercise15_33() { return 0; }
int exercise15_34() { return 0; }
int exercise15_35() { return 0; }
int exercise15_36() { return 0; }
int exercise15_37() { return 0; }
int exercise15_38() { return 0; }
int exercise15_39() { return 0; }
int exercise15_40() { return 0; }
int exercise15_41() { return 0; }
int exercise15_42() { return 0; }
