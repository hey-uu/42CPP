#ifndef FILE_CONVERTER_HPP
# define FILE_CONVERTER_HPP

# include <iostream>
# include <fstream>
# include <sstream>

# define DEBUG_MSG_CONSTRUCTOR		"[FileConverter] : Constructor called\n"
# define DEBUG_MSG_DESTRUCTOR		"[FileConverter] : Destructor called\n"
# define ERRMSG_FILE_OPEN_FAILED	"[ERROR] Failed to open file "

class FileConverter
{
private:
	std::ifstream	fin;
	std::ofstream	fout;
	std::string		fileName;
	std::string		newFileName;
	std::string		substr;
	std::string		newSubstr;
public:
	FileConverter(
		std::string const &fileName,
		std::string const &substr, 
		std::string const &newSubstr);
	~FileConverter(void);
	void	copySame(void);
	void	convertSubstr(void);
};

#endif