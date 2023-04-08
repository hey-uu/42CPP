#ifndef PHONEBOOK_CONSTANTS_HPP
#define PHONEBOOK_CONSTANTS_HPP

namespace phonebook {
namespace cmd {
const std::string exit = "EXIT";
const std::string add = "ADD";
const std::string search = "SEARCH";
}  // namespace cmd

namespace err {
enum ePhoneBookErrCode { kNotNumber, kOutOfRange, kUnavailableCmd };

const std::string message[3] = {
    "\n [ERROR] : Index has wrong value",
	"\n [ERROR] : Index is out of range",
    "\n [ERR0R] : Unavailable command. Enter again."};
}  // namespace err

namespace prompt {
const std::string type1 = " > ";
const std::string type2 = "   >> ";
const std::string type3 = " + ";
}  // namespace prompt

namespace instruct {
const std::string search =
    " * Enter index of the entry to display.\n"
    "   Enter -1 if you want to stop.         : ";
const std::string get_command =
    " * Please choose a command from the following options:\n"
    "   (ADD, SEARCH, EXIT)\n";
const std::string terminate = " * Thanks for using our service.\n";
const std::string get_contact_info = " * Enter Information for new contact.\n";
const std::string eof_detected =
    "\n\n [EOF] The program detected the end of the file.\n";
}  // namespace instruct

namespace banner {
const std::string start =
    "\n"
    "==============================================================\n"
    "                     Phone Book Service!                      \n"
    "==============================================================\n";
const std::string terminate =
    "\n"
    "==============================================================\n"
    "                          Good Bye!\n"
    "==============================================================\n";
const std::string info =
    "\n"
    "==============================================================\n"
    "                    Phone Book Information\n"
    "==============================================================\n";
const std::string specfic_info =
    "\n"
    "==============================================================\n"
    "                     Specific Information                     \n"
    "==============================================================\n";
}  // namespace banner

namespace line {
const std::string double_solid =
    "==============================================================\n";
}

namespace info_table {
const std::string top =
    "         +-------------------------------------------+\n"
    "         |  index   |first name|last name | nickname |\n"
    "         |----------+----------+----------+----------|\n";
const std::string left_indent = "         ";
const std::string middle_line =
    "         |----------+----------+----------+----------|\n";
const std::string end_line =
    "         +-------------------------------------------+\n";
const std::string separator = "|";
}  // namespace info_table

namespace info_type {
const std::string first_name = "First Name : ";
const std::string last_name = "Last Name : ";
const std::string nickname = "Nickname : ";
const std::string phone_number = "Phone Number : ";
const std::string darkest_secret = "Darkest Secret : ";
const std::string all[5] = {first_name, last_name, nickname, phone_number,
                            darkest_secret};
}  // namespace info_type
}  // namespace phonebook

#endif