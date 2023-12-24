#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const input)
{
    ScalarData type(input);

    std::cout << "char: " << type.charToStr() << std::endl;
    std::cout << "int: " << type.intToStr() << std::endl;
    std::cout << "float: " << type.floatToStr() << std::endl;
    std::cout << "double: " << type.doubleToStr() << std::endl;
}