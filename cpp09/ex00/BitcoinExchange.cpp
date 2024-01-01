#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

const std::string prices_file = "./cpp_09/data.csv";

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const& filename)
{
    loadRates();
    loadAmounts(filename);
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

void BitcoinExchange::loadRates()
{
    std::ifstream file(prices_file);
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        date;
        std::string        separator;
        double             price;

        if (!(iss >> date >> separator >> price))
            continue;
        _rates[date] = price;
    }
}

bool BitcoinExchange::isValidDate(
    std::string const& date, int splitted_data[3]) const
{
    std::istringstream iss(date);

    for (int i = 0; i < 3; i++) {
        std::string buffer;
        if (!std::getline(iss, buffer, '-'))
            return false;
        std::istringstream iss2(buffer);
        if (!(iss2 >> splitted_data[i]))
            return false;
    }
}

void BitcoinExchange::loadAmounts(std::string const& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        BitcoinData        data;
        std::string        separator;

        data.line = line;
        if (!(iss >> data.date >> separator >> data.amount))
            data.status = BAD_INPUT;
        if (!isValidDate(data.date, data.splitted_date))
            data.status = BAD_INPUT;
        if (separator != "|")
            data.status = BAD_INPUT;
        if (data.amount < 0)
            data.status = NEGATIVE_PRICE;
        if (data.amount > 1000)
            data.status = TOO_LARGE_PRICE;
        _amounts.push_back(data);
    }
}

void BitcoinExchange::printPrices() const
{

    for (auto const& data : _amounts) {
        if (data.status != VALID) {
            std::cout << data.line << " " << data.status << '\n';
            continue;
        }
        auto it = _rates.find(data.date);
        if (it == _rates.end()) {
            std::cout << data.line << " "
                      << "INVALID DATE" << '\n';
            continue;
        }
        std::cout << data.line << " " << data.amount
                  << " BTC = " << data.amount * it->second << " USD" << '\n';
    }
}
