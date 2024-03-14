# Part 1: For mysql connector/c++ 8.3.0 
mysql connector/c++ 8.3.0 is downloaded from https://dev.mysql.com/downloads/connector/cpp/,
it's help doc is https://dev.mysql.com/doc/relnotes/connector-cpp/en/news-8-3-0.html

## this project(exercise12_15) use it in this way:
step 1: 
>    tar -zxvf ${mysqlconnector}.tar.gz

step 2: 
>    cp -r ${mysqlconnector}/include \${project_root}/mysqlcppconn8dot3dot0/

step 3: 
>    cp -r ${mysqlconnector}/lib64 \${project_root}/mysqlcppconn8dot3dot0/

step 4: modify CMakeLists.txt to use it: 
>    include_directories("mysqlcppconn8dot3dot0/include")
>
>    target_link_libraries(HelloCpp "/home/tian/projects/hellocpp/mysqlcppconn8dot3dot0/lib64/libmysqlcppconn.so")

step 5: include header file, for example: in chapter12.h:
>    #include "mysql/jdbc.h"


# Part 2: For mysql connector/c++ 1.1.12 
mysql connector/c++ 1.1.12 is downloaded it's 64-bits tar file from https://downloads.mysql.com/archives/c-cpp/,
it's help doc is https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-getting-started-examples.html

## this project(exercise12_14)  use it in this way:
step 1: 
>    tar -zxvf ${mysqlconnector}.tar.gz

step 2: 
>    cp -r ${mysqlconnector}/include \${project_root}/mysqlcppconn1dot1dot12/

step 3: 
>    cp -r ${mysqlconnector}/lib64 \${project_root}/mysqlcppconn1dot1dot12/

step 4: modify CMakeLists.txt to use it: 
>    include_directories("mysqlcppconn1dot1dot12/include")
>
>    target_link_libraries(HelloCpp "/home/tian/projects/hellocpp/mysqlcppconn1dot1dot12/lib/libmysqlcppconn.so")

step 5: include header file, for example: in chapter12.h:
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
