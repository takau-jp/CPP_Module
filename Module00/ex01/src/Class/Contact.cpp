/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:04:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:42:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

bool Contact::setField(std::string &field, const std::string &value)
{
	if (value.empty())
		return (false);
	field = value;
	return (true);
}

bool Contact::setFirstName(const std::string &first_name)
{
	return (setField(_first_name, first_name));
}

bool Contact::setLastName(const std::string &last_name)
{
	return (setField(_last_name, last_name));
}

bool Contact::setNickname(const std::string &nickname)
{
	return (setField(_nickname, nickname));
}

bool Contact::setPhoneNumber(const std::string &phone_number)
{
	return (setField(_phone_number, phone_number));
}

bool Contact::setDarkestSecret(const std::string &darkest_secret)
{
	return (setField(_darkest_secret, darkest_secret));
}

const std::string &Contact::getFirstName() const
{
	return (_first_name);
}

const std::string &Contact::getLastName() const
{
	return (_last_name);
}

const std::string &Contact::getNickname() const
{
	return (_nickname);
}

const std::string &Contact::getPhoneNumber() const
{
	return (_phone_number);
}

const std::string &Contact::getDarkestSecret() const
{
	return (_darkest_secret);
}
