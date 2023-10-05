/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:37 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/05 15:37:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"

class Contact {
public:
  int index;
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};
