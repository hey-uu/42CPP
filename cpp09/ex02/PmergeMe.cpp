#include "PmergeMe.hpp"
#include <sstream>

std::string      PmergeMe::_input;
std::vector<int> PmergeMe::_vector;
std::deque<int>  PmergeMe::_deque;
double           PmergeMe::_vector_sort_time = 0;
double           PmergeMe::_deque_sort_time = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& other) {}

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

    for (std::vector<int>::const_iterator it = vector.begin();
         it != vector.end(); it++) {
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
    while (!iss.eof()) {
        if (!(iss >> num))
            throw std::runtime_error("Invalid input");
        _input += intToStr(num) + " ";
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

void PmergeMe::vectorSort() 
{

}

void PmergeMe::dequeSort()
{

}

void PmergeMe::printResult()
{
    std::cout << "Before: " << _input << std::endl;
    std::cout << "After: " << vectorToStr(_vector) << std::endl;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector<int> : " << _vector_sort_time
              << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque<int> : " << _deque_sort_time
              << " us" << std::endl;
}

void PmergeMe::sort(std::string const& input)
{
    parseInput(input);
    vectorSort();
    dequeSort();
    printResult();
}
