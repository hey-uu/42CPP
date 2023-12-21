#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    PresidentialPardonForm();
    virtual void do_action() const;

public:
    PresidentialPardonForm(std::string const& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    ~PresidentialPardonForm();
};

#endif
