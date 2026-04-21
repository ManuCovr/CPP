#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	std::string	_forms[3];
public:
	Intern();
	Intern(const Intern& ref);
	Intern& operator=(const Intern& ref);
	~Intern();

	AForm*	makePresidential(std::string target);
	AForm*	makeRobotomy(std::string target);
	AForm*	makeShrubbery(std::string target);
	AForm*	makeForm(std::string form, std::string target);
};

#endif