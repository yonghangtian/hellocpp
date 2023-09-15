#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname,name);
    g.handicap = hc;
}


int setgolf(golf & g)
{
    char temp[Len];
    std::cout << "Please input your fullname, and the maximum length is " << Len << std::endl;
    // read a line and calculate it's length.
    std::cin.getline(temp, Len);
    int length = strlen(temp);
    if (length == 0)
    {
        return 0;
    }

    strcpy(g.fullname, temp);
    std::cin.ignore(1024, '\n');
    std::cout << "Please input handicap of type int: " << std::endl;
    // read a int  
    std::cin >> g.handicap;
    std::cin.get();
    
    return 1;    
}


void handicap(golf & g, int hc)
{
    g.handicap = hc;
}


void showgolf(const golf & g)
{
    std::cout << "Golf's fullname is " << g.fullname << ", handicap is " << g.handicap << std::endl;
}