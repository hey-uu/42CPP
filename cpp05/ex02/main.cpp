#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1_execute_ShrubberyCreationForm()
{
    std::cout << "========= test1 : ShrubberyCreationForm(sign:145, exec:137) "
                 "========="
              << std::endl;
    std::cout << "> (1) ShrubberyCreationForm's info " << std::endl;
    ShrubberyCreationForm form("target");
    std::cout << form;
    std::cout << std::endl;
    std::cout << "> (2) fail to sign if form's grade < Bureaucrat's grade"
              << std::endl;
    Bureaucrat signerA("signerA", 150);
    std::cout << signerA;
    signerA.signForm(form);
    std::cout << std::endl;
    std::cout << "> (3) fail to execute if form is not signed." << std::endl;
    Bureaucrat executorA("executorA", 140);
    std::cout << executorA;
    executorA.executeForm(form);
    std::cout << std::endl;
    std::cout << "> (4) succeed to sign if form's grade >= Bureaucrat's grade"
              << std::endl;
    Bureaucrat signerB("signerB", 100);
    std::cout << signerB;
    signerB.signForm(form);
    std::cout << std::endl;
    std::cout << "> (5) fail to execute if form's grade < Bureaucrat's grade"
              << std::endl;
    std::cout << executorA;
    executorA.executeForm(form);
    std::cout << std::endl;
    std::cout
        << "> (6) succeed to execute if form's grade >= Bureaucrat's grade"
        << std::endl;
    Bureaucrat executorB("executorB", 100);
    std::cout << executorB;
    executorB.executeForm(form);
    std::cout << std::endl;
}

void test2_execute_RobotomyReqeustForm()
{
    std::cout << "========= test1 : RobotomyRequestForm(sign:72, exec:45) "
                 "========="
              << std::endl;
    std::cout << "> (1) RobotomyRequestForm's info " << std::endl;
    RobotomyRequestForm form("target");
    std::cout << form << std::endl;
    std::cout << "> (2) fail to sign if form's grade < Bureaucrat's grade"
              << std::endl;
    Bureaucrat signerA("signerA", 100);
    std::cout << signerA;
    signerA.signForm(form);
    std::cout << std::endl;
    std::cout << "> (3) fail to execute if form is not signed." << std::endl;
    Bureaucrat executorA("executorA", 70);
    std::cout << executorA;
    executorA.executeForm(form);
    std::cout << std::endl;
    std::cout << "> (4) succeed to sign if form's grade >= Bureaucrat's grade"
              << std::endl;
    Bureaucrat signerB("signerB", 50);
    std::cout << signerB;
    signerB.signForm(form);
    std::cout << std::endl;
    std::cout << "> (5) fail to execute if form's grade < Bureaucrat's grade"
              << std::endl;
    std::cout << executorA;
    executorA.executeForm(form);
    std::cout << std::endl;
    std::cout
        << "> (6) succeed to execute if form's grade >= Bureaucrat's grade"
        << std::endl;
    Bureaucrat executorB("executorB", 30);
    std::cout << executorB;
    executorB.executeForm(form);
    std::cout << std::endl;
}

void test3_execute_PresidentialPardonForm()
{
    std::cout << "========= test1 : PresidentialPardonForm(sign:25, exec:5) "
                 "========="
              << std::endl;
    std::cout << "> (1) PresidentialPardonForm's info " << std::endl;
    PresidentialPardonForm form("target");
    std::cout << form << std::endl;
    std::cout << "> (2) fail to sign if form's grade < Bureaucrat's grade"
              << std::endl;
    Bureaucrat signerA("signerA", 50);
    std::cout << signerA;
    signerA.signForm(form);
    std::cout << std::endl;
    std::cout << "> (3) fail to execute if form is not signed." << std::endl;
    Bureaucrat executorA("executorA", 20);
    std::cout << executorA;
    executorA.executeForm(form);
    std::cout << std::endl;
    std::cout << "> (4) succeed to sign if form's grade >= Bureaucrat's grade"
              << std::endl;
    Bureaucrat signerB("signerB", 10);
    std::cout << signerB;
    signerB.signForm(form);
    std::cout << std::endl;
    std::cout << "> (5) fail to execute if form's grade < Bureaucrat's grade"
              << std::endl;
    std::cout << executorA;
    executorA.executeForm(form);
    std::cout << std::endl;
    std::cout
        << "> (6) succeed to execute if form's grade >= Bureaucrat's grade"
        << std::endl;
    Bureaucrat executorB("executorB", 3);
    std::cout << executorB;
    executorB.executeForm(form);
    std::cout << std::endl;
}

int main(void)
{
    test1_execute_ShrubberyCreationForm();
    test2_execute_RobotomyReqeustForm();
    test3_execute_PresidentialPardonForm();
}
