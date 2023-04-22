#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
    std::clog << "[ DEBUG ] Bureaucrat default constructor called" << std::endl;
} // private

Bureaucrat::Bureaucrat(std::string const &name, int const grade)
    : _name(name), _grade(grade)
{
    try {
        if (_grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (_grade < 1)
            throw Bureaucrat::GradeTooHighException();
    }
    catch (const std::exception &e) {
        std::cerr << "[ ERROR ] Bureaucrat constructor : tried to initialize "
                     "grade to "
                  << grade << " : " << e.what() << std::endl;
        throw;
    }
    std::clog << "[ DEBUG ] Bureaucrat(string, int) constructor called"
              << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::clog << "[ DEBUG ] Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
    : _name(rhs._name), _grade(rhs._grade)
{
    std::clog << "[ DEBUG ] Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs) {
        *(const_cast<std::string *>(&_name)) = rhs._name;
        _grade = rhs._grade;
    }
    std::clog << "[ DEBUG ] Bureaucrat assignment operator called" << std::endl;
    return *this;
}

std::string const &Bureaucrat::getName() const
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
        if (_grade == _kHighestGrade)
            throw Bureaucrat::GradeTooHighException();
    }
    catch (const std::exception &e) {
        std::cerr << "[ ERROR ] incrementGrade : " << e.what() << std::endl;
        throw;
    }
    _grade--;
    std::clog << "[ DEBUG ] Bureaucrat's grade is incremented to " << _grade
              << std::endl;
}

void Bureaucrat::decrementGrade()
{
    try {
        if (_grade == _kLowestGrade)
            throw Bureaucrat::GradeTooLowException();
    }
    catch (const std::exception &e) {
        std::cerr << "[ ERROR ] decrementGrade : " << e.what() << std::endl;
        throw;
    }
    _grade++;
    std::clog << "[ DEBUG ] Bureaucrat's grade is decremented to " << _grade
              << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::domain_error("Grade Too High")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::domain_error("Grade Too Low")
{
}