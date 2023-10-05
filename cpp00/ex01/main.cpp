/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 17:17:53 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <string>

void print_usage() {
  std::cout << "Welcome to the Phonebook" << std::endl;
  std::cout << "Please enter one off these commands: ";
  std::cout << "EXIT, ADD, SEARCH" << std::endl;
}

int main(int ac, char **av) {
  PhoneBook pb = PhoneBook();
  std::string command;
  print_usage();
  while (std::getline(std::cin, command, '\n')) {
    if (command.compare("EXIT") == 0)
      exit(0);
    else if (command.compare("ADD") == 0) {
      Contact *c = new Contact();
      std::string input;
      std::cout << "Enter firstname: " << std::endl;
      c->firstName = input;
      std::cout << "Enter lastname: " << std::endl;
    } else if (command.compare("SEARCH") == 0) {
      std::cout << "SEARCH" << std::endl;
    }
  }
  return 0;
}
