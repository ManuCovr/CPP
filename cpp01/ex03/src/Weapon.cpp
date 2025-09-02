#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

std::string Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
