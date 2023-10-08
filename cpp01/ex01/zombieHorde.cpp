/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:03:21 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/08 10:25:31 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name = 0) {
  Zombie* horde = new Zombie[N];
  for (int i = 0; i < N; ++i) horde[i].setName(name);

  return horde;
}
