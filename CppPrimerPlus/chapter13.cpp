#include "chapter13.h"

Cd::Cd(char *s1, char *s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    // do nothing
}

// reports all CD data
void Cd::Report() const
{
    cout << "performers:" << performers << " label:" << label << " selections:" << selections << " playtime:" << playtime << endl;
}

Cd &Cd::operator=(const Cd &d)
{
    if (this == &d)
    {
        return *this;
    }

    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Cd::~Cd()
{
    // do nothing
}

Classic::Classic(char *s3_feature, char *s1, char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    strcpy(feature, s3_feature);
}

Classic::Classic(char *s3_feature, Cd &cd1) : Cd(cd1)
{
    strcpy(feature, s3_feature);
}

Classic::Classic() : Cd()
{
    // do nothing
}

void Classic::Report() const // reports all Classic data
{
    Cd::Report();
    cout << "feature: " << feature << endl;
}

Classic &Classic::operator=(const Classic &d)
{
    if (this == &d)
    {
        return *this;
    }

    Cd::operator=(d);
    strcpy(feature, d.feature);

    return *this;
}

Classic::~Classic()
{
    // do nothing
}

void Bravo(const Cd &disk);

int chapter13_1()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);

    Cd *pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use Classic method

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd &disk)
{
    disk.Report();
}

// 使用字符指针替代Cd和Classic中的字符串
Cd_new::Cd_new(char *s1, char *s2, int n, double x)
{
    int len = std::strlen(s1);
    performers = new char[len + 1];
    strcpy(performers, s1);

    len = std::strlen(s2);
    label = new char[len + 1];
    strcpy(label, s2);

    selections = n;
    playtime = x;
}

Cd_new::Cd_new(const Cd_new &d)
{
    int len = std::strlen(d.performers);
    performers = new char[len + 1];
    strcpy(performers, d.performers);

    len = std::strlen(d.label);
    label = new char[len + 1];
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
}

Cd_new::Cd_new()
{
    // need to set pointers to nullptr
    performers = nullptr;
    label = nullptr;
}

// reports all Cd_new data
void Cd_new::Report() const
{
    cout << "performers:" << performers << " label:" << label << " selections:" << selections << " playtime:" << playtime << endl;
}

Cd_new &Cd_new::operator=(const Cd_new &d)
{
    if (this == &d)
    {
        return *this;
    }

    delete[] performers;
    delete[] label;

    int len = std::strlen(d.performers);
    performers = new char[len + 1];
    strcpy(performers, d.performers);

    len = std::strlen(d.label);
    label = new char[len + 1];
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Cd_new::~Cd_new()
{
    // need to delete pointers
    delete[] performers;
    delete[] label;
}

Classic_new::Classic_new(char *s3_feature, char *s1, char *s2, int n, double x) : Cd_new(s1, s2, n, x)
{
    int len = std::strlen(s3_feature);
    feature = new char[len + 1];
    strcpy(feature, s3_feature);
}

Classic_new::Classic_new(char *s3_feature, Cd_new &Cd_new1) : Cd_new(Cd_new1)
{
    int len = std::strlen(s3_feature);
    feature = new char[len + 1];
    strcpy(feature, s3_feature);
}

Classic_new::Classic_new() : Cd_new()
{
    // need to set pointers to nullptr
    feature = nullptr;
}

void Classic_new::Report() const // reports all Classic_new data
{
    Cd_new::Report();
    cout << "feature: " << feature << endl;
}

Classic_new &Classic_new::operator=(const Classic_new &d)
{
    if (this == &d)
    {
        return *this;
    }

    Cd_new::operator=(d);

    delete[] feature;
    int len = std::strlen(d.feature);
    feature = new char[len + 1];
    strcpy(feature, d.feature);

    return *this;
}

Classic_new::~Classic_new()
{
    delete[] feature;
}

void Bravo_new(const Cd_new &disk);

int chapter13_2()
{
    Cd_new c1("Beatles", "Capitol", 14, 35.5);
    Classic_new c2 = Classic_new("Piano Sonata in B flat, Fantasia in C",
                                 "Alfred Brendel", "Philips", 2, 57.17);

    Cd_new *pCd_new = &c1;

    cout << "Using object directly:\n";
    c1.Report(); // use Cd_new method
    c2.Report(); // use Classic_new method

    cout << "Using type Cd_new * pointer to objects:\n";
    pCd_new->Report(); // use Cd_new method for Cd_new object
    pCd_new = &c2;
    pCd_new->Report(); // use Classic_new method for Classic_new object

    cout << "Calling a function with a Cd_new reference argument:\n";
    Bravo_new(c1);
    Bravo_new(c2);

    cout << "Testing assignment: ";
    Classic_new copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo_new(const Cd_new &disk)
{
    disk.Report();
}

// dma methods
DMA::DMA(const char *l, int r)
{
    label = new char[std::strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA &rs)
{
    label = new char[std::strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

DMA::~DMA()
{
    delete[] label;
}

void DMA::showLabel() const
{
    cout << "Label: " << label << endl;
}

void DMA::showRating() const
{
    cout << "Rating: " << rating << endl;
}

DMA &DMA::operator=(const DMA &rs)
{
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

// baseDMA methods
baseDMA::baseDMA(const char *l, int r) : DMA(l, r)
{
}

baseDMA::baseDMA(const baseDMA &rs) : DMA(rs)
{
}

baseDMA::~baseDMA()
{
    // call ~DMA automatically.
}

baseDMA &baseDMA::operator=(const baseDMA &rs)
{
    if (this == &rs)
        return *this;
    DMA::operator=(rs);

    return *this;
}

void baseDMA::show() const
{
    showLabel();
    showRating();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *c, const char *l, int r) : DMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const DMA &rs) : DMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA &rs) : DMA(rs)
{
    strcpy(color, rs.color);
}

lacksDMA::~lacksDMA()
{
    // call ~DMA automatically.
}

void lacksDMA::show() const
{
    showLabel();
    showRating();
    cout << color << endl;
}

// hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r) : DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const DMA &rs) : DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs)
    : DMA(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    DMA::operator=(hs); // copy base portion
    delete[] style;     // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

void hasDMA::show() const
{
    showLabel();
    showRating();
    cout << style << endl;
}

int chapter13_3()
{
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    // cout << shirt << endl;
    shirt.show();
    cout << "Displaying lacksDMA object:\n";
    // cout << balloon << endl;
    balloon.show();
    cout << "Displaying hasDMA object:\n";
    // cout << map << endl;
    map.show();
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    // cout << balloon2 << endl;
    balloon2.show();
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    // cout << map2 << endl;
    map2.show();
    // std::cin.get();
    return 0;
}

Port::Port(const char *br, const char *st, int b)
{
    int len = std::strlen(br);
    brand = new char[len + 1];
    strcpy(brand, br);

    strncpy(style, st, 19);
    style[20] = '\0';

    bottles = b;
}

Port::Port(const Port &p)
{
    int len = std::strlen(p.brand);
    brand = new char[len + 1];
    strcpy(brand, p.brand);

    strcpy(style, p.style);

    bottles = p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if (this == &p)
    {
        return *this;
    }

    delete[] brand;

    int len = std::strlen(p.brand);
    brand = new char[len + 1];
    strcpy(brand, p.brand);

    strcpy(style, p.style);

    bottles = p.bottles;

    return *this;
}

Port &Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port &Port::operator-=(int b)
{
    if (bottles < b)
    {
        cout << "Oops, lack of bottle. Current count of bottle is " << BottleCount() << endl;
        return *this;
    }

    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "brand: " << brand << endl;
    cout << "style: " << style << endl;
    cout << "bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << "brand: " << p.brand << ", style: " << p.style << ", bottles: " << p.bottles << endl;

    return os;
}

VintagePort::VintagePort() : Port("none", "vintage", 0)
{
    char none[6] = "none1";
    int len = std::strlen(none);
    nickname = new char[len + 1];
    strcpy(nickname, none);

    year = -1;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b)
{
    int len = std::strlen(nn);
    nickname = new char[len + 1];
    strcpy(nickname, nn);

    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    int len = std::strlen(vp.nickname);
    nickname = new char[len + 1];
    strcpy(nickname, vp.nickname);

    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
    {
        return *this;
    }
    Port::operator=(vp);
    delete[] nickname;
    int len = std::strlen(vp.nickname);
    nickname = new char[len + 1];
    strcpy(nickname, vp.nickname);

    year = vp.year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "nickname: " << nickname << endl;
    cout << "year: " << year << endl;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &) vp;
    os << "nickname: " << vp.nickname << ", year: " << vp.year << endl;

    return os;
}

int chapter13_4()
{

    Port a("Portabelly", "tawny", 8);
    VintagePort b("red", 5, "Blimpo", 4);
    Port c("Mercator", "ruby", 10);

    cout << "Displaying port object:\n";
    cout << a << endl;
    a.Show();
    
    cout << "Displaying VintagePort object:\n";
    cout << b << endl;
    b.Show();

    VintagePort d(b);
    cout << "Result of VintagePort copy:\n";
    cout << d << endl;
    d.Show();

    VintagePort e;
        cout << "Result of VintagePort default constructor:\n";
    cout << e << endl;
    e.Show();

    e = b;
    cout << "Result of VintagePort assignment:\n";
    cout << e << endl;
    e.Show();

    e -= 10;
    cout << "Result of VintagePort -=:\n";
    cout << e << endl;
    e.Show();

    e -= 2;
    cout << "Result of VintagePort -=:\n";
    cout << e << endl;
    e.Show();

    e += 20;
    cout << "Result of VintagePort +=:\n";
    cout << e << endl;
    e.Show();

    return 0;
}