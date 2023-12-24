#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const& other);
    ScalarConverter& operator=(ScalarConverter const& other);
    ~ScalarConverter();
    class ScalarData;

public:
    static void convert(std::string const input);
};

#include "ScalarData.hpp"

#endif