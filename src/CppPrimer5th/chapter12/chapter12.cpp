#include "chapter12.h"

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return eq(lhs, rhs);
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

std::string &StrBlob::operator[](std::size_t i)
{
    check(i, "out of range");
    return data->operator[](i);
}

const std::string &StrBlob::operator[](std::size_t i) const
{
    check(i, "out of range");
    return data->operator[](i);
}

char StrBlobPtr::operator[](std::size_t i)
{
    std::string temp = this->deref();
    return temp[i];
}

std::string & StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p) is the vector to which this object points
}

std::string * StrBlobPtr::operator->() const
{
    return & this->operator*();
}

// prefix version
StrBlobPtr &StrBlobPtr::operator++()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return *this;
}
// prefix version
StrBlobPtr &StrBlobPtr::operator--()
{
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr; // move the current state back one element}
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}
// postfix version
StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr temp = *this;
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return temp;
}
// postfix version
StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr temp = *this;
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr; // move the current state back one element}
    check(curr, "decrement past begin of StrBlobPtr");
    return temp;
}

StrBlobPtr operator+(const StrBlobPtr & a, std::size_t i)
{
    StrBlobPtr temp = a;
    temp.curr += i;
    temp.check(temp.curr, "increment past end of StrBlobPtr");
    return temp;
}

StrBlobPtr operator-(const StrBlobPtr & a, std::size_t i)
{
    StrBlobPtr temp = a;
    temp.curr -= i;
    temp.check(temp.curr, "decrement past begin of StrBlobPtr");
    return temp;
}

int exercise12_1()
{
    StrBlob b1;

    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        b2.show_data();
    }

    b1.show_data();

    return 0;
}

int exercise12_2()
{
    cout << "I use ../examples/12/StrBlob.h instead;";
    return 0;
}

int exercise12_3()
{
    return 0;
}

int exercise12_4()
{
    return 0;
}

int exercise12_5()
{
    // If "StrBlob(std::initializer_list<std::string> il);" is defined "explicit", there is error:
    // [build]  error: converting to ‘StrBlob’ from initializer list would use explicit constructor ‘StrBlob::StrBlob(std::initializer_list<std::__cxx11::basic_string<char> >)’
    // [build]     9 |         StrBlob b2 = {"a", "an", "the"};
    StrBlob b1 = {"a", "an", "the"};

    b1 = {"b", "c", "d"};

    StrBlob b2{"e", "f"};

    b2 = {"ahhahahh"};

    b1.show_data();
    b2.show_data();

    return 0;
}

std::vector<int> *getVectorPointer(std::vector<int> &a)
{
    return &a;
}

void getIntFromCin(std::istream &input, std::vector<int> *data)
{
    cout << "Please input integers \n";
    int a(0);
    while (input >> a)
    {
        data->push_back(a);
    }
}

void showVectorUsingPointer(std::vector<int> *data)
{
    for (auto temp : *data)
    {
        std::cout << temp << " , ";
    }
    std::cout << std::endl;
}

int exercise12_6()
{
    std::vector<int> a{10, 9, 8};
    std::vector<int> *temp = getVectorPointer(a);
    getIntFromCin(cin, temp);
    showVectorUsingPointer(temp);

    delete temp;
    temp = nullptr;
    return 0;
}

std::shared_ptr<std::vector<int>> getVectorSharedPointer(std::vector<int> a)
{
    return std::make_shared<std::vector<int>>(a);
}

void getIntFromCinSharedPointer(std::istream &input, std::shared_ptr<std::vector<int>> data)
{
    cout << "Please input integers(shared pointer version) \n";
    int a(0);
    while (input >> a)
    {
        data->push_back(a);
    }
}

void showVectorUsingSharedPointer(std::shared_ptr<std::vector<int>> data)
{
    for (auto temp : *data)
    {
        std::cout << temp << " , ";
    }
    std::cout << std::endl;
}

int exercise12_7()
{
    std::vector<int> a{10, 9, 8};
    std::shared_ptr<std::vector<int>> temp = getVectorSharedPointer(a);
    getIntFromCinSharedPointer(cin, temp);
    showVectorUsingSharedPointer(temp);

    cout << temp.use_count() << endl;

    return 0;
}

int exercise12_8()
{
    return 0;
}

int exercise12_9()
{

    int *q = new int(42), *r = new int(100);
    cout << "*r " << *r << " *q " << *q << "\n";
    delete r;
    r = q;
    cout << "*r " << *r << " *q " << *q << "\n";
    auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
    cout << "*r2 " << *r2 << " *q2 " << *q2 << "\n";
    cout << "before r2 = q2, r2 use cout " << r2.use_count() << "\n";
    cout << "before r2 = q2, q2 use cout " << q2.use_count() << "\n";
    r2 = q2;
    cout << "after r2 = q2, r2 use cout " << r2.use_count() << "\n";
    cout << "after r2 = q2, q2 use cout " << q2.use_count() << "\n";
    cout << "*r2 " << *r2 << " *q2 " << *q2 << "\n";

    return 0;
}

void processSharedPointer(std::shared_ptr<int> ptr)
{
    cout << ptr.use_count() << "\n";
} // ptr goes out of scope and is destroyed

int exercise12_10()
{
    int *p(new int(41));
    processSharedPointer(std::shared_ptr<int>(p));

    // p is a dangling pointer!
    cout << *p << endl;

    // p(new int(42));

    return 0;
}

int exercise12_11()
{
    std::shared_ptr<int> p(new int(41));
    // free(): double free detected in tcache 2
    // We shouldn't init two unique shared ptr to the same memory.
    processSharedPointer(std::shared_ptr<int>(p.get()));

    return 0;
}

int exercise12_12()
{

    auto p = new int(1);
    auto sp = std::make_shared<int>(41);
    processSharedPointer(sp);
    // error: could not convert ‘p’ from ‘int*’ to ‘std::shared_ptr<int>’
    //  processSharedPointer(new int());
    //  error: could not convert ‘p’ from ‘int*’ to ‘std::shared_ptr<int>’
    //  processSharedPointer(p);
    processSharedPointer(std::shared_ptr<int>(p));

    return 0;
}

int exercise12_13()
{
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    delete p;

    return 0;
}

void cleanPointers(sql::ResultSet *resultSet, sql::Statement *statement, sql::Connection *connection)
{
    delete resultSet;
    delete statement;
    delete connection;
}

void endMySqlConnection(sql::Connection *connection)
{
    delete connection;
}

int exercise12_14()
{
    // mysql official working example:
    // https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-examples-complete-example-2.html

    sql::Connection *con;
    sql::Statement *stmt;
    try
    {
        // 创建MySQL连接
        sql::Driver *driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "tian0724");

        // 连接到hellocpp数据库
        con->setSchema("hellocpp");

        // 先执行一条插入语句，再执行一条查询语句
        stmt = con->createStatement();
        stmt->execute("insert into connection_record(func_name, start_time) values('exercise12_14', now());");
        // stmt->execute("insert into connection_record(func_name, start_time) values(now(), now());");
        // stmt->execute("delete from connection_record where id = 10;");
        sql::ResultSet *res = stmt->executeQuery("select * from connection_record;");
        while (res->next())
        {
            cout << res->getString("id") << " " << res->getString("func_name") << " " << res->getString("start_time") << endl;
        }

        // 第一种方法：直接清理清理连接资源
        // cleanPointers(res, stmt, con);

        // 第二种方法： 定义shared_pinter，使连接资源自动释放（细化为：（1）使用lambda自定义释放函数；（2）使用常规函数自定义释放程序）
        // 使用 lambda表达式
        std::shared_ptr<sql::ResultSet> sp_res(res, [](sql::ResultSet *resultSet)
                                               { delete resultSet; });
        std::shared_ptr<sql::Statement> sp_stmt(stmt, [](sql::Statement *statement)
                                                { delete statement; });

        // 使用自定义函数
        std::shared_ptr<sql::Connection> sp_conn(con, endMySqlConnection);

        // Test Point 1: 检查con和stmt的内存是否被释放了，如果不报错，说明没有被释放;如果报段错误，说明被释放了。
        con->setSchema("hellocpp");
        stmt = con->createStatement();
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    // Test point 2: 检查con的内存是否被释放了，如果不报错，说明没有被释放;如果报段错误，说明被释放了。
    // Exception has occurred.
    // Segmentation fault
    con->setSchema("hellocpp");

    // Test point 3: 检查stmt的内存是否被释放了，如果不报错，说明没有被释放;如果报段错误，说明被释放了。
    // Exception has occurred.
    // Segmentation fault
    stmt = con->createStatement();

    return 0;
}

// 2024-March-3 Let's try to use mysql connector/c++ 8.3.0
int exercise12_15()
{

    sql::Connection *con;
    sql::Statement *stmt;
    try
    {
        // 创建MySQL连接
        sql::Driver *driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "tian0724");

        // 连接到hellocpp数据库
        con->setSchema("hellocpp");

        // 先执行一条插入语句，再执行一条查询语句
        stmt = con->createStatement();
        stmt->execute("insert into connection_record(func_name, start_time) values('exercise12_14', now());");
        // stmt->execute("insert into connection_record(func_name, start_time) values(now(), now());");
        // stmt->execute("delete from connection_record where id = 10;");
        sql::ResultSet *res = stmt->executeQuery("select * from connection_record;");
        while (res->next())
        {
            cout << res->getString("id") << " " << res->getString("func_name") << " " << res->getString("start_time") << endl;
        }

        // 第一种方法：直接清理清理连接资源
        // cleanPointers(res, stmt, con);

        // 第二种方法： 定义shared_pinter，使连接资源自动释放（细化为：（1）使用lambda自定义释放函数；（2）使用常规函数自定义释放程序）
        // 使用 lambda表达式
        std::shared_ptr<sql::ResultSet> sp_res(res, [](sql::ResultSet *resultSet)
                                               { delete resultSet; });
        std::shared_ptr<sql::Statement> sp_stmt(stmt, [](sql::Statement *statement)
                                                { delete statement; });

        // 使用自定义函数
        std::shared_ptr<sql::Connection> sp_conn(con, endMySqlConnection);
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    return 0;
}

int exercise12_16()
{
    std::unique_ptr<int> p1(new int(1024));
    //     [build] /home/tian/projects/hellocpp/CppPrimer5th/chapter12/chapter12.cpp:339:35: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
    // [build]   339 |         std::unique_ptr<int> p2 = p1;
    // [build]       |                                   ^~
    // [build] In file included from /usr/include/c++/11/memory:76,
    // [build]                  from /home/tian/projects/hellocpp/CppPrimer5th/chapter12/chapter12.h:13,
    // [build]                  from /home/tian/projects/hellocpp/CppPrimer5th/chapter12/chapter12.cpp:1:
    // [build] /usr/include/c++/11/bits/unique_ptr.h:468:7: note: declared here
    // [build]   468 |       unique_ptr(const unique_ptr&) = delete;
    // [build]       |       ^~~~~~~~~~

    // std::unique_ptr<int> p2 = p1;
    return 0;
}

int exercise12_17()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    // Error
    // std::unique_ptr<int>  p0(ix);
    // Error: munmap_chunk(): invalid pointer
    // std::unique_ptr<int>  p1(pi);

    std::unique_ptr<int> p2(pi2);
    cout << *p2 << "\n";

    // Error: munmap_chunk(): invalid pointer
    // std::unique_ptr<int> p3(&ix);

    std::unique_ptr<int> p4(new int(2048));
    cout << *p4 << "\n";

    // Error:
    // free(): double free detected in tcache 2.
    // Aborted
    // std::unique_ptr<int>  p5(p2.get());

    return 0;
}

int exercise12_18()
{
    return 0;
}

int exercise12_19()
{
    return 0;
}

int exercise12_20()
{
    string prefix("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/");
    string inFile("input_StrBlob");

    std::ifstream ins(prefix + inFile);
    std::istream_iterator<string> it_ins(ins), it_eof;

    StrBlob a;
    for (; it_ins != it_eof; ++it_ins)
    {
        a.push_back(*it_ins);
    }

    for (StrBlobPtr a_ptr = a.begin(); neq(a_ptr, a.end()); a_ptr.incr())
    {
        cout << a_ptr.deref() << "\n";
    }

    return 0;
}

int exercise12_21()
{
    return 0;
}

int exercise12_22()
{
    string prefix("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/");
    string inFile("input_StrBlob");

    std::ifstream ins(prefix + inFile);
    std::istream_iterator<string> it_ins(ins), it_eof;

    StrBlob a;
    for (; it_ins != it_eof; ++it_ins)
    {
        a.push_back(*it_ins);
    }

    for (ConstStrBlobPtr a_ptr = a.cbegin(); neq(a_ptr, a.cend()); a_ptr.incr())
    {
        cout << a_ptr.deref() << "\n";
    }

    return 0;
}

int count_size_c_str(char *str)
{
    int temp = 0;

    while (str[temp++] != '\0')
    {
    }

    return --temp;
}

int exercise12_23()
{
    char *temp1 = "this is a temp1", *temp2 = "this is a temp2";
    string temp3("this is a temp3"), temp4("this is a temp4");

    int size_temp1 = count_size_c_str(temp1), size_temp2 = count_size_c_str(temp2), i = 0;

    char *temp5 = new char[size_temp1 + size_temp2 + 1];

    // dont want to include cstrint header into my program ;)
    for (; i < size_temp1; ++i)
    {
        temp5[i] = temp1[i];
    }
    for (; i < size_temp1 + size_temp2; ++i)
    {
        temp5[i] = temp2[i - size_temp1];
    }
    temp5[i] = '\0';

    cout << temp5 << "\n";
    delete[] temp5;

    string temp6 = temp3 + temp4;
    cout << temp6 << "\n";
    return 0;
}

int exercise12_24()
{
    string temp1;
    cout << "Please input one line: "
         << "\n";
    getline(cin, temp1);

    cout << "Your input line is " << temp1 << "\n";

    char *temp2 = new char[temp1.size() * 2];
    int i = 0;

    for (; i < temp1.size(); ++i)
    {
        temp2[i] = temp1[i];
        if (i == temp1.size())
            temp2[i] = '\0';
    }

    cout << "(In dynamically allocated memory )Your input line is " << temp1 << "\n";

    delete temp2;
    return 0;
}

int exercise12_25()
{
    int *pa = new int[10]();
    pa[9] = 10;

    for (int i = 0; i < 10; ++i)
    {
        cout << pa[i] << " ";
    }

    delete[] pa;
    return 0;
}

int exercise12_26()
{
    int n = 10;
    std::allocator<string> alloc;
    string *const p = alloc.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && (q != p + n))
    {
        alloc.construct(q++, s);
    }

    const size_t size = q - p;

    // print and destory string in reverse order.
    while (q != p)
    {
        cout << *(--q) << " ";
        alloc.destroy(q);
    }

    return 0;
}

TextQuery::TextQuery(std::ifstream &in_file)
{
    std::vector<string> lines;
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

    contents = std::make_shared<std::vector<string>>(lines);
    words_map = std::make_shared<std::map<string, std::set<int>>>(word_lines_map);
    word_count = std::make_shared<std::map<string, int>>(wds_cnt);

#ifndef NDEBUG
    cout << "print TextQuery's contents: \n";
    std::ostream_iterator<string> it_cout1(cout, "\n");
    std::copy(contents->begin(), contents->end(), it_cout1);
    cout << "print TextQuery's word count: \n";
    for (auto &item : *(word_count))
    {
        cout << item.first << ", " << item.second << "||";
    }
    cout << "\n"
         << "print TextQuery's words map: \n";
    std::ostream_iterator<int> it_cout2(cout, ",");
    for (auto &item : *(words_map))
    {
        cout << " || " << item.first << " ";
        std::copy(item.second.begin(), item.second.end(), it_cout2);
    }
    cout << "\n";
#endif
}

QueryResult TextQuery::query(const string &word)
{
    auto iter = word_count->find(word);
    if (iter == word_count->end())
    {
        throw std::runtime_error("Not found\n");
    }
    std::shared_ptr<std::set<int>> line_set = std::make_shared<std::set<int>>(words_map->find(word)->second);
    int freq = iter->second;

#ifndef NDEBUG
    cout << "\n"
         << "print QueryResult's word and frequency: \n";
    cout << word << " , " << freq;
    cout << "\n"
         << "print QueryResult's line set: \n";
    std::ostream_iterator<int> it_cout2(cout, ",");
    std::copy(line_set->begin(), line_set->end(), it_cout2);
    cout << "\n";
#endif

    QueryResult result(word, freq, contents, line_set);
    return result;
}

std::ostream &print(std::ostream &os, QueryResult result)
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

TextQueryStrBlob::TextQueryStrBlob(std::ifstream &in_file)
{
    std::map<string, int> wds_cnt;
    std::map<string, std::set<int>> word_lines_map;

    string temp;
    int line = 0;

    while (getline(in_file, temp))
    {
        contents.push_back(temp);
        std::istringstream in_str(temp);
        string word;
        while (in_str >> word)
        {
            ++(wds_cnt.insert({word, 0}).first->second);
            word_lines_map[word].insert(line);
        }
        ++line;
    }

    words_map = std::make_shared<std::map<string, std::set<int>>>(word_lines_map);
    word_count = std::make_shared<std::map<string, int>>(wds_cnt);

#ifndef NDEBUG
    cout << "print TextQuery's contents: \n";
    contents.show_data();
    cout << "print TextQuery's word count: \n";
    for (auto &item : *(word_count))
    {
        cout << item.first << ", " << item.second << "||";
    }
    cout << "\n"
         << "print TextQuery's words map: \n";
    std::ostream_iterator<int> it_cout2(cout, ",");
    for (auto &item : *(words_map))
    {
        cout << " || " << item.first << " ";
        std::copy(item.second.begin(), item.second.end(), it_cout2);
    }
    cout << "\n";
#endif
}

QueryResultStrBlob TextQueryStrBlob::query(const string &word)
{
    auto iter = word_count->find(word);
    if (iter == word_count->end())
    {
        throw std::runtime_error("Not found\n");
    }
    std::shared_ptr<std::set<int>> line_set = std::make_shared<std::set<int>>(words_map->find(word)->second);
    int freq = iter->second;

#ifndef NDEBUG
    cout << "\n"
         << "print QueryResult's word and frequency: \n";
    cout << word << " , " << freq;
    cout << "\n"
         << "print QueryResult's line set: \n";
    std::ostream_iterator<int> it_cout2(cout, ",");
    std::copy(line_set->begin(), line_set->end(), it_cout2);
#endif

    QueryResultStrBlob result(word, freq, contents, line_set);
    return result;
}

std::ostream &print(std::ostream &os, QueryResultStrBlob result)
{

    cout << "The word " << result.word << " has appeared " << result.frequency << " times.\n";
    cout << "Here are detail info:\n";
    for (auto line : *(result.line_nums))
    {
        StrBlobPtr a(result.contents, line);
        cout << "( " << line << " )"
             << "   " << a.deref() << "\n";
    }
    return os;
}

void runQueries(std::ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
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

int exercise12_27()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        runQueries(inFile);
    }
    return 0;
}

int exercise12_28()
{
    return 0;
}

void runQueriesDoWhile(std::ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // // iterate with the user: prompt for a word to find and print results

    do
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
    } while (true);
}

int exercise12_29()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        runQueriesDoWhile(inFile);
    }
    return 0;
}

int exercise12_30()
{
    return 0;
}

int exercise12_31()
{
    return 0;
}

void runQueriesStrBlob(std::ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQueryStrBlob tq(infile); // store the file and build the query map
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

int exercise12_32()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        runQueriesStrBlob(inFile);
    }
    return 0;
}

int exercise12_33()
{
    std::ifstream inFile("/home/tian/projects/hellocpp/CppPrimer5th/chapter12/data/input_text.txt");
    if (inFile.is_open())
    {
        TextQuery tq(inFile);
        QueryResult qr = tq.query("//");
        cout << "\n";
        std::ostream_iterator<int> it_cout1(cout, ",");
        std::copy(qr.begin(), qr.end(), it_cout1);
        cout << "\n";
        std::ostream_iterator<string> it_cout2(cout, "\n");
        std::copy(qr.get_file()->begin(), qr.get_file()->end(), it_cout2);
    }
    inFile.close();
    return 0;
}
