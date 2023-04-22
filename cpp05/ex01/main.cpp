#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

std::string &appendInt(std::string &str, int num)
{
    std::stringstream ss;
    ss << num;
    str += ss.str();
    return (str);
}

int main(void)
{
    Bureaucrat *people[10];
    int         cnt;

    for (int i = 0; i < 10; i++) {
        std::string str = "person";
        try {
            std::cout << "== Bureaucrat " << i << " ==" << std::endl;
            people[i] = new Bureaucrat(appendInt(str, i), i * 30);
            std::cout << "[ INFO  ] Name  : " << people[i]->getName()
                      << std::endl;
            std::cout << "[ INFO  ] Grade : " << people[i]->getGrade()
                      << std::endl;
        }
        catch (std::exception const &e) {
            people[i] = NULL;
            continue;
        }
        if (people[i]->getGrade() < 75) {
            try {
                for (cnt = 1; cnt <= 150; cnt++) {
                    people[i]->incrementGrade();
                }
            }
            catch (std::exception const &e) {
                std::cerr << "[ ERROR ] " << people[i]->getName()
                          << ": failed to increment grade at " << cnt
                          << "th trials" << std::endl;
            }
        }
        else {
            try {
                for (cnt = 1; cnt <= 150; cnt++) {
                    people[i]->decrementGrade();
                }
            }
            catch (std::exception const &e) {
                std::cerr << "[ ERROR ] " << people[i]->getName()
                          << ": failed to increment grade at " << cnt
                          << "th trials" << std::endl;
            }
        }
    }
    std::cout << "== Destruction ==" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << " >> " << i << ": " << std::flush;
        if (people[i] == NULL)
            std::cout << std::endl;
        delete people[i];
    }
}
