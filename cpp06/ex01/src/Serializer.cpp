#include "../inc/Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& ref)
{
	*this = ref;
}

Serializer&	Serializer::operator=(const Serializer& ref)
{
	(void)ref;
	return *this;
}

Serializer::~Serializer(){}

unsigned long	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<unsigned long>(ptr);
}

Data*	Serializer::deserialize(unsigned long raw)
{
	return reinterpret_cast<Data*>(raw);
}