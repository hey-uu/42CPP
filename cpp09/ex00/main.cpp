#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
    try {
        if (argc != 2)
            throw std::runtime_error("could not open file");
        BitcoinExchange exchange(argv[1]);
        exchange.printPrices();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
