#include "PmergeMe.hpp"

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

void PmergeMe::sort(std::string const& input)
{
    _input = input;
    measureVectorSortTime(input);
    measureDequeSortTime(input);
    printResult();
}

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
