#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zomb;

	zomb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i;
		zomb[i].nameSetter(name + " " + ss.str());
	}
	return (zomb);
}
