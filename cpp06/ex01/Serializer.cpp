#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const& other)
{
    (void)other;
}

Serializer& Serializer::operator=(Serializer const& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}