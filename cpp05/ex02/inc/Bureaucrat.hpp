#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	Bureaucrat();

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat& operator=(const Bureaucrat& ref);
	~Bureaucrat();

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

	void		upGrade();
	void		downGrade();
	void		signForm(AForm& form);
	void		executeForm(AForm const & form);

	std::string	getName() const;
	int			getGrade() const;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);

#endif