#include "../inc/Serializer.hpp"

int main()
{
    Data ptr;
    Data *copy;
    unsigned long n;

    ptr.a = "I'm good";
    ptr.b = "see?";
    ptr.nbr = 42;
    ptr.nbr2 = 84;
    std::cout << "This is the original data: " << ptr.a << ", " << ptr.b << " My numbers are " << ptr.nbr << " and " << ptr.nbr2 << std::endl;
    n = Serializer::serialize(&ptr);
    std::cout << "data pointer reinterpreted as an integral type: " << n << std::endl;
    copy = Serializer::deserialize(n);
    std::cout << copy->a << ", " << copy->b << " My numbers are " << copy->nbr << " and " << copy->nbr2 << std::endl;
}