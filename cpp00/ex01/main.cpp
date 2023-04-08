#include "PhoneBook.hpp"
#include "stream_utils.hpp"

int main(void) {
  phonebook::PhoneBook phoneBook;
  std::string command;

  try {
    while (1) {
      phoneBook.showMenu();
      phoneBook.getCommand(command);
      if (command == phonebook::cmd::kExit)
        phoneBook.exit();
      else if (command == phonebook::cmd::add)
        phoneBook.add();
      else if (command == phonebook::cmd::kSearch)
        phoneBook.search();
      else
        phoneBook.extra();
    }
  } catch (std::exception &e) {
    std::cout << phonebook::instruct::kEOFDetected;
    phoneBook.exit();
  }
}
