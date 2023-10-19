#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <iterator>
#include <limits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    if (this != &other)
    {
    }
    return (*this);
}

const char *ScalarConverter::InvalidInputException::what() const throw()
{
    return ("Invalid input");
}

const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
    return ("Impossible");
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

int ScalarConverter::getPrecision(std::string const str)
{
    int res = 1;
    size_t pos = str.find('.');
    if (pos == std::string::npos)
        return res;
    res = str.size() - pos - 1;
    if (res < 0)
        return 0;
    return res;
}

void ScalarConverter::convert(std::string const str)
{
    if (str.empty())
        throw ScalarConverter::InvalidInputException();
    try
    {
        toChar(str);
    }
    catch (std::exception const &e)
    {
        std::cout << "char: " << e.what() << std::endl;
    }
    try
    {
        toInt(str);
    }
    catch (std::exception const &e)
    {
        std::cout << "int: " << e.what() << std::endl;
    }
    try
    {
        toFloat(str);
    }
    catch (std::exception const &e)
    {
        std::cout << "float: " << e.what() << std::endl;
    }
    try
    {
        toDouble(str);
    }
    catch (std::exception const &e)
    {
        std::cout << "double: " << e.what() << std::endl;
    }
}

void ScalarConverter::toChar(std::string const str)
{
    if (str.size() == 1)
    {
        if (!std::isprint(str[0]) || std::isdigit(str[0]))
            throw ScalarConverter::NonDisplayableException();
        std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
        return;
    }
    double d = std::strtod(str.c_str(), NULL);
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConversionException();
    if (static_cast<int>(d) >= 32 && static_cast<int>(d) <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        throw ScalarConverter::NonDisplayableException();
}

void ScalarConverter::toInt(std::string const str)
{
    char *rest;
    if (str.compare("nan") == 0 || str.compare("nanf") == 0 || str.compare("inf") == 0 || str.compare("inff") == 0 ||
        str.compare("+inf") == 0 || str.compare("+inff") == 0 || str.compare("-inf") == 0 || str.compare("-inff") == 0)
        throw ScalarConverter::ImpossibleConversionException();
    long d = std::strtol(str.c_str(), &rest, 10);
    if (str.size() == 1)
    {
        if (!std::isdigit(str[0]))
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        return;
    }
    if (str[0] != '+' && str[0] != '-' && !std::isdigit(str[0]))
        throw ScalarConverter::ImpossibleConversionException();
    if (d > std::numeric_limits<int>::max() || static_cast<long>(d) < std::numeric_limits<int>::min())
        throw ScalarConverter::ImpossibleConversionException();
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConversionException();
    if (*rest == 'f')
        rest++;
    if (!*(rest) || *rest == '.')
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        throw ScalarConverter::ImpossibleConversionException();
}

void ScalarConverter::toFloat(std::string const str)
{
    char *rest;
    std::stringstream ss;
    int precision = getPrecision(str);
    float f = std::strtof(str.c_str(), &rest);
    if (errno == ERANGE)
    {
        if (str[0] == '-')
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: inff" << std::endl;
        return;
    }
    if (precision == 0)
        precision = 1;
    if (str.size() == 1)
    {
        if (!std::isdigit(str[0]))
            ss << std::fixed << std::setprecision(precision) << static_cast<float>(str[0]);
        else
            ss << std::fixed << std::setprecision(precision) << static_cast<float>(f);
        std::cout << "float: " << ss.str() << "f" << std::endl;
        return;
    }
    if (*rest == 'f')
    {
        precision--;
        rest++;
    }
    if (!*(rest))
    {
        if (precision > 7)
            precision = 7;
        ss << std::fixed << std::setprecision(precision) << static_cast<float>(f);
        std::cout << "float: " << ss.str() << "f" << std::endl;
    }
    else
        throw ScalarConverter::ImpossibleConversionException();
}

void ScalarConverter::toDouble(std::string const str)
{
    char *rest;
    int toFloat = false;
    std::stringstream ss;
    int precision = getPrecision(str);
    if (precision == 0)
        precision = 1;
    double d = std::strtod(str.c_str(), &rest);
    if (errno == ERANGE)
    {
        if (str[0] == '-')
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: inf" << std::endl;
        return;
    }
    if (str.size() == 1)
    {
        if (!std::isdigit(str[0]))
            ss << std::fixed << std::setprecision(precision) << static_cast<double>(str[0]);
        else
            ss << std::fixed << std::setprecision(precision) << static_cast<double>(d);
        std::cout << "double: " << ss.str() << std::endl;
        return;
    }
    if (*rest == 'f')
    {
        toFloat = true;
        precision--;
        rest++;
    }
    if (!*(rest))
    {
        if (precision > 14)
            precision = 15;
        if (toFloat)
        {
            if (precision > 7)
                precision = 7;
            ss << std::fixed << std::setprecision(precision) << static_cast<float>(d);
        }
        else
            ss << std::fixed << std::setprecision(precision) << static_cast<double>(d);
        std::cout << "double: " << ss.str() << std::endl;
    }
    else
        throw ScalarConverter::ImpossibleConversionException();
}
