#include <cstdlib>
#include <iostream>

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Bureaucrat hermano("Hermano", LOWEST_GRADE);

	Bureaucrat EVIL("EVIL", HIGHEST_GRADE);
	cout << endl;

	cout << endl;
	ShrubberyCreationForm scf("EVIL");
	PresidentialPardonForm ppf("EVIL");
	RobotomyRequestForm rrf("EVIL");
	cout << endl;

	EVIL.executeForm(scf);
	scf.beSigned(EVIL);
	EVIL.executeForm(scf);

	cout << endl;

	EVIL.executeForm(ppf);
	ppf.beSigned(EVIL);
	EVIL.executeForm(ppf);

	cout << endl;

	EVIL.executeForm(rrf);
	rrf.beSigned(EVIL);
	EVIL.executeForm(rrf);

	cout << endl;

	try {
		hermano.executeForm(scf);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}

	cout << endl;
	return EXIT_SUCCESS;
}