#include "chapter2.h"

int exercise2_3()
{
    unsigned u = 10, u2 = 42;

    // 32
    std::cout << u2 - u << std::endl;
    // (10-42)%(MAX_UNSIGHED_NUM)
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    // 32
    std::cout << i2 - i << std::endl;
    //-32
    std::cout << i - i2 << std::endl;
    // 0
    std::cout << i - u << std::endl;
    // 0
    std::cout << u - i << std::endl;

    // (10-42)%(MAX_UNSIGHED_NUM)
    std::cout << u - i2 << std::endl;

    int i3 = -32;
    // 42
    std::cout << u - i3 << std::endl;

    return 0;
}

int exercise2_4_3()
{
    const int v2 = 0;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &v2, &r2 = v2; // p2,r2 low-level const, p3 top-level const,

    r1 = v2; // valid
    // p1 = p2; // p2 low-level const, invalid
    p2 = p1; // valid
    // p1 = p3; // p3 top-level const, but point to a low-level const, invalid
    p2 = p3; // valid

    return 0;
}

int exercise2_5_2()
{
//     int i = 0, &r = i;
//     auto a = r;

//     const int ci = i, &cr = ci;
//     auto b = ci;
//     auto c = cr;
//     auto d = &i;
//     auto e = &ci;

//     auto &g = ci;

//     a = 42; // valid
//     b = 42; // b: int, valid
//     c = 42; // c: int, valid
//     // d = 42; // d: pointer to int, invalid
//     // e = 42; // e: pointer to const int, invalid
//     // g = 42; // g: const int &g, is a low-level const, invalid


    const int i = 42;
    
    auto &k = i;
    // k = 1; // const int &, invalid

    auto j = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    j = 1; // top-level const is ignored.
    // k2 = 1; // const int &, invalid
    // j2 = 1; // const int, invalid


    return 0; 
}