#include "golf10.h"

Golf::Golf() 
{
    fullname[0] = '\0';
    handicap = 0; 
}

// 默认值应该在函数声明部分指出，不能在函数定义中出现默认值
Golf::Golf(const char * fn, const int hc)
{
    strncpy(this->fullname, fn, Len-1);
    this->handicap = hc;
}

void Golf::setGolf(const char * fn, int hc)
{
    strncpy(this->fullname, fn, Len-1);
    this->handicap = hc;
}

int Golf::setGolf()
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

    strcpy(this->fullname, temp);
    std::cin.ignore(1024, '\n');
    std::cout << "Please input handicap of type int: " << std::endl;
    // read a int  
    std::cin >> this->handicap;
    std::cin.get();
    
    return 1;    
}


int Golf::setGolf(Golf & anotherGolf)
{
    strncpy(this->fullname, anotherGolf.fullname, Len-1);
    this->handicap = anotherGolf.handicap;

    return 1;
}

void Golf::resetHandicap(int hc)
{
    this->handicap = hc;
}

void Golf::showgolf() const
{
    std::cout << "Golf's fullname is " << this->fullname << ", handicap is " << this->handicap << std::endl;
}