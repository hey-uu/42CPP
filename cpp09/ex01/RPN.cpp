#include "RPN.hpp"
#include <sstream>

std::stack<int> RPN::operands;

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

RPN::~RPN() {}

void RPN::calculate(char c)
{
    if (operands.size() < 2)
        throw std::runtime_error("Not enough operands");
    int n1 = operands.top();
    operands.pop();
    int n2 = operands.top();
    operands.pop();
    switch (c) {
        case '+':
            operands.push(n2 + n1);
            break;
        case '-':
            operands.push(n2 - n1);
            break;
        case '*':
            operands.push(n2 * n1);
            break;
        case '/':
            if (n1 == 0)
                throw std::runtime_error("Division by zero");
            operands.push(n2 / n1);
            break;
        default:
            throw std::runtime_error("Invalid character");
    }
}

double RPN::calculator(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string        tocken;

    while (iss >> tocken) {
        if (tocken.size() > 1)
            throw std::runtime_error("Invalid character");
        char c = tocken[0];
        if (::isdigit(c))
            operands.push(c - '0');
        else
            calculate(c);
    }
    if (operands.size() != 1)
        throw std::runtime_error("Too many operands");
    return operands.top();
}
