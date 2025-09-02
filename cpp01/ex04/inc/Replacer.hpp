#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

class Replacer
{
private:
	std::string	_og;
	std::string	_s1;
	std::string _s2;
	std::string _replace;
	std::ifstream _input;
	std::ofstream _output;
public:
	Replacer();
	~Replacer();

	void	addArgs(std::string &og, std::string &s1, std::string &s2);
	void	getContent();
	int	setInp();
	int	setOut();
	std::string getFile() const;
};
