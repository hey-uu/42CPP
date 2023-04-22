#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>

class Form {
  public:
    Form();
    Form(std::string const &name, int const sign_grade,
         int const excution_grade);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();

    std::string const &getName() const;
    bool               isSigned() const;
    int                getSignGrade() const;
    int                getExcutionGrade() const;

  private:
    std::string const _name;
    bool              _is_signed;
    int const         _sign_grade;
    int const         _excution_grade;

    class GradeTooHighException : public std::exception {
      public:
        GradeTooHighException();
    };
    class GradeTooLowException : public std::exception {
      public:
        GradeTooLowException();
    };
};

#endif