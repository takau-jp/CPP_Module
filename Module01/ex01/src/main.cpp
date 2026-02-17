/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:46:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 16:05:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie_horde1 = NULL;
	Zombie *zombie_horde2 = NULL;
	Zombie *zombie_horde3 = NULL;
	Zombie stack_zombie_horde1[3];

	try
	{
		zombie_horde1 = zombieHorde(10, "Tom");
		for (int i = 0; i < 10; ++i)
		{
			zombie_horde1[i].announce();
		}
		std::cout << std::endl;

		stack_zombie_horde1[0].setName("Jim");
		stack_zombie_horde1[1] = Zombie("James");
		for (int i = 0; i < 3; ++i)
		{
			stack_zombie_horde1[i].announce();
		}
		std::cout << std::endl;

		zombie_horde2 = zombieHorde(2, "Tom");
		zombie_horde2[1].setName("Tim");
		for (int i = 0; i < 2; ++i)
		{
			zombie_horde2[i].announce();
		}
		std::cout << std::endl;

		Zombie stack_zombie_horde2[3]; 
		stack_zombie_horde2[0].setName("Bob");
		stack_zombie_horde2[1] = Zombie("Bobby");
		for (int i = 0; i < 3; ++i)
		{
			stack_zombie_horde2[i].announce();
		}
		std::cout << std::endl;

		zombie_horde3 = zombieHorde(5, "Alice");
		for (int i = 0; i < 5; ++i)
		{
			zombie_horde3[i].announce();
		}
		std::cout << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (const std::bad_alloc &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	delete[] zombie_horde1;
	std::cout << std::endl;
	delete[] zombie_horde3;
	std::cout << std::endl;
	delete[] zombie_horde2;
	std::cout << std::endl;
}
