#ifndef	FIXED_HPP
# define FIXED_HPP
# include <iomanip>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
	int	_fixed;
	static const int	_bit;
	public:
	Fixed();
	Fixed(const int fix);
	Fixed(const float fl);
	Fixed(const Fixed& ref);
	Fixed& operator=(const Fixed& ref);
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif