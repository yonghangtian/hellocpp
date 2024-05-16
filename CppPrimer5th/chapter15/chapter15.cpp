#include "chapter15.h"


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
int exercise15_1(){ return 0; }
int exercise15_2(){ return 0; }
int exercise15_3(){ return 0; }
int exercise15_4(){ return 0; }
int exercise15_5(){ return 0; }
int exercise15_6(){ return 0; }
int exercise15_7(){ return 0; }
int exercise15_8(){ return 0; }
int exercise15_9(){ return 0; }
int exercise15_10(){ return 0; }
int exercise15_11(){ return 0; }
int exercise15_12(){ return 0; }
int exercise15_13(){ return 0; }
int exercise15_14(){ return 0; }
int exercise15_15(){ return 0; }
int exercise15_16(){ return 0; }
int exercise15_17(){ return 0; }
int exercise15_18(){ return 0; }
int exercise15_19(){ return 0; }
int exercise15_20(){ return 0; }
int exercise15_21(){ return 0; }
int exercise15_22(){ return 0; }
int exercise15_23(){ return 0; }
int exercise15_24(){ return 0; }
int exercise15_25(){ return 0; }
int exercise15_26(){ return 0; }
int exercise15_27(){ return 0; }
int exercise15_28(){ return 0; }
int exercise15_29(){ return 0; }
int exercise15_30(){ return 0; }
int exercise15_31(){ return 0; }
int exercise15_32(){ return 0; }
int exercise15_33(){ return 0; }
int exercise15_34(){ return 0; }
int exercise15_35(){ return 0; }
int exercise15_36(){ return 0; }
int exercise15_37(){ return 0; }
int exercise15_38(){ return 0; }
int exercise15_39(){ return 0; }
int exercise15_40(){ return 0; }
int exercise15_41(){ return 0; }
int exercise15_42(){ return 0; }
