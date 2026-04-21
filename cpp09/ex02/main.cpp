#include "PmergeMe.hpp"


static void printContainer(PmergeMe<std::deque<int> > &obj, size_t limit) {
    std::deque<int>::iterator it = obj.begin();
    size_t count = 0;
    for (; it != obj.end(); ++it) {
        if (count == limit) {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        count++;
    }
}


int main(int ac, char **av) {
    try {
        if (ac >= 2) {
            PmergeMe<std::deque<int> >  Deque(av);
            PmergeMe<std::vector<int> > Vector(av);


            size_t limit = Deque.size() > 100 ? 100 : Deque.size();


            std::cout << "Before: ";
            printContainer(Deque, limit);
            std::cout << std::endl;


            Deque.sort();
            Vector.sort();


            std::cout << "After: ";
            printContainer(Deque, limit);
            std::cout << std::endl;


            Deque.sort_time();
            Vector.sort_time();
        } else
            throw std::runtime_error("Error");
    } catch (...) {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}