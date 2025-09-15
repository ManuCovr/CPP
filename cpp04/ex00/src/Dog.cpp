#include "../inc/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "A wild Dog appeared!" << std::endl;
}

Dog::Dog(const Dog& ref)
{
	*this = ref;
	std::cout << "A wild Dog appeared!"  << std::endl;
}

Dog	&Dog::operator=(const Dog &ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << "A wild Dog appeared!"  << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog ran away!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "BARK BARK WOOF" << std::endl;
}