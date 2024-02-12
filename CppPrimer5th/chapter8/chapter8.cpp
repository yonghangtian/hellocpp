#include "chapter8.h"

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

string format(const string &s) { return s; }

bool valid(const string &s)
{
    // we'll see how to validate phone numbers
    // in chapter 17, for now just return true
    return true;
}

vector<PersonInfo> getData(istream &is)
{
    // will hold a line and word from input, respectively
    string line, word;

    // will hold all the records from the input
    vector<PersonInfo> people;

    std::istringstream record;

    // read the input a line at a time until end-of-file (or other error)
    while (getline(is, line))
    {
        PersonInfo info;                 // object to hold this record's data
        record.str(line);                // bind record to the line we just read
        record >> info.name;             // read the name
        while (record >> word)           // read the phone numbers
            info.phones.push_back(word); // and store them
        people.push_back(info);          // append this record to people
        
        record.clear();                 
    }

    return people;
}

ostream &process(ostream &os, vector<PersonInfo> people)
{
    for (const auto &entry : people)
    {                                          // for each entry in people
        std::ostringstream formatted, badNums; // objects created on each loop
        for (const auto &nums : entry.phones)
        { // for each number
            if (!valid(nums))
            {
                badNums << " " << nums; // string in badNums
            }
            else
                // ``writes'' to formatted's string
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())         // there were no bad numbers
            os << entry.name << " "        // print the name
               << formatted.str() << endl; // and reformatted numbers
        else                               // otherwise, print the name and bad numbers
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }

    return os;
}

istream &readUntilEOF(istream &is)
{
    string temp;
    while (getline(is, temp))
        cout << temp;

    return is;
}

int exercise8_1()
{
    readUntilEOF(cin);
    return 0;
}

int exercise8_2() { return 0; }

int exercise8_3()
{
    char i;
    while (cin >> i)
        cout << i;
    return 0;
}

int exercise8_4()
{
    string file("/home/tianyh/projects/hellocpp/CppPrimer5th/chapter8/exercise8_4.txt");
    std::ifstream input(file);
    vector<string> vecStr;
    while (!input.fail())
    {
        string temp;
        if (getline(input, temp))
        {
            vecStr.push_back(temp);
        }
    }

    for (const auto &a : vecStr)
        cout << a << endl;

    return 0;
}

int exercise8_5()
{
    string file("/home/tianyh/projects/hellocpp/CppPrimer5th/chapter8/exercise8_4.txt");
    std::ifstream input(file);
    vector<string> vecWord;
    string temp, word;
    while (getline(input, temp))
    {
        std::istringstream readStr(temp);
        while (readStr >> word)
            vecWord.push_back(word);
    }

    for (const auto &a : vecWord)
        cout << a << endl;

    return 0;
}

int exercise8_6(int argc, char **argv)
{
    vector<Sales_data> list;
    if (argc >= 2)
    {
        string fileName(argv[1]), temp;
        std::ifstream inFile(fileName);

        while (getline(inFile, temp))
        {
            Sales_data tempData;
            std::istringstream readStr(temp);
            read(readStr, tempData);
            list.push_back(tempData);
        }

        for (const auto &a : list)
        {
            print(cout, a);
            cout << endl;
        }
    }

    return 0;
}

int exercise8_7(int argc, char **argv)
{
    vector<Sales_data> list;
    if (argc >= 3)
    {
        string inFileName(argv[1]), outFileName(argv[2]), temp;
        std::ifstream inFile(inFileName);
        std::ofstream outFile(outFileName, std::ofstream::app);

        while (getline(inFile, temp))
        {
            Sales_data tempData;
            std::istringstream readStr(temp);
            read(readStr, tempData);
            list.push_back(tempData);
        }

        for (const auto &a : list)
        {
            print(outFile, a);
            outFile << endl;
        }
    }

    return 0;
}

int exercise8_8() { return 0; }

int exercise8_9() { return 0; }

int exercise8_10() { return 0; }

int exercise8_11()
{
    string fileName("/home/tianyh/projects/hellocpp/CppPrimer5th/chapter8/exercise8_11.txt");
    std::ifstream inputFile(fileName);
    process(cout, getData(inputFile));

    return 0;
}

int exercise8_12() { return 0; }

int exercise8_13() { return 0; }

int exercise8_14() { return 0; }
