#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

std::fstream openfile(std::string const &filename)
{
    std::fstream data;
    data.open(filename.c_str(), std::ios::in);
    if (!data.is_open())
    {
        std::cout << "Error: could not open database file" << std::endl;
        std::exit(1);
    }
    return data;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./btc [input_file.txt]" << std::endl;
        return 1;
    }

    std::fstream data = openfile("data.csv");
    std::fstream input = openfile(av[1]);
}
