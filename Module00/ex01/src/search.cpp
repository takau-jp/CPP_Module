/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:23:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:04:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

void search(const PhoneBook &phone_book)
{
	if (!displayPhoneBook(phone_book))
		return;

	const Contact *contact = selectContact(phone_book);
	if (contact == NULL)
		return;

	displayContact(*contact);
}
