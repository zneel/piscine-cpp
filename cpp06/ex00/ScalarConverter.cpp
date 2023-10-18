#include "ScalarConverter.hpp"

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
        if (!std::isprint(str[0]))
            throw ScalarConverter::NonDisplayableException();
        std::cout << "char: '" << str[0] << "'" << std::endl;
        return;
    }
    int i = std::atoi(str.c_str());
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        throw ScalarConverter::ImpossibleConversionException();
}

void ScalarConverter::toInt(std::string const str)
{
    if (str.compare("nan") == 0 || str.compare("nanf") == 0 || str.compare("inf") == 0 || str.compare("inff") == 0 ||
        str.compare("+inf") == 0 || str.compare("+inff") == 0 || str.compare("-inf") == 0 || str.compare("-inff") == 0)
        throw ScalarConverter::ImpossibleConversionException();
    char *rest;
    long i = std::strtol(str.c_str(), &rest, 10);
    if (i > INT_MAX || i < INT_MIN)
        throw ScalarConverter::ImpossibleConversionException();
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConversionException();
    if (*rest == 'f')
        rest++;
    if (!*(rest) || *rest == '.')
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    else
        throw ScalarConverter::ImpossibleConversionException();
}

int ScalarConverter::getPrecision(std::string const str)
{
    size_t pos = str.find('.');
    if (pos == std::string::npos)
        return (1);
    return (str.size() - pos - 1);
}

void ScalarConverter::toFloat(std::string const str)
{
    char *rest;
    int precision = getPrecision(str);
    if (precision == 0)
        precision = 1;
    float f = std::strtof(str.c_str(), &rest);
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConversionException();
    if (*rest == 'f')
    {
        if (*(rest + 1) != '\0')
            precision--;
        rest++;
    }
    if (!*(rest))
    {
        if (precision > 7)
            precision = 7;
        std::stringstream ss;
        ss << std::fixed << std::setprecision(precision) << static_cast<float>(f);
        std::cout << "float: " << ss.str() << "f" << std::endl;
    }
    else
        throw ScalarConverter::ImpossibleConversionException();
}

void ScalarConverter::toDouble(std::string const str)
{
    char *rest;
    int precision = getPrecision(str);
    if (precision == 0)
        precision = 1;
    double d = std::strtod(str.c_str(), &rest);
    if (errno == ERANGE)
        throw ScalarConverter::ImpossibleConversionException();
    if (*rest == 'f')
    {
        if (*(rest + 1) != '\0')
            precision--;
        rest++;
    }
    if (!*(rest))
    {
        if (precision > 14)
            precision = 15;
        std::stringstream ss;
        ss << std::fixed << std::setprecision(precision) << static_cast<double>(d);
        std::cout << "double: " << ss.str() << std::endl;
    }
    else
        throw ScalarConverter::ImpossibleConversionException();
}
