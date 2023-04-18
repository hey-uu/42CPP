#ifndef DEBUG_MSG_HPP
#define DEBUG_MSG_HPP

#include <string>

namespace debug {
void printAMateria(void);
void printCharacter(void);
void printCure(void);
void printIce(void);
void printMateriaSource(void);
void debugMsg(int num);

const int kWidth = 20;
enum eState {
  kDefaultConstructor,
  kStringConstructor,
  kCopyConstructor,
  kAssignOperator,
  kDestructor
};

const std::string kMsg[5] = {"Default Constructor Called",
                             "String Constructor Called",
                             "Copy Constructor Called",
                             "Assignment Operator Called", "Destructor Called"};
} // namespace debug

#endif