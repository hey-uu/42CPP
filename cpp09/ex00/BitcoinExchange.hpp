#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <list>
#include <map>
#include <string>

class BitcoinExchange
{
private:
    static BitcoinExchange*  database;
    static const std::string price_file;

    struct BitcoinData
    {
        std::string line;
        std::string date_str;
        int         date_arr[3];
        float       amount;
        double      price;
        int         status;
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
    BitcoinExchange(BitcoinExchange const& other);
    BitcoinExchange& operator=(BitcoinExchange const& other);
    ~BitcoinExchange();

    static bool splitDateStr(std::string const& date_str, int date_arr[3]);
    static bool isLeapYear(int year);
    static bool isValidDate(int splitted_date[3]);
    bool        isValidPrice(BitcoinData& data);
    void        loadRates();

public:
    static BitcoinExchange& getInstance();
    void                    loadAmounts(std::string const& filename);
    void                    printPrices() const;
};

#endif