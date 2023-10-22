#pragma once

#include <map>
#include <string>
class BitcoinExchange
{
  public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    void addData(std::string const &date, float price);
    void parseData(std::string const &filename);

  private:
    std::map<std::string, float> data_;
};
