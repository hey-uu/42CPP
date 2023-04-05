#include "FileConverter.hpp"

FileConverter::FileConverter(
	std::string const &fileName, 
	std::string const &substr, 
	std::string const &newSubstr)
	:	fileName(fileName), newFileName(fileName + ".replace"), 
		substr(substr), newSubstr(newSubstr)
{
	fin.open(fileName);
	if (!fin.is_open())
		throw (ERRMSG_FILE_OPEN_FAILED + fileName);
	fout.open(newFileName);
	if (!fout.is_open())
		throw (ERRMSG_FILE_OPEN_FAILED + newFileName);
	std::cerr << DEBUG_MSG_CONSTRUCTOR;
}

FileConverter::~FileConverter(void)
{
	std::cerr << DEBUG_MSG_DESTRUCTOR;
}

void	FileConverter::copySame(void)
{
	std::stringstream	buf;
	std::string			content;

	buf << fin.rdbuf();
	content = buf.str();
	fout << content;
}

void	FileConverter::convertSubstr(void)
{
	if (substr == newSubstr) {
		copySame();
		return ;
	}

	std::stringstream	buf;
	std::string			content, newContent;
	size_t				startPos, foundPos;

	buf << fin.rdbuf();
	content = buf.str();
	startPos = 0;
	while (startPos < content.length()) {
		foundPos = content.find(substr, startPos);
		newContent.append(content, startPos, foundPos - startPos);
		if (foundPos == std::string::npos) break ;
		newContent.append(newSubstr);
		startPos = foundPos + substr.length();
	}
	fout << newContent;
}