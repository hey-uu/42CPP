#include "PhoneBook.hpp"
#include "stream_utils.hpp"

int main(void) {
  phonebook::PhoneBook phoneBook;
  std::string command;

  try {
    while (1) {
      phoneBook.showMenu();
      std::getline(std::cin, command);
      checkEOF(std::cin);
      if (command == phonebook::cmd::exit)
        phoneBook.terminate();
      else if (command == phonebook::cmd::add)
        phoneBook.add();
      else if (command == phonebook::cmd::search)
        phoneBook.search();
      else
        phoneBook.extra();
    }
  } catch (std::exception &e) {
    std::cout << phonebook::instruct::eof_detected;
    phoneBook.terminate();
  }
}
