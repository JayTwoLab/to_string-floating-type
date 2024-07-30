#ifndef TO_STRING_H
#define TO_STRING_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <type_traits>
#include <limits>

// namespace {{

template <typename T>
std::string to_string(typename std::enable_if< std::is_floating_point<T>::value, T >::type value)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision( std::numeric_limits<T>::max_digits10 ) << value;
    std::string ret = oss.str();
    return ret;
}

template <typename T>
std::string to_string(typename std::enable_if< std::is_floating_point<T>::value, T >::type value, long long precision)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    std::string ret = oss.str();
    return ret;
}

template <typename T>
bool is_equal(T value1, T value2, long long precision)
{
    std::string str1 = to_string<T>(value1, precision);
    std::string str2 = to_string<T>(value2, precision);

    if ( str1 == str2 )
    {
        std::cout << " equal value " << str1 << " " << str2 << std::endl;
        return true;
    }
    std::cout << " not equal value " << str1 << " " << str2 << std::endl;
    return false;
}

template <typename T>
bool is_equal(T value1, T value2)
{
    std::string str1 = to_string<T>(value1);
    std::string str2 = to_string<T>(value2);

    if ( str1 == str2 )
    {
        std::cout << "[string][is_same] same value " << str1 << " " << str2 << std::endl;
        return true;
    }
    std::cout << "[string][is_same] not same value " << str1 << " " << str2 << std::endl;
    return false;
}

// namespace }}

#endif // TO_STRING_H
