#include "chapter12.h"

Cow::Cow()
{
    name[0] = '\0'; 
    hobby = nullptr;
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 20);
    
    int len = std::strlen(ho);
    hobby = new char[len+1];
    std::strcpy(hobby, ho);

    weight = wt;
}

Cow::Cow(const Cow & c)
{
    strncpy(name, c.name, 20);
    
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby, c.hobby);

    weight = c.weight;
}

Cow & Cow::operator=(const Cow & c)
{
    delete [] hobby;

    strncpy(name, c.name, 20);
    
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby, c.hobby);

    weight = c.weight;

    return *this;
}

Cow::~Cow()
{
    delete [] hobby;
}

void Cow::ShowCow() const
{
    cout << "Cow's name is " << name << " hobby is " << hobby << " weight is " << weight << std::endl;
}

int chapter12_1()
{
    Cow a;
    Cow b("lxy","swimming", 54.4);

    b.ShowCow();
    a = b;
    a.ShowCow();

    Cow c(b);
    c.ShowCow();

    Cow d = (a = b);
    d.ShowCow();

    return 0; 
} 

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char [len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete [] str;                    // required
}

void String::stringlower()
{
    for (int i = 0; i < this->len; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
}

void String::stringupper()
{
    for (int i = 0; i < this->len; i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
}

int String::has(const char a) const
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == a)
        {
            result ++;
        }
    }

    return result;
}


// overloaded operator methods    

    // assign a String to a String
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

    // read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

    // read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

String operator+(const String &st1, const String &st2)
{
    int len1 = st1.len;
    int len2 = st2.len;
    char * str3 = new char[len1 + len2 + 1];
    std::strcpy(str3, st1.str);

    for (int i = 0; i < len2; i ++) 
    {
        str3[i+len1] = st2[i];
    }
    str3[len1+len2] = '\0';

    return String(str3);
}

    // simple String output
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os; 
}

    // quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is; 
}

int chapter12_2()
{

    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;               // overloaded << operator
    cin >> s3;                // overloaded >> operator
    s2 = "My name is " + s3;  // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringupper();            // converts string to uppercase
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
         << " 'A' characters in it.\n";
    s1 = "red";       // String(const char *),
                      // then String & operator=(const String&)
    String rgb[3] = { String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
      ans.stringlower();       // converts string to lowercase
      for (int i = 0; i < 3; i++)
      {
          if (ans == rgb[i]) // overloaded == operator
          {
              cout << "That's right!\n";
              success = true;
              break;
          }
      }
      if (success)
          break;
      else
          cout << "Try again!\n";
      }
      cout << "Bye\n";
      return 0;
}

// constructors
Stock::Stock()        // default constructor
{
    company = nullptr;
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
    int len = strlen(co);
    company = new char[len + 1];
    strcpy(company, co);

    if (n < 0)
    {
        cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()
{
    delete [] company;
}

// other methods
void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

    // simple String output
ostream & operator<<(ostream & os, const Stock & st)
{
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield); 
    std::streamsize prec = os.precision(3);

    os << "Company: " << st.company
        << "  Shares: " << st.shares << '\n';
    os << "  Share Price: $" << st.share_val;
    // set format to #.##
    os.precision(2);
    os << "  Total Worth: $" << st.total_val << '\n';

    // restore original format
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);

    return os;
}

void Stock::show() const
{
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield); 
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
        << "  Shares: " << shares << '\n';
    cout << "  Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

int chapter12_3()
{ 
    int STKS = 4;
    // create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();
    // set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    // now top points to the most valuable holding
    cout << "\nMost valuable holding:\n";
	top->show();
    // std::cin.get();

    cout << "using << operator" << std::endl;
    cout << "Stock holdings:\n";
    for (st = 0; st < STKS; st++)
        cout << stocks[st];
    // set pointer to first element
    top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    // now top points to the most valuable holding
    cout << "\nMost valuable holding:\n";
	cout << top;
    // std::cin.get();
    return 0;  
    return 0;  
} 

// definition of stack
Stack::Stack(int n)    
{
    if (n > MAX)
    {
        cout << "Stack can hold at most " << MAX << " items." << std::endl;
        n = MAX;
    }

    top = 0;
    size = n;

    pitems = new Item[n];
}

Stack::Stack(const Stack & st)
{
    cout << "Copy constructor called" << std::endl;
    cout << sizeof(st.pitems) << "," << sizeof(st.size) << "," << sizeof(st.top)  << std::endl;
    size = st.size;
    top = st.top;

    pitems = new Item[size];

    for (int i = 0; i < size; i++) 
    {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item) 
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];

        return true;
    }
    else
        return false; 
}

Stack & Stack::operator=(const Stack & st)
{
    cout << "Assignment operator called" << std::endl;
    if (this == &st)
        return *this;

    delete [] pitems;

    size = st.size;
    top = st.top;

    pitems = new Item[size];

    for (int i = 0; i < size; i++) 
    {
        pitems[i] = st.pitems[i];
    }

    return *this;
}

int chapter12_4()
{ 
    Stack s1(5);
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
    Stack s2(s1);
    Stack s3 = s1;

    s3 = s2;

    customer temp;
    while (!s1.isempty())
    {
        s1.pop(temp);
        runningTotal += temp.payment;
        std::cout << "Current running total is: " << runningTotal << std::endl;
    }

    cout << "Test copy constructor" << std::endl;
    runningTotal = 0.0;
    while (!s2.isempty())
    {
        s2.pop(temp);
        runningTotal += temp.payment;
        std::cout << "Current running total is: " << runningTotal << std::endl;
    }

    cout << "Test = operator" << std::endl;
    runningTotal = 0.0;
    while (!s3.isempty())
    {
        s3.pop(temp);
        runningTotal += temp.payment;
        std::cout << "Current running total is: " << runningTotal << std::endl;
    }

    return 0; 
} 


// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;    // or nullptr
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)   // while queue is not yet empty
    {
        temp = front;       // save address of front item
        front = front->next;// reset pointer to next item
        delete temp;        // delete former front
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// Add item to queue
bool Queue::enqueue(const Item2 & item)
{
    if (isfull())
        return false;
    Node * add = new Node;  // create node
// on failure, new throws std::bad_alloc exception
    add->item = item;       // set node pointers
    add->next = NULL;       // or nullptr;
    items++;
    if (front == NULL)      // if queue is empty,
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear
    rear = add;             // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item2 & item)
{
    if (front == NULL)
        return false;
    item = front->item;     // set item to first item in queue
    items--;
    Node * temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer2::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when; 
}

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int chapter12_5()
{ 
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    // cout << "Case Study: Bank of Heather Automatic Teller\n";
    // cout << "Enter maximum size of queue: ";
    int qs = 10;
    //cin >> qs;
    Queue line(qs);         // line queue holds up to qs people

    // cout << "Enter the number of simulation hours: ";
    int hours = 100;              //  hours of simulation
    //cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    // cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    //cin >> perhour;
    double min_per_cust;    //  average time between arrivals


    for (int i = 60; i > 0; i--)
    {
        Item2 temp; 
        // 清空上一轮模拟中残留的队列数据
        while (!line.isempty())
        {
            line.dequeue(temp);
        }

        //  new customer data
        long turnaways = 0;     //  turned away by full queue
        long customers = 0;     //  joined the queue
        long served = 0;        //  served during the simulation
        long sum_line1 = 0;      //  cumulative line length
        int wait_time1 = 0;      //  time until autoteller is free
        long line_wait = 0;     //  cumulative time in line

        perhour = i;    
        min_per_cust = MIN_PER_HR / perhour;
        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time1 <= 0 && !line.isempty())
            {
                line.dequeue (temp);      // attend next customer
                wait_time1 = temp.ptime(); // for wait_time1 minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line1 += line.queuecount();
        }

        // reporting results
        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double) sum_line1 / cyclelimit << endl;
            cout << " average wait time: "
                << (double)line_wait / served<< " minutes\n";

            if (( (double)line_wait / served) < 1)
            {
                cout << "Average person per hour is " << perhour << ", then average wait time is less than 1 minute." << endl;
                break;
            }
        }
        else
            cout << "No customers!\n";
        cout << "Done!\n";  
    }


    // cin.get();
    // cin.get();
    return 0;

} 

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}

int chapter12_6()
{ 
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    // cout << "Case Study: Bank of Heather Automatic Teller\n";
    // cout << "Enter maximum size of queue: ";
    int qs = 10;
    //cin >> qs;
    Queue line1(qs);         // line queue holds up to qs people
    Queue line2(qs);
    // cout << "Enter the number of simulation hours: ";
    int hours = 100;              //  hours of simulation
    //cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    // cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    //cin >> perhour;
    double min_per_cust;    //  average time between arrivals


    for (int i = 60; i > 0; i--)
    {

        Item2 temp; 
        // 清空上一轮模拟中残留的队列数据
        while (!line1.isempty())
        {
            line1.dequeue(temp);
        }

        while (!line2.isempty())
        {
            line2.dequeue(temp);
        }

        long turnaways = 0;     //  turned away by full queue
        long customers = 0;     //  joined the queue
        long served = 0;        //  served during the simulation
        long sum_line1 = 0;      //  cumulative line length
        long sum_line2 = 0;      //  cumulative line length
        int wait_time1 = 0;      //  time until autoteller is free
        int wait_time2 = 0;      //  time until autoteller is free
        long line_wait = 0;     //  cumulative time in line

        perhour = i;    
        min_per_cust = MIN_PER_HR / perhour;
        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else if (line1.queuecount() < line2.queuecount())
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line1.enqueue(temp); // add newcomer to line
                }
                else
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line2.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue (temp);      // attend next customer
                wait_time1 = temp.ptime(); // for wait_time1 minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;

            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue (temp);      // attend next customer
                wait_time2 = temp.ptime(); // for wait_time1 minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line1 += line1.queuecount();
            sum_line2 += line2.queuecount();
        }

        // reporting results
        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double) sum_line1 / cyclelimit << endl;
            cout << " average wait time: "
                << (double) line_wait / served << " minutes\n";

            if (((double) line_wait / served) < 1)
            {
                cout << "Average person per hour is " <<perhour << ", then average wait time is less than 1 minute." << endl;
                break;
            }
        }
        else
            cout << "No customers!\n";
        cout << "Done!\n";  
    }

    return 0;
} 