#include "golf10.h"

int main()
{
    // Golf a = Golf("tian yonghang", 15);
    Golf a;
    a.setGolf("tian yonghang", 14);
    a.showgolf();
    Golf b;
    if (b.setGolf() == 0)
    {
        std::cout << "User name cannot be null!!" << std::endl;
        return 1;
    }
    b.showgolf();

    std::cout << "Test copy object" << std::endl;
    a.setGolf(b);
    a.showgolf();
    return 0;
}