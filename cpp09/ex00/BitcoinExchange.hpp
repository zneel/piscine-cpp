#pragma once

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

    std::pair<std::string, double> parseFile(std::string const &line, int lineNumber, char delim);
    void addToDb(std::pair<std::string, double> const &p);
    double getPrice(std::pair<std::string, double> &p) const;

  private:
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);
    typedef std::map<std::string, double> Database;

    bool isDate_(std::string const &str);
    bool hasCorrectHyphen_(std::string const &str);
    bool checkMonthDay_(int year, int month, int day);
    std::string trim_(std::string const &);
    Database data_;

    /**
     * exceptions classes
     */
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

    class InvalidInputException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class DuplicateDataException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class EmptyDatabaseException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};
