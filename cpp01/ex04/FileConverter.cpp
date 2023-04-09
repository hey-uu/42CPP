#include "FileConverter.hpp"

FileConverter::FileConverter(std::string const& name,
                             std::string const& substr,
                             std::string const& newSubstr)
    : _name(name),
      _newName(name + ".replace"),
      _substr(substr),
      _newSubstr(newSubstr) {
  std::clog << DEBUG_MSG_CONSTRUCTOR;
  if (substr.length() == 0)
    throw(ERRMSG_EMPTY_STRING);
  _fin.open(name);
  if (!_fin.is_open())
    throw(ERRMSG_FILE_OPEN_FAILED + name);
  _fout.open(_newName);
  if (!_fout.is_open())
    throw(ERRMSG_FILE_OPEN_FAILED + _newName);
  if (_substr == _newSubstr)
    _fptr = &FileConverter::copySame;
  else
    _fptr = &FileConverter::convertSubstr;
}

FileConverter::~FileConverter(void) {
  std::clog << DEBUG_MSG_DESTRUCTOR;
}

void FileConverter::copySame(void) {
  std::stringstream buf;
  std::string content;

  buf << _fin.rdbuf();
  content = buf.str();
  _fout << content;
}

void FileConverter::convertSubstr(void) {
  std::stringstream buf;
  std::string content, newContent;
  size_t startPos, foundPos;

  buf << _fin.rdbuf();
  content = buf.str();
  startPos = 0;
  while (startPos < content.length()) {
    foundPos = content.find(_substr, startPos);
    newContent.append(content, startPos, foundPos - startPos);
    if (foundPos == std::string::npos)
      break;
    newContent.append(_newSubstr);
    startPos = foundPos + _substr.length();
  }
  _fout << newContent;
}

void FileConverter::copy(void) {
  (this->*_fptr)();
}
