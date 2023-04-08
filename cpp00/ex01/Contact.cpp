#include "PhoneBook.hpp"
#include "stream_utils.hpp"

phonebook::Contact::Contact(void) {}

void phonebook::Contact::initialize(std::string contactInfo[5]) {
  _firstName = contactInfo[0];
  _lastName = contactInfo[1];
  _nickname = contactInfo[2];
  _phoneNumber = contactInfo[3];
  _darkestSecret = contactInfo[4];
  for (int i = 0; i < 4; i++) {
    if (contactInfo[i].length() >= 10)
      _summaryInfo[i] = contactInfo[i].substr(0, 10).replace(9, 1, ".");
    else
      _summaryInfo[i] = contactInfo[i];
  }
}

void phonebook::Contact::showInfo() const {
  std::cout << banner::specfic_info;
  std::cout << prompt::type3 << info_type::first_name << _firstName << "\n";
  std::cout << prompt::type3 << info_type::last_name << _lastName << "\n";
  std::cout << prompt::type3 << info_type::nickname << _nickname << "\n";
  std::cout << prompt::type3 << info_type::phone_number << _phoneNumber << "\n";
  std::cout << prompt::type3 << info_type::darkest_secret << _darkestSecret
            << "\n";
  std::cout << line::double_solid;
  std::cout << std::endl;
}

void phonebook::Contact::showSummary() const {
  std::cout << info_table::separator;
  for (int i = 0; i < 4; i++) {
    std::cout << std::setw(10) << std::right << _summaryInfo[i];
    std::cout << info_table::separator;
  }
  std::cout << std::endl;
}

bool phonebook::Contact::getContactInput(std::string contactInfo[5]) {
  std::cout << "\n" << instruct::get_contact_info;
  for (int i = 0; i < 5; i++) {
    std::cout << prompt::type2 << info_type::all[i] << std::flush;
    std::getline(std::cin, contactInfo[i]);
    checkEOF(std::cin);
  }
  return (true);
}
