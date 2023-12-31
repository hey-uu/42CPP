#include "iter.hpp"

void test_int_array()
{
    int arr[3] = {0, 1, 2};

    std::cout << "====== test 1 : int array ======= " << std::endl;
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<int>);
    std::cout << "> increase value " << std::endl;
    iter(arr, 3, increaseElement<int>);
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<int>);
}

void test_const_int_array()
{
    const int arr[3] = {0, 1, 2};

    std::cout << "====== test 2 : const int array ======= " << std::endl;
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<int>);
    // compile error
    // std::cout << "> increase value " << std::endl;
    // iter(arr, 3, increaseElement<int>);
}

void test_char_array()
{
    int arr[3] = {'a', 'b', 'c'};

    std::cout << "====== test 3 : char array ======= " << std::endl;
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<int>);
    std::cout << "> increase value " << std::endl;
    iter(arr, 3, increaseElement<int>);
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<int>);
}

void test_const_char_array()
{
    const int arr[3] = {'a', 'b', 'c'};

    std::cout << "====== test 4 : const char array ======= " << std::endl;
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<int>);
    // compile error
    // std::cout << "> increase value " << std::endl;
    // iter(arr, 3, increaseElement<int>);
}

void test_string_array()
{
    std::string arr[3] = {"hi", "hello", "bye"};

    std::cout << "====== test 5 : string array ======= " << std::endl;
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<std::string>);
}

void test_const_string_array()
{
    const std::string arr[3] = {"hi", "hello", "bye"};

    std::cout << "====== test 6 : const string array ======= " << std::endl;
    std::cout << "> print value" << std::endl;
    iter(arr, 3, printElement<const std::string>);
}

int main(void)
{
    test_int_array();
    test_const_int_array();
    test_char_array();
    test_const_char_array();
    test_string_array();
    test_const_string_array();
}