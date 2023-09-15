#ifndef _COORDIN_H
#define _COORDIN_H
#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <cctype>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::strcpy;
#endif

// base class
class Cd
{ // represents a CD disk
private:
    char performers[50];
    char label[20];
    int selections;  // number of selections
    double playtime; // playing time in minutes
public:
    Cd(char *s1, char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual void Report() const; // reports all CD data
    Cd &operator=(const Cd &d);

    virtual ~Cd();
};

class Classic : public Cd
{
private:
    char feature[50];

public:
    Classic(char *s3_feature, char *s1, char *s2, int n, double x);
    Classic(char *s3_feature, Cd &cd1);
    Classic();
    virtual void Report() const; // reports all Classic data
    Classic &operator=(const Classic &d);

    virtual ~Classic();
};

// base class
class Cd_new
{ // represents a CD disk
private:
    char *performers;
    char *label;
    int selections;  // number of selections
    double playtime; // playing time in minutes
public:
    Cd_new(char *s1, char *s2, int n, double x);
    Cd_new(const Cd_new &d);
    Cd_new();
    virtual void Report() const; // reports all CD data
    Cd_new &operator=(const Cd_new &d);

    virtual ~Cd_new();
};

class Classic_new : public Cd_new
{
private:
    char *feature;

public:
    Classic_new(char *s3_feature, char *s1, char *s2, int n, double x);
    Classic_new(char *s3_feature, Cd_new &cd1);
    Classic_new();
    virtual void Report() const; // reports all Classic_new data
    Classic_new &operator=(const Classic_new &d);

    virtual ~Classic_new();
};

//  abstract base class: DMA
class DMA
{
private:
    char *label;
    int rating;

protected:
    void showLabel() const;
    void showRating() const;

public:
    DMA(const char *l = "null", int r = 0);
    DMA(const DMA &rs);
    virtual ~DMA();
    DMA &operator=(const DMA &rs);
    virtual void show() const = 0;
};

//  Base Class Using DMA
class baseDMA : public DMA
{
public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    virtual void show() const override;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public DMA
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];

public:
    lacksDMA(const char *c = "blank", const char *l = "null",
             int r = 0);
    lacksDMA(const char *c, const DMA &rs);
    lacksDMA(const lacksDMA &rs);
    virtual ~lacksDMA();
    virtual void show() const override;
};

// derived class with DMA
class hasDMA : public DMA
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "null",
           int r = 0);
    hasDMA(const char *s, const DMA &rs);
    hasDMA(const hasDMA &hs);
    virtual ~hasDMA();
    hasDMA &operator=(const hasDMA &rs);
    virtual void show() const override;
};


class Port
{
private:
    char *brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;

public:
    Port(const char *br = "none", const char *st = "none", int b = 0);
    Port(const Port &p); // copy constructor
    virtual ~Port() { delete[] brand; }
    Port &operator=(const Port &p);
    Port &operator+=(int b); // adds b to bottles
    Port &operator-=(int b); // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const Port &p);
};

class VintagePort : public Port // style necessarily = "vintage"
{
private:
    char *nickname; // i.e., "The Noble" or "Old Velvet", etc.
    int year;       // vintage year
public:
    VintagePort();
    VintagePort(const char *br, int b, const char *nn, int y);
    VintagePort(const VintagePort &vp);
    ~VintagePort() { delete[] nickname; }
    VintagePort &operator=(const VintagePort &vp);
    void Show() const;
    friend ostream &operator<<(ostream &os, const VintagePort &vp);
};

int chapter13_1();
int chapter13_2();
int chapter13_3();
int chapter13_4();