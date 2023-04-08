#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

namespace phonebook {
class Contact {
private:
  int _index;
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;
  std::string _summaryInfo[3];

public:
  Contact(void);
  void initialize(int index, std::string contactInfo[5]);
  void showSummary(void) const;
  void showInfo(void) const;
  static void getContactInput(std::string contactInfo[5]);
};
} // namespace phonebook

#endif
