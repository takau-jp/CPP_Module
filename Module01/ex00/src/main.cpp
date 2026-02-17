/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:00:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 16:05:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = NULL;
	Zombie *zombie2 = NULL;
	Zombie *zombie3 = NULL;

	try
	{
		zombie1 = newZombie("Tom");
		zombie1->announce();
		std::cout << std::endl;

		randomChump("Jim");
		std::cout << std::endl;

		zombie2 = newZombie("Terry");
		zombie2->announce();
		std::cout << std::endl;

		randomChump("Bob");
		std::cout << std::endl;

		zombie3 = newZombie("Alice");
		zombie3->announce();
		std::cout << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	delete zombie1;
	std::cout << std::endl;
	delete zombie3;
	std::cout << std::endl;
	delete zombie2;
}
