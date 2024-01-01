#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type      _Container;
    typedef typename _Container::iterator               iterator;
    typedef typename _Container::const_iterator         const_iterator;
    typedef typename _Container::reverse_iterator       reverse_iterator;
    typedef typename _Container::const_reverse_iterator const_reverse_iterator;

    MutantStack();
    MutantStack(MutantStack const& other);
    MutantStack& operator=(MutantStack const& other);
    ~MutantStack();

    // iterator
    iterator               begin();
    const_iterator         begin() const;
    iterator               end();
    const_iterator         end() const;
    reverse_iterator       rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator       rend();
    const_reverse_iterator rend() const;
    const_iterator         cbegin() const;
    const_iterator         cend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"

#endif