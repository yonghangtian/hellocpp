#include "chapter10.h"

// 默认值应该在函数声明部分指出，不能在函数定义中出现默认值
Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT-1);
}

void Person::Show() const 
{
    cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
    cout << fname << "," << lname << endl;
}

int chapter10_2()
{ 
    string ln = "tian";
    char fn[] = "1234567891234567891234567891231";
    Person one;
    Person two("sam");
    Person three("lixinyi", "tian");
    // one.Show();
    // one.FormalShow(); 

    // two.Show();
    // two.FormalShow(); 

    // three.Show();
    // three.FormalShow(); 

    Person * a = new Person(ln, fn);
    a->Show();
    a->FormalShow();
    return 0; 
}

// 见chapter101文件夹
// int chapter10_3(){ return 0; }

// int chapter10_4(){ return 0; }

// definition of stack
Stack::Stack()    
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item) 
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];

        return true;
    }
    else
        return false; 
}

int chapter10_5()
{ 
    Stack s1;
    double runningTotal = 0.0;
    customer c[] = {
        {"tian yonghang", 10.01},
        {"li xinyi", 20.0222},
        {"land lord", 30.4}
    };

    int len = sizeof(c)/sizeof(c[0]);

    for (int i = 0; i < len; i ++)
    {
        
        s1.push(c[i]);
    }
    
    customer temp;
    while (!s1.isempty())
    {
        s1.pop(temp);
        runningTotal += temp.payment;
        std::cout << "Current running total is: " << runningTotal << std::endl;
    }
    return 0; 
}

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std::cout<< "x = " << x << ", y = " << y << std::endl;
}

Move Move::add(const Move & m) const
{
    return Move(this->x + m.x, this->y + m.y);
}

void Move::reset(double a, double b)
{
    this->x = a;
    this->y = b;
}


int chapter10_6()
{ 
    Move m1(10.1, 9.9);
    Move m2(1.1,4.3);

    Move m3 = m1.add(m2);
    m3.showmove();

    m3.reset(1,1);
    m3.showmove();

    return 0; 
}

Plorg::Plorg(const char * n, const int m)
{
    strncpy(name, n, MAX-1);
    ci = m;
}

void Plorg::setPlorg(const char * n)
{
    strncpy(name, n, MAX-1);
}

void Plorg::setCI(const int m)
{
    ci = m;
}

void Plorg::showPlorg() const
{
    std::cout << "Plorg's name is " << name << " and it's CI is " << ci << std::endl;
}


int chapter10_7()
{ 
    Plorg a;
    Plorg b("tianyonghang");

    a.setPlorg("lixinyi");
    b.setCI(100);

    a.showPlorg();
    b.showPlorg();

    return 0; 
}

ItemList::ItemList()
{
    count = 0;
}

bool ItemList::isEmpty() const
{
    return count == 0;
}

bool ItemList::isFull() const
{
    return count == MAX;
}

int ItemList::itemCount() const
{
    return count;
}

bool ItemList::addItem(const Item & item)
{
    if (count < MAX)
    {
        items[count++] = item;
        return true;
    } 

    return false;
}

void ItemList::visit(void (*pf)(Item &))
{
    for(int i = 0; i < count; i++)
        (*pf)(items[i]);
}

void ItemList::show() const
{
    for(int i = 0; i < count; i++)
    {
        std::cout << items[i].fullname << "," << items[i].payment << std::endl;
    }
}

void addInt(Item & x);

int chapter10_8()
{ 
    ItemList s1;
    customer c[] = {
        {"tian yonghang", 10.01},
        {"li xinyi", 20.0222},
        {"land lord", 30.4}
    };

    int len = sizeof(c)/sizeof(c[0]);

    for (int i = 0; i < len; i ++)
    {
        
        s1.addItem(c[i]);
    }
    std::cout << s1.itemCount() << endl;
    s1.show();

    s1.visit(addInt);

    s1.show();

    return 0; 
}

void addInt(Item & x)
{
    x.payment += 100;
}