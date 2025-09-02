#include "../inc/Replacer.hpp"

bool check_file(const std::string &file)
{
	std::ifstream f(file.c_str());
	return f.good();
}

int	main(int ac, char **av)
{
	Replacer	file;
	std::string	og;
	std::string s1;
	std::string s2;
	if (ac == 4)
	{
		og = av[1];
		s1 = av[2];
		s2 = av[3];
		file.addArgs(og, s1, s2);
		if (!check_file(file.getFile()))
		{
			std::cout << "Something is wrong with the file given as input, try again please" << std::endl;
			return 1;
		}
		if (file.setInp())
			return 1;
		file.getContent();
		 if (file.setOut())
		 	return 1;
		std::cout << "File " << file.getFile() << ".replace created sucessfully and replaced \"" << av[2] << "\" for \"" << av[3] << "\"" << std::endl;
	}
	else
	{
		std::cout << "Wrong number of arguments, try again please" << std::endl;
		return 1;
	}
	return 0;
}
