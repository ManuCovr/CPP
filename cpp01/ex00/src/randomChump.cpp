#include "../inc/Zombie.hpp"

void	randomChump(std::string name) // stack
{
	Zombie	zomb(name);
	zomb.announce();
}