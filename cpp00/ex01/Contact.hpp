/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:37 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 18:50:06 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string.h>

class Contact {
public:
  Contact();
  ~Contact();

  int getId();
  void setId(int idx);

  void add(int idx);
  void displayLine();
  void displayFull();

private:
  std::string prompt(std::string prompt);
  int id_;
  std::string firstName_;
  std::string lastName_;
  std::string nickName_;
  std::string phoneNumber_;
  std::string darkestSecret_;
};
