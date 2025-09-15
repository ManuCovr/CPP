#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain developed" << std::endl;
}

Brain::Brain(const Brain& ref)
{
	*this = ref;
	std::cout << "Brain developed (copy constructor)" << std::endl;
}

Brain	&Brain::operator=(const Brain &ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = ref._ideas[i];
		std::cout << "Brain developed (operator overload=)" << std::endl;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain withered" << std::endl;
}

void	Brain::setIdea(int const id, std::string const idea)
{
	if (id >= 0 && id < 100)
		_ideas[id] = idea;
}

std::string const	Brain::getIdea(int const id)
{
	return _ideas[id];
}