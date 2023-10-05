/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 22:23:35 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  void add();
  Contact search(Contact contact);
  void usage();

private:
  int contactCount;
  Contact contacts[8];
};
