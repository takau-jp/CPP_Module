/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:04:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:43:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

PhoneBook::PhoneBook() : _next_index(0), _number_of_registrations(0)
{
}

void PhoneBook::setContact(const Contact &contact)
{
	_contacts[_next_index] = contact;
	if (_number_of_registrations < MAX_CONTACTS)
		++_number_of_registrations;
	_next_index = (_next_index + 1) % MAX_CONTACTS;
}

const Contact *PhoneBook::getContact(int index) const
{
	if (index < 0 || _number_of_registrations <= index)
	{
		return (NULL);
	}
	return (&(_contacts[index]));
}
