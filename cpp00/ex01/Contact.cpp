/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:27:43 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 16:15:12 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

int Contact::getId() { return this->id; }
std::string Contact::getFirstName() { return this->firstName; }
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickName() { return this->nickName; }
std::string Contact::getPhoneNumber() { return this->phoneNumber; }
std::string Contact::getDarkestSecret() { return this->darkestSecret; }

void Contact::setId(int id) { this->id = id; }
void Contact::setFirstName(std::string v) { this->firstName = v; }
void Contact::setLastName(std::string v) { this->lastName = v; }
void Contact::setNickName(std::string v) { this->nickName = v; }
void Contact::setPhoneNumber(std::string v) { this->phoneNumber = v; }
void Contact::setDarkestSecret(std::string v) { this->darkestSecret = v; }

void Contact::add(int idx) {
  this->id = idx;
  this->firstName = prompt("Enter the first name: ");
  this->lastName = prompt("Enter the last name: ");
  this->nickName = prompt("Enter the nickname: ");
  this->darkestSecret = prompt("Enter the darkest secret: ");
  this->phoneNumber = prompt("Enter the phone number: ");
}

std::string Contact::prompt(std::string prompt) {
  std::string input;
  std::cout << prompt << std::endl;
  std::cout << "> ";
  while (std::getline(std::cin, input, '\n') && !input.size()) {
    if (input.size() == 0) {
      std::cout << prompt << std::endl;
      continue;
    }
  }
  if (std::cin.bad() || std::cin.eof())
    std::exit(0);
  return input;
}
