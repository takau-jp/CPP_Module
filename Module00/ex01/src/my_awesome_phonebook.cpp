/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:09:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 23:01:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

int main(void)
{
	PhoneBook phone_book;
	std::string command;

	while (true)
	{
		if (std::cout << "COMMAND (ADD / SEARCH / EXIT)> " &&
			std::getline(std::cin, command))
		{
			if (command == "ADD")
				add(phone_book);
			else if (command == "SEARCH")
				search(phone_book);
			else if (command == "EXIT")
				return (0);
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		if (std::cout.fail() || std::cin.fail())
			return (1);
	}
}
