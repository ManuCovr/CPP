#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <typeinfo>

template <typename Container>
class PmergeMe {
    Container container;
        public:
        typedef typename Container::value_type ValueType;
        typedef typename Container::iterator Iterator;
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe(char **av);
        void sort_time();
        void sort();
        size_t size();
        typename Container::iterator begin();
        typename Container::iterator end();
    private:
        clock_t start_;
        clock_t end_;
        double time();
        int Jacobsthal(int k);
        size_t count_word_and_check(std::string &str);
        void sort(Container &vec);
        std::string container_type();
        void insert(Container &main, Container &pend, ValueType odd, Container &left, Container &vec, bool is_odd, int order);
};

template <typename Container>
std::ostream& operator<<(std::ostream &os, PmergeMe<Container> &obj);

#include "PmergeMe.tpp"

#endif
