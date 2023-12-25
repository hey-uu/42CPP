#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    int              ints[] = {1, 2, 3, 4, 5};
    std::vector<int> intvec(ints, ints + sizeof(ints) / sizeof(int));
    const std::vector<int> intvec2(ints, ints + sizeof(ints) / sizeof(int));

    try {
        ints[2] = 0;
        std::vector<int>::iterator it = easyfind(intvec, 3);
        std::cout << *it << std::endl;
        *it = 0;
        easyfind(intvec, 3);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        std::vector<int>::const_iterator it1 = easyfind(intvec2, 3);
        std::cout << *it1 << std::endl;
        std::vector<int>::const_iterator it2 = easyfind(intvec2, 9);
        std::cout << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
