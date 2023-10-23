#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

std::ifstream *openfile(std::string const &filename)
{
    std::ifstream *data = new std::ifstream();
    data->open(filename.c_str(), std::ios::in);
    if (!data->is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        delete data;
        return NULL;
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

    std::ifstream *data = openfile("data.csv");
    std::ifstream *input = openfile(av[1]);
    if (!data)
        return 1;
    if (!input)
    {
        delete data;
        return 1;
    }
    BitcoinExchange exchange;
    std::string line;
    int lineNumber = 0;
    while (std::getline(*data, line, '\n'))
    {
        if (!line.empty())
            exchange.parseData(line, lineNumber++);
    }
    delete data;
    delete input;
}
