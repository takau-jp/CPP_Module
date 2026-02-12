/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:15:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 13:43:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "my_awesome_phonebook.hpp"

class PhoneBook
{
  public:
	static const int MAX_CONTACTS = 8;

  private:
	int _next_index;
	int _number_of_registrations;
	Contact _contacts[MAX_CONTACTS];

  public:
	PhoneBook();
	void setContact(const Contact &contact);
	const Contact *getContact(int index) const;
};

#endif
