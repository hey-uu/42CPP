#ifndef PHONEBOOK_CONSTANTS_HPP
#define PHONEBOOK_CONSTANTS_HPP

namespace phonebook
{
namespace cmd
{
const std::string kExit = "EXIT";
const std::string add = "ADD";
const std::string kSearch = "SEARCH";
} // namespace cmd

namespace err
{
enum ePhoneBookErrCode
{
    kNotNumber,
    kOutOfRange,
    kUnavailableCmd
};

const std::string kMessage[3] = {"\n [ERROR] : Index has wrong value", "\n [ERROR] : Index is out of range",
                                 "\n [ERR0R] : Unavailable command. Enter again."};
} // namespace err

namespace prompt
{
const std::string kType1 = " > ";
const std::string kType2 = "   >> ";
const std::string kType3 = " + ";
} // namespace prompt

namespace instruct
{
const std::string kSearch = " * Enter index of the entry to display.\n"
                            "   Enter -1 if you want to stop.         : ";
const std::string kGetCommand = " * Please choose a command from the following options:\n"
                                "   (ADD, SEARCH, EXIT)\n";
const std::string kExit = " * Thanks for using our service.\n";
const std::string kGetContactInfo = " * Enter Information for new contact.\n";
const std::string kEOFDetected = "\n\n [EOF] The program detected the end of the file.\n";
} // namespace instruct

namespace banner
{
const std::string kStart = "\n"
                           "==============================================================\n"
                           "                     Phone Book Service!                      \n"
                           "==============================================================\n";
const std::string kExit = "\n"
                          "==============================================================\n"
                          "                          Good Bye!\n"
                          "==============================================================\n";
const std::string info = "\n"
                         "==============================================================\n"
                         "                    Phone Book Information\n"
                         "==============================================================\n";
const std::string kSpecficInfo = "\n"
                                 "==============================================================\n"
                                 "                     Specific Information                     \n"
                                 "==============================================================\n";
} // namespace banner

namespace line
{
const std::string kDoubleSolid = "==============================================================\n";
}

namespace info_table
{
const std::string kTop = "         +-------------------------------------------+\n"
                         "         |  index   |first name|last name | nickname |\n"
                         "         |----------+----------+----------+----------|\n";
const std::string kLeftIndent = "         ";
const std::string kMiddleLine = "         |----------+----------+----------+----------|\n";
const std::string kEndLine = "         +-------------------------------------------+\n";
const std::string kSeparator = "|";
} // namespace info_table

namespace info_type
{
const std::string kFirstName = "First Name : ";
const std::string kLastName = "Last Name : ";
const std::string kNickname = "Nickname : ";
const std::string kPhoneNumber = "Phone Number : ";
const std::string kDarkestSecret = "Darkest Secret : ";
const std::string kAll[5] = {kFirstName, kLastName, kNickname, kPhoneNumber, kDarkestSecret};
} // namespace info_type
} // namespace phonebook

#endif