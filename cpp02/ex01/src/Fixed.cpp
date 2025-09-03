#include "../inc/Fixed.hpp"

const int	Fixed::_bit = 8;

Fixed::Fixed()
{
	_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const int fix)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(fix << _bit); // convert int to fixed point by shifting left bits
}

Fixed::Fixed(const float fl)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(fl * (1 << _bit))); 
}

Fixed	&Fixed::operator=(const Fixed &ref)
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
	return _fixed;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float	Fixed::toFloat() const
{
	return ((float)getRawBits() / (1 << _bit));
}

int		Fixed::toInt() const
{
	return (getRawBits() >> _bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}