#pragma once

#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();
  void add();
  void search();
  void usage();

 private:
  int current_;
  int max_;
  int total_;
  void displayHeader_();
  void displayFooter_();
  int promptSearch_();
  int convertToInt_(std::string str);
  Contact contacts_[8];
};
