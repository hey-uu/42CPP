#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange*  BitcoinExchange::database = NULL;
const std::string prices_file = "./data/data.csv";

BitcoinExchange::BitcoinExchange()
{
    loadRates();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
    : _rates(other._rates), _amounts(other._amounts)
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other)
{
    if (this == &other)
        return *this;
    _rates = other._rates;
    _amounts = other._amounts;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::splitDateStr(std::string const& date_str, int date_arr[3])
{
    std::istringstream iss(date_str);

    for (int i = 0; i < 3; i++) {
        std::string buffer;
        if (!std::getline(iss, buffer, '-'))
            return false;
        if (buffer.length() < 2)
            return false;
        std::istringstream iss2(buffer);
        if (!(iss2 >> date_arr[i]))
            return false;
    }
    if (!iss.eof())
        return false;
    return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

bool BitcoinExchange::isValidDate(int date[3])
{
    time_t           timer = time(NULL);
    struct tm*       t = localtime(&timer);
    static const int days_in_month[12]
        = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date[0] < 2009 || date[0] > t->tm_year + 1900)
        return false;
    if (date[0] == t->tm_year + 100) {
        if (date[1] > t->tm_mon + 1)
            return false;
        if (date[1] == t->tm_mon + 1 && date[2] > t->tm_mday)
            return false;
    }
    if (date[1] < 0 || date[1] > 12)
        return false;
    if (!isLeapYear(date[0]) || date[1] != 2) {
        if (date[2] > days_in_month[date[1] - 1])
            return false;
    } else if (date[2] > 29)
        return false;
    return true;
}

bool BitcoinExchange::isValidPrice(BitcoinData& data)
{
    std::map<std::string, double>::const_iterator it
        = _rates.lower_bound(data.date_str);
    if (it == _rates.begin())
        return false;
    if (it->first > data.date_str)
        it--;
    if (it == _rates.begin() && it->first > data.date_str)
        return false;
    data.price = data.amount * it->second;
    return true;
}

void BitcoinExchange::loadRates()
{
    std::ifstream file(prices_file);
    if (!file.is_open())
        throw std::runtime_error("could not open file");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        date_str;
        int                date_arr[3];
        double             rate = 0;

        if (!std::getline(iss, date_str, ',') || !(iss >> rate) || !iss.eof())
            continue;
        if (!splitDateStr(date_str, date_arr))
            continue;
        if (!isValidDate(date_arr))
            continue;
        if (rate < 0)
            continue;
        _rates[date_str] = rate;
    }
}

void BitcoinExchange::loadAmounts(std::string const& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        BitcoinData        data;
        std::string        separator;

        data.line = line;
        data.status = VALID;
        iss >> data.date_str;
        if (!data.date_str.length())
            continue;
        if (!(iss >> separator >> data.amount)
            || !splitDateStr(data.date_str, data.date_arr)
            || !isValidDate(data.date_arr) || separator != "|"
            || !isValidPrice(data) || !(iss.eof()))
            data.status = BAD_INPUT;
        else if (data.amount < 0)
            data.status = NEGATIVE_PRICE;
        else if (data.amount > 1000)
            data.status = TOO_LARGE_PRICE;
        _amounts.push_back(data);
    }
}

void BitcoinExchange::printPrices() const
{
    for (std::list<BitcoinData>::const_iterator it = _amounts.begin();
         it != _amounts.end(); it++) {
        switch (it->status) {
            case BAD_INPUT:
                std::cout << "Error: bad input => " << it->line << std::endl;
                break;
            case NEGATIVE_PRICE:
                std::cout << "Error: not a positive number." << std::endl;
                break;
            case TOO_LARGE_PRICE:
                std::cout << "Error: too large a number." << std::endl;
                break;
            case VALID:
                std::cout << it->date_str << " => " << it->amount << " = "
                          << it->price << std::endl;
        }
    }
}

BitcoinExchange& BitcoinExchange::getInstance()
{
    if (!database)
        database = new BitcoinExchange();
    return *database;
}
