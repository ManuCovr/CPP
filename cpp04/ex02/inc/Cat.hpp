#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	private:
	Brain	*_brain;
	public:
	Cat();
	Cat(const Cat& ref);
	Cat& operator=(const Cat& ref);
	~Cat();

	void	makeSound() const;
	void	setCatIdea(int const id, std::string const idea);
	std::string const	getCatIdea(int const id) const;
};

#endif