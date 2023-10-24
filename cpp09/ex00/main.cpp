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
        std::cout << "Error: " << filename << ": " << std::strerror(errno) << std::endl;
}

bool parseDb(std::ifstream &fs, BitcoinExchange &exchange)
{
    std::string line;
    int lineNumber = 0;
    bool ok = true;
    while (fs.good() && std::getline(fs, line, '\n'))
    {
        try
        {
            if (!line.empty())
            {
                std::pair<std::string, double> p = exchange.parseFile(line, lineNumber++, ',');
                if (p.first.empty() || p.second == -1)
                    continue;
                exchange.addToDb(p);
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Error data: " << e.what() << std::endl;
            ok = false;
        }
    }

    return ok;
}

bool parseFile(std::ifstream &fs, BitcoinExchange &exchange)
{
    std::string line;
    int lineNumber = 0;
    bool ok = true;
    while (fs.good() && std::getline(fs, line, '\n'))
    {
        try
        {
            if (!line.empty())
            {
                std::pair<std::string, double> p = exchange.parseFile(line, lineNumber++, '|');
                if (p.first.empty() || p.second == -1)
                    continue;
                std::cout << p.first << ": " << exchange.getPrice(p) << std::endl;
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Error input: " << e.what() << std::endl;
            ok = false;
        }
    }

    return ok;
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
    if (!data.is_open())
        return 1;

    if (!input.is_open())
    {
        if (data.is_open())
            data.close();
        return 1;
    }

    BitcoinExchange exchange;

    if (!parseDb(data, exchange))
        return 1;

    if (!parseFile(input, exchange))
        return 1;

    return 0;
}
