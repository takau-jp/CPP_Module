/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:39:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/15 23:23:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

int main(void)
{
	{
		std::cout << "==================== Tom ===================="
				  << std::endl;
		DiamondTrap Tom;
		Tom = DiamondTrap("Tom");
		std::cout << std::endl;
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.whoAmI();
		Tom.guardGate();
		Tom.highFivesGuys();
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.attack("Alice");
		Tom.beRepaired(20);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "==================== Bill ===================="
				  << std::endl;
		DiamondTrap Bill(DiamondTrap("Bill"));
		std::cout << std::endl;
		Bill.takeDamage(20);
		Bill.attack("Alice");
		Bill.beRepaired(20);
		Bill.attack("Alice");
		Bill.takeDamage(20);
		Bill.attack("Alice");
		Bill.takeDamage(20);
		Bill.attack("Alice");
		Bill.takeDamage(20);
		Bill.attack("Alice");
		Bill.takeDamage(20);
		Bill.attack("Alice");
		Bill.takeDamage(20);
		Bill.attack("Alice");
		Bill.takeDamage(20);
		Bill.whoAmI();
		Bill.guardGate();
		Bill.highFivesGuys();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "===== Clap =====" << std::endl;
		ClapTrap *Clap = new DiamondTrap("Clap");
		std::cout << std::endl;
		Clap->attack("Alice");
		std::cout << std::endl;
		delete Clap;
	}

	std::cout << std::endl;

	{
		std::cout << "===== Scav =====" << std::endl;
		ScavTrap *Scav = new DiamondTrap("Scav");
		std::cout << std::endl;
		Scav->attack("Alice");
		std::cout << std::endl;
		delete Scav;
	}

	std::cout << std::endl;

	{
		std::cout << "===== Frag =====" << std::endl;
		FragTrap *Frag = new DiamondTrap("Frag");
		std::cout << std::endl;
		Frag->attack("Alice");
		std::cout << std::endl;
		delete Frag;
	}

	std::cout << std::endl;

	{
		std::cout << "===== Diamond =====" << std::endl;
		DiamondTrap *Diamond = new DiamondTrap("Diamond");
		std::cout << std::endl;
		Diamond->attack("Alice");
		std::cout << std::endl;
		delete Diamond;
	}

	std::cout << std::endl;
}

// // Game Mode
// void game(void);

// int main(void)
// {
// 	game();
// }
