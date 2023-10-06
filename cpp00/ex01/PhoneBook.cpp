/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:53 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 16:35:35 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <ostream>

PhoneBook::PhoneBook() {
  this->max = 8;
  this->current = 0;
  for (int i = 0; i < this->max; ++i)
    this->contacts[i].setId(-1);
}
PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
  this->contacts[this->current].add(this->current);
  this->current++;
  if (this->current >= this->max)
    this->current = 0;
}

bool PhoneBook::hasContacts() {
  for (int i = 0; i < this->max; ++i) {
    if (this->contacts[i].getId() >= 0)
      return true;
  }
  return false;
}

void PhoneBook::search() {
  std::string input;
  if (!this->hasContacts()) {
    std::cout << "No contacts yet..." << std::endl;
    return;
  }
  this->display();
  std::cout << "Please enter an index to display the contact." << std::endl;
  std::cout << "> ";
  while (std::getline(std::cin, input, '\n') && input.empty()) {
    std::cout << "Please enter an index to display the contact." << std::endl;
    std::cout << "> ";
  }
  int index = std::atoi(input.c_str());
  if (index < 0 || index >= this->max) {
    std::cout << "Invalid input. Please enter a valid index." << std::endl;
    return;
  }
  this->displayOne(this->contacts[index]);
}

void PhoneBook::display() {
  for (int i = 0; i < this->max; ++i) {
    if (this->contacts[i].getId() >= 0)
      std::cout << std::right << std::setw(10) << this->contacts[i].getId()
                << "|" << std::setw(10) << this->contacts[i].getFirstName()
                << "|" << std::setw(10) << this->contacts[i].getLastName()
                << "|" << std::setw(10) << this->contacts[i].getNickName()
                << std::endl;
  }
}

void PhoneBook::displayOne(Contact contact) {
  std::cout << ">Index: " << contact.getId() << std::endl;
  std::cout << ">Lastname: " << contact.getLastName() << std::endl;
  std::cout << ">Firstname: " << contact.getFirstName() << std::endl;
  std::cout << ">Nickname: " << contact.getNickName() << std::endl;
  std::cout << ">Phone number: " << contact.getPhoneNumber() << std::endl;
  std::cout << ">Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::usage() {
  std::cout << "Welcome to the Phonebook" << std::endl;
  std::cout << "Please enter one off these commands: ";
  std::cout << "EXIT, ADD, SEARCH" << std::endl;
}
