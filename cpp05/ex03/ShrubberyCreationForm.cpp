#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "none", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : AForm(other)
{
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::do_action() const
{
    std::string   file_name(getTarget() + "_shrubbery");
    std::ofstream new_file(file_name.c_str());

    new_file << "          &&& &&  & &&\n"
                "      && &\\/&\\|& ()|/ @, &&\n"
                "      &\\/(/&/&||/& /_/)_&/_&\n"
                "   &() &\\/&|()|/&\\/ '%\" & ()\n"
                "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
                "&&   && & &| &| /& & % ()& /&&\n"
                " ()&_---()&\\&\\|&&-&&--%---()~\n"
                "     &&     \\|||\n"
                "             |||\n"
                "             |||\n"
                "             |||\n"
                "       , -=-~  .-^- _\"\n";

    new_file.close();
}

AForm* ShrubberyCreationForm::makeForm(std::string const& target)
{
    return (new ShrubberyCreationForm(target));
}