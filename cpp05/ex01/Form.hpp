#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;
class Form
{
public:
    Form();
    Form(std::string const& name, int const sign_grade, int const exec_grade);
    Form(Form const& other);
    ~Form();

    Form&              operator=(Form const& other);
    std::string const& getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecGrade() const;
    void               beSigned(Bureaucrat const& bureau) throw(std::exception);

private:
    class GradeTooHighException : public std::domain_error
    {
    public:
        GradeTooHighException(std::string const& str);
    };
    class GradeTooLowException : public std::domain_error
    {
    public:
        GradeTooLowException(std::string const& str);
    };

    class AlreadySignedException : public std::logic_error
    {
    public:
        AlreadySignedException();
    };

    std::string const _name;
    int const         _sign_grade;
    int const         _exec_grade;
    bool              _is_signed;
    static int const  _kLowestGrade = 150;
    static int const  _kHighestGrade = 1;
    static bool       _isLeftHigher(int const grade_a, int const grade_b);
    static bool       _isLeftLower(int const grade_a, int const grade_b);
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif