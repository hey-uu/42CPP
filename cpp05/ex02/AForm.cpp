#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>

void AForm::checkGradeInRange()
{
    if (_sign_grade > 150 || _exec_grade > 150)
        throw GradeTooLowException(_name);
    else if (_sign_grade < 1 || _exec_grade < 1)
        throw GradeTooHighException(_name);
}

AForm::AForm()
    : _name("none"), _target("target"), _is_signed(false), _sign_grade(150),
      _exec_grade(150)
{
}

AForm::AForm(
    std::string const& name, std::string const& target, int sign_grade,
    int exec_grade)
    : _name(name), _target(target), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade)
{
    try {
        checkGradeInRange();
    } catch (std::exception const& e) {
        std::cerr << "construction failed because " << e.what() << std::endl;
        throw;
    }
}

AForm::AForm(AForm const& other)
    : _name(other._name), _target(other._target), _is_signed(other._is_signed),
      _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
}

AForm& AForm::operator=(AForm const& other)
{
    if (this == &other)
        return *this;
    *(const_cast<std::string*>(&_name)) = other._name;
    *(const_cast<std::string*>(&_target)) = other._target;
    *(const_cast<int*>(&_sign_grade)) = other._sign_grade;
    *(const_cast<int*>(&_exec_grade)) = other._exec_grade;
    return *this;
}

AForm::~AForm() {}

std::string const& AForm::getName() const
{
    return _name;
}

std::string const& AForm::getTarget() const
{
    return _target;
}

bool AForm::getIsSigned() const
{
    return _is_signed;
}

int AForm::getSignGrade() const
{
    return _sign_grade;
}

int AForm::getExecutionGrade() const
{
    return _exec_grade;
}

void AForm::beSigned(Bureaucrat const& signer)
{
    // if (_is_signed == true)
    // return;
    if (_sign_grade < signer.getGrade())
        throw GradeTooLowException(signer.getName());
    _is_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (_is_signed == false)
        throw NotSignedException(_name);
    if (_exec_grade < executor.getGrade())
        throw GradeTooLowException(executor.getName());
    do_action();
}

AForm::NotSignedException::NotSignedException(std::string const& name) throw()
    : _errmsg(name + " is not signed")
{
}

AForm::NotSignedException::~NotSignedException() throw(){};

const char* AForm::NotSignedException::what() const throw()
{
    return _errmsg.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(
    std::string const& name) throw()
    : _errmsg(name + "'s grade is too high")
{
}

AForm::GradeTooHighException::~GradeTooHighException() throw(){};

const char* AForm::GradeTooHighException::what() const throw()
{
    return _errmsg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(
    std::string const& name) throw()
    : _errmsg(name + "'s grade is too low")
{
}

AForm::GradeTooLowException::~GradeTooLowException() throw(){};

const char* AForm::GradeTooLowException::what() const throw()
{
    return _errmsg.c_str();
}

std::ostream& operator<<(std::ostream& os, AForm const& form)
{
    os << "[ INFO  ] " << std::setw(10) << std::left << "type"
       << " | " << std::setw(22) << std::left << "name"
       << " | " << std::setw(10) << std::left << "target"
       << " | " << std::setw(10) << std::left << "signed"
       << " | " << std::setw(10) << std::left << "sign grade"
       << " | " << std::setw(10) << std::left << "exec grade"
       << " | " << std::endl;
    os << "          " << std::setw(10) << std::left << "Form"
       << " | " << std::setw(22) << std::left << form.getName() << " | "
       << std::setw(10) << std::left << form.getTarget() << " | "
       << std::setw(10) << std::left << form.getIsSigned() << " | "
       << std::setw(10) << std::left << form.getSignGrade() << " | "
       << std::setw(10) << std::left << form.getExecutionGrade() << " | "
       << std::endl;
    return os;
}
