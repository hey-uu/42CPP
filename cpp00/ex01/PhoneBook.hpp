#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"
#include "phonebook_constants.hpp"

namespace phonebook {
class PhoneBook {
private:
  Contact _contacts[8];
  int _lastIdx;
  int _count;
  void _printErr(int errCode) const;

public:
  PhoneBook(void);
  void getCommand(std::string &command) const;
  void showMenu(void) const;
  void showSummary(void) const;
  void exit(void) const;
  void add(void);
  void search(void) const;
  void extra(void) const;
};
} // namespace phonebook

#endif
