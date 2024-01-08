#include "PmergeMe.hpp"
#include <cassert>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string      PmergeMe::_input;
std::vector<int> PmergeMe::_vector;
std::deque<int>  PmergeMe::_deque;
double           PmergeMe::_vector_sort_time = 0;
double           PmergeMe::_deque_sort_time = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& other)
{
    (void)other;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

std::string PmergeMe::intToStr(int num)
{
    std::ostringstream ss;

    ss << num;
    return ss.str();
}

std::string PmergeMe::vectorToStr(std::vector<int> const& vector)
{
    std::string str;
    int         prev = vector[0];

    for (std::vector<int>::const_iterator it = vector.begin();
         it != vector.end(); it++) {
        assert(it == vector.begin() || prev <= *it);
        str += intToStr(*it);
        str += " ";
    }
    return str;
}

void PmergeMe::parseInput(std::string const& input)
{
    std::istringstream iss(input);
    int                num;

    _input = "";
    _vector.clear();
    _deque.clear();
    while (iss >> num) {
        _input += intToStr(num) + " ";
        if (num < 0)
            throw std::runtime_error("Negative Number");
        _vector.push_back(num);
        _deque.push_back(num);
    }
    if (!(iss.eof()))
        throw std::runtime_error("Invalid Format");
}

template <typename Container>
void PmergeMe::measureRunTime(
    typename Func<Container>::sort fct, Container& seq, double& time)
{
    clock_t start = clock();
    fct(seq, seq.size());
    clock_t end = clock();
    time = (end - start) / (static_cast<double>(CLOCKS_PER_SEC) / 1000000);
}

// std::string PmergeMe::dequeToStr(std::deque<int> const& deque)
// {
//     std::string str;

//     for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end();
//          it++) {
//         str += PmergeMe::intToStr(*it);
//         str += " ";
//     }
//     return str;
// }

void PmergeMe::printResult()
{
    std::cout << "Before: " << _input << std::endl;
    std::cout << "After: " << vectorToStr(_vector) << std::endl;
    // std::cout << "After: " << dequeToStr(_deque) << std::endl;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector<int> : " << std::setprecision(4)
              << _vector_sort_time << " µs" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque<int> : " << std::setprecision(4)
              << _deque_sort_time << " µs" << std::endl;
}

void PmergeMe::sort(std::string const& input)
{
    parseInput(input);
    measureRunTime(&vectorSort, _vector, _vector_sort_time);
    measureRunTime(&dequeSort, _deque, _deque_sort_time);
    printResult();
}
