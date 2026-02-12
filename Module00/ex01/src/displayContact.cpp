/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayContact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:39:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:57:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

static void printField(const char *field, const std::string &value);

void displayContact(const Contact &contact)
{
	printField("First Name", contact.getFirstName());
	printField("Last Name", contact.getLastName());
	printField("Nickname", contact.getNickname());
	printField("Phone Number", contact.getPhoneNumber());
	printField("Darkest Secret", contact.getDarkestSecret());
}

static void printField(const char *field, const std::string &value)
{
	std::cout << std::left << std::setw(15) << field << ": " << value
			  << std::endl;
}
