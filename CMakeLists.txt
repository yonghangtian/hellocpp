cmake_minimum_required(VERSION 3.10.0)
project(HelloCpp VERSION 0.1.0)
add_compile_options(-std=c++11)
include(CTest)
enable_testing()

# 安装cppcheck: 将编译命令导出到 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 安装cppcheck: 设置CPPCHECK路径
set(CPPCHECK_EXECUTABLE "/usr/bin/cppcheck")
# 安装cppcheck: 添加编译选项以显示警告信息
add_compile_options(-Wall -Wextra)


#将第三方包的.h头文件放在include目录，将so文件放到lib目录中。
# 在CMake中，你不能直接设置运行时的动态库搜索路径，因为这通常由操作系统管理，并且与具体的平台相关。然而，你可以在构建过程中设置链接器的搜索路径，以确保在链接阶段能找到正确的库。对于运行时动态库的搜索，你通常需要通过设置环境变量或者在程序启动时指定。
# 对于链接器的搜索路径，你可以在CMakeLists.txt中使用link_directories命令来添加。但是，更推荐的做法是在target_link_libraries命令中直接指定库的完整路径，因为这样做更加明确且不容易受到其他项目设置的影响
# PRJECT_SORCE_DIR变量是项目的根目录，即CMakeList.txt文件所在的目录

# mysqlcppconn1.1.12(CppPrimer5th:exercise12_14):  below part for mysqlcppconn1.1.12, installed on project root downloaded from oracle official website.
include_directories( ${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/include/mysqlcppconn1dot1dot12/include)
SET(MYSQL_CONN1_LIB
    ${PROJECT_SOURCE_DIR}/lib/mysqlcppconn1dot1dot12/lib64/libmysqlcppconn.so)

# mysqlcppconn8.3.0(CppPrimer5th:exercise12_15):  below part for mysqlcppconn8.3.0, installed on project root downloaded from oracle official website.
# include_directories("/home/tian/projects/hellocpp/mysqlcppconn8dot3dot0/include")
# target_link_libraries(HelloCpp "/home/tian/projects/hellocpp/mysqlcppconn8dot3dot0/lib64/libmysqlcppconn.so")

#add_executable(HelloCpp CppPrimerPlus/chapter91/chapter91_main.cpp CppPrimerPlus/chapter91/golf.cpp)
#add_executable(HelloCpp CppPrimerPlus/chapter111/randwalk.cpp CppPrimerPlus/chapter111/vect.cpp)
#add_executable(HelloCpp main.cpp CppPrimerPlus/chapter13.cpp)
#add_executable(HelloCpp main.cpp CppPrimerPlus/chapter17/chapter17.cpp)
#add_executable(HelloCpp main.cpp CppPrimer5th/chapter10/chapter10.cpp CppPrimer5th/chapter7/chapter7.cpp)
# add_executable(HelloCpp main.cpp CppPrimer5th/chapter12/chapter12.cpp)
# add_executable(HelloCpp main.cpp CppPrimer5th/chapter13/chapter13.cpp CppPrimer5th/chapter12/chapter12.cpp CppPrimer5th/chapter7/chapter7.cpp)
add_executable(HelloCpp main.cpp CppPrimer5th/chapter12/chapter12.cpp)

target_link_libraries(HelloCpp ${MYSQL_CONN1_LIB})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


# 安装cppcheck: 将cppcheck添加到编译目标之后
add_custom_command(TARGET HelloCpp POST_BUILD COMMAND ${CPPCHECK_EXECUTABLE} --enable=warning
                    --std=c++11 --force --quiet --project=compile_commands.json COMMENT "Running cppcheck after build")
