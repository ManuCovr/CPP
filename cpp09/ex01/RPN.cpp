#include "RPN.hpp"


bool check_token(std::string inp){
    if(std::isdigit(inp[0]) && inp.size() == 1)
        return true;
    if(inp == "-" || inp == "+" || inp == "/" || inp == "*")
        return true;
    return false;
}


void RPN::yaslam(char op){
    if(Stack.empty())
        throw std::exception();
    int n1 = Stack.top();
    Stack.pop();
    if(Stack.empty())
        throw std::exception();
    int n2 = Stack.top();
    Stack.pop();
    if(op == '*')
        Stack.push( n2 * n1);
    else if (op == '-')
        Stack.push( n2 - n1);
    else if(op == '+')
        Stack.push(n2 + n1);
    else if(op == '/')
    {
        if(n1 == 0){
            std::cerr << "impossible op " << n2 << " / " << n1 << std::endl;
            throw std::exception();
        }
        Stack.push(n2 / n1);
    }
}


bool RPN::input_check(std::string &inp){
    if(inp.empty())
        return false;
    char *cstr = new char[inp.size() + 1];
    std::strcpy(cstr, inp.c_str());
    char* token = std::strtok(cstr, " ");
    try {
        while(token){
            if(!check_token(token)){
                delete[] cstr;
                return false;
            }
            char op = token[0];
            if(op == '-' || op == '+' || op == '/' || op == '*')
                yaslam(op);
            else
                Stack.push(std::atoi(token));
            token = std::strtok(NULL, " ");
        }
    } catch(...) {
        delete[] cstr;
        throw;
    }
    delete[] cstr;
    return true;
}


RPN::RPN(std::string args){
    if(!input_check(args))
        throw std::exception();
}


int RPN::pop(void){
     return Stack.top();
}


bool RPN::empty(void){
    return (Stack.empty());
}


size_t RPN::size(void){
    return (Stack.size());
}


std::ostream &operator<<(std::ostream &os ,RPN &rpn){
    if(rpn.size() != 1)
        throw std::exception();
    os << rpn.pop() ;
    return os;
}


RPN::RPN(const RPN &rpn) {
    this->Stack = rpn.Stack;
}


RPN &RPN::operator=(const RPN &rpn) {
    if (this == &rpn)
        return *this;
    this->Stack = rpn.Stack;
    return *this;
}

RPN::RPN() {}


RPN::~RPN() {}