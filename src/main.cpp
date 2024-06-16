// #include "CppPrimerPlus/chapter17/chapter17.h"
// #include "CppPrimerPlus/chapter18.h"
// #include "CppPrimer5th/chapter2/chapter2.h"
#include "CppPrimer5th/chapter12/chapter12.h"
#include "CppPrimer5th/chapter15/chapter15.h"
#include "hello_log.h"


// global variable
bool spdlog_init_flag = true;
std::shared_ptr<spdlog::sinks::stdout_color_sink_st> console_sink;
std::shared_ptr<spdlog::sinks::rotating_file_sink_st> file_sink; 
std::shared_ptr<spdlog::logger> hellocpp_logger;

int main(int argc, char **argv)
{
    int a = testSpdLog();
    // int a = exercise12_14();
    // int a = exercise8_7(argc, argv);
    // int a = exercise6_26(argc, argv);

    return a;
}

