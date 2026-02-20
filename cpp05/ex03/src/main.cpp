#include <cstdlib>
#include <iostream>

#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	AForm *a;
	AForm *b;
	AForm *c;

	cout << endl;

	Intern Arnaldo;

	a = Arnaldo.makeForm("robotomy request", "EVIL");
	cout << endl;
	b = Arnaldo.makeForm("presidential pardon", "EVIL");
	cout << endl;
	c = Arnaldo.makeForm("shrubbery creation", "EVIL");
	cout << endl;

	Arnaldo.makeForm("Dude", "EVIL");
	cout << endl;

	delete a;
	delete b;
	delete c;
	return EXIT_SUCCESS;
}