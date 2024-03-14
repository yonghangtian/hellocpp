#include "chapter6.h"

// 读取键盘输入，直到遇到@符号为止，并回显输入（数字除外），同时将大写字符转换为小写，将小写字符转换为大写（使用cctype函数系列）。
// 大写到小写： + 32； 小写到大写： -32
int chapter6_1()
{ 
    cout << "Enter text for analysis, and type @"
            " to terminate input.\n";
    char ch;  

    cin.get(ch);                // get first character
    while (ch != '@')            // test for sentinel
    {
        if(islower(ch))   // is it a whitespace character?
        {   
            ch = ch - 32;
            cout << ch;
        }
        else if(isupper(ch))    // is it a?
        {
            ch = ch + 32;
            cout << ch;
        }
        else if(isdigit(ch))
        {
            cout << "";
        }
        else
        {
            cout << ch;
        }

        cin.get(ch);            // get next character
    }

    return 0; 

}

// 将最多10个donation值读入到一个double数组中，使用array模板，
// 程序遇到非数字输入时中断，并报告这些数字的平均值以及数字中多少个数字高于平均值
int chapter6_2()
{ 
    const int MAX = 10;
    // STL中需使用常量，所以MAX需要添加const关键字。
    array<double, MAX> donations;
    double sum = 0.0, avg = 0.0;
    cout << "Please enter your donation." << endl;
    cout << "You may enter up to " << MAX << " donations <q to terminate>." << endl;
    
    cout << "donation 1: ";
    int i = 0;

    while (i < MAX && cin >> donations[i]){
        sum += donations[i];
        if (++i < MAX){
            cout << "donation " << i+1 << ": ";
        }
    }

    avg = sum / i;
    int moreThanAvg = 0;
    for(int j = 0; j < i; j ++){
        if (donations[j] > avg){
            ++moreThanAvg;
        }
    }

    cout << "The avg donation is " << avg << ", there are " << moreThanAvg << " donations more than avg." << endl;
    return 0; 
}

// 处理错误输入的代码：
// while (!(cin >> golf[i])) { 
// cin.clear(); // reset input
// while (cin.get() != '\n')
//     continue; // get rid of bad input
// cout << "Please enter a number: ";

// 编写一个菜单驱动的雏形。只接受 c p t g四个选项，并用switch语句将不同选项的结果输出。
int chapter6_3()
{ 
    char ch;

    cout << "c) carnivore p) pianist \n t) tree  g) game" << endl;

    while (!(cin >> ch) || (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g')) {
        cin.clear();
        while (cin.get() != '\n') {
            continue;
        }
        cout << "Please input char in (c, p, t, g)" << endl;
    }

    switch (ch)
    {
        case 'c': cout << "carnivore" << endl;
                break;
        case 'p': cout << "pianist" << endl;
                break;
        case 't': cout << "tree" << endl;
                break;
        case 'g': cout << "game" << endl;
                break;
        default:
                break;
    }
    return 0; 
}

int chapter6_4()
{ 
    bop bops[3] = {{"tianyonghang","engineer","helloworld",0},
                    {"lixinyi","lawyer","how dare you!",1},
                    {"shuangshuang","doctor","welcome home",2}};

    char ch;
    cout << "a) display by fullname b) display by title \n c) display by popname  d) display by perference\n q)quit" << endl;


    while (!(cin >> ch) || (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'q')) {
        cin.clear();
        while (cin.get() != '\n') {
            continue;
        }
        cout << "Please input char in (a b c d q)" << endl;
    }

    switch (ch)
    {
        case 'a':
            for (int i = 0 ; i < 3; i++) {
                cout << bops[i].fullname << endl;
            }    
            break;
        case 'b': 
            for (int i = 0 ; i < 3; i++) {
                cout << bops[i].title << endl;
            }
            break;
        case 'c': 
            for (int i = 0 ; i < 3; i++) {
                cout << bops[i].bopname << endl;
            }
            break;
        case 'd':
            for (int i = 0 ; i < 3; i++) {
                switch (bops[i].preference)
                {
                case 0:
                    cout << bops[i].fullname << endl;
                    break;
                case 1:
                    cout << bops[i].title << endl;
                    break;
                case 2:
                    cout << bops[i].bopname << endl;
                    break;
                default:
                    break;
                }
            }
            break;
        default:
                break;
    }

    return 0; 

}

// 计算个人所得税
int chapter6_5()
{ 
    float tvarps, tax = 0.0f;

    while (cin >> tvarps) {
        if (tvarps < 0.0f) {
            cout << "Income can not be " << tvarps << endl;
            break;
        }

        if (tvarps <= 5000) {
            tax = 0.0f;
        }
        else if (tvarps > 5000 && tvarps <= 15000) {
            tax = (tvarps - 5000) * 0.1f;
        }
        else if (tvarps > 15000 && tvarps <= 35000) {
            tax = (15000 - 5000) * 0.1f + (tvarps - 15000) * 0.15f;
        }
        else if (tvarps > 35000) {
            tax = (15000 - 5000) * 0.1f + (35000 - 15000) * 0.15f + (tvarps - 35000) * 0.2f;
        }

        cout << "When income is "<< tvarps <<", Tax is " << tax;
    }

    return 0; 
}

int chapter6_6()
{ return 0; }

int chapter6_7()
{ return 0; }

// 打开一个文本文件，逐个字符地读取该文件，直到到达文件末尾，然后指出该文件中包含了多少个字节
// 需要打开的文件是homework/chapter6_8.txt
int chapter6_8()
{ 
    ifstream inFile;
    // cpp默认接收的是绝对路径
    char filename[100] = "/home/tian/projects/helloworld/CppPrimerPlus/chapter6_8.txt";
    //char filename[100] = "../chapter6_8.txt";
    inFile.open(filename);

    if (!inFile.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    // keep window open
        exit(EXIT_FAILURE);
    }

    char ch; 
    int count = 0;

    inFile >> ch;        // get first value
    while (inFile.good())   // while input good and not at EOF
    {
        ++count;            // one more char read
        inFile >> ch;
    }
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
    }
    inFile.close();         // finished with the file

    return 0; 
}


// 从文件中读取编程练习6中的信息
// 需要打开的文件是homework/chapter6_9.txt
int chapter6_9()
{ 
    ifstream inFile;
    // cpp默认接收的是绝对路径
    char filename[100] = "/home/tian/projects/helloworld/CppPrimerPlus/chapter6_9.txt";
    inFile.open(filename);
    if (!inFile.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    // keep window open
        exit(EXIT_FAILURE);
    }

    donation ds[3];

    string name = "";
    double amount = 0.0;
    int i = 0;
    do
    {
        getline(inFile, name);
        if (inFile.good()) {
            (inFile >> amount).get();
            if (inFile.good()) {
                ds[i].amount = amount;
                ds[i].fullname = name;
                ++i;
            }
            else {
                cout << "Error 1";
                break;
            }
        } else {
            cout << "Error 2";
            break;
        }

    } while (!inFile.eof() && i < 3);

    for (i = 0; i < 3; i++) {
        cout << ds[i].fullname << endl;
        cout << ds[i].amount << endl;
    }

    inFile.close();         // finished with the file
    return 0; 
}
