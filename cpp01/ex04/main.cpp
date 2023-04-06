#include "FileConverter.hpp"

#define ERRMSG_WRONG_ARGS "[ERROR] Arguments must be '<filename> <string1> <string2>'"

int	main(int argc, char **argv)
{
	try {
		if (argc != 4)
			throw (ERRMSG_WRONG_ARGS);
		FileConverter	converter(argv[1], argv[2], argv[3]);
		converter.convertSubstr();
	}
	catch (char const *errMsg) {
		std::cerr << errMsg << "\n";
	}
	catch (std::string const errMsg) {
		std::cerr << errMsg << "\n";
	}
}
