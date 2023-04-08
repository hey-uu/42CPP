#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

namespace phonebook {
class Contact {
 private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;
  std::string _summaryInfo[4];

 public:
  Contact(void);
  void initialize(std::string contactInfo[5]);
  static bool getContactInput(std::string contactInfo[5]);
  void showSummary(void) const;
  void showInfo(void) const;
};
}  // namespace phonebook

#endif
