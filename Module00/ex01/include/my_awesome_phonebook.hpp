/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:16:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/12 12:41:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_AWESOME_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

void add(PhoneBook &phone_book);

void search(const PhoneBook &phone_book);
bool displayPhoneBook(const PhoneBook &phone_book);
const Contact *selectContact(const PhoneBook &phone_book);
void displayContact(const Contact &contact);

#endif
