/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:47:08 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/08 10:35:17 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
  int count = 20;
  std::ostringstream ss;
  ss << count;
  std::string str = ss.str();

  std::cout << ">Allocating " << str << " Carls on heap" << std::endl;
  Zombie* horde = zombieHorde(count, "Carl");
  for (int i = 0; i < count; ++i) horde[i].announce();
  std::cout << ">Destroying " << str << " Carls on heap" << std::endl;
  delete[] horde;
}
