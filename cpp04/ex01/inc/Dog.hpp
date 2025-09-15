#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
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