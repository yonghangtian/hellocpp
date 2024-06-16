#ifndef _COORDIN_H
#define _COORDIN_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype> // For std::toupper
#include <string>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <queue>
#include <list>
#include <array>
#include <memory>
#include <initializer_list>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::istream;
using std::ostream;
using std::string;
#endif

int review_1();
int review_2();
int chapter18_1();
int chapter18_2();
int chapter18_3();
int chapter18_4();

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };

private:
    Info *pi;

public:
    Cpmv()
    {
        pi = new Info();
        pi->qcode = "temp";
        pi->zcode = "temp";
    }

    Cpmv(std::string q, std::string z)
    {
        pi = new Info();
        pi->qcode = q;
        pi->zcode = z;
    }

    Cpmv(const Cpmv &cp)
    {
        pi = new Info();
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
    }

    Cpmv(Cpmv &&mv)
    {
        pi = mv.pi;
        mv.pi = nullptr;
    }

    ~Cpmv()
    {
        delete pi;
    }

    Cpmv &operator=(const Cpmv &cp)
    {
        if (this == &cp)
            return *this;
        delete pi;
        pi = new Info();
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
        return *this;
    }

    Cpmv &operator=(Cpmv &&mv)
    {
        if (this == &mv)
            return *this;
        delete pi;
        pi = mv.pi;
        mv.pi = nullptr;
        return *this;
    }

    Cpmv operator+(const Cpmv &obj) const
    {
        Cpmv result;
        result.pi->qcode = this->pi->qcode + obj.pi->qcode;
        result.pi->zcode = this->pi->zcode + obj.pi->zcode;
        return result;
    }

    void Display() const
    {
        std::cout << "qcode: " << pi->qcode << ", zcode: " << pi->zcode << std::endl;
    }

    void ShowObject() const
    {
        std::cout << "pi's address: " << (void *) pi << std::endl;
    }
};