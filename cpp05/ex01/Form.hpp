#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    bool              _is_signed; // at construction, false
    int const         _sign_grade;
    int const         _exec_grade;
    int static const _kHighestGrade = 1;
    int static const _kLowestGrade = 150;

    void checkGradeInRange();

    class GradeTooHighException : public std::exception
    {
    private:
        std::string const _errmsg;

    public:
        GradeTooHighException(std::string const& name) throw();
        ~GradeTooHighException() throw();
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    private:
        std::string const _errmsg;

    public:
        GradeTooLowException(std::string const& name) throw();
        ~GradeTooLowException() throw();
        const char* what() const throw();
    };

public:
    Form();
    Form(std::string const& name, int sign_grade, int exec_grade);
    Form(Form const& other);
    Form& operator=(Form const& other);
    ~Form();

    std::string const& getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecutionGrade() const;
    void               beSigned(Bureaucrat const& bureau);
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif
