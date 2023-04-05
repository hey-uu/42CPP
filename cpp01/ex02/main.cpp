#include <iostream>

int	main(void)
{
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "the memory address of the string variable: " << &stringVAR << "\n";
	std::cout << "the memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "the memory address held by stringREF: " << &stringREF << "\n";
	
	std::cout << "the value of the string variable: " << stringVAR << "\n";
	std::cout << "the value pointed to by stringPTR: " << *stringPTR << "\n";
	std::cout << "the value pointed to by stringREF: " << stringREF << "\n";
}