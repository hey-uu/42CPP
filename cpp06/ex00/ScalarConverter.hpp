#ifndef SCARLAR_CONVERTER_HPP
#define SCARLAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const& other);
    ScalarConverter& operator=(ScalarConverter const& other);
    ~ScalarConverter();

    void   toChar(std::string const& input);
    void   toInt(std::string const& input);
    void   toFloat(std::string const& input);
    // void   _toDouble(std::string const& input);

public:
    static void convert(std::string const input);
};

#endif
