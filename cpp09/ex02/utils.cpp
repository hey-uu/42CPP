#include <cassert>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

std::string intToStr(int num)
{
    std::ostringstream ss;

    ss << num;
    return ss.str();
}

std::string vectorToStr(std::vector<int> const& vector)
{
    std::string                      str;
    int                              prev = vector[0];
    std::vector<int>::const_iterator it;

    for (it = vector.begin(); it != vector.end(); it++) {
        assert(prev <= *it); prev = *it;
        str += intToStr(*it);
        str += " ";
    }
    return str;
}

std::string dequeToStr(std::deque<int> const& deque)
{
    std::string                     str;
    int                             prev = deque[0];
    std::deque<int>::const_iterator it;

    for (it = deque.begin(); it != deque.end(); it++) {
        assert(prev <= *it); prev = *it;
        str += intToStr(*it);
        str += " ";
    }
    return str;
}

size_t jacobsthalNumber(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}
