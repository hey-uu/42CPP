#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

void _test_intern_makeForm(
    std::string const form_name, std::string const target_name,
    int signer_grade, int executor_grade)
{
    Intern     intern;
    Bureaucrat signer("signer", signer_grade);
    Bureaucrat executor("executor", executor_grade);

    AForm* form = intern.makeForm(form_name, target_name);
    if (!form)
        return;
    std::cout << *form;
    signer.signForm(*form);
    executor.executeForm(*form);
    delete form;
}

void test1_intern_makeForm()
{
    std::cout << "========= test1 : makeForm =========" << std::endl;
    std::cout << "> (1) make ShrubberyCreationForm(145, 137) " << std::endl;
    _test_intern_makeForm("shrubbery creation", "targetA", 140, 130);
    std::cout << std::endl;
    std::cout << "> (2) make RobotomyRequestForm(72, 45)" << std::endl;
    _test_intern_makeForm("robotomy request", "targetB", 70, 40);
    std::cout << std::endl;
    std::cout << "> (3) make PresidentialPardonForm(25, 5)" << std::endl;
    _test_intern_makeForm("presidential pardon", "targetC", 20, 1);
    std::cout << std::endl;
    std::cout << "> (4) fail to make any form" << std::endl;
    _test_intern_makeForm("some other form", "targetD", 1, 1);
    std::cout << std::endl;
}

int main(void)
{
    test1_intern_makeForm();
}
