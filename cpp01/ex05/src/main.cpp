#include "../inc/Harl.hpp"

int	main()
{
	Harl	harl;
	std::string test;
	std::cout << "Welcome to Harl's complain center!" << std::endl << "Type a level of the complain you want to make (DEBUG, INFO, WARNING or ERROR): ";
	while (std::cin >> test)
	{
		harl.complain(test);
		std::cout << "type the level of the complain you want to make (DEBUG, INFO, WARNING or ERROR): ";
	}
}