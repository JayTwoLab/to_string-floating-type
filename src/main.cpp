#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <type_traits>

#include "to_string.h"

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    float  f = 10.12f;
    double d = 10.12;

    std::cout << std::fixed << f << " "<< d << std::endl;
    // 10.120000 10.120000

    std::cout << std::fixed << to_string<float>(f) << " " << to_string<double>(d) << std::endl;
    // 10.119999886 10.11999999999999922

    std::cout << std::fixed << to_string<float>(f, 2) << " " << to_string<double>(d, 2) << std::endl;
    // 10.12 10.12

    std::cout << std::fixed << to_string<float>(f,10) << " " << to_string<double>(d,20) << std::endl;
    // 10.1199998856 10.11999999999999921840

    is_equal<double>(10.12, 10.12,  2); // equal 
    is_equal<double>(10.12, 10.1,   1); // equal
    is_equal<double>(10.12, 10.12,  3); // equal

    is_equal<double>(10.12, 10.121,      3); // not equal
    is_equal<double>(10.12, 10.121,     20); // not equal
    is_equal<double>(10.12, 10.1201,    20); // not equal
    is_equal<double>(10.12, 10.12001,   20); // not equal
    is_equal<double>(10.12, 10.120001,  20); // not equal
    is_equal<double>(10.12, 10.1200001, 20);  // not equal

    is_equal<double>(10.12, 10.12,  10); // equal 

}
