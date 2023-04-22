#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>

// public
Form::Form()
    : _name("?"), _sign_grade(_kLowestGrade), _exec_grade(_kLowestGrade),
      _is_signed(false)
{
    std::clog << "[ DEBUG ] Form default constructor called" << std::endl;
}

Form::Form(std::string const& name, int const sign_grade, int const exec_grade)
    : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade),
      _is_signed(false)
{
    try {
        if (_isLeftLower(_sign_grade, _kLowestGrade)
            || _isLeftLower(_exec_grade, _kLowestGrade))
            throw Form::GradeTooLowException("construct");
        else if (
            _isLeftHigher(_sign_grade, _kHighestGrade)
            || _isLeftHigher(_exec_grade, _kHighestGrade))
            throw Form::GradeTooHighException("construct");
    } catch (const std::exception& e) {
        std::cerr << "[ ERROR ] Form(string, int, int) constructor : tried to "
                     "initialize as "
                  << *this << " : " << e.what() << std::endl;
        throw;
    }
    std::clog
        << "[ DEBUG ] Form(string, int, int) constructor successfully called"
        << std::endl;
}

Form::Form(Form const& other)
    : _name(other._name), _sign_grade(other._sign_grade),
      _exec_grade(other._exec_grade), _is_signed(false)
{
    std::clog << "[ DEBUG ] Form copy constructor called" << std::endl;
}

Form& Form::operator=(Form const& other)
{
    if (this != &other) {
        *(const_cast<std::string*>(&_name)) = other._name;
        *(const_cast<int*>(&_sign_grade)) = other._sign_grade;
        *(const_cast<int*>(&_exec_grade)) = other._exec_grade;
        _is_signed = other._is_signed;
    }
    std::clog << "[ DEBUG ] Form assignment operator called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::clog << "[ DEBUG ] Form destructor called" << std::endl;
}

std::string const& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _is_signed;
}

int Form::getSignGrade() const
{
    return _sign_grade;
}

int Form::getExecGrade() const
{
    return _exec_grade;
}

void Form::beSigned(Bureaucrat const& bureau) throw(std::exception)
{
    if (_is_signed == true)
        throw Form::AlreadySignedException();
    if (_isLeftLower(bureau.getGrade(), _sign_grade))
        throw Form::GradeTooLowException("sign");
    _is_signed = true;
    std::clog << "[ DEBUG ] Form::beSigned() : the form is successfully signed"
              << std::endl;
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
    std::string is_signed_str = (form.getIsSigned()) ? "yes" : "no";
    os << " ( "
       << "type: Form | "
       << "Name: " << form.getName() << " | "
       << "Signed: " << is_signed_str << " | "
       << "Sign Grade: " << form.getSignGrade() << " | "
       << "Execution grade: " << form.getExecGrade() << " ) ";
    return (os);
}

// private
Form::GradeTooHighException::GradeTooHighException(std::string const& str)
    : std::domain_error("grade is too high to " + str)
{
}

Form::GradeTooLowException::GradeTooLowException(std::string const& str)
    : std::domain_error("grade is too low to " + str)
{
}

Form::AlreadySignedException::AlreadySignedException()
    : std::logic_error("the form is already signed by some bureaucrat")
{
}

bool Form::_isLeftHigher(int const grade_a, int const grade_b)
{
    return (grade_a < grade_b);
}

bool Form::_isLeftLower(int const grade_a, int const grade_b)
{
    return (grade_a > grade_b);
}