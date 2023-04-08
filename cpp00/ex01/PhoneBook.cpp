#include "PhoneBook.hpp"

#include "stream_utils.hpp"

/** PUBLIC **/
phonebook::PhoneBook::PhoneBook(void) : _lastIdx(-1), _count(0) {}

void phonebook::PhoneBook::showMenu(void) const {
  std::cout << banner::start;
  std::cout << instruct::get_command;
  std::cout << prompt::type1 << std::flush;
}

void phonebook::PhoneBook::terminate(void) const {
  std::cout << banner::terminate;
  std::cout << instruct::terminate << std::endl;
  exit(0);
}

void phonebook::PhoneBook::add(void) {
  std::string contactInfo[5];

  Contact::getContactInput(contactInfo);
  _lastIdx = (_lastIdx + 1) & 7;
  _contacts[_lastIdx].initialize(contactInfo);
  if (_count < 8) _count++;
}

void phonebook::PhoneBook::search(void) const {
  int idx;

  showSummary();
  while (1) {
    std::cout << instruct::search << std::flush;
    std::cin >> idx;
    checkEOF(std::cin);
    if (std::cin.fail() == true)
      _printErr(err::kNotNumber);
    else if (idx < -1 || idx >= _count)
      _printErr(err::kOutOfRange);
    else
      break;
    inBuffClear(std::cin);
  }
  inBuffClear(std::cin);
  if (idx == -1) return;
  _contacts[idx].showInfo();
}

void phonebook::PhoneBook::extra(void) const {
  _printErr(err::kUnavailableCmd);
}

void phonebook::PhoneBook::showSummary(void) const {
  std::cout << banner::info << info_table::top;
  for (int i = 0; i < _count; i++) {
    std::cout << info_table::left_indent;
    _contacts[i].showSummary();
    if (i != _count - 1) std::cout << info_table::middle_line;
  }
  std::cout << info_table::end_line << std::endl;
}

/** PRIVATE **/
void phonebook::PhoneBook::_printErr(int errCode) const {
  std::cerr << err::message[errCode] << std::endl << std::endl;
}
