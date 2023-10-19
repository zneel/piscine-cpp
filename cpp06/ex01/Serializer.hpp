#pragma once

#include <stdint.h>
#include <string>

struct Data
{
    std::string street;
    std::string name;
};

class Serializer
{

  private:
    Serializer(Serializer const &);
    Serializer &operator=(Serializer const &);
    ~Serializer();
    Serializer();

  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};
