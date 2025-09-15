#include "../inc/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "A wild Dog appeared!" << std::endl;
}

Dog::Dog(const Dog& ref)
{
	_brain = new Brain(*ref._brain);
	this->_type = ref._type;
	std::cout << "A wild Dog appeared! (copy constructor)" << std::endl;
}

Dog	&Dog::operator=(const Dog &ref)
{
	if (this != &ref)
	{
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
		this->_type = ref._type;
		std::cout << "A wild Dog appeared!(operator overload=)" << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog ran away!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "BARK BARK WOOF" << std::endl;
}

void	Dog::setDogIdea(int const id, std::string const idea)
{
	_brain->setIdea(id, idea);
}

std::string const	Dog::getDogIdea(int const id) const
{
	return (_brain->getIdea(id));
}