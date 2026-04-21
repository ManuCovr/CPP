#include "../inc/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Wrong argument number, try with only one" << std::endl;
	else
	{
		try
		{
			ScalarConverter::convert(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}