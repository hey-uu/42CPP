#include <iostream>
#include <cstdlib>
#include <sstream>

int main()
{
    float             f = 123.3f;
    std::stringstream ss;

    ss << f;
    ss << "f";
    std::cout << f << std::endl;
    std::cout << ss.str() << std::endl;
}