/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:59:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 15:37:08 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "contact.hpp"
#include <string>

class PhoneBook {
public:
  void add(Contact contact);
  Contact search(Contact contact);

private:
  int contactCount;
  Contact contacts[8];
};
