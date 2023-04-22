#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <sstream>

std::string& appendInt(std::string& str, int num)
{
    std::stringstream ss;
    ss << num;
    str += ss.str();
    return (str);
}

int main(void)
{
    Bureaucrat* crat = new Bureaucrat("Crat", 80);
    Form*       form[5];

    for (int i = 0; i < 5; i++) {
        std::string form_name = "Form";
        try {
            form[i] = NULL;
            form[i] = new Form(appendInt(form_name, i), i * 30 + 1, i * 30 + 3);
        } catch (std::exception const& e) {
            std::cerr << "[ ERROR ] failed at " << i << "th trials"
                      << std::endl;
            continue;
        }
        if (crat->signForm(*form[i]) == false)
            continue;
        crat->signForm(*form[i]);
        delete form[i];
    }
}
