#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iomanip>
# include <iostream>

class AAnimal
{
	protected:
	std::string _type;

	public:
	AAnimal();
	AAnimal(const AAnimal& ref);
	AAnimal& operator=(const AAnimal& ref);
	virtual ~AAnimal();

	virtual std::string	getType() const;
	virtual void	makeSound() const = 0;
};

#endif