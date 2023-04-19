#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  ~Bureaucrat();
  Bureaucrat(Bureaucrat const &rhs);
  Bureaucrat &operator=(Bureaucrat const &rhs);
  std::string const &getName() const;
  int getGrade() const;

private:
  std::string const _name;
  int _grade;

};

#endif
