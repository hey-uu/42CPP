#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T*     _arr;
    size_t _size;

public:
    Array();
    Array(size_t n);
    Array(Array<T> const& other);
    Array<T>& operator=(Array<T> const& other);
    ~Array();
    T&       operator[](size_t idx);
    const T& operator[](size_t idx) const;
    size_t   size() const;
};

#include "Array.tpp"

#endif