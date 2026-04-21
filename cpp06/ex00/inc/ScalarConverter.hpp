#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
# include <cctype>
# include <iomanip>
# include <string>
# include <limits>
# include <climits>
# include <cfloat>
#include <cstdlib>

# define ERROR	0
# define CHAR	1
# define INT	2
# define DOUBLE	3
# define FLOAT	4
# define NAN	5
# define INF	6
# define MINF	7

class ScalarConverter
{
private:
	ScalarConverter();
	
public:
	ScalarConverter(const ScalarConverter& ref);
	ScalarConverter& operator=(const ScalarConverter& ref);
	~ScalarConverter();

	class ErrorException: public std::exception
	{
		public:
			virtual const char	*what() const throw();

	};

	static void	MinfConvert();
	static void	InfConvert();
	static void	NanConvert();
	static void	FloatConvert(std::string inp);
	static void DoubleConvert(std::string inp);
	static void	CharConvert(std::string inp);
	static void	IntConvert(std::string inp);
	static void convert(std::string inp);
	static int	typeCheck(std::string inp);
};

#endif