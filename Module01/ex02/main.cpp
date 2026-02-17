/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:40:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 15:50:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string origin = "HI THIS IS BRAIN";
	std::string *stringPTR = &origin;
	std::string &stringREF = origin;

	// memory address
	std::cout << "origin memory address: " << &origin << std::endl;
	std::cout << "stringPTR memory address: " << stringPTR << std::endl;
	std::cout << "stringREF memory address: " << &stringREF << std::endl;

	// value
	std::cout << "origin value: " << origin << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
}
