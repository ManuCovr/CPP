#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	const std::string	_target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();

	class GradeNotExcusedException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	std::string	getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};

#endif