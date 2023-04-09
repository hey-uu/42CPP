#ifndef FILE_CONVERTER_HPP
#define FILE_CONVERTER_HPP

#include <fstream>
#include <iostream>
#include <sstream>

#define DEBUG_MSG_CONSTRUCTOR "[FileConverter] : Constructor called\n"
#define DEBUG_MSG_DESTRUCTOR "[FileConverter] : Destructor called\n"
#define ERRMSG_EMPTY_STRING "[ERROR] : Empty string"
#define ERRMSG_FILE_OPEN_FAILED "[ERROR] Failed to open file "

class FileConverter {
 private:
  std::ifstream _fin;
  std::ofstream _fout;
  std::string _name;
  std::string _newName;
  std::string _substr;
  std::string _newSubstr;
  void (FileConverter::*_fptr)(void);
  void copySame(void);
  void convertSubstr(void);

 public:
  FileConverter(std::string const& name,
                std::string const& substr,
                std::string const& newSubstr);
  ~FileConverter(void);
  void copy(void);
};

#endif