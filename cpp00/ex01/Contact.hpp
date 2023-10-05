/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:37 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 22:42:32 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"

class Contact {
public:
  Contact();
  ~Contact();
  void display();
  void add();

private:
  std::string prompt(std::string prompt);
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};
