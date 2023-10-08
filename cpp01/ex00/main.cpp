/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:47:08 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/08 10:00:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
  std::cout << "Allocating on heap" << std::endl;
  Zombie* carl = newZombie("Carl");
  carl->announce();
  delete carl;
  std::cout << "=======================" << std::endl;
  std::cout << "Allocating on stack" << std::endl;
  randomChump("Toto");
  std::cout << "=======================" << std::endl;
}
