#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "A wild (but the wrong one) Animal appeared!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	*this = ref;
	std::cout << "A wild (but the wrong one) Animal appeared!" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << "A wild (but the wrong one) Animal appeared!" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal (the wrong one) ran away!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << " * Random (but wrong) animal sound * " << std::endl;
}