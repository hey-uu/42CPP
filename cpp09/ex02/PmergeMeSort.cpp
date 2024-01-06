#include "PmergeMe.hpp"

size_t PmergeMe::jacobisthalNumber(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 2;
    return jacobisthalNumber(n - 1) + 2 * jacobisthalNumber(n - 2);
}

void PmergeMe::vectorComparePairs(std::vector<int>& seq, size_t len)
{
    size_t total_half = seq.size() / 2;
    size_t half = len / 2;

    for (size_t i = 0; i < half; i++) {
        if (seq[i] < seq[i + half]) {
            std::swap(seq[i], seq[i + half]);
            for (size_t intvl = total_half; intvl > half; intvl /= 2)
                std::swap(seq[i + intvl], seq[i + half + intvl]);
        }
    }
}

void PmergeMe::vectorEraseInsertElem(
    std::vector<int>& seq, size_t level_len, size_t erase_pos,
    size_t insert_pos)
{
    int    val = seq[erase_pos];
    size_t half = level_len / 2;
    size_t total_half = seq.size() / 2;

    seq.erase(seq.begin() + erase_pos);
    seq.insert(seq.begin() + insert_pos, val);
    for (size_t intvl = total_half; intvl > half; intvl /= 2) {
        val = seq[erase_pos + intvl];
        seq.erase(seq.begin() + erase_pos + intvl);
        seq.insert(seq.begin() + insert_pos + intvl, val);
    }
}

void PmergeMe::vectorBinaryInsertElem(
    std::vector<int>& seq, size_t level_len, size_t sorted_len, size_t idx)
{
    const int val = seq[idx];
    size_t    start = 0;
    size_t    end = sorted_len - 1;
    size_t    mid = (start + end) / 2;

    while (start <= end) {
        if (seq[mid] < val)
            start = mid + 1;
        else if (seq[mid] > val && mid > 0)
            end = mid - 1;
        else
            break;
        mid = (start + end) / 2;
    }
    if (seq[mid] < val)
        mid++;
    vectorEraseInsertElem(seq, level_len, idx, mid);
}

void PmergeMe::vectorBinaryInsert(std::vector<int>& seq, size_t level_len)
{
    size_t start = level_len / 2;
    size_t group_n = 1;
    size_t group_len = 0;

    vectorEraseInsertElem(seq, level_len, start, 0);
    start++;
    while (start < level_len) {
        group_len = jacobisthalNumber(group_n++);
        if (start + group_len > level_len)
            group_len = level_len - start;
        for (size_t i = 0; i < group_len; i++)
            vectorBinaryInsertElem(
                seq, level_len, start + i, start + group_len - 1);
        start += group_len;
    }
}

void PmergeMe::dequeComparePairs(std::deque<int>& seq, size_t len)
{
    size_t total_half = seq.size() / 2;
    size_t half = len / 2;

    for (size_t i = 0; i < half; i++) {
        if (seq[i] < seq[i + half]) {
            std::swap(seq[i], seq[i + half]);
            for (size_t intvl = total_half; intvl > half; intvl /= 2)
                std::swap(seq[i + intvl], seq[i + half + intvl]);
        }
    }
}

void PmergeMe::dequeEraseInsertElem(
    std::deque<int>& seq, size_t level_len, size_t erase_pos, size_t insert_pos)
{
    int    val = seq[erase_pos];
    size_t half = level_len / 2;
    size_t total_half = seq.size() / 2;

    seq.erase(seq.begin() + erase_pos);
    seq.insert(seq.begin() + insert_pos, val);
    for (size_t intvl = total_half; intvl > half; intvl /= 2) {
        val = seq[erase_pos + intvl];
        seq.erase(seq.begin() + erase_pos + intvl);
        seq.insert(seq.begin() + insert_pos + intvl, val);
    }
}

void PmergeMe::dequeBinaryInsertElem(
    std::deque<int>& seq, size_t level_len, size_t sorted_len, size_t idx)
{
    const int val = seq[idx];
    size_t    start = 0;
    size_t    end = sorted_len - 1;
    size_t    mid = (start + end) / 2;

    while (start <= end) {
        if (seq[mid] < val)
            start = mid + 1;
        else if (seq[mid] > val && mid > 0)
            end = mid - 1;
        else
            break;
        mid = (start + end) / 2;
    }
    if (seq[mid] < val)
        mid++;
    dequeEraseInsertElem(seq, level_len, idx, mid);
}

void PmergeMe::dequeBinaryInsert(std::deque<int>& seq, size_t level_len)
{
    size_t start = level_len / 2;
    size_t group_n = 1;
    size_t group_len = 0;

    dequeEraseInsertElem(seq, level_len, start, 0);
    start++;
    while (start < level_len) {
        group_len = jacobisthalNumber(group_n++);
        if (start + group_len > level_len)
            group_len = level_len - start;
        for (size_t i = 0; i < group_len; i++)
            dequeBinaryInsertElem(
                seq, level_len, start + i, start + group_len - 1);
        start += group_len;
    }
}

void PmergeMe::vectorSort(std::vector<int>& seq, size_t len)
{
    if (len <= 1)
        return;
    vectorComparePairs(seq, len);
    vectorSort(seq, len / 2);
    vectorBinaryInsert(seq, len);
}

void PmergeMe::dequeSort(std::deque<int>& seq, size_t len)
{
    if (len <= 1)
        return;
    dequeComparePairs(seq, len);
    dequeSort(seq, len / 2);
    dequeBinaryInsert(seq, len);
}
