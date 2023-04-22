#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int const grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const& rhs);
    Bureaucrat&        operator=(Bureaucrat const& rhs);
    std::string const& getName() const;
    int                getGrade() const;
    void               incrementGrade();
    void               decrementGrade();

    class GradeTooHighException : public std::domain_error
    {
    public:
        GradeTooHighException();
    };
    class GradeTooLowException : public std::domain_error
    {
    public:
        GradeTooLowException();
    };

private:
    std::string const _name;
    int               _grade;
    static const int  _kLowestGrade = 150;
    static const int  _kHighestGrade = 1;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureau);

#endif
