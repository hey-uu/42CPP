#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>

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

static std::string trim(std::string input)
{
    // erase blanks
    int front_pos = input.find_first_not_of(' ');
    input.erase(0, front_pos);
    int back_pos = input.find_last_not_of(' ');
    input.erase(back_pos + 1);
    return input;
}

static double toDouble(std::string input)
{
    // handle pseudo literal(ex: .0f)
    if (input.find_last_of('f') == input.length() - 1)
        input.erase(input.length() - 1);

    // string to double
    std::istringstream ss(input);
    double             d = 0;

    ss >> d;
    return d;
}

static void printChar(char charVal, double doubleVal)
{
    std::cout << "char: ";
    if (doubleVal != doubleVal
        || doubleVal == std::numeric_limits<double>::infinity()
        || doubleVal == -std::numeric_limits<double>::infinity())
        std::cout << "impossible" << std::endl;
    else if (isprint(charVal))
        std::cout << "'" << charVal << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

static void printInt(int intVal, double doubleVal)
{
    std::cout << "int: ";
    if (doubleVal != doubleVal || doubleVal > INT_MAX || doubleVal < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << intVal << std::endl;
}

static void printFloat(float floatVal, int intVal)
{
    std::cout << "float: ";
    if (floatVal != floatVal
        || floatVal == std::numeric_limits<float>::infinity()
        || floatVal == -std::numeric_limits<float>::infinity()
        || floatVal - intVal > 0)
        std::cout << floatVal << "f" << std::endl;
    else
        std::cout << floatVal << ".0f" << std::endl;
}

static void printDouble(double doubleVal, int intVal)
{
    std::cout << "double: ";
    if (doubleVal != doubleVal
        || doubleVal == std::numeric_limits<double>::infinity()
        || doubleVal == -std::numeric_limits<double>::infinity()
        || doubleVal - intVal > 0)
        std::cout << doubleVal << std::endl;
    else
        std::cout << doubleVal << ".0" << std::endl;
}

void ScalarConverter::convert(std::string const input)
{
    char   charVal;
    int    intVal;
    float  floatVal;
    double doubleVal;

    std::string val = trim(input);
    std::cout << input << std::endl;
    if (val.length() == 1 && !isdigit(val[0])) {
        charVal = static_cast<char>(val[0]); // type은 char
        intVal = static_cast<int>(charVal);
        floatVal = static_cast<float>(charVal);
        doubleVal = static_cast<float>(charVal);
    } else {
        doubleVal = toDouble(val);
        charVal = static_cast<float>(doubleVal);
        intVal = static_cast<int>(doubleVal);
        floatVal = static_cast<float>(doubleVal);
    }

    printChar(charVal, doubleVal);
    printInt(intVal, doubleVal);
    printFloat(floatVal, intVal);
    printDouble(doubleVal, intVal);
}
