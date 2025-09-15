#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iomanip>
# include <iostream>

class Animal
{
	protected:
	std::string _type;

	public:
	Animal();
	Animal(const Animal& ref);
	Animal& operator=(const Animal& ref);
	virtual ~Animal();

	virtual std::string	getType() const;
	virtual void	makeSound() const;
};

#endif