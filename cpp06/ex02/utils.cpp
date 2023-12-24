#include "utils.hpp"

Base* generate(void)
{
    int choice = std::rand() % 3; // Random number between 0 and 2

    switch (choice) {
        case 0:
            std::cout << "generated type A" << std::endl;
            return new A;
        case 1:
            std::cout << "generated type B" << std::endl;
            return new B;
        case 2:
            std::cout << "generated type C" << std::endl;
            return new C;
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "the pointer is type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "the pointer is type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "the pointer is type C" << std::endl;
    else
        std::cout << "the pointer is none of type A, B, C" << std::endl;
}

void identify(Base& p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "the reference is type A" << std::endl;
        return;
    } catch (std::bad_cast& e) {
    }
    try {
        dynamic_cast<B&>(p);
        std::cout << "the reference is type B" << std::endl;
        return;
    } catch (std::bad_cast& e) {
    }
    try {
        dynamic_cast<C&>(p);
        std::cout << "the reference is type C" << std::endl;
        return;
    } catch (std::bad_cast& e) {
    }
}
