/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/23 16:44:14 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    PhoneBook pb = PhoneBook();
    std::string command;
    while (1)
    {
        std::getline(std::cin, command);
        if (command.compare("EXIT"))
            exit(0);
    }
    return 0;
}