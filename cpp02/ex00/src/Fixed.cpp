#include "../inc/Fixed.hpp"

const int	Fixed::_bit = 8;

Fixed::Fixed() // default constructor
{
	_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed& ref) // assignment op
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed = ref.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}