#ifndef FIXED_HPP
# define FIXED_HPP
# include <iomanip>
# include <iostream>

class Fixed
{
  private:
	int _fixed;
	static const int _bit;

  public:
	Fixed();
	Fixed(const Fixed &ref);
	Fixed &operator=(const Fixed &ref);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif