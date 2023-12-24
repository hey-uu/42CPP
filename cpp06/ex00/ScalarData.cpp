#include "ScalarData.hpp"
#include <cmath>
#include <limits>
#include <sstream>
#include <string>

ScalarConverter::ScalarData::ScalarData() {}

ScalarConverter::ScalarData::ScalarData(ScalarData const& other)
    : _type(other._type), _c_data(other._c_data), _i_data(other._i_data),
      _f_data(other._f_data), _d_data(other._d_data)
{
}

ScalarConverter::ScalarData&
ScalarConverter::ScalarData::operator=(ScalarData const& other)
{
    if (this == &other)
        return *this;
    _type = other._type;
    _c_data = other._c_data;
    _i_data = other._i_data;
    _f_data = other._f_data;
    _d_data = other._d_data;
    return *this;
}

ScalarConverter::ScalarData::~ScalarData() {}

static std::string _trim(std::string input)
{
    // erase blanks
    int front_pos = input.find_first_not_of(' ');
    input.erase(0, front_pos);
    int back_pos = input.find_last_not_of(' ');
    input.erase(back_pos + 1);
    return input;
}

ScalarConverter::ScalarData::ScalarData(std::string const& input)
{
    std::string str = _trim(input);

    if (input.length() == 1 && !isdigit(input[0])) {
        _type = CHAR;
        _c_data = strToChar(input);
        return;
    }
    if (input == "inff" || input == "-inff" || input == "nanf") {
        _type = FLOAT_PSEUDO;
        _f_data = strToFloatPseudoLiteral(input);
        return;
    }
    if (input == "inf" || input == "-inf" || input == "nan") {
        _type = DOUBLE_PSEUDO;
        _d_data = strToDoublePseudoLiteral(input);
        return;
    }
    if (input.find(".") == std::string::npos) {
        _type = INT;
        _i_data = strToInt(input);
        return;
    }
    if (input.rfind("f") == input.length() - 1) {
        _type = FLOAT;
        _f_data = strToFloat(input);
        return;
    }
    _type = DOUBLE;
    _d_data = strToDouble(input);
}

char ScalarConverter::ScalarData::strToChar(std::string const& input)
{
    return input[0];
}

float ScalarConverter::ScalarData::strToFloatPseudoLiteral(
    std::string const& input)
{
    if (input == "inff")
        return std::numeric_limits<float>::infinity();
    else if (input == "-inff")
        return -std::numeric_limits<float>::infinity();
    else
        return std::numeric_limits<float>::quiet_NaN();
}

double
ScalarConverter::ScalarData::strToDoublePseudoLiteral(std::string const& input)
{
    if (input == "inf")
        return std::numeric_limits<double>::infinity();
    else if (input == "-inf")
        return -std::numeric_limits<double>::infinity();
    else
        return std::numeric_limits<double>::quiet_NaN();
}

int ScalarConverter::ScalarData::strToInt(std::string const& input)
{
    std::istringstream ss(input);
    int                i_data;

    ss >> i_data;
    if (!ss.eof())
        throw std::invalid_argument("invalid argument: int");
    if (ss.fail())
        throw std::out_of_range("out of range: int");
    return i_data;
}

float ScalarConverter::ScalarData::strToFloat(std::string input)
{
    input.erase(input.length() - 1);
    std::istringstream ss(input);
    float              f_data;

    ss >> f_data;
    if (!ss.eof())
        throw std::invalid_argument("invalid argument: float");
    if (ss.fail())
        throw std::out_of_range("out of range: float");
    return f_data;
}

double ScalarConverter::ScalarData::strToDouble(std::string input)
{
    std::istringstream ss(input);
    double             d_data;

    ss >> d_data;
    if (!ss.eof())
        throw std::invalid_argument("invalid argument: double");
    if (ss.fail())
        throw std::out_of_range("out of range: double");
    return d_data;
}

std::string ScalarConverter::ScalarData::charToStr()
{
    switch (_type) {
        case CHAR:
            break;
        case INT:
            _c_data = static_cast<char>(_i_data);
            break;
        case FLOAT:
            _c_data = static_cast<char>(_f_data);
            break;
        case DOUBLE:
            _c_data = static_cast<char>(_d_data);
            break;
        default:
            return "impossible";
    }
    if (std::isprint(_c_data))
        return "'" + std::string(1, _c_data) + "'";
    return "Non displayable";
}

std::string ScalarConverter::ScalarData::intToStr()
{
    switch (_type) {
        case CHAR:
            _i_data = static_cast<int>(_c_data);
            break;
        case INT:
            break;
        case FLOAT:
            _i_data = static_cast<int>(_f_data);
            break;
        case DOUBLE:
            _i_data = static_cast<int>(_d_data);
            break;
        default:
            return "impossible";
    }
    std::stringstream ss;
    ss << _i_data;
    return ss.str();
}

std::string ScalarConverter::ScalarData::floatToStr()
{
    switch (_type) {
        case CHAR:
            _f_data = static_cast<float>(_c_data);
            break;
        case INT:
            _f_data = static_cast<float>(_i_data);
            break;
        case FLOAT:
        case FLOAT_PSEUDO:
            break;
        case DOUBLE:
        case DOUBLE_PSEUDO:
            _f_data = static_cast<float>(_d_data);
            break;
    }
    std::stringstream ss;
    if (_type != FLOAT_PSEUDO && _type != DOUBLE_PSEUDO
        && std::floor(_f_data) == _f_data)
        ss << _f_data << ".0f";
    else
        ss << _f_data << 'f';

    return ss.str();
}

std::string ScalarConverter::ScalarData::doubleToStr()
{
    switch (_type) {
        case CHAR:
            _d_data = static_cast<double>(_c_data);
            break;
        case INT:
            _d_data = static_cast<double>(_i_data);
            break;
        case FLOAT:
        case FLOAT_PSEUDO:
            _d_data = static_cast<double>(_f_data);
            break;
        case DOUBLE:
        case DOUBLE_PSEUDO:
            break;
        default:
            return "impossible";
    }
    std::stringstream ss;
    if (_type != FLOAT_PSEUDO && _type != DOUBLE_PSEUDO
        && std::floor(_d_data) == _d_data)
        ss << _d_data << ".0";
    else
        ss << _d_data;
    return ss.str();
}
