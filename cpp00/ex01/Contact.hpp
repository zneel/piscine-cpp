#pragma once

#include <string.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

class Contact {
 public:
  Contact();
  ~Contact();

  int getId();
  void setId(int idx);

  void add(int idx);
  void displayLine() const;
  void displayFull() const;

 private:
  std::string prompt_(std::string prompt);
  int id_;
  std::string firstName_;
  std::string lastName_;
  std::string nickName_;
  std::string phoneNumber_;
  std::string darkestSecret_;
};
