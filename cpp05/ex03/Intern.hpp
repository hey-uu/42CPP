#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
private:
    typedef AForm* (*form_maker)(std::string const& target);

public:
    Intern();
    Intern(Intern const& other);
    Intern& operator=(Intern const& other);
    ~Intern();
    AForm* makeForm(std::string const& name, std::string const& target) const;
};

#endif