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

bool BitcoinExchange::checkMonthDay(int year, int month, int day)
{
    bool isLeap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31) // months with 31 days
            return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30) // months with 30 days
            return false;
        break;
    case 2:
        if (isLeap && day > 29) // 29 days in leap years
            return false;
        if (!isLeap && day > 28) // 28 days in non-leap years
            return false;
        break;
    default:
        return false;
    }

    return true;
}

bool BitcoinExchange::hasCorrectHyphen(std::string const &str)
{
    if (str[4] != '-' || str[7] != '-')
        return false;
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
    if (!checkMonthDay(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str())))
        return false;
    return true;
}

void BitcoinExchange::parseData(std::string const &line, int lineNumber)
{
    std::string parsed[2];
    std::istringstream iss(line);
    std::string token;
    int index = 0;
    while (getline(iss, token, ',') && index < 2)
        parsed[index++] = token;
    if (index != 2)
        throw InvalidCSVException();
    if (parsed[0].empty() || parsed[1].empty())
        throw InvalidCSVException();
    if (lineNumber == 0 && parsed[0] != "date" && parsed[1] != "exchange_rate")
        throw InvalidCSVException();
    if (lineNumber > 0 && !isDate(parsed[0]))
        throw InvalidDateException();
    if (lineNumber > 0)
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
