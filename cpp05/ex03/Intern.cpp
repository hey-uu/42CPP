#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& other)
{
    (void)other;
}

Intern& Intern::operator=(Intern const& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm*
Intern::makeForm(std::string const& name, std::string const& target) const
{
    std::string static const types[3]
        = {"shrubbery creation", "robotomy request", "presidential pardon"};
    form_maker fcts[3]
        = {ShrubberyCreationForm::makeForm, RobotomyRequestForm::makeForm,
           PresidentialPardonForm::makeForm};

    for (int i = 0; i < 3; i++) {
        if (name == types[i]) {
            std::cout << "Intern creates " << name << " form" << std::endl;
            return fcts[i](target);
        }
    }
    std::cerr << "Intern couldn't create a form" << std::endl;
    return NULL;
}
