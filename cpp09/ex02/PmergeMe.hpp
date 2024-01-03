#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
private:
    static std::string      _input;
    static std::vector<int> _vector;
    static std::deque<int>  _deque;
    static double           _vector_sort_time;
    static double           _deque_sort_time;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // utils
    static std::string intToStr(int num);
    static std::string vectorToStr(std::vector<int> const& vector);
    static void        parseInput(std::string const& input);
    static void        vectorSort();
    static void        dequeSort();
    static void        printResult();

public:
    static void sort(std::string const& input);
};

#endif
