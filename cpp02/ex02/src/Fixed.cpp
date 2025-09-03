#include "../inc/Fixed.hpp"

const int	Fixed::_bit = 8;

Fixed::Fixed()
{
	_fixed = 0;
}

Fixed::Fixed(const Fixed& ref)
{
	*this = ref;
}

Fixed::Fixed(const int fix)
{
	setRawBits(fix << _bit);
}

Fixed::Fixed(const float fl)
{
	setRawBits(roundf(fl * (1 << _bit)));
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	_fixed = ref.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

Fixed	Fixed::operator+(const Fixed& ref) const
{
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed	Fixed::operator-(const Fixed& ref) const
{
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed	Fixed::operator*(const Fixed& ref) const
{
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed	Fixed::operator/(const Fixed& ref) const
{
	return Fixed(this->toFloat() / ref.toFloat());
}

bool		Fixed::operator>(const Fixed& ref) const
{
	return (_fixed > ref._fixed);
}

bool		Fixed::operator<(const Fixed& ref) const
{
	return (_fixed < ref._fixed);
}

bool		Fixed::operator>=(const Fixed& ref) const
{
	return (_fixed >= ref._fixed);
}

bool		Fixed::operator<=(const Fixed& ref) const
{
	return (_fixed <= ref._fixed);
}

bool		Fixed::operator==(const Fixed& ref) const
{
	return (_fixed == ref._fixed);
}

bool		Fixed::operator!=(const Fixed& ref) const
{
	return (_fixed != ref._fixed);
}

Fixed&	Fixed::operator++()
{
	_fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int nb)
{
	(void)nb;
	Fixed tp(this->toFloat());
	_fixed++;
	return tp;
}

Fixed&	Fixed::operator--()
{
	_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int nb)
{
	(void)nb;
	Fixed tp(this->toFloat());
	_fixed--;
	return tp;
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	return ref2;
}

Fixed const &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	return ref2;
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	return ref2;
}

Fixed const &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	return ref2;
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