/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:38:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 14:05:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

static bool parseIntStrict(const std::string &input, int &index);

const Contact *selectContact(const PhoneBook &phone_book)
{
	while (true)
	{
		std::string input;
		if (!(std::cout << "Enter the index of the contact.> ") ||
			!std::getline(std::cin, input))
		{
			return (NULL);
		}
		if (input.empty())
			continue;
		int index;
		if (!parseIntStrict(input, index))
		{
			std::cout << "Please enter a valid integer." << std::endl;
			continue;
		}
		const Contact *contact = phone_book.getContact(index);
		if (contact == NULL)
		{
			std::cout << index << " is out of range." << std::endl;
			continue;
		}
		return (contact);
	}
}

static bool parseIntStrict(const std::string &input, int &index)
{
	std::stringstream ss(input);
	ss >> index;
	// !ss: conversion failed,
	// !ss.eof(): trailing non-digit chars (e.g."123abc")
	if (!ss || !ss.eof())
		return (false);

	std::stringstream ss2;
	ss2 << index;

	// round-trip check (e.g."001", " 1 ", "+1", overflow)
	if (input != ss2.str())
		return (false);
	return (true);
}
