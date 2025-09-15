#include "../inc/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "A wild Cat appeared!" << std::endl;
}

Cat::Cat(const Cat& ref)
{
	_brain = new Brain(*ref._brain);
	this->_type = ref._type;
	std::cout << "A wild Cat appeared! (copy constructor)" << std::endl;
}

Cat	&Cat::operator=(const Cat &ref)
{
	if (this != &ref)
	{
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
		this->_type = ref._type;
		std::cout << "A wild Cat appeared! (operator overload=)" << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat ran away!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEOWW" << std::endl;
}

void	Cat::setCatIdea(int const id, std::string const idea)
{
	_brain->setIdea(id, idea);
}

std::string const	Cat::getCatIdea(int const id) const
{
	return (_brain->getIdea(id));
}
