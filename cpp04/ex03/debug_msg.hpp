#ifndef DEBUG_MSG_HPP
#define DEBUG_MSG_HPP

#include <string>

namespace debug {
void printAMateria(void);
void printCharacter(void);
void printCure(void);
void printIce(void);
void printICharacter(void);
void printIMateriaSource(void);
void printMateriaSource(void);
void debugMsg(int num);
} // namespace debug

namespace debug {
const int kWidth = 20; 
enum eState {
  kDefaultConstructor,
  kStringConstructor,
  kCopyConstructor,
  kAssignOperator,
  kDestructor
};
}

namespace debug {
const std::string kMsg[5] = {"Default Constructor Called",
                             "String Constructor Called",
                             "Copy Constructor Called",
                             "Assignment Operator Called", "Destructor Called"};
}

#endif