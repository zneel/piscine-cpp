#include "Serializer.hpp"
#include <iostream>

int main()
{
    struct Data data = {"e1", "norminet"};
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw: 0x" << std::hex << raw << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ptr->street: " << ptr->street << std::endl;
    std::cout << "ptr->name: " << ptr->name << std::endl;
    return (0);
}
