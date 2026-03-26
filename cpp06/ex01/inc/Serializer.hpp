#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>

struct Data
{
    std::string a;
    std::string b;
    int nbr;
    int nbr2;
};
class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& ref);
    Serializer& operator=(const Serializer& ref);
    ~Serializer();
public:
    static unsigned long    serialize(Data* ptr);
    static Data*            deserialize(unsigned long raw);
};
#endif