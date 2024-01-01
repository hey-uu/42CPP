#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type _Container;
    typedef typename _Container::iterator                     iterator;
    typedef typename _Container::const_iterator               const_iterator;
    typedef typename _Container::reverse_iterator             reverse_iterator;
    typedef typename _Container::const_reverse_iterator const_reverse_iterator;

    MutantStack();
    MutantStack(Container const& container);
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