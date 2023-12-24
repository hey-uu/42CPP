#ifndef SCALAR_DATA_HPP
#define SCALAR_DATA_HPP

#include "ScalarConverter.hpp"

class ScalarConverter::ScalarData
{
private:
    int    _type;
    char   _c_data;
    int    _i_data;
    float  _f_data;
    double _d_data;

    ScalarData();


    char   strToChar(std::string const& input);
    int    strToInt(std::string const& input);
    float  strToFloat(std::string input);
    float  strToFloatPseudoLiteral(std::string const& input);
    double strToDouble(std::string input);
    double strToDoublePseudoLiteral(std::string const& input);

    enum e_type
    {
        CHAR,
        INT,
        FLOAT,
        FLOAT_PSEUDO,
        DOUBLE,
        DOUBLE_PSEUDO
    };

public:
    ScalarData(std::string const& input);
    ScalarData(ScalarData const& other);
    ScalarData& operator=(ScalarData const& other);
    ~ScalarData();

    std::string charToStr();
    std::string intToStr();
    std::string floatToStr();
    std::string doubleToStr();
};

#endif