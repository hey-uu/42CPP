#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

int main()
{
    // tes1: basic
    std::cout << "\n====== test1: basic ======" << std::endl;
    Span sp = Span(5);
    sp.addNumber(-6);
    sp.addNumber(-3);
    sp.addNumber(-17);
    sp.addNumber(-9);
    sp.addNumber(-11);
    std::cout << sp.shortestSpan() << std::endl; // 2
    std::cout << sp.longestSpan() << std::endl;  // 14

    // test2: addNumber using iterator
    std::cout << "\n====== test2: addNumber using iterator ======" << std::endl;
    int              myints[] = {16, 2, 77, 29, -20, 5};
    std::vector<int> intvec(myints, myints + sizeof(myints) / sizeof(int));
    Span             sp2 = Span(6);
    sp2.addNumber(intvec.begin(), intvec.end());
    std::cout << sp2.shortestSpan() << std::endl; // 3
    std::cout << sp2.longestSpan() << std::endl;  // 97

    // test3: Span addNumber
    std::cout << "\n====== test3: addNumber : Span is full ======" << std::endl;
    try {
        Span sp3 = Span(1);
        sp3.addNumber(1);
        sp3.addNumber(2);

    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    // test4: Span addNumber
    std::cout
        << "\n====== test4: addNumber using iterator : Span is full ======"
        << std::endl;
    try {
        Span sp4 = Span(1);
        sp4.addNumber(intvec.begin(), intvec.end());

    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    // test5: ShortestSpan Not enough data
    std::cout << "\n====== test5: ShortestSpan: Not enough data ======"
              << std::endl;
    try {
        Span sp5 = Span(1);
        sp5.addNumber(1);
        std::cout << sp5.shortestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    // test6: LongestSpan Not enough data
    std::cout << "\n====== test6: LongestSpan: Not enough data ======"
              << std::endl;
    try {
        Span sp6 = Span(1);
        int  data = sp6.longestSpan();
        std::cout << data << std::endl;
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    // test7: many numbers
    std::cout << "\n====== test7: many data ======" << std::endl;
    try {
        std::srand(time(0));
        Span           sp7 = Span(10000);
        std::list<int> int_list;
        for (int i = 0; i < 10000; i++) {
            const int value = std::rand();
            int_list.push_back(value);
        }
        sp7.addNumber(int_list.begin(), int_list.end());
        std::cout << sp7.shortestSpan() << std::endl; // 2
        std::cout << sp7.longestSpan() << std::endl;  // 14
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
