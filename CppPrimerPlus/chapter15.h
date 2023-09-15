#ifndef _COORDIN_H
#define _COORDIN_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
#endif

class Remote; // a forward declaration

class Tv
{
private:
    int state;             // on or off
    int volume;            // assumed to be digitized
    int maxchannel;        // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;             // TV or DVD
public:
    friend class Remote;   // Remote can access Tv private parts
    enum {Off, On};
    enum {MinVal,MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();   
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = (input == TV)? DVD : TV;}
    void settings() const; // display all settings

    void set_remote_mode(Remote & t);
};

class Remote
{
private:
    int mode;              // controls TV o     V r DVD
    int tv_mode;           // interactive mode with TV or normal mode 
public:
    friend class Tv;       // Tv can access Remote's private parts
    enum {Interactive, Normal};

    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) {t.set_input();}

    void set_remote_mode() { tv_mode = (tv_mode == Interactive)? Normal : Interactive;}
    void settings() const; // display all settings
};

class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    explicit bad_hmean(double a = 0, double b = 0, const string & s = "bad_hmean: invalid arguments: a = -b, ") : std::logic_error(s), v1(a), v2(b){}
    const string msg() const;
};

inline const string bad_hmean::msg() const
{   
    string hmean_msg = std::string(std::logic_error::what()) + "hmean(" + std::to_string(v1) + ", " + std::to_string(v2) + ")";
    return hmean_msg;
}

class bad_gmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    explicit bad_gmean(double a = 0, double b = 0, const string & s = "bad_gmean: gmean() arguments should be >= 0, ") : std::logic_error(s), v1(a), v2(b){}
    const string msg() const;
};

inline const string bad_gmean::msg() const
{  
    string gmean_msg = std::string(std::logic_error::what()) + "gmean(" +  std::to_string(v1) + ", " + std::to_string(v2) + ")";
    return gmean_msg;
}

class Sales
{
public:
    enum {MONTHS = 12};   // could be a static const
    class bad_index : public std::logic_error
    {
    private:
        int bi;  // bad index value
    public:
        explicit bad_index(int ix,
            const std::string & s = "Index error in Sales object\n");
        int bi_val() const {return bi;}
        virtual ~bad_index() throw() {}
    };
    explicit Sales(int yy = 0);
    Sales(int yy, const double * gr, int n);
    virtual ~Sales() { }
    int Year() const { return year; }
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
private:
    double gross[MONTHS];
    int year;
};

class LabeledSales : public Sales
{
  public:
    class nbad_index : public Sales::bad_index
    {
    private:
        std::string lbl;
    public:
        nbad_index(const std::string & lb, int ix,
           const std::string & s = "Index error in LabeledSales object\n");
        const std::string & label_val() const {return lbl;}
        virtual ~nbad_index() throw() {}
     };
    explicit LabeledSales(const std::string & lb = "none", int yy = 0);
    LabeledSales(const std::string & lb, int yy, const double * gr, int n);
    virtual ~LabeledSales() { }
    const std::string & Label() const {return label;}
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
private:
    std::string label;
};


int chapter15_1();
int chapter15_2();
int chapter15_3();
int chapter15_4();