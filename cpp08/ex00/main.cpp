#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    int              myints[] = {1, 2, 3, 4, 5};
    std::vector<int> myvector(myints, myints + sizeof(myints) / sizeof(int));

    try {
        std::vector<int>::iterator it = easyfind(myvector, 3);
        std::cout << *it << std::endl;
        *it = 0;
        easyfind(myvector, 3);

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
