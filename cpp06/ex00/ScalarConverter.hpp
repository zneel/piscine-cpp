#pragma once

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class ScalarConverter
{
  public:
    static void convert(std::string const str);

    class InvalidInputException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class ImpossibleConversionException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class NonDisplayableException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

  private:
    static void toChar(std::string const);
    static void toFloat(std::string const);
    static void toInt(std::string const);
    static void toDouble(std::string const);
    static int getPrecision(std::string const);

    ScalarConverter(ScalarConverter const &);
    ScalarConverter &operator=(ScalarConverter const &);
    ~ScalarConverter();
    ScalarConverter();
};
