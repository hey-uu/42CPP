#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
  Brain(void);
  Brain(std::string const &prefix);
  Brain(Brain const &other);
  Brain &operator=(Brain const &other);
  ~Brain(void);
  void showIdeas(void) const;
  void showIdeasUpTo(int up_to) const;

private:
  int _count;
  std::string _ideas[100];
  static const int _max_count = 100;
};

#endif