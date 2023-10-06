/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 16:28:35 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  void add();
  void search();
  void usage();

private:
  int current;
  int max;
  void displayHeader();
  void displayFooter();
  bool hasContacts();
  void displayOne(Contact contact);
  void display();
  Contact contacts[8];
};
