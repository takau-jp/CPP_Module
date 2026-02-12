/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:15:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:43:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "my_awesome_phonebook.hpp"

class Contact
{
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	bool setField(std::string &field, const std::string &value);

  public:
	bool setFirstName(const std::string &first_name);
	bool setLastName(const std::string &last_name);
	bool setNickname(const std::string &nickname);
	bool setPhoneNumber(const std::string &phone_number);
	bool setDarkestSecret(const std::string &darkest_secret);
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNumber() const;
	const std::string &getDarkestSecret() const;
};

#endif
