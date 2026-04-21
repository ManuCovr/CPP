#include "../inc/ScalarConverter.hpp"

// Copy constructor 
ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
}

// Assignment operator
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& ref)
{
	(void)ref;
	return *this;
}

const char	*ScalarConverter::ErrorException::what() const throw()
{
	return "Error found with the argument";
}

ScalarConverter::~ScalarConverter(){}

// Entry point: detects the type of the input and dispatches to the correct conversion function
void	ScalarConverter::convert(std::string inp)
{
	int i = typeCheck(inp);
	switch (i)
	{
	case 0:
		throw ErrorException();
		break;
	case 1:
		CharConvert(inp);
		break;
	case 2:
		IntConvert(inp);
		break;
	case 3:
		DoubleConvert(inp);
		break;
	case 4:
		FloatConvert(inp);
		break;
	case 5:
		NanConvert();
		break;
	case 6:
		InfConvert();
		break;
	case 7:
		MinfConvert();
		break;
	default:
		break;
	}
}

// Special literal: nan - all numeric conversions are impossible
void	ScalarConverter::NanConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

// Special literal: +inf - all numeric conversions are impossible
void	ScalarConverter::InfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

// Special literal: -inf - all numeric conversions are impossible
void	ScalarConverter::MinfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

// Input is a single non-digit character - cast directly to other types
void	ScalarConverter::CharConvert(std::string inp)
{
	char tmp = inp[0];

	if (!isprint(tmp))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << tmp << std::endl;
	std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

// Input is an integer
// Throws if value overflows int range
void	ScalarConverter::IntConvert(std::string inp)
{
	char		*end;
	long int	tmp = strtol(inp.c_str(), &end, 10);

	if (*end != '\0') // strtol sets end to first invalid char - if not null terminator, input is bad
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		throw ErrorException();
	if (!isprint(static_cast<int>(tmp)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(tmp) << std::endl;
	std::cout << "int: " << tmp << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

// Input is a float (ends with 'f') - parse as double via strtod, then cast
// lowest() not available in C++98, so use -max() for the lower bound check
void	ScalarConverter::FloatConvert(std::string inp)
{
	char	*end;
	double	tmp = strtod(inp.c_str(), &end);

	if (*end != '\0' && *end != 'f') // allow trailing 'f' for float literals like "1.5f"
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	if (tmp < -std::numeric_limits<float>::max() || tmp > std::numeric_limits<float>::max())
		throw ErrorException();
	if (tmp < std::numeric_limits<char>::min() || tmp > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(tmp);
		if (!isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << tmp << std::endl;
}

// Input is a double - parse as long double via strtold for maximum precision, then cast down
void	ScalarConverter::DoubleConvert(std::string inp)
{
	char		*end;
	long double	tmp = strtold(inp.c_str(), &end);

	if (*end != '\0')
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	if (tmp < -std::numeric_limits<double>::max() || tmp > std::numeric_limits<double>::max())
		throw ErrorException();
	if (tmp < std::numeric_limits<char>::min() || tmp > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(tmp);
		if (!isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	if (tmp < -std::numeric_limits<float>::max() || tmp > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

// Detects the type of the input string and returns an enum value
// Order matters: check special literals before numeric formats
int		ScalarConverter::typeCheck(std::string inp)
{
	if (inp.empty())
		return ERROR;
	// Single non-digit char (e.g. 'a', '+', '.')
	if (inp.length() == 1 && !isdigit(inp[0]))
		return CHAR;
	else if (inp == "nan" || inp == "nanf")
		return NAN;
	else if (inp == "-inf" || inp == "-inff")
		return MINF;
	else if (inp.compare("+inf") <= 0 || inp.compare("+inff") <= 0)
		return INF;
	// Only digits and optional leading +/- -> INT
	else if (inp.length() > 0 && inp.find_first_not_of("+-0123456789") == std::string::npos)
	{
		if (inp[0] == '+' || inp[0] == '-')
		{
			if (inp.length() == 1 || inp.find_first_not_of("0123456789", 1) != std::string::npos)
				return ERROR;
		}
		else
		{
			if (inp.find_first_not_of("0123456789") != std::string::npos)
				return ERROR;
		}
		return INT;
	}
	// Digits and a single dot -> DOUBLE (e.g. "1.5")
	else if (inp.length() > 0 && inp.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (inp[0] == '+' || inp[0] == '-')
		{
			if (inp.length() == 1 || inp.find_first_not_of("0123456789.", 1) != std::string::npos)
				return ERROR;
		}
		if (inp.find_first_of(".") != inp.find_last_of(".")) // reject multiple dots
			return ERROR;
		if (inp[inp.size() - 1] == '.' || inp[0] == '.') // reject leading/trailing dot
			return ERROR;
		return DOUBLE;
	}
	// Digits, a dot, and trailing 'f' -> FLOAT (e.g. "1.5f")
	else if (inp.length() > 0 && inp.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (inp[0] == '+' || inp[0] == '-')
		{
			if (inp.length() == 1 || inp.find_first_not_of("0123456789.f", 1) != std::string::npos)
				return ERROR;
		}
		if (inp.find_first_of(".") != inp.find_last_of(".")) // reject multiple dots
			return ERROR;
		if (inp.find_first_of("f") != inp.find_last_of("f")) // reject multiple f's
			return ERROR;
		if (inp[inp.size() - 1] != 'f' || inp.find('.') == std::string::npos) // must end in 'f' and have a dot
			return ERROR;
		return FLOAT;
	}
	return ERROR;
}