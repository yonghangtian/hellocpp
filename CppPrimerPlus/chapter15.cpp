#include "chapter15.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
    }
}

void Remote::settings() const
{
    cout << "This is a remote: " << endl;
    cout << "Mode = "
        << (mode == Tv::TV? "TV" : "DVD") << endl;
    cout << "Another Mode = "
        << (tv_mode == Interactive? "interactive" : "normal") << endl;
}

void Tv::set_remote_mode(Remote & t)
{
    if (state == On)
    {
        cout << "TV is on, call Remote's func now." << endl;
        t.set_remote_mode();
        t.settings();
    }
    else
    {
        cout << "TV is off, cannot call Remote's func." << endl;
    }
}

int chapter15_1() 
{ 
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58,28);
    cout << "\n58\" settings:\n";
    s58.settings();
    // std::cin.get();

    s58.set_remote_mode(grey);
    cout << "another time" << endl;
    s58.set_remote_mode(grey);
    return 0; 

}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return std::sqrt(a * b); 
}

int chapter15_2() 
{ 
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean & bg)    // start of catch block
        {
            cout << bg.what() << endl;
            cout << bg.msg() << endl;
            cout << "Try again.\n";
            continue;
        }                  
        catch (bad_gmean & hg) 
        {
            cout << hg.what() << endl;
            cout << hg.msg() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

// 15_3 is too similiar with 15_2, so won't do it.
int chapter15_3() { return 0; }

Sales::bad_index::bad_index(int ix, const string & s )
    : std::logic_error(s), bi(ix)
{
}

Sales::Sales(int yy)
{
    year = yy;
    for (int i = 0; i < MONTHS; ++i)
        gross[i] = 0;
}

Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = (n < MONTHS)? n : MONTHS;
    int i;
    for (i = 0; i < lim; ++i)
        gross[i] = gr[i];
    // for i > n and i < MONTHS
    for ( ; i < MONTHS; ++i)
        gross[i] = 0;
}

double Sales::operator[](int i) const
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

double & Sales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string & lb, int ix,
           const string & s ) : Sales::bad_index(ix, s)
{
    lbl = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy)
         : Sales(yy)
{
    label = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy, const double * gr, int n)
        : Sales(yy, gr, n)
{
    label = lb;
}

double LabeledSales::operator[](int i) const
{    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

int chapter15_4() 
{
    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] =
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar",2012, vals2, 12 );

    cout << "First try block:\n";
    try
    {
        int i;
        cout << "Year = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {
 
            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {

            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    catch(Sales::bad_index & bad)
    {
        LabeledSales::nbad_index * pn;
        cout << bad.what();
        cout << "bad index: " << bad.bi_val() << endl;
        if ( pn = dynamic_cast<LabeledSales::nbad_index *> (&bad))
        {
            cout << "Company: " << pn->label_val() << endl;
        }
    }

    cout << "\nNext try block:\n";
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "End of try block 2.\n";
    }
    catch(Sales::bad_index & bad)
    {
        LabeledSales::nbad_index * pn;
        cout << bad.what();
        cout << "bad index: " << bad.bi_val() << endl;
        if ( pn = dynamic_cast<LabeledSales::nbad_index *> (&bad))
        {
            cout << "Company: " << pn->label_val() << endl;
        }
    }
    cout << "done\n";
   // std::cin.get();
    return 0;
}