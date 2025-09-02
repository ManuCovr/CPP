#include "../inc/Replacer.hpp"

Replacer::Replacer()
{}

Replacer::~Replacer()
{}

void	Replacer::addArgs(std::string &og, std::string &s1, std::string &s2)
{
	_og = og;
	_s1 = s1;
	_s2 = s2;
}

void	Replacer::getContent()
{
	char	c;
	for (int i = 0; _input.get(c); i++)
		_replace.push_back(c);
	_input.close();
}

int	Replacer::setOut()
{
	size_t	p = 0;
	int	flag = 0;
	std::string new_file = _og + ".replace";
	_output.open(new_file.c_str());
	if (_s1.empty())
	{
		std::cout << "empty string, aborting" << std::endl;
		return 1;
	}
	while ((p = _replace.find(_s1, p)) != std::string::npos)
	{
		_replace.erase(p, _s1.length());
		_replace.insert(p, _s2);
		p += _s2.length();
		flag = 1;
	}
	if (flag)
	{
		_output << _replace;
		_output.close();
		return 0;
	}
	else if (flag == 0)
	{
		std::cout << "Couldn't find the first string inside the file, aborting execution." << std::endl;
		return 1;
	}
	return 0;
}

int	Replacer::setInp()
{
	_input.open(_og.c_str());
	if (_og.empty())
	{
		std::cout << "Empty file, aborting." << std::endl;
		return 1;
	}
	return 0;
}

std::string	Replacer::getFile() const
{
	return (_og);
}