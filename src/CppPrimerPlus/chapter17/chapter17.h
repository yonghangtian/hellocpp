#ifndef _COORDIN_H
#define _COORDIN_H
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iomanip> // to use std::setw
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::ios_base;
#endif

int chapter17_1();
int chapter17_2();
int chapter17_3();
int chapter17_4();
int chapter17_5();
int chapter17_6();
int chapter17_7();


class abstr_emp
{
private:
    std::string fname;    // abstr_emp's first name
    std::string lname;    // abstr_emp's last name
    std::string job;
public:
	 enum classkind{Employee, Manager, Fink, Highfink};
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string &  ln,
             const std::string &  j);
    virtual void ShowAll() const;    // labels and shows all data
    virtual void SetAll();        // prompts user for values
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    // just displays first and last name
    virtual ~abstr_emp() = 0;         // virtual base class
	 virtual void writeall(std::ofstream & ofs) const;
	 virtual void getall(std::ifstream & ofs);
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string &  ln,
             const std::string &  j);
    virtual void ShowAll() const;
    virtual void SetAll();
	 virtual void writeall(std::ofstream & ofs) const;
	 virtual void getall(std::ifstream & ofs);
};

class manager:  virtual public abstr_emp
{
private:
    int inchargeof;        // number of abstr_emps managed
protected:
    int InChargeOf() const { return inchargeof; } // output
    int & InChargeOf(){ return inchargeof; }      // input
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
	 virtual void writeall(std::ofstream & ofs) const;
	 virtual void getall(std::ifstream & ofs);
};

class fink: virtual public abstr_emp
{
private:
    std::string reportsto;        // to whom fink reports
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo(){ return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
	 virtual void writeall(std::ofstream & ofs) const;
	 virtual void getall(std::ifstream & ofs);
};

class highfink: public manager, public fink // management fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
	 virtual void writeall(std::ofstream & ofs) const;
	 virtual void getall(std::ifstream & ofs);
};


class Store
{	
private:
	std::ofstream * pfout;
public:
	Store(std::ofstream & fout) {pfout = &fout;}
	~Store() {}
	Store & operator()(const string & str)
	{
		std::size_t len = str.length();
		pfout->write((char *) &len, sizeof(std::size_t));
		pfout->write(str.data(), len);
		return *this;
	}	
};