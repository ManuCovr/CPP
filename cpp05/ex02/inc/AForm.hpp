#ifndef	AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	AForm();
	const std::string	_name;
	bool				_sign;
	const int			_gradeSign;
	const int			_gradeExe;

public:
	AForm(std::string name, int gradeSign, int gradeExe);
	AForm(const AForm& ref);
	AForm& operator=(const AForm& ref);
	virtual ~AForm();

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

	virtual void	beSigned(const Bureaucrat& dude);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	virtual std::string	getName() const;
	virtual bool		getSign() const;
	virtual int			getGradeSign() const;
	virtual int			getGradeExe() const;
};

std::ostream&	operator<<(std::ostream& out, const AForm& ref);

#endif