#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Form;
class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int const grade) throw(std::exception);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const& rhs);
    Bureaucrat&        operator=(Bureaucrat const& rhs);
    std::string const& getName() const;
    int                getGrade() const;
    std::string        getStrGrade() const;
    void               incrementGrade() throw(std::exception);
    void               decrementGrade() throw(std::exception);
    bool               signForm(Form& form);

private:
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

    std::string const _name;
    int               _grade;
    static const int  _kLowestGrade = 150;
    static const int  _kHighestGrade = 1;
    static bool       _isLeftLower(int const grade_a, int const grade_b);
    static bool       _isLeftHigher(int const grade_a, int const grade_b);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureau);

#endif
