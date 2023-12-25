
template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
    _arr = new T[0]();
}

template <typename T>
Array<T>::Array(size_t n) : _arr(NULL), _size(n)
{
    _arr = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const& other) : _arr(NULL), _size(other._size)
{
    _arr = new T[other._size]();
    for (size_t i = 0; i < other._size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& other)
{
    if (this == &other)
        return *this;
    delete[] _arr;
    _arr = NULL;
    _size = other._size;
    _arr = new T[other._size]();
    for (size_t i = 0; i < other._size; i++)
        _arr[i] = other._arr[i];
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
    _arr = NULL;
}

template <typename T>
T& Array<T>::operator[](size_t idx)
{
    if (idx >= _size)
        throw std::out_of_range("out of range");
    return _arr[idx];
}

template <typename T>
const T& Array<T>::operator[](size_t idx) const
{
    if (idx >= _size)
        throw std::out_of_range("out of range");
    return _arr[idx];
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
}
