#ifndef BUREAUCRAT_HPP
#define BUREACRAT_HPP

#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(Bureaucrat const &other);
  Bureaucrat &operator=(Bureaucrat const &other);
  ~Bureaucrat();

  // getter
  std::string const &getName() const;
  int getGrade() const;

private:
  const std::string _name;
  int _grade;
};

#endif