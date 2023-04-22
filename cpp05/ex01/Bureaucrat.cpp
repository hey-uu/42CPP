#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat() : _name("?"), _grade(_kLowestGrade)
{
    std::clog << "[ DEBUG ] Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int const grade) throw(
    std::exception)
    : _name(name), _grade(grade)
{
    try {
        if (_isLeftLower(_grade, _kLowestGrade))
            throw Bureaucrat::GradeTooLowException();
        else if (_isLeftHigher(_grade, _kHighestGrade))
            throw Bureaucrat::GradeTooHighException();
    } catch (const std::exception& e) {
        std::cerr << "[ ERROR ] Bureaucrat(string, int) constructor : tried to "
                     "initialize as "
                  << *this << " : " << e.what() << std::endl;
        throw;
    }
    std::clog
        << "[ DEBUG ] Bureaucrat(string, int) constructor successfully called"
        << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs)
    : _name(rhs._name), _grade(rhs._grade)
{
    std::clog << "[ DEBUG ] Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
    if (this != &rhs) {
        *(const_cast<std::string*>(&_name)) = rhs._name;
        _grade = rhs._grade;
    }
    std::clog << "[ DEBUG ] Bureaucrat assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::clog << "[ DEBUG ] Bureaucrat destructor called" << std::endl;
}

std::string const& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getStrGrade() const
{
    std::stringstream ss;
    ss << _grade;
    return ss.str();
}

void Bureaucrat::incrementGrade() throw(std::exception)
{
    try {
        if (_grade == _kHighestGrade)
            throw Bureaucrat::GradeTooHighException();
    } catch (const std::exception& e) {
        std::cerr << "[ ERROR ] incrementGrade : " << e.what() << std::endl;
        throw;
    }
    _grade--;
    std::clog << "[ DEBUG ] Bureaucrat's grade is incremented to " << _grade
              << std::endl;
}

void Bureaucrat::decrementGrade() throw(std::exception)
{
    try {
        if (_grade == _kLowestGrade)
            throw Bureaucrat::GradeTooLowException();
    } catch (const std::exception& e) {
        std::cerr << "[ ERROR ] decrementGrade : " << e.what() << std::endl;
        throw;
    }
    _grade++;
    std::clog << "[ DEBUG ] Bureaucrat's grade is decremented to " << _grade
              << std::endl;
}

bool Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << ">> SUCCESS << " << _name << " signed " << form.getName()
                  << std::endl;
        return true;
    } catch (std::exception const& e) {
        std::cout << ">> FAIL << " << _name << " couldn't sign "
                  << form.getName() << " because " << e.what() << std::endl;
    }
    return false;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureau)
{
    os << " ( "
       << "type: Bureaucrat | "
       << "name: " + bureau.getName() << " | "
       << "grade: " + bureau.getStrGrade() << " ) ";
    return (os);
}

// private
Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::domain_error("Grade Too High")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::domain_error("Grade Too Low")
{
}

bool Bureaucrat::_isLeftLower(int const grade_a, int const grade_b)
{
    return (grade_a > grade_b);
}

bool Bureaucrat::_isLeftHigher(int const grade_a, int const grade_b)
{
    return (grade_a < grade_b);
}
