#include "chapter14.h"

Wine::Wine(const string lab, int yrs)
{
    label = lab;
    years = yrs;
    bottles = PairArray(ArrayInt(yrs), ArrayInt(yrs));
}

Wine::Wine(const string lab, int yrs, const int *y, const int *b)
{
    label = lab;
    years = yrs;
    bottles = PairArray(ArrayInt(y, yrs), ArrayInt(b, yrs));
}

void Wine::GetBottles()
{
    int y[years], b[years];
    cout << "Enter " << label << "data for " << years << " year(s):" << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year:";
        cin >> y[i];
        cout << "Enter bottles for that year:";
        cin >> b[i];
    }
    cin.get();
    bottles = PairArray(ArrayInt(y, years), ArrayInt(b, years));
}

void Wine::Show()
{
    cout << "Wine:" << label << endl;
    cout << "\t\tYear"
         << "\t\tBottles" << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "\t\t" << bottles.first()[i] << "\t\t" << bottles.second()[i] << endl;
    }
}

const string &Wine::Label() const
{
    return label;
}

int Wine::sum()
{
    int result = 0;
    for (int i = 0; i < years; i++)
    {
        result += bottles.second()[i];
    }
    return result;
}

int chapter14_1()
{
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);                         // store label, years, give arrays yrs elements
    holding.GetBottles();                           // solicit input for year, bottle count
    holding.Show();                                 // display object contents
    cout << "Total bottles for " << holding.Label() // use Label() method
         << ": " << holding.sum() << endl;          // use sum() method

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    // create new object, initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() // use Label() method
         << ": " << more.sum() << endl;          // use sum() method
    cout << "Bye\n";
    return 0;
}

Wine2::Wine2(const char *lab, int yrs) : string(lab), PairArray(ArrayInt(yrs), ArrayInt(yrs))
{
    years = yrs;
}

Wine2::Wine2(const char *lab, int yrs, const int *y, const int *b) : string(lab), PairArray(ArrayInt(y, yrs), ArrayInt(b, yrs))
{
    years = yrs;
}

void Wine2::GetBottles()
{
    int y[years], b[years];
    cout << "Enter " << (const string &)(*this) << "data for " << years << " year(s):" << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year:";
        cin >> y[i];
        cout << "Enter bottles for that year:";
        cin >> b[i];
    }
    cin.get();
    (PairArray &)(*this) = PairArray(ArrayInt(y, years), ArrayInt(b, years));
}

void Wine2::Show()
{
    cout << "Wine2:" << (const string &)(*this) << endl;
    cout << "\t\tYear"
         << "\t\tBottles" << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "\t\t" << PairArray::first()[i] << "\t\t" << PairArray::second()[i] << endl;
    }
}

const string &Wine2::Label() const
{
    return (const string &)(*this);
}

int Wine2::sum()
{
    int result = 0;
    for (int i = 0; i < years; i++)
    {
        result += PairArray::second()[i];
    }
    return result;
}

int chapter14_2()
{
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine2 holding(lab, yrs); // store label, years, give arrays yrs elements
    holding.GetBottles();    // solicit input for year, bottle count
    holding.Show();          // display object contents

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    // create new object, initialize using data in arrays y and b
    Wine2 more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() // use Label() method
         << ": " << more.sum() << endl;          // use sum() method
    cout << "Bye\n";
    return 0;
}

// Worker methods
Worker::~Worker() {}

// protected methods
void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

// Waiter methods
void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

// protected methods
void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

// Singer methods

char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto",
                                "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

// protected methods
void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << '\n';
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    while (cin.get() != '\n')
        continue;
}

// SingingWaiter methods
void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}

int chapter14_3()
{
    int SIZE = 5;
    QueueTP<Worker*> workerQueue;
    Worker * lolas;

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        
        cout << "Enter the employee category:\n"
             << "w: waiter  s: singer  "
             << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':
            lolas = new Waiter;
            break;
        case 's':
            lolas = new Singer;
            break;
        case 't':
            lolas = new SingingWaiter;
            break;
        }
        cin.get();
        lolas->Set();
        workerQueue.enqueue(lolas);
    }

    cout << "\nHere is your staff:\n";
    while (!workerQueue.isempty())
    {
        cout << endl;
        workerQueue.dequeue(lolas);
        lolas->Show();
    }
    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}


// Person methods
Person::~Person() {}

// protected methods
void Person::Data() const
{
    cout << "Firstname: " << firstname << endl;
    cout << "Lastname: " << lastname << endl;
}

void Person::Get()
{
	cout << "Enter person's firstname: ";
    getline(cin, firstname);
    cout << "Enter person's lastname: ";
    getline(cin, lastname);
}

// GunSlinger methods
void GunSlinger::Set()
{
	cout << "GunSlinger:" << endl;
    Person::Get();
    Get(); 
}

void GunSlinger::Show() const
{
    cout << "Category: GunSlinger\n";
    Person::Data();
    Data();
}

// protected methods
void GunSlinger::Data() const
{
    cout << "Shoot time: " << shootTime << endl;
	cout << "Notches on the gun: " << notches << endl;
}

void GunSlinger::Get()
{
    cout << "Enter GunSlinger's shoot time: ";
    cin >> shootTime;
    while (cin.get() != '\n')
        continue;
	cout << "Enter GunSlinger's notches: ";
    cin >> notches;
    while (cin.get() != '\n')
        continue;
}

// PokerPlayer methods
void PokerPlayer::Set()
{
	cout << "PokerPlayer:" << endl;
    Person::Get();
    Get();
}

void PokerPlayer::Show() const
{
    cout << "Category: PokerPlayer\n";
    Person::Data();
    Data(); 
}

// protected methods
void PokerPlayer::Data() const
{
	cout << "Card: " << randomInt << endl;
}

// BadDude methods
void BadDude::Data() const
{
    GunSlinger::Data();
    PokerPlayer::Data();
}

void BadDude::Get()
{
    GunSlinger::Get();
    PokerPlayer::Get();
}

void BadDude::Set()
{
    cout << "BadDude:"<< endl;
    Person::Get();
    Get();
}

void BadDude::Show() const
{
    cout << "Category: BadDude" << endl;
    Person::Data();
    Data();
}


int chapter14_4()
{
    int SIZE = 5;
    QueueTP<Person*> personQueue;
    Person * lolas;

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        
        cout << "Enter the employee category:\n"
             << "w: GunSlinger  s: PokerPlayer  "
             << "t: BadDude  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':
            lolas = new GunSlinger;
            break;
        case 's':
            lolas = new PokerPlayer;
            break;
        case 't':
            lolas = new BadDude;
            break;
        }
        cin.get();
        lolas->Set();
        personQueue.enqueue(lolas);
    }

    cout << "\nHere is your staff:\n";
    while (!personQueue.isempty())
    {
        cout << endl;
        personQueue.dequeue(lolas);
        lolas->Show();
    }
    cout << "Bye.\n";

    return 0;
}

abstr_emp::abstr_emp()
  : fname("Undefined"), lname("Undefined"), job("Undefined")
{
}

abstr_emp::abstr_emp(const std::string& fn, 
  const std::string& ln, const std::string& j)
  : fname(fn), lname(ln), job(j)
{
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::ShowAll() const
{
  cout << "First name: " << fname << std::endl;
  cout << "Last name: " << lname << std::endl;
  cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
  cout << "Enter the employee's first name: ";
  cin >> fname;

  cout << "Enter the employee's last name: ";
  cin >> lname;

  while (cin.get() != '\n')
  {
    continue;
  }

  cout << "Enter the employee's job title: ";
  getline(cin, job);
}

std::ostream & operator<< (std::ostream& os, const abstr_emp& e)
{
  os << e.fname << " " << e.lname;
  return os;
}

// employee methods
employee::employee()
  : abstr_emp()
{
}

employee::employee(const std::string& fn,
  const std::string& ln, const std::string& j)
  : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
  cout << "Category: Employee" << std::endl;
  abstr_emp::ShowAll();
}

void employee::SetAll()
{
  abstr_emp::SetAll();
}

// manager methods

manager::manager()
  : abstr_emp(), inchargeof(0)
{
}

manager::manager(const std::string& fn, const std::string& ln,
  const std::string& j, int ico)
  : abstr_emp(fn, ln, j), inchargeof(ico)
{
  if (inchargeof < 0)
  {
    cout << "Ivalid value. Value set to 0." << std::endl;
    inchargeof = 0;
  }
}

manager::manager(const abstr_emp& e, int ico)
  : abstr_emp(e), inchargeof(ico)
{
  if (inchargeof < 0)
  {
    cout << "Ivalid value. Value set to 0." << std::endl;
    inchargeof = 0;
  }
}

manager::manager(const manager& m)
  : abstr_emp(m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
  cout << "Category: Manager" << std::endl;
  abstr_emp::ShowAll();
  cout << "In charge of " << inchargeof << " people." << std::endl;
}

void manager::SetAll()
{
  abstr_emp::SetAll();
  cout << "Enter the number of people is in charge of: ";
  cin >> inchargeof;

  while (inchargeof < 0)
  {
    cout << "Please enter a valid number of people : " << std::endl;
    cin >> inchargeof;
  }
}

// fink methods

fink::fink()
  : abstr_emp(), reportsto("Undefined")
{
}

fink::fink(const std::string& fn, const std::string& ln,
  const std::string& j, const std::string& rpo)
  : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp& e, const std::string& rpo)
  : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink& e)
  : abstr_emp(e), reportsto(e.reportsto)
{
}

void fink::ShowAll() const
{
  cout << "Category: Fink" << std::endl;
  abstr_emp::ShowAll();
  cout << (const abstr_emp &)*this << " reports to " << reportsto << "." << std::endl;
}

void fink::SetAll()
{
  abstr_emp::SetAll();
  cout << "Enter the person's name " << (const abstr_emp &)*this << " reports to: ";
  getline(cin, reportsto);
}

// highfink methods

highfink::highfink()
  : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string& fn, const std::string& ln,
  const std::string& j, const std::string& rpo, int ico)
  : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)
{
}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
  : abstr_emp(e), fink(e, rpo), manager(e, ico)
{
}

highfink::highfink(const fink& f, int ico)
  : abstr_emp(f), fink(f), manager(f, ico)
{
}

highfink::highfink(const manager& m, const std::string& rpo)
  : abstr_emp(m), fink(m, rpo), manager(m)
{
}

highfink::highfink(const highfink& h)
  : abstr_emp(h), fink(h), manager(h)
{
}

void highfink::ShowAll() const
{
  cout << "Category: Highfink" << std::endl;
  abstr_emp::ShowAll();
  cout << (const abstr_emp &)*this << " reports to " << ReportsTo() << "." << std::endl;
  cout << "In charge of " << InChargeOf() << " people." << std::endl;
}

void highfink::SetAll()
{
  abstr_emp::SetAll();

  cout << "Reports to: ";
  getline(cin, ReportsTo());  

  cout << "The number of people is in charge of: ";
  cin >> InChargeOf();

  while (InChargeOf() < 0)
  {
    cout << "Please enter a valid number of people : " << std::endl;
    cin >> InChargeOf();
  }
}

int chapter14_5()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    abstr_emp tri1[4] = {em, fi, hf, hf2};
    for (int i = 0; i < 4; i++)
        tri1[i].ShowAll();

    return 0;
}


// Why is no assignment operator defined?   因为类中大多数使用的是string类，string定义了赋值运算符，所以不需要再定义
// Why are ShowAll() and SetAll() virtual?  （1）希望继承的类重新实现该方法；（2）基类指针使用该方法时能够动态指定向不同的派生类对象
// Why is abstr_emp a virtual base class?   在MI时，防止生成多个基类对象
// Why does the highfink class have no data section? 因为该对象的数据部分都从manager和fink类中继承来了
// Why is only one version of operator<<() needed?  因为<<只需要展示firstname和lastname。
// What would happen if the end of the program were replaced with this code? （1）无法创建队列；（2）替换完成后，ShowAll将只能展示每个类的abstr_emp基类的数据
// abstr_emp tri[4] = {em, fi, hf, hf2};
// for (int i = 0; i < 4; i++)
// tri[i].ShowAll();
