template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(Container const& container)
    : std::stack<T, Container>(container)
{
    // this->c.insert(this->c.begin(), container.begin(), container.end());
}


template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const& other)
    : std::stack<T>(other)
{
}

template <typename T, typename Container>
MutantStack<T, Container>&
MutantStack<T, Container>::operator=(MutantStack<T, Container> const& other)
{
    if (this == &other)
        return *this;
    MutantStack<T, Container> temp(other);
    swap(temp);
    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const
{
    return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin()
{
    return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin() const
{
    return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend()
{
    return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend() const
{
    return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cbegin() const
{
    return this->c.cbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cend() const
{
    return this->c.cend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::crbegin() const
{
    return this->c.crbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::crend() const
{
    return this->c.crend();
}