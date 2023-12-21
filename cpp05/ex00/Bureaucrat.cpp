#include "Bureaucrat.hpp"
#include <iomanip>

void error_message(const char* message)
{
    std::cerr << "[ ERROR ] " << message << std::endl;
}

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
        error_message(e.what());
        throw;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& other)
    : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    Bureaucrat new_bureau(other);
    *this = new_bureau;
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
        error_message(e.what());
        throw;
    }
}

void Bureaucrat::decrementGrade()
{
    try {
        _grade++;
        checkGradeInRange();
    } catch (std::exception const& e) {
        error_message(e.what());
        throw;
    }

    std::string const& msg = std::string("hello ") + std::string("abc");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    std::string const& name) throw()
    : _errmsg("Grade is too High(" + name + ")")
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return _errmsg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    std::string const& name) throw()
    : _errmsg("Grade is too Low(" + name + ")")
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
