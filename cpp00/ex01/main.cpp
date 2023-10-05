/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 22:43:50 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  PhoneBook pb = PhoneBook();
  std::string command;
  pb.usage();
  while (std::getline(std::cin, command, '\n')) {
    if (command.compare("EXIT") == 0)
      std::exit(0);
    else if (command.compare("ADD") == 0) {
    } else if (command.compare("SEARCH") == 0) {
      std::cout << "SEARCH" << std::endl;
    }
  }
  return 0;
}
