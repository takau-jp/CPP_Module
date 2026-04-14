/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 04:15:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 19:52:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <new>
#include <sstream>

#include "ClapTrap.hpp"

enum e_action
{
	ATTACK,
	BE_REPAIRED,
	TAKE_DAMAGE,
	RANDOM
};

void printStatus(ClapTrap *cats, int cat_count);
std::string hpBar(unsigned int hp);
void doAction(ClapTrap *cats, int cat_count, int action);

void game()
{
	ClapTrap *cats = NULL;

	try
	{
		srand(std::time(NULL));

		int cat_count = 2;

		std::string count;
		while (true)
		{
			std::cout << "How many cats? (2-10, Enter for default=2): ";
			if (!std::getline(std::cin, count))
				return;
			if (count.empty() || count == "2")
				cat_count = 2;
			else if (count == "3")
				cat_count = 3;
			else if (count == "4")
				cat_count = 4;
			else if (count == "5")
				cat_count = 5;
			else if (count == "6")
				cat_count = 6;
			else if (count == "7")
				cat_count = 7;
			else if (count == "8")
				cat_count = 8;
			else if (count == "9")
				cat_count = 9;
			else if (count == "10")
				cat_count = 10;
			else
				continue;
			break;
		}

		cats = new ClapTrap[cat_count];
		for (int i = 0; i < cat_count; ++i)
		{
			std::stringstream ss;
			ss << i;
			cats[i] = ClapTrap("cat" + ss.str());
		}

		printStatus(cats, cat_count);

		std::string input;
		while (true)
		{
			std::cout << "----------------------------------------"
					  << std::endl;
			std::cout << "[Enter: random | 0: attack | 1: repair | 2: damage | "
						 "3: exit]"
					  << std::endl;
			std::cout << "> ";
			if (!getline(std::cin, input))
				break;
			std::cout << "\n" << std::endl;
			if (input == "0")
				doAction(cats, cat_count, ATTACK);
			else if (input == "1")
				doAction(cats, cat_count, BE_REPAIRED);
			else if (input == "2")
				doAction(cats, cat_count, TAKE_DAMAGE);
			else if (input == "3")
			{
				std::cout << "EXIT\n" << std::endl;
				break;
			}
			else
				doAction(cats, cat_count, RANDOM);
			std::cout << std::endl;
			printStatus(cats, cat_count);
			std::cout << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	delete[] cats;
}

void printStatus(ClapTrap *cats, int cat_count)
{
	std::cout << "==================================" << std::endl;
	for (int i = 0; i < cat_count; ++i)
	{
		std::cout << " " << cats[i].getName() << "\tHP " << std::setw(3)
				  << cats[i].getHitPoints() << " "
				  << hpBar(cats[i].getHitPoints()) << "  EP: " << std::setw(2)
				  << cats[i].getEnergyPoints() << std::endl;
	}
	std::cout << "================================== " << std::endl;
}

std::string hpBar(unsigned int hp)
{
	const unsigned int width = 10;
	std::string bar;

	for (unsigned int i = 0; i < width; i++)
		bar += (i < hp) ? "█" : "-";
	return (bar);
}

void doAction(ClapTrap *cats, int cat_count, int action)
{
	if (action == RANDOM)
		action = rand() % 3; // 0: attack, 1: beRepaired, 2: takeDamage

	if (action == ATTACK)
	{
		int attacker = rand() % cat_count;
		int target = rand() % cat_count;
		if (cat_count != 1)
		{
			while (attacker == target)
				target = rand() % cat_count;
		}

		std::cout << cats[attacker].getName() << ".attack("
				  << cats[target].getName() << ")" << std::endl;

		cats[attacker].attack(cats[target].getName());
	}
	else if (action == BE_REPAIRED)
	{
		int actor = rand() % cat_count;
		unsigned int amount = rand() % 20;

		std::cout << cats[actor].getName() << ".beRepaired(" << amount << ")"
				  << std::endl;

		cats[actor].beRepaired(amount);
	}
	else
	{
		int actor = rand() % cat_count;
		unsigned int amount = rand() % 20;

		std::cout << cats[actor].getName() << ".takeDamage(" << amount << ")"
				  << std::endl;

		cats[actor].takeDamage(amount);
	}
}
