#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", "none", 72, 45)
{
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm("RobotomyRequestForm", target, 72, 45)
{
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
    : AForm(other)
{
    srand(time(0));
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::do_action() const
{
    std::cout << "GRZZ-GRZZ GRZZ-GRZZ" << std::endl;
    if (rand() < RAND_MAX / 2)
        std::cout << getTarget()
                  << " has been robotomized successfuly"
                  << std::endl;
    else
        std::cout << getTarget()
                  << " has been failed robotomy"
                  << std::endl;
}
