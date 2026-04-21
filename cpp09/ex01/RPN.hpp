#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdlib>

class RPN {
    private:
        std::stack<int> Stack;
        void yaslam(char op);
        bool input_check(std::string &inp);
    public:
        bool empty(void);
        size_t size(void);
        int pop();
        RPN();
        RPN &operator=(const RPN &rpn);
        RPN(const RPN &rpn);
        RPN(std::string args);
        ~RPN();
};

std::ostream &operator<<(std::ostream &os ,RPN &rpn);

#endif
