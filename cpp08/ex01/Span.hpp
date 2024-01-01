#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <vector>

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
    for (InputIterator num_it = first; num_it != last; num_it++) {
        std::vector<int>::iterator pos_it
            = std::upper_bound(_numbers.begin(), _numbers.end(), *num_it);
        _numbers.insert(pos_it, *num_it);
    }
    _used_size += len;
}

#endif