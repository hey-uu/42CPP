#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename Fct>
void iter(T* array, size_t length, Fct fct)
{
    for (size_t i = 0; i < length; i++)
        fct(array[i]);
}

template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void increaseElement(T& element)
{
    element++;
}

#endif