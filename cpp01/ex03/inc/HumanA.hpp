#ifndef	HUMANA_HPP
# define HUMANA_HPP
# include <iomanip>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon		&_wp;
public:
	HumanA(std::string name, Weapon &wp);
	~HumanA();

	void	attack();
};

#endif