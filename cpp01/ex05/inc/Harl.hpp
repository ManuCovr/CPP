#include <iostream>

class Harl
{
private:
	std::string	_level[4];
	void	debug();
	void	info();
	void	warning();
	void	error();
public:
	Harl();
	~Harl();

	void	complain(std::string level);
};

typedef	void (Harl::*fc)(void);