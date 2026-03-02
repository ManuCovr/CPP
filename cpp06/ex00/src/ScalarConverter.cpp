#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& ref)
{
	return *this;
}

const char	*ScalarConverter::ErrorException::what() const throw()
{
	return "Error found with the argument";
}

ScalarConverter::~ScalarConverter(){}

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

void	ScalarConverter::NanConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	ScalarConverter::InfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void	ScalarConverter::MinfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

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

void	ScalarConverter::IntConvert(std::string inp)
{
	long int	tmp;
	try
	{
		tmp = std::stol(inp);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		throw ErrorException();
	if (!isprint(tmp))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(tmp) << std::endl;
	std::cout << "int: " << tmp << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

void	ScalarConverter::FloatConvert(std::string inp)
{
	double	tmp;
	try
	{
		tmp  = std::stod(inp);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (tmp < std::numeric_limits<float>::lowest() || tmp > std::numeric_limits<float>::max())
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

void	ScalarConverter::DoubleConvert(std::string inp)
{
	long double	tmp;
	try
	{
		tmp  = std::stold(inp);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (tmp < std::numeric_limits<double>::lowest() || tmp > std::numeric_limits<double>::max())
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
	if (tmp < std::numeric_limits<float>::lowest() || tmp > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << tmp << std::endl;
}

int		ScalarConverter::typeCheck(std::string inp)
{
	if (inp.empty())
		return ERROR;
	if (inp.length() == 1 && !isdigit(inp[0]))
		return CHAR;
	else if (inp == "nan" || inp == "nanf")
		return NAN;
	else if (inp == "-inf" || inp == "-inff")
		return MINF;
	else if (inp.compare("+inf") <= 0 || inp.compare("+inff") <= 0)
		return INF;
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
	else if (inp.length() > 0 && inp.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (inp[0] == '+' || inp[0] == '-')
		{
			if (inp.length() == 1 || inp.find_first_not_of("0123456789.", 1) != std::string::npos)
				return ERROR;
		}
		if (inp.find_first_of(".") != inp.find_last_of("."))
			return ERROR;
		if (inp.back() == '.' || inp.front() == '.')
			return ERROR;
		return DOUBLE;
	}
	else if (inp.length() > 0 && inp.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (inp[0] == '+' || inp[0] == '-')
		{
			if (inp.length() == 1 || inp.find_first_not_of("0123456789.f", 1) != std::string::npos)
				return ERROR;
		}
		if (inp.find_first_of(".") != inp.find_last_of("."))
			return ERROR;
		if (inp.find_first_of("f") != inp.find_last_of("f"))
			return ERROR;
		if (inp.back() != 'f' || inp.find('.') == std::string::npos)
			return ERROR;
		return FLOAT;
	}
	return ERROR;
}

