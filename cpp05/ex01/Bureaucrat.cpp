#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

void Bureaucrat::checkGradeInRange() const
{
    if (_grade > 150)
        throw GradeTooLowException(_name);
    else if (_grade < 1)
        throw GradeTooHighException(_name);
}

// essenstial
Bureaucrat::Bureaucrat() : _name("none"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : _name(name), _grade(grade)
{
    try {
        checkGradeInRange();
    } catch (std::exception const& e) {
        std::cerr << "construction failed because " << e.what() << std::endl;
        throw;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& other)
    : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    if (this == &other)
        return *this;
    *(const_cast<std::string*>(&_name)) = other._name;
    _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    try {
        _grade--;
        checkGradeInRange();
    } catch (std::exception const& e) {
        _grade++;
        std::cerr << "failed to increment grade because " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try {
        _grade++;
        checkGradeInRange();
    } catch (std::exception const& e) {
        _grade--;
        std::cerr << "failed to decrement grade because " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception const& e) {
        std::cout << _name << " couldn't sign " << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    std::string const& name) throw()
    : _errmsg(name + "'s grade is too high")
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return _errmsg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    std::string const& name) throw()
    : _errmsg(name + "'s grade is too low")
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return _errmsg.c_str();
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureau)
{
    os << "[ INFO  ] " << std::setw(10) << std::left << "type"
       << " | " << std::setw(10) << std::left << "name"
       << " | " << std::setw(10) << std::left << "grade"
       << " | " << std::endl;
    os << "          " << std::setw(10) << std::left << "Bureaucrat"
       << " | " << std::setw(10) << std::left << bureau.getName() << " | "
       << std::setw(10) << std::left << bureau.getGrade() << " | " << std::endl;
    return os;
}
