#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span() : _size(0), _used_size(0), _numbers() {}

Span::Span(unsigned int cnt) : _size(cnt), _used_size(0), _numbers() {}

Span::Span(Span const& other)
    : _size(other._size), _used_size(other._used_size), _numbers(other._numbers)
{
}

Span& Span::operator=(Span const& other)
{
    if (this == &other)
        return *this;
    _size = other._size;
    _used_size = other._used_size;
    _numbers = other._numbers;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_used_size == _size)
        throw std::runtime_error("Span is full");
    std::vector<int>::iterator it = std::upper_bound(_numbers.begin(), _numbers.end(), number);
    _numbers.insert(it, number);
    _used_size++;
}

unsigned int Span::shortestSpan() const 
{
    if (_used_size <= 1)
        throw std::runtime_error("Not enough data");
    int min = _numbers[1] - _numbers[0];
    for (unsigned int i = 2; i < _used_size; i++)
    {
        int diff = _numbers[i] - _numbers[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan() const 
{
    if (_used_size <= 1)
        throw std::runtime_error("Not enough data");
    return _numbers[_used_size - 1] - _numbers[0];
}
