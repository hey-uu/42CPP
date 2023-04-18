#include "debug_msg.hpp"
#include <iomanip>
#include <iostream>

void debug::printAMateria(void) {
  std::clog << "\t";
  std::clog << std::setw(kWidth) << std::left << "| AMateria ";
  std::clog << "| ";
}

void debug::printCharacter(void) {
  std::clog << "\t";
  std::clog << std::setw(kWidth) << std::left << "| Character ";
  std::clog << "| ";
}

void debug::printCure(void) {
  std::clog << "\t";
  std::clog << std::setw(kWidth) << std::left << "| Cure ";
  std::clog << "| ";
}

void debug::printIce(void) {
  std::clog << "\t";
  std::clog << std::setw(kWidth) << std::left << "| Ice ";
  std::clog << "| ";
}

void debug::printMateriaSource(void) {
  std::clog << "\t";
  std::clog << std::setw(kWidth) << std::left << "| MateriaSource ";
  std::clog << "| ";
}

void debug::debugMsg(int num) {
  std::clog << "[ DEBUG ] " << debug::kMsg[num] << std::endl;
}