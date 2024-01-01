#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <list>
#include <map>
#include <string>

class BitcoinExchange
{

private:
    struct BitcoinData
    {
        std::string line;
        std::string date;
        int         splitted_date[3];
        float       amount;
        char        status;
    };

    enum Status
    {
        VALID,
        BAD_INPUT,
        NEGATIVE_PRICE,
        TOO_LARGE_PRICE
    };

    std::map<std::string, double> _rates;
    std::list<BitcoinData>        _amounts;

    BitcoinExchange();
    void loadRates();
    void loadAmounts(std::string const& filename);
    bool isValidDate(std::string const& date, int splitted_date[3]) const;

public:
    static const std::string price_file;

    BitcoinExchange(std::string const& filename);
    BitcoinExchange(BitcoinExchange const& other);
    BitcoinExchange& operator=(BitcoinExchange const& other);
    ~BitcoinExchange();

    void printPrices() const;
};

#endif