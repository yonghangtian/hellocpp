cmake_minimum_required(VERSION 3.0.0)
project(HelloCpp VERSION 0.1.0)
add_compile_options(-std=c++11)
include(CTest)
enable_testing()

#add_executable(HelloCpp CppPrimerPlus/chapter91/chapter91_main.cpp CppPrimerPlus/chapter91/golf.cpp)
#add_executable(HelloCpp CppPrimerPlus/chapter111/randwalk.cpp CppPrimerPlus/chapter111/vect.cpp)
#add_executable(HelloCpp main.cpp CppPrimerPlus/chapter13.cpp)
#add_executable(HelloCpp main.cpp CppPrimerPlus/chapter17/chapter17.cpp)
# add_executable(HelloCpp main.cpp CppPrimer5thEdtion/chapter5/chapter5.cpp)
add_executable(HelloCpp main.cpp CppPrimer5thEdtion/chapter9/chapter9.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)