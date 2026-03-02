#ifndef	FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_gradeSign;
	const int			_gradeExe;
	Form();

public:
	Form(std::string name, int gradeSign, int gradeExe);
	Form(const Form& ref);
	Form& operator=(const Form& ref);
	~Form();

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

	void	beSigned(const Bureaucrat& dude);

	std::string	getName() const;
	bool		getSign() const;
	int			getGradeSign() const;
	int			getGradeExe() const;
};

std::ostream&	operator<<(std::ostream& out, const Form& ref);

#endif