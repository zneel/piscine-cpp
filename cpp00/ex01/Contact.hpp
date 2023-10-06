/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:37 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/06 16:08:11 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string.h>

class Contact {
public:
  Contact();
  ~Contact();
  void add(int idx);
  int getId();
  std::string getFirstName();
  std::string getLastName();
  std::string getNickName();
  std::string getPhoneNumber();
  std::string getDarkestSecret();

  void setId(int id);
  void setFirstName(std::string v);
  void setLastName(std::string v);
  void setNickName(std::string v);
  void setPhoneNumber(std::string v);
  void setDarkestSecret(std::string v);

private:
  int id;
  std::string prompt(std::string prompt);
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};
