#include "../inc/Intern.hpp"

Intern::Intern()
{
	_forms[0] = "Presidential pardon";
	_forms[1] = "Robotomy request";
	_forms[2] = "Shrubbery creation";
}

Intern::Intern(const Intern& ref)
{
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref)
{
	if (this != &ref)
		for (int i = 0; i < 3; i++)
			this->_forms[i] = ref._forms[i];
	return *this;
}

Intern::~Intern(){}


AForm* Intern::makeForm(std::string form, std::string target)
{
    if (form == "presidential pardon")
    {
        std::cout << "Intern creates presidential pardon form" << std::endl;
        return new PresidentialPardonForm(target);
    }
    if (form == "robotomy request")
    {
        std::cout << "Intern creates robotomy request form" << std::endl;
        return new RobotomyRequestForm(target);
    }
    if (form == "shrubbery creation")
    {
        std::cout << "Intern creates shrubbery creation form" << std::endl;
        return new ShrubberyCreationForm(target);
    }
    std::cout << "Intern couldn't create " << form << " form, he's getting fired" << std::endl;
    return NULL;
}

