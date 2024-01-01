#include "easyfind.hpp"
#include <iostream>
#include <set>
#include <vector>

int main(void)
{
    int                    ints[] = {1, 2, 3, 4, 5};
    std::vector<int>       int_vec(ints, ints + sizeof(ints) / sizeof(int));
    const std::vector<int> int_cvec(ints, ints + sizeof(ints) / sizeof(int));
    std::set<int>          int_set(ints, ints + sizeof(ints) / sizeof(int));
    const std::set<int>    int_cset(ints, ints + sizeof(ints) / sizeof(int));

    std::cout << "\n===== test1: vecotr<int> =====" << std::endl;
    try {
        std::cout << "> try to find 3" << std::endl;
        std::vector<int>::iterator it = easyfind(int_vec, 3);
        std::cout << "found: " << *it << std::endl;
        std::cout << "> change 3 to 0" << std::endl;
        *it = 0;
        std::cout << "> try to find 3 again" << std::endl;
        easyfind(int_vec, 3);
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
    }

    std::cout << "\n===== test2: const vecotr<int> =====" << std::endl;
    try {
        std::cout << "> try to find 3" << std::endl;
        std::vector<int>::const_iterator it1 = easyfind(int_cvec, 3);
        std::cout << "found: " << *it1 << std::endl;
        std::cout << "> try to find 9" << std::endl;
        std::vector<int>::const_iterator it2 = easyfind(int_cvec, 9);
        std::cout << "found: " << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
    }

    std::cout << "\n===== test3: set<int> =====" << std::endl;
    try {
        std::cout << "> try to find 3" << std::endl;
        std::set<int>::iterator it1 = easyfind(int_set, 3);
        std::cout << "found: " << *it1 << std::endl;
        // std::cout << "> change 3 to 10" << std::endl;
        // *it1 = 10; set is immutable
        std::cout << "> try to find 9" << std::endl;
        std::set<int>::iterator it2 = easyfind(int_set, 9);
        std::cout << "found: " << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
    }

    std::cout << "\n===== test4: const set<int> =====" << std::endl;
    try {
        std::cout << "> try to find 3" << std::endl;
        std::set<int>::const_iterator it1 = easyfind(int_cset, 3);
        std::cout << "found: " << *it1 << std::endl;
        std::cout << "> try to find 9" << std::endl;
        std::set<int>::const_iterator it2 = easyfind(int_cset, 9);
        std::cout << "found: " << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
    }
}
