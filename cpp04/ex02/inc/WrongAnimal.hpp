#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iomanip>
# include <iostream>

class WrongAnimal
{
	protected:
	std::string _type;

	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& ref);
	WrongAnimal& operator=(const WrongAnimal& ref);
	~WrongAnimal();

	std::string	getType() const;
	void	makeSound() const;
};

#endif