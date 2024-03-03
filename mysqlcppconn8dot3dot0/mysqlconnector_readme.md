# Part 1: For mysql connector/c++ 8.3.0 
mysql connector/c++ 8.3.0 is downloaded from https://dev.mysql.com/downloads/connector/cpp/,
it's help doc is https://dev.mysql.com/doc/relnotes/connector-cpp/en/news-8-3-0.html

## this project(exercise12_15) use it in this way:
step 1: 
>    tar -zxvf ${mysqlconnector}.tar.gz

step 2: 
>    cp -r ${mysqlconnector}/include ${project_root}/mysqlcppconn8dot3dot0/

step 3: 
>    cp -r ${mysqlconnector}/lib64 ${project_root}/mysqlcppconn8dot3dot0/

step 4: modify CMakeLists.txt to use it: 
>    include_directories("mysqlcppconn8dot3dot0/include")
>
>    target_link_libraries(HelloCpp "/home/tianyh/projects/hellocpp/mysqlcppconn8dot3dot0/lib64/libmysqlcppconn.so")

step 5: include header file, for example: in chapter12.h:
>    #include "mysql/jdbc.h"


# Part 2: For mysql connector/c++ 1.1.12 
mysql connector/c++ 1.1.12 is installed directly from apt-get in ubuntu22.04 lts,
it's help doc is https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-getting-started-examples.html
>    ~$ sudo apt install libmysqlcppconn-dev
>
>    ~$ sudo apt list --installed | grep mysql
>>      libmysqlclient21/jammy-updates,jammy-security,now 8.0.36-0ubuntu0.22.04.1 amd64 [installed,automatic]
>>      libmysqlcppconn-dev/jammy,now 1.1.12-4ubuntu2 amd64 [installed]
>>      libmysqlcppconn7v5/jammy,now 1.1.12-4ubuntu2 amd64 [installed,automatic]
>>      mysql-client-8.0/jammy-updates,jammy-security,now 8.0.36-0ubuntu0.22.04.1 amd64 [installed,automatic]
>>      mysql-client-core-8.0/jammy-updates,jammy-security,now 8.0.36-0ubuntu0.22.04.1 amd64 [installed,automatic]
>>      mysql-common/jammy,now 5.8+1.0.8 all [installed,automatic]
>>      mysql-server-8.0/jammy-updates,jammy-security,now 8.0.36-0ubuntu0.22.04.1 amd64 [installed,automatic]
>>      mysql-server-core-8.0/jammy-updates,jammy-security,now 8.0.36-0ubuntu0.22.04.1 amd64 [installed,automatic]
>>      mysql-server/jammy-updates,jammy-security,now 8.0.36-0ubuntu0.22.04.1 all [installed]


## this project(exercise12_14)  use it in this way:
step 1: make sure you apt works:
>    $ sudo find /usr -type f -name "mysql_connection.h"
>>    /usr/include/mysql_connection.h
>    ^C
>
>    $ sudo find /usr -type f -name "libmysqlcppconn*"
>>    /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so.7.1.1.12
>>    /usr/lib/x86_64-linux-gnu/libmysqlcppconn-static.a
>
>    $ sudo find /usr -type l -name "libmysqlcppconn*"
>>    /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so.7
>>    /usr/lib/x86_64-linux-gnu/libmysqlcppconn.a
>>    /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so
>
>    $ ll /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so
>>    lrwxrwxrwx 1 root root 20 Mar 23  2020 /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so -> libmysqlcppconn.so.7

step 2: modify CMakeLists.txt to use it: 
>    target_link_libraries(HelloCpp mysqlcppconn)

step 3: include header file, for example: in chapter12.h:
>  #include <mysql_connection.h>
>
>  #include <cppconn/driver.h>
>
>  #include <cppconn/exception.h>
>
>  #include <cppconn/resultset.h>
>
>  #include <cppconn/statement.h>
>
>  #include <cppconn/prepared_statement.h>
