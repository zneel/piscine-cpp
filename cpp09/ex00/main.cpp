#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>

void openfile(std::ifstream *fs, std::string const &filename)
{
    fs->open(filename.c_str(), std::ios::in);
    if (!fs->is_open())
    {
        std::cout << "Error: " << std::strerror(errno) << std::endl;
        std::exit(1);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./btc [input_file.txt]" << std::endl;
        return 1;
    }

    std::ifstream data;
    std::ifstream input;
    openfile(&data, "data.csv");
    openfile(&input, av[1]);
    if (!data || !input)
        return 1;
    BitcoinExchange exchange;
    std::string line;
    int lineNumber = 0;
    while (std::getline(data, line, '\n'))
    {
        try
        {
            if (!line.empty())
                exchange.parseDbLine(line, lineNumber++);
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    while (std::getline(input, line, '\n'))
    {
        try
        {
            if (!line.empty())
                exchange.parseInputLine(line, lineNumber++);
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}
