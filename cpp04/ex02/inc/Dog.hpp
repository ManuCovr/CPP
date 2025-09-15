#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
	Brain	*_brain;
	public:
	Dog();
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	~Dog();

	void	makeSound() const;
	void	setDogIdea(int const id, std::string const idea);
	std::string const	getDogIdea(int const id) const;
};

#endif