/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:39:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 19:23:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int main(void)
{
	{
		std::cout << "==================== Tom ===================="
				  << std::endl;
		ClapTrap Tom;
		Tom = ClapTrap("Tom");
		std::cout << std::endl;
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.beRepaired(8);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "==================== Bill ===================="
				  << std::endl;
		ClapTrap Bill(ClapTrap("Bill"));
		std::cout << std::endl;
		Bill.takeDamage(8);
		Bill.attack("Alice");
		Bill.beRepaired(8);
		Bill.attack("Alice");
		Bill.takeDamage(8);
		Bill.attack("Alice");
		Bill.takeDamage(8);
		Bill.attack("Alice");
		Bill.takeDamage(8);
		std::cout << std::endl;
	}
}

// // Game Mode
// void game(void);

// int main(void)
// {
// 	game();
// }
