#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>

class Span
{
private:
    unsigned int     _size;
    unsigned int     _used_size;
    std::vector<int> _numbers;

    Span();

public:
    Span(unsigned int cnt);
    Span(Span const& other);
    Span& operator=(Span const& other);
    ~Span();

    void         addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename InputIterator>
    void addNumber(InputIterator first, InputIterator last);
};

template <typename InputIterator>
void Span::addNumber(InputIterator first, InputIterator last)
{
    const int len = std::distance(first, last);
    if (_used_size + len > _size)
        throw std::runtime_error("Span is full");
    std::vector<int> temp(first, last);
    sort(temp.begin(), temp.end());
    _numbers.insert(_numbers.begin() + _used_size, temp.begin(), temp.end());
    _used_size += len;
}

#endif