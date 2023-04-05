#include <iostream>
#include <string>

class myClass
{
public:
	myClass();
};

myClass::myClass(void)
{
	std::cout << "before throwing\n";
	throw (1);
	std::cout << "after throwing\n";
	throw (2);
}

int	main(void)
{
	try {
		myClass myclass;
	}
	catch (int code) {
		std::cout << "error code : " << code << "\n";
	}
	std::cout << "after try-catch\n";
}