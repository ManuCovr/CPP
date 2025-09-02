#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

HumanA::HumanA(std::string name, Weapon &wp) : _wp(wp)
{
	this->_name = name;
	std::cout << _name << " grabbed a " << _wp.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << _name << " died horribly" << std::endl;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with " << this->_wp.getType() << std::endl;
}
