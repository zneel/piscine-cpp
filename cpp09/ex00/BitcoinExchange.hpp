#pragma once

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{
  public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    void parseDbLine(std::string const &line, int lineNumber);
    void parseInputLine(std::string const &line, int lineNumber);
    double getCurrentPrice(std::string const &date) const;

  private:
    class InvalidDateException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class InvalidCSVException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class NumberTooLargeException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class InvalidNumberException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    bool isDate(std::string const &str);
    bool hasCorrectHyphen(std::string const &str);
    bool checkMonthDay(int year, int month, int day);
    std::map<std::string, float> data_;
};
