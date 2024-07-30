#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <type_traits>

#include "to_string.h"

void test1(void);
void test2(void);
void test_double(double d1, double d2, long long precision);

int main()
{
    // test1();
    test2();
    return 0;
}

void test1(void)
{
    float  f = 10.12f;
    double d = 10.12;

    std::cout << std::fixed << f
              << " "<< d << std::endl;
    // 10.120000 10.120000

    std::cout << std::fixed << j2::to_string<float>(f)
              << " " << j2::to_string<double>(d) << std::endl;
    // 10.119999886 10.11999999999999922

    std::cout << std::fixed << j2::to_string<float>(f, 2)
              << " " << j2::to_string<double>(d, 2) << std::endl;
    // 10.12 10.12

    std::cout << std::fixed << j2::to_string<float>(f,10)
              << " " << j2::to_string<double>(d,20) << std::endl;
    // 10.1199998856 10.11999999999999921840
}

void test2()
{
    test_double(10.12, 10.12, 2); // [equal] 10.12 10.12
    test_double(10.12, 10.1, 1); // [equal] 10.1 10.1
    test_double(10.12, 10.12, 3); // [equal] 10.120 10.120
    test_double(10.12, 10.121, 3); // [not equal] 10.120 10.121
    test_double(10.12, 10.121, 20); // [not equal] 10.11999999999999921840 10.12100000000000044054
    test_double(10.12, 10.1201, 20); // [not equal] 10.11999999999999921840 10.12010000000000076170
    test_double(10.12, 10.12001, 20); // [not equal] 10.11999999999999921840 10.12001000000000061618
    test_double(10.12, 10.120001, 20); // [not equal] 10.11999999999999921840 10.12000100000000024636
    test_double(10.12, 10.1200001, 20);  // [not equal] 10.11999999999999921840 10.12000010000000038701
    test_double(10.12, 10.12, 10); // [equal] 10.1200000000 10.1200000000
}

void test_double(double d1, double d2, long long precision)
{
    bool ret = j2::is_equal<double>(d1, d2, precision);

    if (ret)  {
        std::cout << "[equal] ";
    } else  {
        std::cout << "[not equal] ";
    }

    std::cout
        << std::fixed
        << j2::to_string<double>(d1, precision)
        << " "
        << j2::to_string<double>(d2, precision)
        << std::endl;
}
