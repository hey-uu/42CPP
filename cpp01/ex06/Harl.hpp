#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

enum eLevelIdx { DEBUG, INFO, WARNING, ERROR, EXTRA };

class Harl {
 private:
  int levelIdx;
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void extra(void);
  void setLevelIdx(std::string const& level);

 public:
  Harl();
  ~Harl();
  void complain(std::string level);
  void filterComplains(std::string level);
};

#endif