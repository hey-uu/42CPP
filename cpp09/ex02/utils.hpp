#ifndef UTILS_HPP
#define UTILS_HPP

#include <deque>
#include <string>
#include <vector>

std::string intToStr(int num);
std::string vectorToStr(std::vector<int> const& vector);
std::string dequeToStr(std::deque<int> const& deque);
size_t      jacobsthalNumber(size_t n);

#endif