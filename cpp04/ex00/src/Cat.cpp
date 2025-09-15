#include "../inc/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "A wild Cat appeared!" << std::endl;
}

Cat::Cat(const Cat& ref)
{
	*this = ref;
	std::cout << "A wild Cat appeared!"  << std::endl;
}

Cat	&Cat::operator=(const Cat &ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << "A wild Cat appeared!"  << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat ran away!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEOWW" << std::endl;
}