#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_wp = NULL;
}

HumanB::~HumanB()
{
	std::cout << _name << " died horribly" << std::endl;
}

void	HumanB::attack()
{
	if (this->_wp == NULL)
		std::cout << _name << " is defenseless..." << std::endl;
	else
		std::cout << _name << " attacks with " << this->_wp->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wp)
{
	this->_wp = &wp;
	std::cout << _name << " grabbed a " << _wp->getType() << std::endl;
}