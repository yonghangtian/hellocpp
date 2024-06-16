#include "chapter9.h"

// check chapter91 folder
int chapter9_1()
{   
    return 0; 
}

void strcount(const std::string str)
{
    using namespace std; 
    static int total = 0;
    cout << "\"" << str << "\" contains ";
    total += str.size(); 
    cout << str.size() << " characters\n"; 
    cout << total << " characters total\n";
}

int chapter9_2()
{
    using namespace std;
    string str;
    cout << "Enter a line: \n";
    getline(cin, str);

    while (str !="") 
        {
            strcount(str); 
            cout << "Enter next line (empty line to quit):\n"; 
            getline(cin, str);
        } 
    cout << "Bye\n"; 
    
    return 0;
}


int chapter9_3()
{ 
    char buffer[1000];
    chaff * chs = new (buffer) chaff[2];
    
    cout << "address of buffer is : " << (void *) buffer << endl;

    for(int i = 0 ; i < 2; i ++) 
    {
        cout << "Please input c-type string:" << endl;
        cin.getline(chs[i].dross, 19);
        cout << "Plase input a int :" << endl;
        cin >> chs[i].slag;
        cin.get();
        cout << (void *) chs[i].dross << ", " <<  &chs[i].slag << endl;  
    }

    delete [] chs;
    return 0; 
}

int chapter9_3_dynamic()
{ 
    char * buffer = new char[1000];
    chaff * chs = new (buffer) chaff[2];
    
    cout << "address of buffer is : " << (void *) buffer << endl;

    for(int i = 0 ; i < 2; i ++) 
    {
        cout << "Please input c-type string:" << endl;
        cin.getline(chs[i].dross, 19);
        cout << "Plase input a int :" << endl;
        cin >> chs[i].slag;
        cin.get();
        cout << (void *) chs[i].dross << ", " <<  &chs[i].slag << endl;  
    }

    delete [] buffer;
    return 0; 
}

// 不写了，看github吧 https://github.com/tinawebdev/cpp-primer-plus/tree/master/chapter09
int chapter9_4(){ return 0; }
