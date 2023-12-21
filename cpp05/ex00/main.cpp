#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

void _test_constructor(std::string const name, int grade)
{
    try {
        Bureaucrat bureau = Bureaucrat(name, grade);
        std::cout << bureau;
        std::cerr << "> construction succeeded" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "> construction failed" << std::endl;
    }
}

void _test_decrement_grade(std::string const& name, int grade)
{
    Bureaucrat bureau = Bureaucrat(name, grade);
    try {
        bureau.decrementGrade();
        std::cout << bureau;
        std::cerr << "> decrementation succeeded" << std::endl;
    } catch (std::exception const& e) {
        std::cerr << "> decrementation failed" << std::endl;
    }
}

void _test_increment_grade(std::string const& name, int grade)
{
    Bureaucrat bureau = Bureaucrat(name, grade);

    try {
        bureau.incrementGrade();
        std::cout << bureau;
        std::cerr << "> incrementation succeeded" << std::endl;
    } catch (std::exception const& e) {
        std::cerr << "> incrementation failed" << std::endl;
    }
}

void test1_constructor()
{
    std::cout << "========= test1 : constructor =========" << std::endl;
    std::cout << "> (1) fail if grade is too high(grade < 1)" << std::endl;
    _test_constructor("personA", 0);
    _test_constructor("personB", -12);
    std::cout << std::endl;
    std::cout << "> (2) fail if grade is too low(grade > 150)" << std::endl;
    _test_constructor("personC", 151);
    _test_constructor("personD", 165);
    std::cout << std::endl;
    std::cout << "> (3) succeed if 1 <= grade <= 150" << std::endl;
    _test_constructor("personE", 1);
    _test_constructor("personF", 150);
    _test_constructor("personG", 70);
    std::cout << std::endl;
}

void test2_decrement_grade()
{
    std::cout << "========= test2 : decrement grade =========" << std::endl;
    std::cout << "> (1) fail if grade = 150" << std::endl;
    _test_decrement_grade("personA", 150);
    std::cout << std::endl;
    std::cout << "> (2) succeed if grade < 150" << std::endl;
    _test_decrement_grade("personB", 149);
    _test_decrement_grade("personC", 28);
    std::cout << std::endl;
}

void test3_increment_grade() {
    std::cout << "========= test3 : increment grade =========" << std::endl;
    std::cout << "> (1) fail if grade = 1" << std::endl;
    _test_increment_grade("personA", 1);
    std::cout << std::endl;
    std::cout << "> (2) succeed if grade > 1" << std::endl;
    _test_increment_grade("personB", 2);
    _test_increment_grade("personC", 100);
    std::cout << std::endl;
}

int main(void)
{
    test1_constructor();
    test2_decrement_grade();
    test3_increment_grade();
}
