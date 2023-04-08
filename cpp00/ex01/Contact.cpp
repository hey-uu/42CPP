#include "PhoneBook.hpp"
#include "stream_utils.hpp"

phonebook::Contact::Contact(void) {}

void phonebook::Contact::initialize(int index, std::string contactInfo[5]) {
  _index = index;
  _firstName = contactInfo[0];
  _lastName = contactInfo[1];
  _nickname = contactInfo[2];
  _phoneNumber = contactInfo[3];
  _darkestSecret = contactInfo[4];
  for (int i = 0; i < 3; i++) {
    if (contactInfo[i].length() >= 10)
      _summaryInfo[i] = contactInfo[i].substr(0, 10).replace(9, 1, ".");
    else
      _summaryInfo[i] = contactInfo[i];
  }
}

void phonebook::Contact::showInfo() const {
  std::cout << banner::kSpecficInfo;
  std::cout << prompt::kType3 << info_type::kFirstName << _firstName << "\n";
  std::cout << prompt::kType3 << info_type::kLastName << _lastName << "\n";
  std::cout << prompt::kType3 << info_type::kNickname << _nickname << "\n";
  std::cout << prompt::kType3 << info_type::kPhoneNumber << _phoneNumber
            << "\n";
  std::cout << prompt::kType3 << info_type::kDarkestSecret << _darkestSecret
            << "\n";
  std::cout << line::kDoubleSolid;
  std::cout << std::endl;
}

void phonebook::Contact::showSummary() const {
  std::cout << info_table::kSeparator;
  std::cout << std::setw(10) << std::right << _index;
  std::cout << info_table::kSeparator;
  for (int i = 0; i < 3; i++) {
    std::cout << std::setw(10) << std::right << _summaryInfo[i];
    std::cout << info_table::kSeparator;
  }
  std::cout << std::endl;
}

void phonebook::Contact::getContactInput(std::string contactInfo[5]) {
  std::cout << "\n" << instruct::kGetContactInfo;
  for (int i = 0; i < 5; i++) {
    while (1) {
      std::cout << prompt::kType2 << info_type::kAll[i] << std::flush;
      std::getline(std::cin, contactInfo[i]);
      utils::checkEOF(std::cin);
      if (contactInfo[i].find_first_not_of(" \n\f\r\t\v") != std::string::npos)
        break ;
    }
  }
}
