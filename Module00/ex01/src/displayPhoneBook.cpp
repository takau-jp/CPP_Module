/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayPhoneBook.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:37:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:57:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

static void printHeader();
static void printColumn(const std::string &value);

bool displayPhoneBook(const PhoneBook &phone_book)
{
	for (int i = 0; i < PhoneBook::MAX_CONTACTS; i++)
	{
		const Contact *contact = phone_book.getContact(i);
		if (contact == NULL)
		{
			if (i == 0)
			{
				std::cout << "There is no contact." << std::endl;
				return (false);
			}
			return (true);
		}
		if (i == 0)
		{
			printHeader();
		}
		std::cout << std::right << std::setw(10) << i << "|";
		printColumn(contact->getFirstName());
		std::cout << "|";
		printColumn(contact->getLastName());
		std::cout << "|";
		printColumn(contact->getNickname());
		std::cout << std::endl;

		if (!std::cout)
			return (false);
	}
	return (true);
}

static void printHeader()
{
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
}

static void printColumn(const std::string &value)
{
	if (value.length() <= 10)
		std::cout << std::right << std::setw(10) << value;
	else
		std::cout << value.substr(0, 9) << ".";
}
