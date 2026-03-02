#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	const std::string	_target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	std::string	getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};

#endif