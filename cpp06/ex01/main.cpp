#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data1 = {'a', 10, 42.0f, 27.2, "hello"};

    std::cout << "Data: " << data1.c_data << ", " << data1.i_data << ", "
              << data1.f_data << ", " << data1.d_data << ", " << data1.str_data
              << std::endl;

    uintptr_t addr = Serializer::serialize(&data1);
    std::cout << "Address: " << addr << std::endl;

    Data* data_ptr = Serializer::deserialize(addr);
    std::cout << "Data: " << data_ptr->c_data << ", " << data_ptr->i_data
              << ", " << data_ptr->f_data << ", " << data_ptr->d_data << ", "
              << data_ptr->str_data << std::endl;
}
