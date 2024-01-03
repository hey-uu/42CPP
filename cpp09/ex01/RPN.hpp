#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
private:
    static std::stack<int> operands;
    static void            calculate(char c);

public:
    static double calculator(const std::string& expression);
};

#endif
