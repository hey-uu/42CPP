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
    PmergeMe(PmergeMe const& other);
    PmergeMe& operator=(PmergeMe const& other);
    ~PmergeMe();

    // utils
    static std::string intToStr(int num);
    static std::string vectorToStr(std::vector<int> const& vector);
    // static std::string dequeToStr(std::deque<int> const& vector);
    static size_t      jacobisthalNumber(size_t n);

    template <typename Container>
    struct Func
    {
        typedef void (*sort)(Container& seq, size_t len);
    };

    template <typename Container>
    static void measureRunTime(
        typename Func<Container>::sort fct, Container& seq, double& time);

    // main flow
    static void parseInput(std::string const& input);
    static void vectorSort(std::vector<int>& seq, size_t len);
    static void dequeSort(std::deque<int>& seq, size_t len);
    static void printResult();
    // vector sort
    static void vectorComparePairs(std::vector<int>& seq, size_t len);
    static void vectorEraseInsertElem(
        std::vector<int>& seq, size_t level_len, size_t erase_pos,
        size_t insert_pos);
    static void vectorBinaryInsertElem(
        std::vector<int>& seq, size_t level_len, size_t sorted_len, size_t idx);
    static void vectorBinaryInsert(std::vector<int>& seq, size_t level_len);
    // deque ssort
    static void dequeComparePairs(std::deque<int>& seq, size_t len);
    static void dequeEraseInsertElem(
        std::deque<int>& seq, size_t level_len, size_t erase_pos,
        size_t insert_pos);
    static void dequeBinaryInsertElem(
        std::deque<int>& seq, size_t level_len, size_t sorted_len, size_t idx);
    static void dequeBinaryInsert(std::deque<int>& seq, size_t level_len);

public:
    static void sort(std::string const& input);
};

#endif
