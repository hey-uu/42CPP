#include "PmergeMe.hpp"

static std::string concatenateInput(int argc, char* argv[])
{
    std::string res;
    for (int i = 0; i < argc; i++) {
        res += argv[i];
        res += " ";
    }
    return res;
}

static std::string checkInput(std::string const& input)
{
    std::istringstream iss(input);
    std::string        res = "";
    int                num;
    while (iss >> num) {
        res += intToStr(num) + " ";
        if (num < 0)
            throw std::runtime_error("Negative Number");
    }
    if (!(iss.eof()))
        throw std::runtime_error("Invalid Format");

    return res;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Need input" << std::endl;
        return 1;
    }
    std::string input = concatenateInput(argc - 1, argv + 1);
    try {
        std::string checkedInput = checkInput(input);
        PmergeMe::sort(checkedInput);
    } catch (std::exception const& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
