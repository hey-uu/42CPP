#include "PhoneBook.hpp"

#include "stream_utils.hpp"
#include <sstream>

/** PUBLIC **/
phonebook::PhoneBook::PhoneBook(void) : _lastIdx(-1), _count(0)
{
}

void phonebook::PhoneBook::showMenu(void) const
{
    std::cout << banner::kStart;
    std::cout << instruct::kGetCommand;
}

void phonebook::PhoneBook::getCommand(std::string &command) const
{
    command.clear();
    while (1)
    {
        std::cout << prompt::kType1 << std::flush;
        std::getline(std::cin, command);
        utils::checkEOF(std::cin);
        if (command.find_first_not_of(" \n\f\r\t\v") != std::string::npos)
            break;
    }
}

void phonebook::PhoneBook::showSummary(void) const
{
    std::cout << banner::info << info_table::kTop;
    for (int i = 0; i < _count; i++)
    {
        std::cout << info_table::kLeftIndent;
        _contacts[i].showSummary();
        if (i != _count - 1)
            std::cout << info_table::kMiddleLine;
    }
    std::cout << info_table::kEndLine << std::endl;
}

void phonebook::PhoneBook::add(void)
{
    std::string contactInfo[5];

    Contact::getContactInput(contactInfo);
    _lastIdx = (_lastIdx + 1) & 7;
    _contacts[_lastIdx].initialize(_lastIdx, contactInfo);
    if (_count < 8)
        _count++;
}

void phonebook::PhoneBook::search(void) const
{
    std::stringstream sStream;
    std::string sIdx;
    int idx;

    showSummary();
    while (1)
    {
        std::cout << instruct::kSearch << std::flush;
        std::getline(std::cin, sIdx);
        utils::checkEOF(std::cin);
        sStream.str(sIdx);
        sStream >> idx;
std::cout << "idx : " << idx << std::endl;
        if (sStream.fail() == true || sStream.eof() == false)
            _printErr(err::kNotNumber);
        else if (idx < -1 || idx >= _count)
            _printErr(err::kOutOfRange);
        else
            break;
        sStream.clear();
    }
    if (idx == -1)
        return;
    _contacts[idx].showInfo();
}

void phonebook::PhoneBook::exit(void) const
{
    std::cout << banner::kExit;
    std::cout << instruct::kExit << std::endl;
    std::exit(0);
}

void phonebook::PhoneBook::extra(void) const
{
    _printErr(err::kUnavailableCmd);
}

/** PRIVATE **/
void phonebook::PhoneBook::_printErr(int errCode) const
{
    std::cerr << err::kMessage[errCode] << std::endl << std::endl;
}
