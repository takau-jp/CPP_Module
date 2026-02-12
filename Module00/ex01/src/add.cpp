/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:23:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:57:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

static bool readField(Contact &contact, const char *prompt,
					  bool (Contact::*setter)(const std::string &));

void add(PhoneBook &phone_book)
{
	Contact contact;

	if (!readField(contact, "First Name> ", &Contact::setFirstName))
		return;
	if (!readField(contact, "Last Name> ", &Contact::setLastName))
		return;
	if (!readField(contact, "Nickname> ", &Contact::setNickname))
		return;
	if (!readField(contact, "Phone Number> ", &Contact::setPhoneNumber))
		return;
	if (!readField(contact, "Darkest Secret> ", &Contact::setDarkestSecret))
		return;
	phone_book.setContact(contact);
}

static bool readField(Contact &contact, const char *prompt,
					  bool (Contact::*setter)(const std::string &))
{
	std::string input;

	while (true)
	{
		if (std::cout << prompt && std::getline(std::cin, input))
		{
			if ((contact.*setter)(input))
				return (true);
		}
		else
			return (false);
	}
}
