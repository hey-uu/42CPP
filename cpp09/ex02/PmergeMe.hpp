#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include "utils.hpp"
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
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
    PmergeMe(PmergeMe const& other);
    PmergeMe& operator=(PmergeMe const& other);
    ~PmergeMe();

    static void printResult();
    // vector sort
    static void measureVectorSortTime(std::string const& input);
    static void pushVectorInput(std::string const& input);
    static void vectorSort(std::vector<int>& seq, size_t len);
    static void vectorSwap(std::vector<int>& seq, size_t idx1, size_t idx2);
    static void vectorComparePairs(std::vector<int>& seq, size_t len);
    static void vectorMoveElem(
        std::vector<int>& seq, size_t level_len, size_t erase_pos,
        size_t insert_pos);
    static void vectorBinaryInsertElem(
        std::vector<int>& seq, size_t level_len, size_t sorted_len, size_t idx);
    static void vectorBinaryInsert(std::vector<int>& seq, size_t level_len);
    // deque sort
    static void measureDequeSortTime(std::string const& input);
    static void pushDequeInput(std::string const& input);
    static void dequeSort(std::deque<int>& seq, size_t len);
    static void dequeSwap(std::deque<int>& seq, size_t idx1, size_t idx2);
    static void dequeComparePairs(std::deque<int>& seq, size_t len);
    static void dequeMoveElem(
        std::deque<int>& seq, size_t level_len, size_t erase_pos,
        size_t insert_pos);
    static void dequeBinaryInsertElem(
        std::deque<int>& seq, size_t level_len, size_t sorted_len, size_t idx);
    static void dequeBinaryInsert(std::deque<int>& seq, size_t level_len);

public:
    static void sort(std::string const& input);
};

#endif
