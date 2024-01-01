#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void _test_push(MutantStack<T>& mstack, int n)
{
    std::cout << "pushed: " << n << std::endl;
    mstack.push(n);
}

template <typename T>
void _test_top(MutantStack<T>& mstack)
{
    std::cout << "top: " << mstack.top() << std::endl;
}

template <typename T>
void _test_pop(MutantStack<T>& mstack)
{
    T top = mstack.top();
    mstack.pop();
    std::cout << "popped: " << top << std::endl;
}

template <typename T>
void _test_size(MutantStack<T>& mstack)
{
    std::cout << "size: " << mstack.size() << std::endl;
}

template <typename T>
void _test_iterate_all(MutantStack<T>& mstack)
{
    std::cout << "iterate all: " << std::endl;
    typename MutantStack<T>::iterator itb = mstack.begin();
    typename MutantStack<T>::iterator ite = mstack.end();
    while (itb != ite) {
        std::cout << *itb << std::endl;
        ++itb;
    }
}

template <typename T>
void _test_iterate_all(MutantStack<T> const& mstack)
{
    std::cout << "iterate all: " << std::endl;
    typename MutantStack<T>::const_iterator itb = mstack.begin();
    typename MutantStack<T>::const_iterator ite = mstack.end();
    while (itb != ite) {
        std::cout << *itb << std::endl;
        ++itb;
    }
}

template <typename T, typename Container>
void _test_iterate_all(MutantStack<T, Container> const& mstack)
{
    std::cout << "iterate all: " << std::endl;
    typename MutantStack<T, Container>::const_iterator itb = mstack.begin();
    typename MutantStack<T, Container>::const_iterator ite = mstack.end();
    while (itb != ite) {
        std::cout << *itb << std::endl;
        ++itb;
    }
}

template <typename T>
void _test_change_value(typename MutantStack<T>::iterator it, T val)
{
    std::cout << "changed value " << *it << " into " << val << std::endl;
    *it = val;
}

template <typename T>
void _test_push_back(std::list<T>& mstack, int n)
{
    std::cout << "pushed: " << n << std::endl;
    mstack.push_back(n);
}

template <typename T>
void _test_back(std::list<T>& list)
{
    std::cout << "back: " << list.back() << std::endl;
}

template <typename T>
void _test_pop_back(std::list<T>& list)
{
    T back = list.back();
    list.pop_back();
    std::cout << "popped: " << back << std::endl;
}

template <typename T>
void _test_size(std::list<T>& list)
{
    std::cout << "size: " << list.size() << std::endl;
}

template <typename T>
void _test_iterate_all(std::list<T>& list)
{
    std::cout << "iterate all: " << std::endl;
    typename std::list<T>::iterator itb = list.begin();
    typename std::list<T>::iterator ite = list.end();
    while (itb != ite) {
        std::cout << *itb << std::endl;
        ++itb;
    }
}

template <typename T>
void _test_change_value(typename std::list<T>::iterator it, T val)
{
    std::cout << "changed value " << *it << " into " << val << std::endl;
    *it = val;
}

int main()
{
    MutantStack<int> mstack;

    std::cout << "\n======== test1: mstack methods ========" << std::endl;
    _test_push(mstack, 5);
    _test_push(mstack, 100);
    _test_push(mstack, 17);

    _test_top(mstack);
    _test_pop(mstack);
    _test_top(mstack);
    _test_pop(mstack);
    _test_size(mstack);
    _test_top(mstack);

    _test_push(mstack, 3);
    _test_push(mstack, 5);
    _test_push(mstack, 737);
    _test_push(mstack, 0);

    _test_size(mstack);
    _test_top(mstack);

    std::cout << "\n======== test2: list methods ========" << std::endl;

    std::list<int> list;

    _test_push_back(list, 5);
    _test_push_back(list, 100);
    _test_push_back(list, 17);

    _test_back(list);
    _test_pop_back(list);
    _test_back(list);
    _test_pop_back(list);
    _test_size(list);
    _test_back(list);

    _test_push_back(list, 3);
    _test_push_back(list, 5);
    _test_push_back(list, 737);
    _test_push_back(list, 0);

    _test_size(list);
    _test_back(list);

    std::cout << "\n======== test3: mstack iterator ========" << std::endl;
    _test_iterate_all(mstack);
    MutantStack<int>::iterator mastack_it = mstack.begin();
    mastack_it++;
    mastack_it++;
    _test_change_value(mastack_it, 42);
    _test_iterate_all(mstack);

    std::cout << "\n======== test4: list iterator ========" << std::endl;
    _test_iterate_all(list);
    std::list<int>::iterator list_it = list.begin();
    list_it++;
    list_it++;
    _test_change_value(list_it, 42);
    _test_iterate_all(list);

    std::cout << "\n======== test5: mstack copy ========" << std::endl;
    MutantStack<int> mstack_copy1(mstack);

    _test_change_value(mstack_copy1.begin(), 42 * 42);
    _test_iterate_all(mstack_copy1);
    _test_iterate_all(mstack);

    MutantStack<int> mstack_copy2 = mstack;
    _test_change_value(mstack_copy2.begin(), 42 * 42);
    _test_iterate_all(mstack_copy2);
    _test_iterate_all(mstack);

    std::cout << "> mutant stack can be coppied into std::stack" << std::endl;
    std::stack<int> stack(mstack);

    std::cout << "\n======== test6: mstack const iterator ========"
              << std::endl;
    const int              ints[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    const std::vector<int> int_vec(ints, ints + 10);
    const MutantStack<int, std::vector<int> > mstack2(int_vec);
    _test_iterate_all(mstack2);
    return 0;
}
