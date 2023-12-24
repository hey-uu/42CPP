#include "ScalarConverter.hpp"
#include <iostream>

// void test_convert(std::string const input)
// {
//     static int num = 1;

//     std::cout << "===== test" << num << ": " << input << " =====" <<
//     std::endl; try {
//         ScalarConverter::convert(input);
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << '\n';
//     }
//     std::cout << std::endl;
//     num++;
// }

// void do_tests()
// {
//     // char
//     test_convert("a");
//     test_convert("c");

//     // int
//     test_convert("0");
//     test_convert("2147483647");
//     test_convert("2147483648");
//     test_convert("-2147483648");
//     test_convert("-2147483649");

//     // float
//     test_convert("42.0f");
//     test_convert("123.423f");
//     test_convert("2147483650.0f");
//     test_convert("inff");
//     test_convert("-inff");
//     test_convert("nanf");

//     // double
//     test_convert("2147483650.0");
//     test_convert("inf");
//     test_convert("-inf");
//     test_convert("nan");
// }

int main(int argc, char* argv[])
{
    // (void)argc;
    // (void)argv;
    // do_tests();
    if (argc != 2)
        return 1;
    ScalarConverter::convert(argv[1]);
}
