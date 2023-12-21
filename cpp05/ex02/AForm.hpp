#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    std::string const _name;
    std::string const _target;
    bool              _is_signed; // at construction, false
    int const         _sign_grade;
    int const         _exec_grade;
    int static const _kHighestGrade = 1;
    int static const _kLowestGrade = 150;

    AForm();
    void checkGradeInRange();

    class NotSignedException : public std::exception
    {
    private:
        std::string const _errmsg;

    public:
        NotSignedException(std::string const& name) throw();
        ~NotSignedException() throw();
        const char* what() const throw();
    };

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

protected:
    virtual void do_action() const = 0;

public:
    AForm(
        std::string const& name, std::string const& target, int sign_grade,
        int exec_grade);
    AForm(AForm const& other);
    AForm& operator=(AForm const& other);
    virtual ~AForm();

    std::string const& getName() const;
    std::string const& getTarget() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecutionGrade() const;
    void               beSigned(Bureaucrat const& signer);
    void               execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif
