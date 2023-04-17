#include "IMateriaSource.hpp"
#include <iostream>
#include "debug_msg.hpp"

IMateriaSource::IMateriaSource(void) {
  debug::printIMateriaSource();
  debug::debugMsg(debug::kDefaultConstructor);
}

IMateriaSource::IMateriaSource(IMateriaSource const &other) {
  debug::printIMateriaSource();
  debug::debugMsg(debug::kCopyConstructor);
  (void) other;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other) {
  debug::printIMateriaSource();
  debug::debugMsg(debug::kAssignOperator);
  (void) other;
  return (*this);
}

IMateriaSource::~IMateriaSource(void) {
  debug::printIMateriaSource();
  debug::debugMsg(debug::kDestructor);
}
