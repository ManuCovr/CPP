#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	const std::string	_target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	std::string	getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};

#endif