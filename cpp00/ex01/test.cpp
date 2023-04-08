#include <iostream>
#include <sstream>

int	main(void)
{
	std::string str;
	std::getline(std::cin, str);
	std::stringstream	ss(str);
	int idx;
	std::string str2;
	ss >> idx >> str2;
	std::cout << "idx : " << idx << std::endl;
	std::cout << "str2 : " << str2 << std::endl;
	std::cout << "atoi : " << std::atoi(str.c_str()) << std::endl;
}
