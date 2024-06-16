#include "chapter4.h"

int chapter4_1()
{
    string firstName, lastName;
    char grade;
    int age;

    cout << "What is your first name?" << endl;
    getline(cin, firstName);

    cout << "What is your last name?" << endl;
    getline(cin, lastName);

    cout << "What letter grade(from A to E) do you deserve?" << endl;
    cin >> grade;

    cout << "What is your age?" << endl;
    cin >> age;

    cout << "Name: " << lastName << ", " << firstName << endl;

    cout << "Grade: " << (char) (grade + 1) << endl;

    cout << "Age: " << age << endl;

    return 1;
}

// construct person name using cstring
int chapter4_3()
{
    char firstName[ArSize], lastName[ArSize], fullName[2*ArSize + 2];
    
    cout << "Please input your first name:" << endl;
    cin >> firstName;

    cout << "Please input your last name:" << endl;
    cin >> lastName;
    
    // 清除上一个cin产生的换行符
    cin.ignore(1024, '\n');
    
    for (int i = 0; i < strlen(firstName); i++) 
    {
        fullName[i] = firstName[i];
    }

    fullName[strlen(firstName)] = ',';
    fullName[strlen(firstName) + 1] = ' ';


    for (int i = 0; i < strlen(lastName); i++) 
    {
        fullName[strlen(firstName) + 2 + i] = lastName[i];
    }
    // important!!! cstring need to end with \0
    fullName[strlen(firstName) + strlen(lastName)] = '\0';

    cout << "Your full name is " << fullName << endl;

    return 0;
}

// construct person name using string
int chapter4_4()
{
    string firstName, lastName, fullName;
    string connector = ", ";
    
    cout << "What is your first name?" << endl;
    getline(cin, firstName);

    cout << "What is your last name?" << endl;
    getline(cin, lastName);
    
    fullName = firstName + connector + lastName;

    cout << "Your full name is " << fullName << endl; 

    return 0;
}

int chapter4_5() 
{
    CandyBar candy1 = { "Mocha Munch", 2.3, 350};

    cout << candy1.brand << ", " << candy1.weight << "g, "  << candy1.calorie << endl;
    return 0;
}

int chapter4_6()
{
    CandyBar candys[3] = {{ "Mocha Munch", 2.3, 350}, { "WANG WANG wahahah", 4000.01, 20000}};

    cout << "Please input candy No.3's brand:" << endl;
    getline(cin, candys[2].brand);

    cout << "Please input candy No.3's weight:" << endl;
    cin >> candys[2].weight;

    cout << "Please input candy No.3's calorie:" << endl;
    cin >> candys[2].calorie;
    
    cin.ignore(1024, '\n');

    for (int i = 0; i < 3; i++)
    {
        cout << candys[i].brand << ", " << candys[i].weight << ", " << candys[i].calorie << endl;
    }

    return 0;
}

int chapter4_7()
{
    Pizza* p = new Pizza;

    cout << "Please input pizza company's name:" << endl;
    getline(cin, p->companyName);

    cout << "Input weight:" << endl;
    cin >> p->weight;

    cout << "Input inch:" << endl;
    cin >> p->inch;

    cin.ignore(1024, '\n');

    cout << "Pizza info: Company name: " << p->companyName << "; weight: " << p->weight << "; inch: " << p->inch<< endl; 

    delete p;
    return 0;
}

int chapter4_8()
{
    // same with chapter4_7
    return 0;
}

int chapter4_9()
{
    // create pointer's array
    CandyBar* p_candys = new CandyBar[3]; 

    *p_candys = { "Mocha Munch", 2.3, 350};
    *(p_candys+1) = { "WANG WANG wahahah", 4000.01, 20000};

    cout << "Please input candy No.3's brand:" << endl;
    getline(cin, (p_candys+2)->brand);

    cout << "Please input candy No.3's weight:" << endl;
    cin >> (p_candys+2)->weight;

    cout << "Please input candy No.3's calorie:" << endl;
    cin >> (p_candys+2)->calorie;
    
    cin.ignore(1024, '\n');

    for (int i = 0; i < 3; i++)
    {
        cout << (p_candys+i)->brand << ", " << (p_candys+i)->weight << ", " << (p_candys+i)->calorie << endl;
    }

    // drop pointer's array
    delete [] p_candys;
    return 0;
}

int chapter4_10()
{
    array<float, 3> records;
    float sum = 0.0f;
    cout << "Please input three numbers: " << endl;
    for (int i = 0; i < records.size(); i ++)
    {
        cin >> records[i];
        sum += records[i];
    }

    cout << "Average number of this array is " << sum/3 << endl;


    return 0;
}