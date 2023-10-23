#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>

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

bool BitcoinExchange::checkLeapYear(int year, int month, int day)
{
    if (month != 2)
        return true;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        if (month == 2 && day == 29)
            return true;
    }
    else
    {
        if (month == 2 && day == 28)
            return true;
    }
    std::cout << year << " " << month << " " << day << std::endl;
    return false;
}

bool BitcoinExchange::hasCorrectHyphen(std::string const &str)
{
    std::string::const_iterator start = str.begin();
    std::string::const_iterator end = str.end();
    int i = 0;
    while (start != end)
    {
        if (i == 4 && *start != '-')
            return false;
        if (i == 7 && *start != '-')
            return false;
        i++;
        start++;
    }
    return true;
}

bool BitcoinExchange::isDate(std::string const &str)
{
    if (str.length() != 10)
        return false;
    if (!hasCorrectHyphen(str))
        return false;
    std::string year = str.substr(0, 4);
    std::string month = str.substr(5, 2);
    std::string day = str.substr(8, 2);
    if (year.find_first_not_of("0123456789") != std::string::npos)
        return false;
    if (month.find_first_not_of("0123456789") != std::string::npos)
        return false;
    if (day.find_first_not_of("0123456789") != std::string::npos)
        return false;
    if (std::atoi(year.c_str()) < 1970 || std::atoi(year.c_str()) > 2038)
        return false;
    if (!checkLeapYear(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str())))
        return false;
    return true;
}

void BitcoinExchange::parseData(std::string const &line, int lineNumber)
{
    std::string parsed[2];
    std::string delim = ",";
    std::string::const_iterator start = line.begin();
    std::string::const_iterator end = line.end();
    int index = 0;
    while (start != end)
    {
        if (*start == ',')
        {
            if (start + 1 != end)
                start++;
            else
                break;
            index = 1;
        }
        parsed[index] += *start;
        start++;
    }
    if (lineNumber == 0 && !(parsed[0].compare("date") == 0) && !(parsed[1].compare("exchange_rate") == 0))
        throw InvalidCSVException();
    if (lineNumber > 0 && !isDate(parsed[0]))
        throw InvalidDateException();
    data_[parsed[0]] = std::strtod(parsed[1].c_str(), NULL);
    std::cout << parsed[0] << std::endl;
    std::cout << parsed[1] << std::endl;
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
    return "Invalid date";
}

const char *BitcoinExchange::InvalidCSVException::what() const throw()
{
    return "Invalid csv";
}
