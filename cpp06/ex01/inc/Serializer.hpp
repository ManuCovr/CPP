#ifndef	SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <cstdint>


struct Data
{
	std::string	a;
	std::string	b;
	int	nbr;
	int	nbr2;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& ref);
	Serializer& operator=(const Serializer& ref);
	~Serializer();
	
public:

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif