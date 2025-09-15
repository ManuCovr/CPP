#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iomanip>
# include <iostream>

class Brain
{
	private:
	std::string _ideas[100];

	public:
	Brain();
	Brain(const Brain& ref);
	Brain& operator=(const Brain& ref);
	~Brain();

	void	setIdea(int const id, std::string const idea);
	std::string const	getIdea(int const id);
};

#endif