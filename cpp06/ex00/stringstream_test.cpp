#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

int main()
{
    std::istringstream ss("123adf");
    int                d;

    if ((ss >> d))
        std::cout << "it's okay" << std::endl;
    std::cout << "fail: " << ss.fail() << std::endl;
    std::cout << "eof: " << ss.eof() << std::endl;
    std::cout << "good: " << ss.good() << std::endl;
    std::cout << d << std::endl;
    std::cout << std::endl;

    std::istringstream ss3("2147");
    if ((ss3 >> d))
        std::cout << "it's okay" << std::endl;
    std::cout << "fail: " << ss3.fail() << std::endl;
    std::cout << "eof: " << ss3.eof() << std::endl;
    std::cout << "good: " << ss3.good() << std::endl;
    std::cout << d << std::endl;
    std::cout << std::endl;

    std::istringstream ss2("2147483648");
    if ((ss2 >> d))
        std::cout << "it's okay" << std::endl;
    std::cout << "fail: " << ss2.fail() << std::endl;
    std::cout << "eof: " << ss2.eof() << std::endl;
    std::cout << "good: " << ss2.good() << std::endl;
    std::cout << d << std::endl;
    std::cout << std::endl;

    // float test
    std::istringstream ss4("12a3.212adf");
    double             f;

    if ((ss4 >> f))
        std::cout << "it's okay" << std::endl;
    std::cout << "fail: " << ss4.fail() << std::endl;
    std::cout << "eof: " << ss4.eof() << std::endl;
    std::cout << "good: " << ss4.good() << std::endl;
    std::cout << f << std::endl;
    std::cout << std::endl;

    std::istringstream ss5("2147");
    if ((ss5 >> f))
        std::cout << "it's okay" << std::endl;
    std::cout << "fail: " << ss5.fail() << std::endl;
    std::cout << "eof: " << ss5.eof() << std::endl;
    std::cout << "good: " << ss5.good() << std::endl;
    std::cout << f << std::endl;
    std::cout << std::endl;

    std::istringstream ss6("2147481231231231.12312312313648");
    if ((ss6 >> f))
        std::cout << "it's okay" << std::endl;
    std::cout << "fail: " << ss6.fail() << std::endl;
    std::cout << "eof: " << ss6.eof() << std::endl;
    std::cout << "good: " << ss6.good() << std::endl;
    std::cout << f << std::endl;
    std::cout << std::endl;

    float f3 = 3.0f;

    std::cout << f3 << std::endl;
}