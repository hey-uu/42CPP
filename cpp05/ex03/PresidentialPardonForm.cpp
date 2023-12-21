#include <cstdlib>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", "none", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const& other)
    : AForm(other)
{
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::do_action() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

AForm* PresidentialPardonForm::makeForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}