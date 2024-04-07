#include "chapter7.h"

const double TestStatic::interestRate = initRate();
double TestStatic::interestRateTwo = initRate();

//   ERROR: assignment of read-only variable 'TestStatic::interestRate'
// void TestStatic::rate(double newRate)
// {
//     interestRate = newRate;
// }

void TestStatic::rateTwo(double newRate)
{
    interestRateTwo = newRate;
}

void Screen::show(std::ostream &os) const
{
    for (int i = 0; i != this->height; ++i)
    {
        for (int j = 0; j != this->width; ++j)
        {
            os << contents[i * width + j] << ' ';
        }
        os << endl;
    }
}

Screen &Screen::move(pos row, pos col)
{
    pos temp = cursor + row * width + col;

    if (temp < width * height)
        cursor = temp;
    else
    {
        cout << "your input row " << row << " and col " << col << " will move cursor" << cursor << " out of range" << endl;
    }

    return *this;
}

inline Screen &Screen::set(pos row, pos col, char var)
{
    contents[row * width + col] = var;
    return *this;
}

inline Screen &Screen::set(char var)
{
    contents[cursor] = var;
    return *this;
}

Window_mgr::Window_mgr(pos h, pos w, char cts, size_t a)
{
    for (size_t s = 0; s != a; ++s)
    {
        Screen screen(h, w, cts);
        screens.push_back(screen);
    }
}

void Window_mgr::clear(size_t a)
{
    if (a < screens.size())
    {
        Screen emptyScreen(0, 0, 0, ' ');
        screens[a] = emptyScreen;
    }
}

void Window_mgr::show(std::ostream &os) const
{
    for (const auto &screen : screens)
        screen.show(cout);
}

Sales_data::Sales_data(unsigned n, std::istream &is)
{
    // unsigned n does nothing, but make this constructor different from the default constructor
    // read will read a transaction from is into this object
    read(is, *this);
}

// add the value of the given Sales_data into this object
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    cout << "Sales_data &Sales_data::combine(const Sales_data &rhs)" << endl;
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ``this'' object
    return *this;                 // return the object on which the function was called
}

// Sales_data &Sales_data::combine(const Sales_data rhs)
// {
//     cout << "Sales_data &Sales_data::combine(const Sales_data rhs)" << endl;
//     units_sold += rhs.units_sold; // add the members of rhs into
//     revenue += rhs.revenue;       // the members of ``this'' object
//     return *this;                 // return the object on which the function was called
// }

// Sales_data &Sales_data::combine(const Sales_data &rhs) const
// {
//     cout << "Sales_data &Sales_data::combine(const Sales_data &rhs) const" << endl;
//     Sales_data sd(bookNo, units_sold + rhs.units_sold, revenue + rhs.revenue);
//     return *this; // return the object on which the function was called
// }

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);     // add data members from rhs into sum
    return sum;
}

bool Sales_data::operator==(const Sales_data &a) const
{
    return (a.bookNo == bookNo) && (a.units_sold == units_sold) && (a.revenue == revenue);
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    if (isbn() == rhs.isbn())
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
    }
    return *this;
}

// transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &
operator>>(std::istream &in, Sales_data &s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_data(); // input failed: reset object to default state
    return in;
}

std::ostream &
operator<<(std::ostream &out, const Sales_data &s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    if (lhs.isbn() == rhs.isbn())
    {
        sum += rhs;
    }
    return sum;
}

bool compareIsbn(const Sales_data &a, const Sales_data &b)
{
    return (a.isbn() < b.isbn()) ? true : false;
}

Type initVal()
{
    return 2.2;
}

Type Exercise::initVal()
{
    return 3.3;
}

Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}

// define static data and function members
const string Account::accountType("Savings Account");
double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Example::rate = 6.5;
vector<double> Example::vec(Example::vecSize);

int exercise7_1()
{

    cout << TestStatic::rate() << endl;
    cout << TestStatic::rateTwo() << endl;

    // TestStatic::rate(0.1);
    TestStatic::rateTwo(0.3);

    cout << TestStatic::rate() << endl;
    cout << TestStatic::rateTwo() << endl;

    return 0;
}

int exercise7_23()
{

    Screen a(7, 8, 'a');
    a.show(cout);
    return 0;
}

int exercise7_24()
{
    Screen a(7, 8, 'a');
    Screen b(10, 10, 10, 'b');
    Screen c;

    a.show(cout);
    b.show(cout);
    c.show(cout);
    return 0;
}

int exercise7_25()
{

    Screen a(7, 8, 'a');
    Screen b(10, 10, 10, 'b');

    Screen d = a;
    Screen f(b);

    a.show(cout);
    b.show(cout);
    d.show(cout);
    f.show(cout);
    return 0;
}

int exercise7_26()
{
    Sales_data a("pride", 10, 9.99);
    Sales_data b("pride", 20, 8.88);

    a.combine(b);

    cout << a.avg_price() << endl;

    return 0;
}

int exercise7_27()
{
    char chr = '*';
    Screen myScreen(5, 5, chr);
    myScreen.move(4, 1).set('#').show(cout);
    cout << "\n";
    myScreen.show(cout);
    cout << "\n";
    return 0;
}
int exercise7_28() { return 0; }

int exercise7_29()
{
    return 0;
}

int exercise7_30()
{
    // 优点：
    // 清晰性：使用"this"指针可以明确地指示正在访问的是类的成员。这可以提高代码的可读性，使读者更容易理解代码的意图。
    // 解决名称冲突：当成员变量和局部变量或参数具有相同的名称时，使用"this"指针可以消除歧义。通过"this->member"的语法，可以明确地指定要访问的是成员变量而不是局部变量或参数。
    // 强调对象的身份：使用"this"指针可以强调当前操作是在对象的上下文中进行的。这有助于在面向对象的编程中更好地理解和跟踪对象的状态和行为。

    // 缺点：
    // 冗余性：在大多数情况下，不使用"this"指针也可以正常访问成员。因此，显式使用"this"指针可能会增加代码的冗余性，降低简洁性。
    // 可读性：对于不熟悉"this"指针的开发者来说，显式使用"this"指针可能会降低代码的可读性。他们可能需要额外的时间来理解代码中的"this"指针的含义和用法。
    // 潜在的性能影响：虽然现代编译器通常会对"this"指针进行优化，但在某些情况下，显式使用"this"指针可能会导致微小的性能开销。这是因为每次访问成员时都需要通过"this"指针进行间接引用。
    return 0;
}

int exercise7_31()
{
    // class Y;
    // class X
    // {
    //     Y *part1;
    // };

    // class Y
    // {
    //     X part2;
    // };
    return 0;
}

int exercise7_32()
{
    size_t b = 2;
    Window_mgr a(5, 5, '*', 2);
    a.show(cout);
    cout << "---" << endl;
    a.clear(1);
    a.show(cout);
    return 0;
}
int exercise7_33()
{

    Screen a(5, 5, '*');
    cout << a.size() << endl;

    return 0;
}

int exercise7_34()
{
    Screen a(5, 5, '*');
    cout << a.size() << endl;
    return 0;
}
int exercise7_35()
{

    Exercise ex("test");

    cout << ex.setVal(0.0) << endl;

    return 0;
}

int exercise7_36()
{
    struct X
    {
        X(int i, int j) : base(i), rem(base % j) {}
        int base, rem;
    };

    X example(20, 3);

    cout << example.base << ", " << example.rem << endl;
    return 0;
}

int exercise7_37()
{
    Sales_data first_item(1, cin);    // cin constructor
    Sales_data next;                  // default constructor
    Sales_data last("9-999-99999-9"); // Sales_data(const std::string &s) : bookNo(s) {}
    print(cout, first_item);
    print(cout, next);
    print(cout, last);
    return 0;
}

int exercise7_38()
{
    Sales_data first_item(1);
    print(cout, first_item);
    return 0;
}

int exercise7_39()
{
    // Exercise ex;

    return 0;
}
int exercise7_40() { return 0; }

int exercise7_41()
{
    Sales_data sd1("example");

    Sales_data sd2("example", 1, 1.2);
    return 0;
}

int exercise7_42() { return 0; }

int exercise7_43()
{
    C obj; // Creating an instance of C using its default constructor
    std::cout << "Object created!" << std::endl;

    return 0;
}
int exercise7_44()
{
    // no matching function for call to ‘NoDefault::NoDefault()’
    // vector<NoDefault> vec(10);
    return 0;
}

int exercise7_45()
{
    vector<C> vec(10);
    return 0;
}

int exercise7_46() { return 0; }
int exercise7_47() { return 0; }

int exercise7_48()
{
    string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    print(cout, item1);

    Sales_data item2("9-999-99999-9");
    print(cout, item2);
    return 0;
}

int exercise7_49()
{

    Sales_data sd1("9999", 100, 9.99);

    string str("9999");

    sd1.combine(str);

    return 0;
}
int exercise7_50() { return 0; }
int exercise7_51() { return 0; }
int exercise7_52()
{
    Sales_data item{"978-0590353403", 25, 15.99};
    // two initialize method are same, both using cpp 11's list initialization
    // Sales_data item = {"978-0590353403", 25, 15.99};
    print(cout, item);

    return 0;
}

int exercise7_53()
{

    Debug db;
    db.set_io(false);

    db.set_other(false);

    return 0;
}

int exercise7_54() { return 0; }
int exercise7_55() { return 0; }
int exercise7_56() { return 0; }
int exercise7_57()
{
    Account ac("tian", 2.0);
    cout << ac.balance() << endl;

    ac.calculate();
    cout << ac.balance() << endl;

    return 0;
}
int exercise7_58()
{

    Example ex1;

    cout << ex1.rate << ", " << ex1.vecSize << endl;

    for (const auto &a : Example::vec)
    {
        cout << a << ", ";
    }

    return 0;
}

unsigned long g_a = 0, g_b = 0;

void thread_routine(unsigned long *a)
{
    int cpu = -1;
    while (true)
    {
        int cur_cpu = sched_getcpu();
        if (cur_cpu != cpu)
        {
            cout << "pre:" << cpu << ", cur:" << cur_cpu << std::endl;
            cpu = cur_cpu;
        }
        ++*a;
    }
}

// tian@tian-mb13:~/projects/hellocpp/build$ taskset -c 0 ./HelloCpp
// pre:-1, cur:0
// pre:-1, cur:0
// g_a: 2.13e+09 g_b: 2.14e+09
// tian@tian-mb13:~/projects/hellocpp/build$ taskset -c 0,10 ./HelloCpp
// pre:-1, cur:10pre:-1, cur:0
// g_a: 1.41e+09 g_b: 1.41e+0
// 测试结果显示：两个线程绑定在同一个核上时，计算效果比两个线程放在两个核心上效果更好。
int testThreads()
{
    std::thread thread1(&thread_routine, &g_a);
    thread1.detach();

    std::thread thread2(&thread_routine, &g_b);
    thread2.detach();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    cout << std::scientific << std::setprecision(2) << "g_a: " << static_cast<long double>(g_a) << " g_b: " << static_cast<double>(g_b);

    return 0;
}