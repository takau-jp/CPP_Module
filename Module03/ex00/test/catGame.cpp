/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catGame.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 04:15:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/08 04:32:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "ClapTrap.hpp"

enum e_action
{
	ATTACK,
	BE_REPAIRED,
	TAKE_DAMAGE,
	DEAD,
	NO_ENERGY,
	RANDOM
};

void printStatus(std::vector<ClapTrap> &cats);
std::string hpBar(unsigned int hp);
void doAction(std::vector<ClapTrap> &cats, int action);
void printCat(int action);

void catGame()
{
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

		std::vector<ClapTrap> cats;
		cats.reserve(cat_count);
		for (int i = 0; i < cat_count; ++i)
		{
			std::stringstream ss;
			ss << i;
			cats.push_back("cat" + ss.str());
		}

		printStatus(cats);

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
				doAction(cats, ATTACK);
			else if (input == "1")
				doAction(cats, BE_REPAIRED);
			else if (input == "2")
				doAction(cats, TAKE_DAMAGE);
			else if (input == "3")
			{
				std::cout << "EXIT\n" << std::endl;
				break;
			}
			else
				doAction(cats, RANDOM);
			std::cout << std::endl;
			printStatus(cats);
			std::cout << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void printStatus(std::vector<ClapTrap> &cats)
{
	std::cout << "==================================" << std::endl;
	for (size_t i = 0; i < cats.size(); ++i)
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

void printCat(int action)
{
	if (action == ATTACK)
	{
		std::cout << "   /\\_/\\          /\\_/\\" << std::endl;
		std::cout << "  ( >`ω´<)ﾉ <<*  ( ;ω; )" << std::endl;
		std::cout << "  /|   |\\        /|  |\\" << std::endl;
		std::cout << " (_|   |_)      (_|  |_)" << std::endl;
	}
	else if (action == BE_REPAIRED)
	{
		std::cout << "   /\\_/\\" << std::endl;
		std::cout << "  ( ^ω^ )  purr..." << std::endl;
		std::cout << "  /| + |\\" << std::endl;
		std::cout << " (_|   |_)" << std::endl;
	}
	else if (action == TAKE_DAMAGE)
	{
		std::cout << "   /\\_/\\" << std::endl;
		std::cout << "  ( ;ω; )  * OUCH!" << std::endl;
		std::cout << "  /|  |\\" << std::endl;
		std::cout << " (_|  |_)" << std::endl;
	}
	else if (action == DEAD)
	{
		std::cout << "    |\\ _,,,---,,_" << std::endl;
		std::cout << "    /,`.-'`'    -.  ;-;;,_" << std::endl;
		std::cout << "   |,4-  ) )-,_..; \\ (  `'-'" << std::endl;
		std::cout << "  '---''(_/--'  `-'\\_)" << std::endl;
	}
	else // NO_ENERGY
	{
		std::cout << "   /\\_/\\" << std::endl;
		std::cout << "  ( -ω-)  zzz..." << std::endl;
		std::cout << "  /|   |\\" << std::endl;
		std::cout << " (_|   |_)" << std::endl;
	}
	std::cout << std::endl;
}

void doAction(std::vector<ClapTrap> &cats, int action)
{
	if (action == RANDOM)
		action = rand() % 3; // 0: attack, 1: beRepaired, 2: takeDamage

	if (action == ATTACK)
	{
		int attacker = rand() % cats.size();
		int target = rand() % cats.size();
		if (cats.size() != 1)
		{
			while (attacker == target)
				target = rand() % cats.size();
		}

		std::cout << cats[attacker].getName() << ".attack("
				  << cats[target].getName() << ")\n"
				  << std::endl;
		if (!cats[attacker].getHitPoints())
			printCat(DEAD);
		else if (!cats[attacker].getEnergyPoints())
			printCat(NO_ENERGY);
		else
			printCat(action);
		cats[attacker].attack(cats[target].getName());
	}
	else if (action == BE_REPAIRED)
	{
		int actor = rand() % cats.size();
		unsigned int amount = rand() % 20;

		std::cout << cats[actor].getName() << ".beRepaired(" << amount << ")\n"
				  << std::endl;
		if (!cats[actor].getHitPoints())
			printCat(DEAD);
		else if (!cats[actor].getEnergyPoints())
			printCat(NO_ENERGY);
		else
			printCat(action);

		cats[actor].beRepaired(amount);
	}
	else
	{
		int actor = rand() % cats.size();
		unsigned int amount = rand() % 20;

		std::cout << cats[actor].getName() << ".takeDamage(" << amount << ")\n"
				  << std::endl;
		if (!cats[actor].getHitPoints())
			printCat(DEAD);
		else
			printCat(action);

		cats[actor].takeDamage(amount);
	}
}
