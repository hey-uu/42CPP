#include <iostream>
#include <string>
#include <cctype>

#define NOISE_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << NOISE_MSG;
		return (0);
	}
	for (int i = 1 ; i < argc ; ++i) {
		std::string str = argv[i];
		for (int j = 0 ; j < str.length() ; ++j) {
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
