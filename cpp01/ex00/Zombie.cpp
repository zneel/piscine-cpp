/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:11:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/08 09:59:29 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->name_ = name;
  std::cout << "Zombie: " << this->name_ << " created" << std::endl;
}
Zombie::~Zombie() {
  std::cout << "Zombie: " << this->name_ << " deleted" << std::endl;
}

void Zombie::announce() {
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
