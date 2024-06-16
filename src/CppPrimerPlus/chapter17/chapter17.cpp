#include "chapter17.h"

int chapter17_1()
{
    char ch;
    int count = 0;

    std::cout << "Enter a string (terminate with $): ";

    while (cin.get(ch))
    {

        if (ch == '$')
        {
            cin.putback(ch);
            break;
        }
        else
        {
            count++;
        }
    }
    cout << count << endl;
    cout << ch << endl;

    // Clear the newline character from the input stream
    cin.ignore(1000, '\n');

    return 0;
}

int chapter17_2()
{

    std::string prefix = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/";

    std::string outputFileName;
    cout << "Please enter the file name: " << endl;

    getline(cin, outputFileName);

    outputFileName = prefix + outputFileName;

    cout << outputFileName << endl;
    // Open the output file for writing
    std::ofstream outputFile(outputFileName);

    if (outputFile.is_open())
    {
        std::cerr << "Error: Cannot open output file." << std::endl;
        return 1;
    }

    std::cout << "Enter text (wsl2 use Ctrl+Z to simulate to end input):" << std::endl;

    std::string line;
    while (std::getline(cin, line))
    {
        outputFile << line << std::endl;
    }

    // Close the output file
    outputFile.close();

    std::cout << "Input copied to " << outputFileName << "." << std::endl;
    return 0;
}

int chapter17_3()
{

    std::string file1 = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/result.txt";
    std::string prefix = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/";

    std::ifstream inputFile(file1);

    if (!inputFile.is_open())
    {
        // std::cerr << "Error: Cannot open input file." << std::endl;
        std::cerr << inputFile.is_open() << endl;
        return 1;
    }

    std::string outputFileName;

    cout << "Please enter another file name: " << endl;

    getline(cin, outputFileName);

    outputFileName = prefix + outputFileName;

    cout << outputFileName << endl;
    // Open the output file for writing
    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot open output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << line << std::endl;
    }

    // Close the output file
    outputFile.close();
    inputFile.close();

    std::cout << "Input copied to " << outputFileName << "." << std::endl;
    return 0;
}

int chapter17_4()
{
    std::string file1 = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/result.txt";
    std::string file2 = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/temp.txt";
    std::string prefix = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/";

    std::ifstream inputFile1(file1);

    if (!inputFile1.is_open())
    {
        // std::cerr << "Error: Cannot open input file." << std::endl;
        std::cerr << inputFile1.is_open() << endl;
        return 1;
    }

    std::ifstream inputFile2(file2);

    if (!inputFile2.is_open())
    {
        // std::cerr << "Error: Cannot open input file." << std::endl;
        std::cerr << inputFile2.is_open() << endl;
        return 1;
    }

    std::string outputFileName;

    cout << "Please enter another file name: " << endl;

    getline(cin, outputFileName);

    outputFileName = prefix + outputFileName;

    cout << outputFileName << endl;
    // Open the output file for writing
    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot open output file." << std::endl;
        return 1;
    }

    std::string line1, line2;
    // when inputFile2 EOF first, std::getline(inputFile1, line1) will get one line before.
    while ((!inputFile1.eof()) && (!inputFile2.eof()))
    {
        std::getline(inputFile1, line1);
        std::getline(inputFile2, line2);
        outputFile << (line1 + line2) << std::endl;
    }

    while (inputFile1.eof() && (!inputFile2.eof()))
    {
        std::getline(inputFile2, line2);
        outputFile << line2 << std::endl;
    }

    while (inputFile2.eof() && (!inputFile1.eof()))
    {
        std::getline(inputFile1, line1);
        outputFile << line1 << std::endl;
    }

    // Close the output file
    outputFile.close();
    inputFile1.close();
    inputFile2.close();

    std::cout << "Input copied to " << outputFileName << "." << std::endl;

    return 0;
}

unsigned char toLower(unsigned char a);
void check(std::ifstream &infile, string filename);
void check(std::ofstream &infile, string filename);
bool stringComp(string s1, string s2);  // case insensitive < comparison
bool stringEqual(string s1, string s2); // case insensitive == comparison

int chapter17_5()
{
    using std::back_insert_iterator;
    using std::ifstream;
    using std::ofstream;
    using std::vector;

    ifstream patfile("/home/tian/projects/helloworld/CppPrimerPlus/chapter17/pat.dat");
    ifstream matfile("/home/tian/projects/helloworld/CppPrimerPlus/chapter17/mat.dat");
    ofstream matnpatfile("/home/tian/projects/helloworld/CppPrimerPlus/chapter17/matnpat.dat");
    check(patfile, "pat.dat");
    check(matfile, "mat.dat");
    check(matnpatfile, "matnpat.dat");

    string name;
    vector<string> patlist;
    vector<string> matlist;

    while (getline(patfile, name) && name != "")
        patlist.push_back(name);
    while (getline(matfile, name) && name != "")
        matlist.push_back(name);

    vector<string> matnpat_list;
    back_insert_iterator<vector<string>> iiter(matnpat_list);
    copy(patlist.begin(), patlist.end(), iiter);
    copy(matlist.begin(), matlist.end(), iiter);
    sort(matnpat_list.begin(), matnpat_list.end(), stringComp);
    vector<string>::iterator iv =
        unique(matnpat_list.begin(), matnpat_list.end(), stringEqual);
    matnpat_list.erase(iv, matnpat_list.end());
    std::ostream_iterator<string> os_iter(cout, "\n");

    // cout << "Here is your list of guests: " << endl;
    // copy(matnpat_list.begin(), matnpat_list.end(), os_iter);

    for (const string &line : matnpat_list)
    {
        matnpatfile << line << endl;
    }

    return 0;
}

unsigned char toLower(unsigned char a)
{
    return std::tolower(a);
}

void check(std::ifstream &infile, string filename)
{
    if (!infile.is_open())
    {
        std::cerr << "Error, cannot open " << filename << endl;
        exit(EXIT_FAILURE);
    }
}

void check(std::ofstream &outfile, string filename)
{
    if (!outfile.is_open())
    {
        std::cerr << "Error, cannot open " << filename << endl;
        exit(EXIT_FAILURE);
    }
}

bool stringComp(string s1, string s2)
{
    transform(s1.begin(), s1.end(), s1.begin(), toLower);
    transform(s2.begin(), s2.end(), s2.begin(), toLower);
    return s1 < s2;
}

bool stringEqual(string s1, string s2)
{
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 == s2;
}

// emp.cpp -- implementation file for abstr_emp class and children
// This is exercise 6 of chapter 17 in C++ Primer Plus 5e by Stephen Prata
// Updates were made by to include the writeall() and getall() functions
// abstr_emp class methods
/*
    std::string fname;
    std::string lname;
    std::string job;
*/
abstr_emp::abstr_emp() : fname(""), lname(""), job("")
{
}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln,
                     const std::string &j) : fname(fn), lname(ln), job(j)
{
}

// labels and shows all data
void abstr_emp::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}

// prompts user for values
void abstr_emp::SetAll()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter first name: ";
    cin >> fname;
    while (cin.get() != '\n')
        continue;
    cout << "Enter last name: ";
    cin >> lname;
    while (cin.get() != '\n')
        continue;
    cout << "Enter the job: ";
    getline(cin, job);
}

// just displays first and last name
std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << e.lname << ", " << e.fname;
    return os;
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::writeall(std::ofstream &ofs) const
{
    using std::endl;
    ofs << "First name: " << fname << endl;
    ofs << "Last name: " << lname << endl;
    ofs << "Job: " << job << endl;
}

void abstr_emp::getall(std::ifstream &ifs)
{
    ifs.ignore(256, ':');
    while (' ' == ifs.peek())
        ifs.get();
    getline(ifs, fname);
    std::cout << "First name is " << fname << std::endl;

    ifs.ignore(256, ':');
    while (' ' == ifs.peek())
        ifs.get();
    getline(ifs, lname);
    std::cout << "Last name is " << lname << std::endl;

    ifs.ignore(256, ':');
    while (' ' == ifs.peek())
        ifs.get();
    getline(ifs, job);
    std::cout << "Job is " << job << std::endl;
}

// employee class methods (inherits abstr_emp class publically)
employee::employee() : abstr_emp()
{
}

employee::employee(const std::string &fn, const std::string &ln,
                   const std::string &j) : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout << "Status: Employee" << endl;
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::writeall(std::ofstream &ofs) const
{
    using std::endl;
    ofs << abstr_emp::Employee << endl;
    abstr_emp::writeall(ofs);
}

void employee::getall(std::ifstream &ifs)
{
    abstr_emp::getall(ifs);
}

// manager class methods (inherits abstr_emp publically and virtually)
/*
    int inchargeof;        // number of abstr_emps managed
*/
manager::manager() : abstr_emp()
{
    inchargeof = 0;
}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico) : abstr_emp(fn, ln, j)
{
    using std::cout;
    using std::endl;
    inchargeof = ico;
    if (inchargeof < 0)
    {
        cout << "Error, cannot be in charge of negative people." << endl;
        cout << "Setting inchargeof to 0" << endl;
        inchargeof = 0;
    }
}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e)
{
    using std::cout;
    using std::endl;
    inchargeof = ico;
    if (inchargeof < 0)
    {
        cout << "Error, cannot be in charge of negative people." << endl;
        cout << "Setting inchargeof to 0" << endl;
        inchargeof = 0;
    }
}

manager::manager(const manager &m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout << "Status: Manager" << endl;
    abstr_emp::ShowAll();
    cout << "In charge of " << inchargeof << " people" << endl;
}

void manager::SetAll()
{
    using std::cin;
    using std::cout;
    using std::endl;
    abstr_emp::SetAll();
    cout << "Enter the number of people the manager is in charge of: ";
    cin >> inchargeof;
    if (inchargeof < 0)
    {
        cout << "Error, cannot be in charge of negative people." << endl;
        cout << "Setting inchargeof to 0" << endl;
        inchargeof = 0;
    }
}

void manager::writeall(std::ofstream &ofs) const
{
    using std::endl;
    ofs << abstr_emp::Manager << endl;
    abstr_emp::writeall(ofs);
    ofs << "Number of people managed: " << inchargeof << endl;
}

void manager::getall(std::ifstream &ifs)
{
    abstr_emp::getall(ifs);
    ifs.ignore(256, ':');
    ifs >> inchargeof;
    ifs.get(); // discard newline character
}

// fink class methods (inherits abstr_emp publically and virtually)
/*
    std::string reportsto;        // to whom fink reports
*/
fink::fink() : abstr_emp(), reportsto("")
{
}

fink::fink(const std::string &fn, const std::string &ln,
           const std::string &j, const std::string &rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp &e, const std::string &rpo)
    : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink &e) : abstr_emp(e)
{
    reportsto = e.reportsto;
}

void fink::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout << "Status: fink" << endl;
    abstr_emp::ShowAll();
    cout << "Reports to " << reportsto << endl;
}

void fink::SetAll()
{
    using std::cin;
    using std::cout;
    using std::endl;
    abstr_emp::SetAll();
    cout << "Enter whomever is reported to: ";
    getline(cin, reportsto);
}

void fink::writeall(std::ofstream &ofs) const
{
    using std::endl;
    ofs << abstr_emp::Fink << endl;
    abstr_emp::writeall(ofs);
    ofs << "Reports to: " << reportsto << endl;
}

void fink::getall(std::ifstream &ifs)
{
    abstr_emp::getall(ifs);
    ifs.ignore(256, ':');
    getline(ifs, reportsto);
}

// highfink class methods (inherits manager and fink classes publically)
highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink &f, int ico)
    : abstr_emp(f), manager(f, ico), fink()
{
}

highfink::highfink(const manager &m, const std::string &rpo)
    : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
    using std::cout;
    using std::endl;
    cout << "Status: Highfink" << endl;
    abstr_emp::ShowAll();
    cout << "In charge of " << InChargeOf() << " people" << endl;
    cout << "Reports to " << ReportsTo() << endl;
}

void highfink::SetAll()
{
    using std::cin;
    using std::cout;
    using std::endl;
    abstr_emp::SetAll();
    cout << "Enter the number of people managed: ";
    cin >> InChargeOf();
    if (InChargeOf() < 0)
    {
        cout << "Error, cannot be in charge of negative people." << endl;
        cout << "Setting inchargeof to 0" << endl;
        InChargeOf() = 0;
    }
    cin.get(); // remove newline character
    cout << "Enter whomever is reported to: ";
    getline(cin, ReportsTo());
}

void highfink::writeall(std::ofstream &ofs) const
{
    using std::endl;
    ofs << abstr_emp::Highfink << endl;
    abstr_emp::writeall(ofs);
    ofs << "Number of people managed: " << InChargeOf() << endl;
    ofs << "Reports to: " << ReportsTo() << endl;
}

void highfink::getall(std::ifstream &ifs)
{
    abstr_emp::getall(ifs);
    ifs.ignore(256, ':');
    ifs >> InChargeOf();
    ifs.get(); // discard newline character
    ifs.ignore(256, ':');
    getline(ifs, ReportsTo());
}

const int MAX = 10;

void displayMenu(void);
void eatline(void);

int chapter17_6()
{
    // On first use, the program should solicit data from user, show all entries, and save into in a file. On subsequent uses, the program should first read and display the file data, let the user add data, and show all the data.
    abstr_emp *pc[MAX];
    cout << "You may enter of to " << MAX << " employees" << endl;
    int count = 0;
    char ch;
    string file1 = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/employeeList.dat";
    // Read from employeeList.dat file
    std::ifstream fin;
    fin.open(file1);
    if (fin.is_open())
    {
        int classtype;
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case abstr_emp::Employee:
                cout << "Creating an employee object" << endl;
                pc[count] = new employee;
                pc[count++]->getall(fin);
                break;
            case abstr_emp::Manager:
                cout << "Creating an manager object" << endl;
                pc[count] = new manager;
                pc[count++]->getall(fin);
                break;
            case abstr_emp::Fink:
                cout << "Creating an fink object" << endl;
                pc[count] = new fink;
                pc[count++]->getall(fin);
                break;
            case abstr_emp::Highfink:
                cout << "Creating an highfink object" << endl;
                pc[count] = new highfink;
                pc[count++]->getall(fin);
                break;
            default:
                std::cerr << "It looks like an error has occurred" << endl;
                break;
            }
        }
        cout << "Here is your current employee list: " << endl;
        for (int i = 0; i < count; i++)
        {
            pc[i]->ShowAll();
            cout << endl;
        }
        fin.close();
    }

    // Allow user to enter more data
    while (count < MAX)
    {
        displayMenu();
        cin >> ch;
        eatline();
        switch (ch)
        {
        case 'a':
            pc[count] = new employee;
            pc[count]->SetAll();
            count++;
            break;
        case 'b':
            pc[count] = new manager;
            pc[count]->SetAll();
            count++;
            break;
        case 'c':
            pc[count] = new fink;
            pc[count]->SetAll();
            count++;
            break;
        case 'd':
            pc[count] = new highfink;
            pc[count]->SetAll();
            count++;
            break;
        case 'q':
            break;
        default:
            cout << "Error input not recognized" << endl;
            continue; // this should apply to while loop
            break;
        }
        if (ch == 'q')
            break;
    }

    // write data to file and display data
    std::ofstream fout;
    fout.open(file1);
    if (!fout.is_open())
    {
        std::cerr << "Error, cannot open employeeList.dat" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Here's our updated list: " << endl;
    for (int i = 0; i < count; i++)
    {
        pc[i]->ShowAll();
        cout << endl;
        pc[i]->writeall(fout);
    }

    fout.close();
    return 0;
}

void displayMenu(void)
{
    cout << "Select one of the following:" << endl;
    cout << std::left;
    cout << std::setw(20) << "a. Employee"
         << std::setw(20) << "b. Manager"
         << endl
         << std::setw(20) << "c. Fink"
         << std::setw(20) << "d. Highfink"
         << endl
         << "(q to quit)" << endl;
}

void eatline(void)
{
    char ch;
    while (cin.get(ch) && ch != '\n')
        continue;
}

void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);
void ShowStr(const string &);

int chapter17_7()
{
    std::vector<string> vostr;
    string temp;
    string file1 = "/home/tian/projects/helloworld/CppPrimerPlus/chapter17/strings.dat";
    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    
    // store in a file
    std::ofstream fout(file1, ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    std::vector<string> vistr;
    std::ifstream fin(file1, ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        std::cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void ShowStr(const string & temp)
{
    cout << temp << endl;
}

void GetStrs(std::ifstream & fin, std::vector<string> & vistr)
{
	size_t len;
	string str;
	char ch;
	// check that there is something to read
	while (fin.peek() && !fin.eof()) 
	{
		fin.read((char *) &len, sizeof(size_t));
		for (size_t i = 0; i < len; i++)
		{
			fin.read(&ch, sizeof(char));
			str.push_back(ch);
		}
		vistr.push_back(str);
		str.clear();
	}
}