#include "Bureaucrat.hpp"
#include "Form.hpp"

void _test_form_constructor(
    std::string const name, int sign_grade, int exec_grade)
{
    try {
        Form form = Form(name, sign_grade, exec_grade);
        std::cout << form;
        std::cerr << "> construction succeeded" << std::endl;
    } catch (std::exception const& e) {
        std::cerr << "> construction failed" << std::endl;
    }
}

void _test_sign_form(
    std::string const bureau_name, int bureau_grade,
    std::string const form_name, int sign_grade, int exec_grade)
{
    if ((sign_grade > 150 || sign_grade < 1)
        || (exec_grade > 150 || exec_grade < 1))
        return;
    Bureaucrat bureau = Bureaucrat(bureau_name, bureau_grade);
    Form       form = Form(form_name, sign_grade, exec_grade);

    bureau.signForm(form);
    std::cout << bureau;
    std::cout << form;
}

void test1_create_form()
{
    std::cout << "========= test1 : constructor =========" << std::endl;
    std::cout
        << "> (1) fail if grade is too high(sign grade or execution grade < 1)"
        << std::endl;
    _test_form_constructor("formA", 0, 13);
    _test_form_constructor("formB", 14, -132);
    std::cout << std::endl;
    std::cout
        << "> (2) fail if grade is too low(sign grade or execution grade > 150)"
        << std::endl;
    _test_form_constructor("formC", 153, 132);
    _test_form_constructor("formD", 123, 165);
    std::cout << std::endl;
    std::cout << "> (3) succeed if 1 <= sign grade, execution grade <= 150"
              << std::endl;
    _test_form_constructor("formE", 1, 1);
    _test_form_constructor("formF", 150, 150);
    _test_form_constructor("formG", 70, 23);
    std::cout << std::endl;
}

void test2_sign_form()
{
    std::cout << "========= test2 : sign form =========" << std::endl;
    std::cout << "> (1) fail if sign grade < bureaucrat's grade" << std::endl;
    _test_sign_form("signerA", 70, "formA", 20, 50);
    _test_sign_form("signerA", 70, "formB", 20, 100);
    std::cout << std::endl;
    std::cout << "> (2) succeed if sign grade >= bureaucrat's grade"
              << std::endl;
    _test_sign_form("signerA", 70, "formC", 120, 50);
    _test_sign_form("signerA", 70, "formD", 120, 100);
    std::cout << std::endl;
}

int main(void)
{
    test1_create_form();
    test2_sign_form();
}
