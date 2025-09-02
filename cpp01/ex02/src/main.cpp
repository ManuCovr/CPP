#include <iostream>

int	main()
{
	std::string original = "HI THIS IS BRAIN";
	std::string *stringPTR = &original;
	std::string &stringREF = original;

	std::cout << "• The memory address of original: " << &original << std::endl;
	std::cout << "• The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "• The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "• The value of original: " << original << std::endl;
	std::cout << "• The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "• The value pointed to by stringREF: " << stringREF << std::endl;
}