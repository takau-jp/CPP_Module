/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:39:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/15 16:47:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

int main(void)
{
	ScavTrap Tom("Tom");

	std::cout << std::endl;
	Tom.attack("Alice");
	Tom.takeDamage(10);
	Tom.beRepaired(20);
	Tom.guardGate();
}

// // Game Mode
// void game(void);

// int main(void)
// {
// 	game();
// }
