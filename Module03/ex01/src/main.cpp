/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:39:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/09 02:46:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

int main(void)
{
	ScavTrap Tom;
	Tom = ScavTrap("Tom");
	ScavTrap Bill(ScavTrap("Bill"));

	std::cout << std::endl;
	std::cout << "==================== Tom ====================" << std::endl;
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.guardGate();
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.attack(Bill.getName());
	Tom.beRepaired(8);

	std::cout << std::endl;
	std::cout << "==================== Bill ====================" << std::endl;
	Bill.takeDamage(8);
	Bill.attack(Tom.getName());
	Bill.beRepaired(8);
	Bill.attack(Tom.getName());
	Bill.takeDamage(8);
	Bill.attack(Tom.getName());
	Bill.takeDamage(8);
	Bill.attack(Tom.getName());
	Bill.takeDamage(8);

	std::cout << std::endl;
}

// // Game Mode
// void game(void);

// int main(void)
// {
// 	game();
// }
