#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {
  std::clog << "[ DEBUG ] Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::clog << "[ DEBUG ] Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
    : _name(rhs._name), _grade(rhs._grade) {
  std::clog << "[ DEBUG ] Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs) {
    *(const_cast<std::string *>(&_name)) = rhs._name;
    _grade = rhs._grade;
  }
  std::clog << "[ DEBUG ] Bureaucrat assignment operator called" << std::endl;
}

std::string const &Bureaucrat::getName() const {

}