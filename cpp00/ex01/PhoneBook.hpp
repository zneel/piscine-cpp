/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 19:41:08 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

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
  void displayHeader();
  void displayFooter();
  bool hasContacts();
  int convertToInt(std::string str);
  Contact contacts_[8];
};
