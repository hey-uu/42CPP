#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
    std::string const _name;
    int               _grade;
    int static const _kLowestGrade = 150;
    int static const _kHighestGrade = 1;

    void checkGradeInRange() const;

public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    ~Bureaucrat();

    std::string const& getName() const;
    int                getGrade() const;
    void               incrementGrade();
    void               decrementGrade();

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
        GradeTooLowException(std::string const& bureau) throw();
        ~GradeTooLowException() throw();
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureau);

#endif