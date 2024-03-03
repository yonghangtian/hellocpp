#include "chapter12.h"
#include "../examples/12/StrBlob.h"

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
        con = driver->connect("tcp://127.0.0.1:3306", "root", "950724");

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
        con = driver->connect("tcp://127.0.0.1:3306", "root", "950724");

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
    return 0;
}

int exercise12_17()
{
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
    return 0;
}

int exercise12_21()
{
    return 0;
}

int exercise12_22()
{
    return 0;
}

int exercise12_23()
{
    return 0;
}

int exercise12_24()
{
    return 0;
}

int exercise12_25()
{
    return 0;
}

int exercise12_26()
{
    return 0;
}

int exercise12_27()
{
    return 0;
}

int exercise12_28()
{
    return 0;
}

int exercise12_29()
{
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

int exercise12_32()
{
    return 0;
}

int exercise12_33()
{
    return 0;
}
