#include "Array.hpp"
#include <iostream>

void _test_show(Array<int>& arr)
{
    std::cout << "---- show " << std::endl;
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
}

void _test_size(Array<int>& arr)
{
    std::cout << "---- size()" << std::endl;
    std::cout << "size=" << arr.size() << std::endl;
}

void _test_get_element(const Array<int>& arr, unsigned int idx)
{
    try {
        std::cout << "---- oeprator[] : get" << std::endl;
        std::cout << "arr[" << idx << "]: " << arr[idx] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void _test_change_element(Array<int>& arr, unsigned int idx, int data)
{
    try {
        std::cout << "---- oeprator[] : change" << std::endl;
        std::cout << "before: arr[" << idx << "]=" << arr[idx] << std::endl;
        arr[idx] = data;
        std::cout << "after: arr[" << idx << "]=" << arr[idx] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void _test_copy_constructor(Array<int>& arr)
{
    std::cout << "---- copy constructor" << std::endl;
    Array<int> new_arr(arr);
    std::cout << "copied array" << std::endl;
    _test_show(new_arr);
    std::cout << "changed values of copied array" << std::endl;
    for (size_t i = 0; i < new_arr.size(); i++)
        new_arr[i]++;
    std::cout << "copied array" << std::endl;
    _test_show(new_arr);
    std::cout << "original array" << std::endl;
    _test_show(arr);
}

void test_0_size_int_arr()
{
    std::cout << "==== test: 0 size int array ====" << std::endl;
    Array<int> arr;
    _test_size(arr);
    _test_show(arr);
    _test_get_element(arr, 0);
    _test_change_element(arr, 0, 1);
    _test_copy_constructor(arr);
    std::cout << std::endl;
}

void test_3_size_int_arr()
{
    std::cout << "==== test: 3 size int array ====" << std::endl;
    Array<int> arr(3);
    _test_size(arr);
    _test_show(arr);
    _test_get_element(arr, 1);
    _test_get_element(arr, 3);
    _test_change_element(arr, 0, 1);
    _test_change_element(arr, 1, 10);
    _test_change_element(arr, 2, 100);
    _test_copy_constructor(arr);
    std::cout << std::endl;
}

int main()
{
    test_0_size_int_arr();
    test_3_size_int_arr();
}