#include "chapter13.h"

// Initialize the static counter to 0
int numbered::serialNumberCounter = 0;
int employee::serialNumberCounter = 0;

ostream &operator<<(ostream &os, const HasPtr &hp)
{
    os << "ps point to " << *hp.ps << " , i is " << hp.i << " , ps is " << hp.ps << "\n";
    return os;
}

ostream &operator<<(ostream &os, const PlHasPtr &hp)
{
    os << "ps point to " << *hp.ps << " , i is " << hp.i << " , refCnt is " << hp.refCnt << "\n";
    return os;
}

ostream &operator<<(ostream &os, const TreeNode &tn)
{
    os << "string " << tn.value << " , count is " << tn.count << " , left addr is " << tn.left << " , right addr is " << tn.right << " , refCnt is " << *tn.refCnt << "\n";
    return os;
}

ostream &operator<<(ostream &os, const MessageForPlFolder &m)
{
    os << "Message content: " << m.contents << "\n";
    for (auto f : m.folders)
    {
        os << "---> Folder addr: " << f << "\n";
    }
    return os;
}

ostream &operator<<(ostream &os, const PlFolder &f)
{
    os << "This is a folder: "
       << "\n";
    for (auto m : *f.spMessages)
    {
        os << "|----> Message addr: " << m << "\n";
    }
    return os;
}

ostream &operator<<(ostream &os, const Message &m)
{
    os << "Message content: " << m.contents << "\n";
    for (auto f : m.folders)
    {
        os << "---> Folder addr: " << f << "\n";
    }
    return os;
}

ostream &operator<<(ostream &os, const Folder &f)
{
    os << "This is a folder: "
       << "\n";
    for (auto m : f.messages)
    {
        os << "|----> Message addr: " << m << "\n";
    }
    return os;
}

std::ostream &print(std::ostream &os, QueryResultUseStrVec result)
{
    cout << "The word " << result.word << " has appeared " << result.frequency << " times.\n";
    cout << "Here are detail info:\n";
    for (auto line : *(result.line_nums))
    {
        cout << "( " << line << " )"
             << "   " << result.contents->at(line) << "\n";
    }
    return os;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    return (lhs.size() == rhs.size()) && (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

ostream &operator<<(ostream &os, const SelfDefinedStr &s)
{
    os << "This is a SelfDefinedStr: "
       << "\n";
    // for (auto a = s.elements; a!=s.first_free;)
    // {
    //     os << *(a++);
    // }
    std::for_each(s.begin(), s.end(), [&](char &p)
                  { os << p; });
    return os;
}

bool operator==(const SelfDefinedStr &lhs, const SelfDefinedStr &rhs)
{
    return (lhs.size() == rhs.size()) && (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const SelfDefinedStr &lhs, const SelfDefinedStr &rhs)
{
    return !(lhs == rhs);
}

// add this Message to Folders that point to m
void MessageForPlFolder::add_to_Folders(const MessageForPlFolder &m)
{
    for (auto f : m.folders) // for each Folder that holds m
        f->addMsg(this);     // add a pointer to this Message to that Folder
}

// remove this Message from the corresponding Folders
void MessageForPlFolder::remove_from_Folders()
{
    for (auto f : folders) // for each pointer in folders
        f->remMsg(this);   // remove this Message from that Folder
}

MessageForPlFolder::MessageForPlFolder(const MessageForPlFolder &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); // add this Message to the Folders that point to m
}

MessageForPlFolder &MessageForPlFolder::operator=(const MessageForPlFolder &rhs)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();   // update existing Folders
    contents = rhs.contents; // copy message contents from rhs
    folders = rhs.folders;   // copy Folder pointers from rhs
    add_to_Folders(rhs);     // add this Message to those Folders
    return *this;
}

MessageForPlFolder::~MessageForPlFolder()
{
    remove_from_Folders();
}

void MessageForPlFolder::save(PlFolder &f)
{
    folders.insert(&f); // add the given Folder to our list of Folders
    f.addMsg(this);     // add this Message to f's set of Messages
}

void MessageForPlFolder::remove(PlFolder &f)
{
    folders.erase(&f); // take the given Folder out of our list of Folders
    f.remMsg(this);    // remove this Message to f's set of Messages
}

PlFolder &PlFolder::operator=(const PlFolder &f)
{
    if (spMessages == f.spMessages)
    {
        return *this;
    }

    spMessages = f.spMessages;
    return *this;
}

PlFolder::~PlFolder()
{
    for (auto m : *spMessages)
    {
        m->folders.erase(this);
    }
}

// add this Message to Folder
void PlFolder::addMsg(MessageForPlFolder *m)
{
    if (!spMessages)
    {
        std::set<MessageForPlFolder *> messages;
        spMessages = std::make_shared<std::set<MessageForPlFolder *>>(messages);
    }
    spMessages->insert(m);
}

// remove this Message to Folder
void PlFolder::remMsg(MessageForPlFolder *m)
{
    spMessages->erase(m);
}

// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) // for each Folder that holds m
        f->addMsg(this);     // add a pointer to this Message to that Folder
}

// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
    for (auto f : folders) // for each pointer in folders
        f->remMsg(this);   // remove this Message from that Folder
}

void Message::addFolder(Folder *f)
{
    folders.insert(f);
}

void Message::remFolder(Folder *f)
{
    folders.erase(f);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); // add this Message to the Folders that point to m
}

Message &Message::operator=(const Message &rhs)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();   // update existing Folders
    contents = rhs.contents; // copy message contents from rhs
    folders = rhs.folders;   // copy Folder pointers from rhs
    add_to_Folders(rhs);     // add this Message to those Folders
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f); // add the given Folder to our list of Folders
    f.addMsg(this);     // add this Message to f's set of Messages
}

void Message::remove(Folder &f)
{
    folders.erase(&f); // take the given Folder out of our list of Folders
    f.remMsg(this);    // remove this Message to f's set of Messages
}

void Folder::remove_from_Messages()
{
    for (auto m : messages)
    {
        m->remFolder(this);
    }
}
void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.messages) // for each Folder that holds m
        m->addFolder(this);
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
    for (auto m : messages)
    {
        m->addFolder(this);
    }
}

Folder &Folder::operator=(const Folder &f)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Messages(); // update existing Folders
    messages = f.messages;  // copy Folder pointers from rhs
    add_to_Messages(f);     // add this Message to those Folders
    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

// definition for static data member
std::allocator<string> StrVec::alloc;

StrVec::StrVec(const StrVec &temp)
{
    auto ps_pair = alloc_n_copy(temp.begin(), temp.end());
    elements = ps_pair.first;
    first_free = ps_pair.second;
    cap = ps_pair.second;
}

StrVec &StrVec::operator=(const StrVec &temp)
{
    auto ps_pair = alloc_n_copy(temp.begin(), temp.end());
    free();
    elements = ps_pair.first;
    first_free = ps_pair.second;
    cap = ps_pair.second;

    return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> temp)
{
    auto newdata = alloc_n_copy(temp.begin(), temp.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
}

std::string &StrVec::operator[](size_t i)
{
    if (i >= size())
        throw std::runtime_error("Out of range\n");

    return *(elements + i);
}

const std::string &StrVec::operator[](size_t i) const
{
    if (i >= size())
        throw std::runtime_error("Out of range\n");

    return *(elements + i);
}

std::string StrVec::at(size_t i) const
{
    if (i >= size())
        throw std::runtime_error("Out of range\n");

    return *(elements + i);
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&s) noexcept
{
    if (this != &s)
    {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() noexcept
{
    free();
}

StrVec::StrVec(std::initializer_list<std::string> temp)
{
    auto newdata = alloc_n_copy(temp.begin(), temp.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::push_back(const std::string &s)
{
    cout << "(" << __FUNCTION__ << ")"
         << " push_back(const std::string &s)\n";
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s)
{
    cout << "(" << __FUNCTION__ << ")"
         << " push_back(std::string &&s)\n";
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    // Let's try
    auto const p = alloc.allocate(e - b);
    return {p, std::uninitialized_copy(b, e, p)};
}

void StrVec::free()
{
    if (elements)
    {
        // Way 1: original for loop
        // for (auto p = first_free; p != elements;)
        // {
        //     alloc.destroy(--p);
        // }

        // Way 2: iterator and lambda
        auto reverse_begin = boost::make_reverse_iterator(end());
        auto reverse_end = boost::make_reverse_iterator(begin());
        std::for_each(reverse_begin, reverse_end, [&](string &p)
                      { alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto const p = alloc.allocate(newcapacity);
    auto dest = p;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*(elem++)));
    }
    free();
    elements = p;
    first_free = dest;
    cap = elements + newcapacity;
}

TextQueryUseStrVec::TextQueryUseStrVec(std::ifstream &in_file)
{
    StrVec lines;
    std::map<string, int> wds_cnt;
    std::map<string, std::set<int>> word_lines_map;

    string temp("");
    int line = 0;

    while (getline(in_file, temp))
    {
        lines.push_back(temp);
        std::istringstream in_str(temp);
        string word;
        while (in_str >> word)
        {
            ++(wds_cnt.insert({word, 0}).first->second);
            word_lines_map[word].insert(line);
        }
        ++line;
    }

    contents = std::make_shared<StrVec>(lines);
    words_map = std::make_shared<std::map<string, std::set<int>>>(word_lines_map);
    word_count = std::make_shared<std::map<string, int>>(wds_cnt);
}

QueryResultUseStrVec TextQueryUseStrVec::query(const string &word)
{
    auto iter = word_count->find(word);
    if (iter == word_count->end())
    {
        throw std::runtime_error("Not found\n");
    }
    std::shared_ptr<std::set<int>> line_set = std::make_shared<std::set<int>>(words_map->find(word)->second);
    int freq = iter->second;

    QueryResultUseStrVec result(word, freq, contents, line_set);
    return result;
}

// definition for static data member
std::allocator<char> SelfDefinedStr::alloc;

SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
{
    cout << "SelfDefinedStr(const SelfDefinedStr &temp) \n";
    auto ps_pair = alloc_n_copy(temp.begin(), temp.end());
    elements = ps_pair.first;
    first_free = ps_pair.second;
    cap = ps_pair.second;
}

SelfDefinedStr &SelfDefinedStr::operator=(const SelfDefinedStr &temp)
{
    cout << "SelfDefinedStr &operator=(const SelfDefinedStr &temp) \n";
    auto ps_pair = alloc_n_copy(temp.begin(), temp.end());
    free();
    elements = ps_pair.first;
    first_free = ps_pair.second;
    cap = ps_pair.second;

    return *this;
}

SelfDefinedStr::SelfDefinedStr(SelfDefinedStr &&sds) noexcept
    : elements(sds.elements), first_free(sds.first_free), cap(sds.cap)
{
    cout << "SelfDefinedStr(SelfDefinedStr && sds) noexcept \n";
    sds.elements = sds.first_free = sds.cap = nullptr;
}

SelfDefinedStr &SelfDefinedStr::operator=(SelfDefinedStr &&sds) noexcept
{
    cout << "SelfDefinedStr &operator=(SelfDefinedStr && sds) noexcept  \n";
    if (this != &sds)
    {
        free();
        elements = sds.elements;
        first_free = sds.first_free;
        cap = sds.cap;
        sds.elements = sds.first_free = sds.cap = nullptr;
    }
    return *this;
}

char SelfDefinedStr::operator[](size_t i) const
{
    return this->at(i);
}

// at function
char SelfDefinedStr::at(size_t i) const
{
    if (i >= size())
        throw std::runtime_error("Out of range\n");

    return *(elements + i);
}

SelfDefinedStr::~SelfDefinedStr() noexcept
{
    free();
}

SelfDefinedStr::SelfDefinedStr(const char *temp)
{
    // need calc the len of temp
    size_t len = 0;
    while (temp[len] != '\0')
    {
        ++len;
    }

    auto newdata = alloc_n_copy(temp, temp + len);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void SelfDefinedStr::push_back(const char s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<char *, char *> SelfDefinedStr::alloc_n_copy(const char *b, const char *e)
{
    // Let's try
    auto const p = alloc.allocate(e - b);
    return {p, std::uninitialized_copy(b, e, p)};
}

void SelfDefinedStr::free()
{
    if (elements)
    {
        // Way 1: original for loop
        // for (auto p = first_free; p != elements;)
        // {
        //     alloc.destroy(--p);
        // }

        // Way 2: iterator and lambda
        auto reverse_begin = boost::make_reverse_iterator(end());
        auto reverse_end = boost::make_reverse_iterator(begin());
        std::for_each(reverse_begin, reverse_end, [&](char &p)
                      { alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

void SelfDefinedStr::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto const p = alloc.allocate(newcapacity);
    auto dest = p;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, *(elem++));
    }
    free();
    elements = p;
    first_free = dest;
    cap = elements + newcapacity;
}

Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    return *this;
}

// working version
// Foo Foo::sorted() const &
// {
//     Foo ret(*this);
//     std::sort(ret.data.begin(), ret.data.end());
//     return ret;
// }

// For exercise13_56
// Foo Foo::sorted() const &
// {
//     Foo ret(*this);
//     // Error: Segmentation fault, as ret is a lvalue, ret.sorted() call "Foo sorted() const &" endless.
//     return ret.sorted();
// }

// For exercise13_57, Foo(*this) is rvalue, so Foo(*this).sorted() calls "Foo Foo::sorted() &&"
Foo Foo::sorted() const &
{
    return Foo(*this).sorted();
}

int exercise13_1()
{
    return 0;
}

int exercise13_2()
{
    return 0;
}

int exercise13_3()
{
    StrBlob a({"abc", "def"});
    StrBlob b = a;

    a.show_data();
    b.show_data();

    StrBlobPtr c = a.begin();
    cout << c.deref() << "\n";
    StrBlobPtr d = c;
    d.incr();
    cout << d.deref() << "\n";

    return 0;
}

int exercise13_4()
{
    // Point global;
    // Point foo_bar(Point arg) //函数参数Point arg的初始化。
    // {
    //     Point local = arg, *heap = new Point(global);//(1)局部变量Point local的初始化;(2)new Point(global)使用拷贝构造函数创建了一个新的Point对象在堆上，这是第三个使用
    //     *heap = local;// 是赋值操作（可能调用了赋值运算符）
    //     // 在C++中，当使用初始化列表来初始化数组时，如果提供的初始化器数量少于数组的元素数量，
    //     // 那么剩余的元素会使用该类型的默认构造函数进行初始化。如果类型没有默认构造函数，则代码将不会编译通过。
    //     Point pa[4] = {local, *heap};//初始化数组pa时，local和*heap都是通过拷贝构造函数初始化的，这是第四和第五个使用
    //     return *heap; // 这里返回*heap时，通常会通过拷贝构造函数来创建返回的临时对象（如果是按值返回）
    // }

    return 0;
}

int exercise13_5()
{
    HasPtr a("this is a HasPtr");

    HasPtr b(a);
    // use complier's debug, we can see that a.ps 's address is : 0x5555555792f0
    // while, b.ps 's address is 0x555555579340. We have achieved the target(copy string, not the pointer.)
    return 0;
}

int exercise13_6()
{
    return 0;
}

int exercise13_7()
{
    StrBlob a({"abc", "def"});
    StrBlob b({"lxy", "tyh"});
    StrBlobPtr c = a.begin();
    StrBlobPtr d = b.begin();
    a.show_data();
    b.show_data();
    cout << c.deref() << "\n";
    cout << d.deref() << "\n";

    d = c;

    b = a;
    b.show_data();
    d.incr();
    cout << d.deref() << "\n";
    return 0;
}

int exercise13_8()
{
    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");

    cout << a << b;
    a = b;

    cout << a;
    return 0;
}

int exercise13_9()
{
    return 0;
}

int exercise13_10()
{
    return 0;
}

int exercise13_11()
{
    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");

    cout << a << b;
    a = b;

    cout << a;
    return 0;
}

bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}

int exercise13_12()
{
    Sales_data a("pride", 10, 9.99);
    Sales_data b("pride", 20, 8.88);

    Sales_data *c = &a;

    cout << fcn(c, b) << "\n";

    cout << b << "\n";

    return 0;
}

int exercise13_13()
{
    // (HasPtr) HasPtr()
    // (HasPtr) HasPtr()
    // ps point to this is a HasPtr , i is 0
    // ps point to second hasptr , i is 0
    // (operator=) HasPtr &operator=(const HasPtr &)
    // ps point to second hasptr , i is 0
    // (HasPtr) HasPtr()
    // (HasPtr) HasPtr(const HasPtr &)
    // (HasPtr) HasPtr(const HasPtr &)
    // (HasPtr) HasPtr(const HasPtr &)
    // ps point to second hasptr , i is 0
    // ps point to second hasptr , i is 0
    // ps point to let's try , i is 0
    // (~HasPtr) ~HasPtr()
    // String "let's try" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed
    // (~HasPtr) ~HasPtr()
    // String "second hasptr" is destoryed

    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");
    cout << a << b;
    a = b;
    cout << a;
    HasPtr *c = new HasPtr("let's try");
    HasPtr d[3] = {a, b, *c};
    cout << d[0] << d[1] << d[2];
    delete c;
    return 0;
}

void f(numbered s) { cout << s.getSerialNumber() << endl; }

void f_const(const numbered &s) { cout << s.getSerialNumber() << endl; }

int exercise13_14()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}

int exercise13_15()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}

int exercise13_16()
{
    numbered a, b = a, c = b;
    cout << a.getSerialNumber() << "\n";
    f(a);
    cout << b.getSerialNumber() << "\n";
    f(b);
    cout << c.getSerialNumber() << "\n";
    f(c);
    return 0;
}

int exercise13_17()
{
    return 0;
}

int exercise13_18()
{
    employee a;
    employee b = a, c = b;

    a.getEmployeeInfo();
    b.getEmployeeInfo();
    c.getEmployeeInfo();

    return 0;
}

int exercise13_19()
{
    employee a;
    employee b = a, c = b;
    b.setName("tian");
    c.setName("yonghang");
    a.getEmployeeInfo();
    b.getEmployeeInfo();
    c.getEmployeeInfo();

    return 0;
}

int exercise13_20()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        TextQuery tq(inFile);
        QueryResult qr = tq.query("//");
        print(cout, qr) << endl;

        TextQuery tq2 = tq;
        QueryResult qr2 = qr;
        print(cout, qr2) << endl;
        qr2 = tq2.query("program");
        print(cout, qr2) << endl;
    }

    inFile.close();
    return 0;
}

int exercise13_21()
{
    return 0;
}

int exercise13_22()
{
    return 0;
}

int exercise13_23()
{
    exercise13_13();
    return 0;
}

int exercise13_24()
{
    return 0;
}

int exercise13_25()
{
    return 0;
}

int exercise13_26()
{
    StrBlob a({"abc", "def"});
    StrBlob b;
    a.show_data();
    b.show_data();

    // Before assignment, data use count 1
    // After assignment, data use count 2
    // temp also point to the shared pointer.
    b = a;
    //     Current data use count 1
    // abc , def ,
    // temp was destoryed.
    b.show_data();
    // Current data use count 1
    // abc , def ,
    a.show_data();
    return 0;
}

int exercise13_27()
{
    PlHasPtr a("this is a HasPtr", 2);
    PlHasPtr b("second hasptr", 5);
    cout << a << b;
    a = b;
    cout << a;
    PlHasPtr *c = new PlHasPtr("let's try");
    PlHasPtr d[3] = {a, b, *c};
    cout << d[0] << d[1] << d[2];
    delete c;
    return 0;
}

int exercise13_28()
{
    TreeNode root("root", 10);
    TreeNode leftLeaf("leftLeaf", 4);
    TreeNode rightLeaf("rightLeaf", 6);

    root.setLeft(&leftLeaf);
    root.setRight(&rightLeaf);

    cout << root;

    TreeNode cpRoot;
    cpRoot = root;

    cout << cpRoot;

    cpRoot.setLeft(new TreeNode("newleft", 5));
    cpRoot.setRight(new TreeNode("newright", 7));
    cout << cpRoot;

    delete cpRoot.getLeft();
    delete cpRoot.getRight();
    return 0;
}

int exercise13_29()
{
    // inline void swap(HasPtr &lhs, HasPtr &rhs)
    // {
    //  using std::swap;
    //  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    //  swap(lhs.i, rhs.i); // swap the int members
    // }
    return 0;
}

int exercise13_30()
{
    HasPtr a("this is a HasPtr");
    HasPtr b("second hasptr");
    cout << a << b;
    swap(a, b);
    cout << a << b;
    return 0;
}

int exercise13_31()
{

    HasPtr a("this is a HasPtr", 1);
    HasPtr b("second hasptr", 100);
    HasPtr c("third hasptr", 2);
    cout << "a < b : " << (a < b) << "\n";
    cout << "b < a : " << (b < a) << "\n";

    vector<HasPtr> vec{a, b, c};

    for (const auto &item : vec)
    {
        cout << item << "\n";
    }

    // we're using copy and swap version of operator=
    std::sort(vec.begin(), vec.end());
    cout << "After sort \n";
    for (const auto &item : vec)
    {
        cout << item << "\n";
    }
    // ps point to this is a HasPtr , i is 1 , ps is 0x1f776b0
    // ps point to second hasptr , i is 100 , ps is 0x1f776d0
    // ps point to third hasptr , i is 2 , ps is 0x1f776f0
    // swap called
    // swap called
    // swap called
    // After sort
    // ps point to this is a HasPtr , i is 1 , ps is 0x1f776b0
    // ps point to third hasptr , i is 2 , ps is 0x1f776f0
    // ps point to second hasptr , i is 100 , ps is 0x1f776d0

    return 0;
}

int exercise13_32()
{
    exercise13_27();
    return 0;
}

int exercise13_33()
{
    return 0;
}

int exercise13_34()
{
    MessageForPlFolder a("this is a");
    cout << &a << " <-- a's addr \n";
    PlFolder one;
    cout << &one << " <-- one's addr \n";
    {
        a.save(one);
        MessageForPlFolder b("b, it is.");
        cout << &b << " <-- b's addr \n";
        b.save(one);
        PlFolder two;
        cout << &two << " <-- two's addr \n";
        b.save(two);
        PlFolder three(one);
        cout << a << b << one << two << three;

        one = two;
        cout << "Test folder assignment \n"
             << one << two << three;
        one = three;

        MessageForPlFolder c("c ha");
        c = b;
        c.remove(two);
        cout << "Test message assignment \n"
             << a << b << c << one << two;
    }
    cout << "Out of block(Folder two and Message two are out of scope): \n";
    cout << a << one;

    return 0;
}

int exercise13_35()
{
    return 0;
}

int exercise13_36()
{
    Message a("this is a");
    cout << &a << " <-- a's addr \n";
    Folder one;
    cout << &one << " <-- one's addr \n";
    {
        a.save(one);
        Message b("b, it is.");
        cout << &b << " <-- b's addr \n";
        b.save(one);
        Folder two;
        cout << &two << " <-- two's addr \n";
        b.save(two);
        Folder three(one);
        cout << a << b << one << two << three;

        one = two;
        cout << "---------------------------Test folder assignment--------------------------- \n"
             << a << b << one << two << three;
        one = three;
        cout << "---------------------------Test folder assignment(again)--------------------------- \n"
             << a << b << one << two << three;

        Message c("c ha");
        c = b;
        c.remove(two);
        cout << "---------------------------Test message assignment--------------------------- \n"
             << a << b << c << one << two << three;
    }
    cout << "Out of block(Folder two and Message two are out of scope): \n";
    cout << a << one;

    return 0;
}

int exercise13_37()
{
    exercise13_36();
    return 0;
}

int exercise13_38()
{
    return 0;
}

int exercise13_39()
{
    StrVec a;
    string t1("temp str"), t2("temp str2"), t3("temp str3");
    a.push_back(t1);
    a.push_back(t2);

    cout << a.size() << "\n"
         << a.capacity() << "\n";

    return 0;
}

int exercise13_40()
{
    string t1("temp str"), t2("temp str2"), t3("temp str3");
    StrVec a{t1, t2, t3};
    cout << a.size() << "\n"
         << a.capacity() << "\n";
    return 0;
}

int exercise13_41()
{
    return 0;
}

int exercise13_42()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        // infile is an ifstream that is the file we want to query
        TextQueryUseStrVec tq(inFile); // store the file and build the query map
        // // iterate with the user: prompt for a word to find and print results
        while (true)
        {
            cout << "enter word to look for, or q to quit: ";

            string s;
            // stop if we hit end-of-file on the input or if a 'q' is entered
            if (!(cin >> s) || s == "q")
                break;
            // run the query and print the results
            try
            {
                print(cout, tq.query(s)) << endl;
            }
            catch (std::runtime_error e)
            {
                cout << "# ERR: Exception in " << __FILE__;
                cout << "(" << __FUNCTION__ << ") on line "
                     << __LINE__ << endl;
                cout << "# ERR: " << e.what();
                break;
            }
        }
    }

    return 0;
}

int exercise13_43()
{
    return 0;
}

int exercise13_44()
{
    char *temp = "this is a str";
    SelfDefinedStr a(temp);

    SelfDefinedStr b = a;
    b.push_back('h');
    b.push_back('t');
    b.push_back('y');

    SelfDefinedStr c;

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    return 0;
}

int exercise13_45()
{
    return 0;
}

int f()
{
    return 1;
}

int exercise13_46()
{

    std::vector<int> vi(100);
    int &&r1 = f();
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0] * f();

    cout << "r1 : " << r1 << ", r2 : " << r2 << ", r3 : " << r3 << ", r4 : " << r4;
    return 0;
}

int exercise13_47()
{
    return 0;
}

int exercise13_48()
{
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr::SelfDefinedStr(const SelfDefinedStr &temp)

    char *temp = "this is a str";
    SelfDefinedStr a(temp);

    SelfDefinedStr b = a;
    b.push_back('h');
    b.push_back('t');
    b.push_back('y');

    SelfDefinedStr c("another str");

    vector<SelfDefinedStr> vec{a, b, c};
    return 0;
}

int exercise13_49()
{
    // (1) 这些是Push_back时调用的
    // SelfDefinedStr(const SelfDefinedStr &temp)

    // SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept

    // SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept
    vector<SelfDefinedStr> vec;
    char *temp = "this is a str";
    SelfDefinedStr a(temp);

    // SelfDefinedStr b = a;
    // b.push_back('h');
    // b.push_back('t');
    // b.push_back('y');
    SelfDefinedStr c("another str");
    SelfDefinedStr d = "another str1111";
    vec.push_back(a);
    vec.push_back(c);
    vec.push_back(d);
    return 0;
}

int exercise13_50()
{
    // 0x7fff14b4ff00
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept
    // 0x7fff14b4ff00, 0x1742570
    // SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept
    // 0x7fff14b4ff00, 0x1742590, 0x17425a8
    // SelfDefinedStr(const SelfDefinedStr &temp)
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept
    // SelfDefinedStr(SelfDefinedStr && sds) noexcept
    // 0x7fff14b4ff00, 0x17425f0, 0x1742608, 0x1742620

    vector<SelfDefinedStr> vec;
    char *temp = "this is a str";
    SelfDefinedStr a(temp);

    SelfDefinedStr c("another str");
    SelfDefinedStr d = "another str1111";
    cout << &vec << "\n";
    vec.push_back(std::move(a));
    cout << &vec << ", " << &vec[0] << "\n";
    vec.push_back(c);
    cout << &vec << ", " << &vec[0] << ", " << &vec[1] << "\n";
    vec.push_back(d);
    cout << &vec << ", " << &vec[0] << ", " << &vec[1] << ", " << &vec[2] << "\n";
    return 0;
}

int exercise13_51()
{
    return 0;
}

int exercise13_52()
{
    string temp("this is a temp");
    HasPtr a(temp, 1);
    temp.push_back('a');
    cout << "temp addr: " << &temp << "\n";
    HasPtr b(temp, 2);
    HasPtr c, d;
    cout << a << b << c << d;
    // (HasPtr) HasPtr(const HasPtr &)
    // (operator=) HasPtr &operator=(HasPtr &)
    // swap called
    // (~HasPtr) ~HasPtr()
    c = a;

    // HasPtr(HasPtr &&p) noexcept
    // (operator=) HasPtr &operator=(HasPtr &)
    // swap called
    // (~HasPtr) ~HasPtr()
    d = std::move(b);
    cout << a << c << d;
    return 0;
}

int exercise13_53()
{
    string temp("this is a temp");
    HasPtr a(temp, 1);
    temp.push_back('a');
    cout << "temp addr: " << &temp << "\n";
    HasPtr b(temp, 2);
    HasPtr c, d;
    cout << a << b << c << d;
    // (operator=) HasPtr &operator=(const HasPtr &)
    c = a;
    // (operator=) HasPtr &operator=(HasPtr &&)
    // swap called
    d = std::move(b);
    cout << a << c << d;
    return 0;
}

int exercise13_54()
{
    // When we enable  (2) copy and swap verion of operator=, and inline HasPtr &operator=(HasPtr &&hp)
    // error: ambiguous overload for ‘operator=’ (operand types are ‘HasPtr’ and ‘std::remove_reference<HasPtr&>::type {aka HasPtr}’)
    return 0;
}

int exercise13_55()
{
    StrVec a;
    string temp("this is a str");
    // (push_back) push_back(const std::string &s)
    a.push_back(temp);
    // (push_back) push_back(std::string &&s)
    a.push_back("test");
    return 0;
}

int exercise13_56()
{
    Foo a;
    a.data.push_back(1);
    a.data.push_back(3);
    a.data.push_back(2);

    // Segmentation fault
    Foo c = a.sorted();
    return 0;
}

int exercise13_57()
{
    // 1, 3, 2,
    // 1, 2, 3,
    Foo a;
    a.data.push_back(1);
    a.data.push_back(3);
    a.data.push_back(2);
    for (auto b : a.data)
    {
        cout << b << ", ";
    }
    cout << "\n";
    Foo c = a.sorted();
    for (auto b : c.data)
    {
        cout << b << ", ";
    }
    cout << "\n";
    return 0;
}

int exercise13_58()
{
    return 0;
}
