#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void) {
  std::clog << "[ DEBUG ] Brain default constructor called" << std::endl;
  std::stringstream ss;
  std::string str;
  for (int i = 0; i < _kMaxCnt; i++) {
    ss << (i + 1);
    str = ss.str();
    _ideas[i] = "idea" + str;
    ss.str("");
  }
}

Brain::Brain(std::string const &prefix) {
  std::clog << "[ DEBUG ] Brain string constructor called" << std::endl;
  std::stringstream ss;
  std::string str;
  for (int i = 0; i < _kMaxCnt; i++) {
    ss << (i + 1);
    str = ss.str();
    _ideas[i] = prefix + "idea" + str;
    ss.str("");
  }
}

Brain::Brain(Brain const &other) {
  std::clog << "[ DEBUG ] Brain copy constructor called" << std::endl;
  for (int i = 0; i < _kMaxCnt; i++)
    _ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(Brain const &other) {
  std::clog << "[ DEBUG ] Brain assignment operator called" << std::endl;
  if (this == &other)
    return (*this);
  for (int i = 0; i < _kMaxCnt; i++)
    _ideas[i] = other._ideas[i];
  return (*this);
}

Brain::~Brain(void) {
  std::clog << "[ DEBUG ] Brain destructor called" << std::endl;
}

void Brain::showIdeas(void) const {
  for (int i = 0; i < _kMaxCnt; i++)
    std::cout << "ideas[" << i << "] : " << _ideas[i] << std::endl;
}

void Brain::showIdeasUpTo(int up_to) const {
  int num = (up_to > _kMaxCnt) ? _kMaxCnt : up_to;
  for (int i = 0; i < num; i++)
    std::cout << "ideas[" << i << "] : " << _ideas[i] << std::endl;
}
