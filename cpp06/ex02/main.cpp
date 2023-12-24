#include "utils.hpp"

const int TEST_NUM = 10;

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < TEST_NUM; i++) {
        std::cout << "===== test " << i + 1 << " ======" << std::endl;
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
        ptr = NULL;
    }
    return 0;
}
