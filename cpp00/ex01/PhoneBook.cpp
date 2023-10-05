/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:53 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 22:43:43 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() { this->contactCount = 0; }
PhoneBook::~PhoneBook() {}
void PhoneBook::add() { this->contacts[this->contactCount % 8].add(); }
Contact PhoneBook::search(Contact contact) { return contact; }
void PhoneBook::usage() {
  std::cout << "Welcome to the Phonebook" << std::endl;
  std::cout << "Please enter one off these commands: ";
  std::cout << "EXIT, ADD, SEARCH" << std::endl;
}
