#include "../inc/Bureaucrat.hpp"

int	main()
{
	Bureaucrat	teste("GOAT", 2);
	std::cout << "BUREAUCRAT INFO: " << teste << std::endl;
	try
	{
		Bureaucrat	vegeta("Vegeta", 1);
		std::cout << std::endl;
		std::cout << "BUREAUCRAT INFO: " << vegeta << std::endl;
		Bureaucrat	goku("Goku", 150);
		std::cout << std::endl;
		std::cout << "BUREAUCRAT INFO: " << goku << std::endl;
		Bureaucrat	bulma("Bulma", 149);
		std::cout << std::endl;
		std::cout << "BUREAUCRAT INFO: " << bulma << std::endl;
		bulma.downGrade();
		std::cout << std::endl;
		std::cout << "BUREAUCRAT INFO: " << bulma << std::endl;
		teste.upGrade();
		std::cout << "BUREAUCRAT INFO: " << teste << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid Bureaucrat grade: " << e.what() << std::endl;
	}
}