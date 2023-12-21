#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    ShrubberyCreationForm();
    virtual void do_action() const;

public:
    ShrubberyCreationForm(std::string const& target);
    ShrubberyCreationForm(ShrubberyCreationForm const& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
    ~ShrubberyCreationForm();
};
#endif
