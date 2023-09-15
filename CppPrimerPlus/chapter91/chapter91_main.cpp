#include "golf.h"

int main()
{
    golf a;
    setgolf(a, "tian yonghang", 15);
    showgolf(a);
    golf b;
    if (setgolf(b) == 0)
    {
        std::cout << "User name cannot be null!!" << std::endl;
        return 1;
    }
    showgolf(b);
    return 0;
}