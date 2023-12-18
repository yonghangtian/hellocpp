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

void Screen::show() const
{
    for (int i = 0; i != this->height; ++i)
    {
        for (int j = 0; j != this->width; ++j)
        {
            cout << contents[i * j] << ' ';
        }
        cout << endl;
    }
}

Sales_data::Sales_data(std::istream &is)
{
    // read will read a transaction from is into this object
    read(is, *this);
}

// add the value of the given Sales_data into this object
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ``this'' object
    return *this;                 // return the object on which the function was called
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);     // add data members from rhs into sum
    return sum;
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
    a.show();
    return 0;
}

int exercise7_24()
{
    Screen a(7, 8, 'a');
    Screen b(10, 10, 10, 'b');
    Screen c;

    a.show();
    b.show();
    c.show();
    return 0;
}

int exercise7_25()
{

    Screen a(7, 8, 'a');
    Screen b(10, 10, 10, 'b');

    Screen d = a;
    Screen f(b);

    a.show();
    b.show();
    d.show();
    f.show();
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
int exercise7_27() { return 0; }
int exercise7_28() { return 0; }
int exercise7_29() { return 0; }
int exercise7_30() { return 0; }
int exercise7_31() { return 0; }
int exercise7_32() { return 0; }
int exercise7_33() { return 0; }
int exercise7_34() { return 0; }
int exercise7_35() { return 0; }
int exercise7_36() { return 0; }
int exercise7_37() { return 0; }
int exercise7_38() { return 0; }
int exercise7_39() { return 0; }
int exercise7_40() { return 0; }
int exercise7_41() { return 0; }
int exercise7_42() { return 0; }
int exercise7_43() { return 0; }
int exercise7_44() { return 0; }
int exercise7_45() { return 0; }
int exercise7_46() { return 0; }
int exercise7_47() { return 0; }
int exercise7_48() { return 0; }
int exercise7_49() { return 0; }
int exercise7_50() { return 0; }
int exercise7_51() { return 0; }
int exercise7_52() { return 0; }
int exercise7_53() { return 0; }
int exercise7_54() { return 0; }
int exercise7_55() { return 0; }
int exercise7_56() { return 0; }
int exercise7_57() { return 0; }
int exercise7_58() { return 0; }


unsigned long g_a = 0, g_b = 0;

void thread_routine(unsigned long * a)
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

// tianyh@tian-mb13:~/projects/hellocpp/build$ taskset -c 0 ./HelloCpp 
// pre:-1, cur:0
// pre:-1, cur:0
// g_a: 2.13e+09 g_b: 2.14e+09
// tianyh@tian-mb13:~/projects/hellocpp/build$ taskset -c 0,10 ./HelloCpp 
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

    cout << std::scientific << std::setprecision(2)  << "g_a: "  << static_cast<long double>(g_a)  << " g_b: " << static_cast<double>(g_b);

    return 0;
}