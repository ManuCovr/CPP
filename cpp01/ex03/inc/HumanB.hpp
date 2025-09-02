#ifndef	HUMANB_HPP
# define HUMANB_HPP
# include <iomanip>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon		*_wp;
public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &wp);
};

#endif