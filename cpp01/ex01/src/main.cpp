#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie *zomb;
	zomb = zombieHorde(5, "walker");
	for (int i = 0; i < 5; i++)
		zomb[i].announce();
	delete[] zomb;
	return (0);
}