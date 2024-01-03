#include "PmergeMe.hpp"

static std::string parseInput(int argc, char* argv[])
{
    std::string input;

    for (int i = 0; i < argc; i++) {
        input += argv[i];
        input += " ";
    }
    return input;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Need input" << std::endl;
        return 1;
    }
    std::string input = parseInput(argc - 1, argv + 1);
    try {
        PmergeMe::sort(input);
    } catch (std::exception const& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
