#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>

static void error_message(const char* message)
{
    std::cerr << "[ ERROR ] " << message << std::endl;
}

void Form::checkGradeInRange()
{
    if (_sign_grade > 150 || _exec_grade > 150)
        throw GradeTooLowException(_name);
    else if (_sign_grade < 1 || _exec_grade < 1)
        throw GradeTooHighException(_name);
}

Form::Form()
    : _name("none"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
}

Form::Form(std::string const& name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade)
{
    try {
        checkGradeInRange();
    } catch (std::exception const& e) {
        error_message(e.what());
        throw;
    }
}

Form::Form(Form const& other)
    : _name(other._name), _is_signed(other._is_signed),
      _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
}

Form& Form::operator=(Form const& other)
{
    if (this == &other)
        return *this;
    *(const_cast<std::string*>(&_name)) = other._name;
    *(const_cast<int*>(&_sign_grade)) = other._sign_grade;
    *(const_cast<int*>(&_exec_grade)) = other._exec_grade;
    return *this;
}

Form::~Form() {}

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

int Form::getExecutionGrade() const
{
    return _exec_grade;
}

void Form::beSigned(Bureaucrat const& bureau)
{
    try {
        // if (_is_signed == true)
            // return;
        const int bureau_grade = bureau.getGrade();
        if (_sign_grade < bureau_grade)
            throw GradeTooLowException(bureau.getName());
        _is_signed = true;
    } catch (std::exception const& e) {
        error_message(e.what());
        throw;
    }
}

Form::GradeTooHighException::GradeTooHighException(
    std::string const& name) throw()
    : _errmsg("Grade is too high(" + name + ")")
{
}

Form::GradeTooHighException::~GradeTooHighException() throw(){};

const char* Form::GradeTooHighException::what() const throw()
{
    return _errmsg.c_str();
}

Form::GradeTooLowException::GradeTooLowException(
    std::string const& name) throw()
    : _errmsg("Grade is too Low(" + name + ")")
{
}

Form::GradeTooLowException::~GradeTooLowException() throw(){};

const char* Form::GradeTooLowException::what() const throw()
{
    return _errmsg.c_str();
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
    os << "[ INFO  ] " << std::setw(10) << std::left << "type"
       << " | " << std::setw(10) << std::left << "name"
       << " | " << std::setw(10) << std::left << "signed"
       << " | " << std::setw(10) << std::left << "sign grade"
       << " | " << std::setw(10) << std::left << "exec grade"
       << " | " << std::endl;
    os << "          " << std::setw(10) << std::left << "Form"
       << " | " << std::setw(10) << std::left << form.getName() 
       << " | " << std::setw(10) << std::left << form.getIsSigned() 
       << " | " << std::setw(10) << std::left << form.getSignGrade() 
       << " | " << std::setw(10) << std::left << form.getExecutionGrade() << " | "
       << std::endl;
    return os;
}