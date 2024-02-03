#include "PmergeMe.hpp"

void PmergeMe::measureDequeSortTime(std::string const& input)
{
    clock_t start = clock();
    pushDequeInput(input);
    dequeSort(_deque, _deque.size());
    clock_t end = clock();
    _deque_sort_time
        = (end - start) / (static_cast<double>(CLOCKS_PER_SEC) / 1000000);
}

void PmergeMe::pushDequeInput(std::string const& input)
{
    std::istringstream iss(input);
    int                num;

    _deque.clear();
    while (iss >> num) {
        _deque.push_back(num);
    }
}

void PmergeMe::dequeSort(std::deque<int>& seq, size_t len)
{
    if (len <= 1)
        return;
    dequeComparePairs(seq, len);
    dequeSort(seq, len / 2);
    dequeBinaryInsert(seq, len);
}

void PmergeMe::dequeComparePairs(std::deque<int>& seq, size_t len)
{
    size_t half = len / 2;

    for (size_t i = 0; i < half; i++) {
        if (seq[i] < seq[i + half])
            dequeSwap(seq, i, i + half);
    }
}

void PmergeMe::dequeSwap(std::deque<int>& seq, size_t idx1, size_t idx2)
{
    size_t total_half = seq.size() / 2;

    std::swap(seq[idx1], seq[idx2]);
    if (idx2 >= total_half)
        return;
    for (size_t start = total_half; start > idx2; start /= 2)
        dequeSwap(seq, start + idx1, start + idx2);
}

void PmergeMe::dequeBinaryInsert(std::deque<int>& seq, size_t level_len)
{
    size_t start = level_len / 2;
    size_t group_n = 1;
    size_t group_len = 0;
    size_t subseq_len = 2;

    dequeMoveElem(seq, level_len, start, 0);
    start++;
    while (start < level_len) {
        subseq_len *= 2;
        group_len = 2 * jacobsthalNumber(group_n++);
        if (start + group_len > level_len)
            group_len = level_len - start;
        for (size_t i = 0; i < group_len; i++) {
            dequeBinaryInsertElem(
                seq, level_len, std::min(start + i, subseq_len - 1),
                start + group_len - 1);
        }
        start += group_len;
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
    dequeMoveElem(seq, level_len, idx, mid);
}

void PmergeMe::dequeMoveElem(
    std::deque<int>& seq, size_t level_len, size_t erase_pos, size_t insert_pos)
{
    int    val = seq[erase_pos];
    size_t total_half = seq.size() / 2;

    seq.erase(seq.begin() + erase_pos);
    seq.insert(seq.begin() + insert_pos, val);
    for (size_t start = total_half; start > erase_pos; start /= 2) {
        val = seq[start + erase_pos];
        dequeMoveElem(seq, level_len, start + erase_pos, start + insert_pos);
    }
}
