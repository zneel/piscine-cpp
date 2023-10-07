/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:53 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/07 11:50:57 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <iterator>
#include <string>

/**
 * @brief Construct a new Phone Book:: Phone Book object
 *
 */
PhoneBook::PhoneBook() {
  this->max_ = 8;
  this->current_ = 0;
  this->total_ = 0;
  for (int i = 0; i < this->max_; ++i)
    this->contacts_[i].setId(-1);
}

PhoneBook::~PhoneBook() {}

/**
 * @brief
 * Add a contact to the phonebook
 *
 */
void PhoneBook::add() {
  this->contacts_[this->current_].add(this->current_);
  this->current_++;
  this->total_++;
  if (this->current_ >= this->max_)
    this->current_ = 0;
}

int PhoneBook::convertToInt(std::string v) {
  int value = 0;
  for (std::string::iterator it = v.begin(); it != v.end(); ++it) {
    if (!std::isdigit(*it))
      return -1;
    value = value * 10 + (*it - '0');
  }
  return value;
}

/**
 * @brief Search a contact in the phonebook
 *
 */
void PhoneBook::search() {
  if (!this->total_) {
    std::cout << "No contacts yet..." << std::endl;

    return;
  }
  std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
  std::cout << "│   INDEX  │FIRST NAME│ LASTNAME │ NICKNAME │" << std::endl;
  std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
  for (int i = 0; i < this->max_; ++i)
    this->contacts_[i].displayLine();
  std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
  std::cout << "Enter an index: " << std::endl;
  std::cout << "> ";
  std::string input = "";
  while (std::getline(std::cin, input, '\n') && input.empty()) {
    std::cout << "Enter an index: " << std::endl;
    std::cout << "> ";
  }
  if (std::cin.bad() || std::cin.eof())
    std::exit(0);
  int index = convertToInt(input);
  if (index < 0 || index >= this->max_ || index >= this->total_) {
    std::cout << "Invalid input." << std::endl;

    return;
  }
  this->contacts_[index].displayFull();
}

/**
 * @brief Display the usage of the phonebook
 *
 */
void PhoneBook::usage() {
  std::cout << "Welcome to the Phonebook" << std::endl;
  std::cout << "Please enter one off these commands: ";
  std::cout << "EXIT, ADD, SEARCH" << std::endl;
}
