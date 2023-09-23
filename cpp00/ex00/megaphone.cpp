/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:52:06 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/23 13:52:35 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, const char **argv)
{
	if (argc == 1)
	{
		std::cout << DEFAULT << std::endl;
		return (0);
	}
	std::string str;
	for (int i = 1; i < argc; ++i)
	{
		str += argv[i];
		if (i < argc - 1)
			str += ' ';
	}
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		*it = std::toupper(*it);
	}
	std::cout << str << std::endl;
	return (0);
}
