#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : data_(other.data_)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        data_ = rhs.data_;
    }
    return *this;
}

void BitcoinExchange::addData(std::string const &date, float price)
{
}

void BitcoinExchange::parseData(std::string const &filename)
{
}
