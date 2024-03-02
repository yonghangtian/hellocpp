#include "chapter12.h"
#include "../examples/12/StrBlob.h"

int exercise12_1()
{
    StrBlob b1;

    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        b2.show_data();
    }

    b1.show_data();

    return 0;
}

int exercise12_2()
{
    cout << "I use ../examples/12/StrBlob.h instead;";
    return 0;
}

int exercise12_3()
{
    return 0;
}

int exercise12_4()
{
    return 0;
}

int exercise12_5()
{
    // If "StrBlob(std::initializer_list<std::string> il);" is defined "explicit", there is error:
    // [build]  error: converting to ‘StrBlob’ from initializer list would use explicit constructor ‘StrBlob::StrBlob(std::initializer_list<std::__cxx11::basic_string<char> >)’
    // [build]     9 |         StrBlob b2 = {"a", "an", "the"};
    StrBlob b1 = {"a", "an", "the"};

    b1 = {"b", "c", "d"};

    StrBlob b2{"e", "f"};

    b2 = {"ahhahahh"};

    b1.show_data();
    b2.show_data();

    return 0;
}

std::vector<int> *getVectorPointer(std::vector<int> &a)
{
    return &a;
}

void getIntFromCin(std::istream &input, std::vector<int> *data)
{
    cout << "Please input integers \n";
    int a(0);
    while (input >> a)
    {
        data->push_back(a);
    }
}

void showVectorUsingPointer(std::vector<int> *data)
{
    for (auto temp : *data)
    {
        std::cout << temp << " , ";
    }
    std::cout << std::endl;
}

int exercise12_6()
{
    std::vector<int> a{10, 9, 8};
    std::vector<int> *temp = getVectorPointer(a);
    getIntFromCin(cin, temp);
    showVectorUsingPointer(temp);

    delete temp;
    temp = nullptr;
    return 0;
}

std::shared_ptr<std::vector<int>> getVectorSharedPointer(std::vector<int> a)
{
    return std::make_shared<std::vector<int>>(a);
}

void getIntFromCinSharedPointer(std::istream &input, std::shared_ptr<std::vector<int>> data)
{
    cout << "Please input integers(shared pointer version) \n";
    int a(0);
    while (input >> a)
    {
        data->push_back(a);
    }
}

void showVectorUsingSharedPointer(std::shared_ptr<std::vector<int>> data)
{
    for (auto temp : *data)
    {
        std::cout << temp << " , ";
    }
    std::cout << std::endl;
}

int exercise12_7()
{
    std::vector<int> a{10, 9, 8};
    std::shared_ptr<std::vector<int>> temp = getVectorSharedPointer(a);
    getIntFromCinSharedPointer(cin, temp);
    showVectorUsingSharedPointer(temp);

    cout << temp.use_count() << endl;

    return 0;
}

int exercise12_8()
{
    return 0;
}

int exercise12_9()
{

    int *q = new int(42), *r = new int(100);
    cout << "*r " << *r << " *q " << *q << "\n";
    delete r;
    r = q;
    cout << "*r " << *r << " *q " << *q << "\n";
    auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
    cout << "*r2 " << *r2 << " *q2 " << *q2 << "\n";
    cout << "before r2 = q2, r2 use cout " << r2.use_count() << "\n";
    cout << "before r2 = q2, q2 use cout " << q2.use_count() << "\n";
    r2 = q2;
    cout << "after r2 = q2, r2 use cout " << r2.use_count() << "\n";
    cout << "after r2 = q2, q2 use cout " << q2.use_count() << "\n";
    cout << "*r2 " << *r2 << " *q2 " << *q2 << "\n";

    return 0;
}

void processSharedPointer(std::shared_ptr<int> ptr)
{
    cout << ptr.use_count() << "\n";
} // ptr goes out of scope and is destroyed

int exercise12_10()
{
    int *p(new int(41));
    processSharedPointer(std::shared_ptr<int>(p));

    // p is a dangling pointer!
    cout << *p << endl;

    // p(new int(42));

    return 0;
}

int exercise12_11()
{
    std::shared_ptr<int> p(new int(41));
    // free(): double free detected in tcache 2
    // We shouldn't init two unique shared ptr to the same memory.
    processSharedPointer(std::shared_ptr<int>(p.get()));

    return 0;
}

int exercise12_12()
{

    auto p = new int(1);
    auto sp = std::make_shared<int>(41);
    processSharedPointer(sp);
    // error: could not convert ‘p’ from ‘int*’ to ‘std::shared_ptr<int>’
    //  processSharedPointer(new int());
    //  error: could not convert ‘p’ from ‘int*’ to ‘std::shared_ptr<int>’
    //  processSharedPointer(p);
    processSharedPointer(std::shared_ptr<int>(p));

    return 0;
}

int exercise12_13()
{
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    delete p;

    return 0;
}

int exercise12_14()
{
    return 0;
}

int exercise12_15()
{
    return 0;
}

int exercise12_16()
{
    return 0;
}

int exercise12_17()
{
    return 0;
}

int exercise12_18()
{
    return 0;
}

int exercise12_19()
{
    return 0;
}

int exercise12_20()
{
    return 0;
}

int exercise12_21()
{
    return 0;
}

int exercise12_22()
{
    return 0;
}

int exercise12_23()
{
    return 0;
}

int exercise12_24()
{
    return 0;
}

int exercise12_25()
{
    return 0;
}

int exercise12_26()
{
    return 0;
}

int exercise12_27()
{
    return 0;
}

int exercise12_28()
{
    return 0;
}

int exercise12_29()
{
    return 0;
}

int exercise12_30()
{
    return 0;
}

int exercise12_31()
{
    return 0;
}

int exercise12_32()
{
    return 0;
}

int exercise12_33()
{
    return 0;
}
