/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 00:00:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 19:50:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "DiamondTrap.hpp"
#include "Game.hpp"

static int getTeamSize(void);
static std::string hpBar(unsigned int hp, unsigned int max_hp);

void game(void)
{
	try
	{
		int count = getTeamSize();
		if (count < 0)
		{
			std::cout << std::endl;
			return;
		}
		Game g(count);
		g.run();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

static int getTeamSize(void)
{
	std::string input;
	while (true)
	{
		std::cout << "How many DiamondTraps? (2-10, Enter for default=2): ";
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				return (-1);
			else
				throw std::ios_base::failure("Failed to read input.");
		}
		if (input.empty() || input == "2")
			return (2);
		else if (input == "3")
			return (3);
		else if (input == "4")
			return (4);
		else if (input == "5")
			return (5);
		else if (input == "6")
			return (6);
		else if (input == "7")
			return (7);
		else if (input == "8")
			return (8);
		else if (input == "9")
			return (9);
		else if (input == "10")
			return (10);
	}
}

Game::Game(int count) : _diamonds(NULL), _count(count)
{
	try
	{
		_diamonds = new DiamondTrap *[count];
		for (int i = 0; i < count; ++i)
			_diamonds[i] = NULL;

		for (int i = 0; i < count; ++i)
		{
			std::stringstream ss;
			ss << i;
			_diamonds[i] = new DiamondTrap("Diamond" + ss.str());
		}
	}
	catch (...)
	{
		if (_diamonds != NULL)
		{
			for (int i = 0; i < count; ++i)
				delete _diamonds[i];
			delete[] _diamonds;
		}
		throw;
	}
}

Game::~Game()
{
	for (int i = 0; i < _count; ++i)
		delete _diamonds[i];
	delete[] _diamonds;
}

void Game::run()
{
	srand(std::time(NULL));

	std::cout << "\n=== Battle Start! ===" << std::endl;
	printStatus();

	int turn = 1;
	while (!isOver())
	{
		std::cout << "======================================== TURN " << turn++
				  << " ========================================" << std::endl;
		if (!doTurn())
			break;
		std::cout << std::endl;
		printStatus();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Game::printStatus() const
{
	std::cout << "========== DiamondTrap Team ==========" << std::endl;
	for (int i = 0; i < _count; ++i)
	{
		unsigned int hp = _diamonds[i]->getHitPoints();
		std::cout << " " << std::setw(10) << _diamonds[i]->getName() << "  HP "
				  << std::setw(3) << hp << " [" << hpBar(hp, 100) << "]"
				  << "  EP " << std::setw(2) << _diamonds[i]->getEnergyPoints()
				  << (hp == 0 ? "  [DEAD]" : "") << std::endl;
	}
	std::cout << "======================================" << std::endl;
}

static std::string hpBar(unsigned int hp, unsigned int max_hp)
{
	const unsigned int width = 10;
	std::string bar;

	for (unsigned int i = 0; i < width; i++)
		bar += (i < hp * width / (max_hp ? max_hp : 1)) ? "█" : "-";
	return (bar);
}

bool Game::isOver() const
{
	int alive = 0;
	for (int i = 0; i < _count; ++i)
		if (_diamonds[i]->getHitPoints() > 0)
			++alive;
	return (alive <= 1);
}

bool Game::doTurn(void)
{
	std::string input;
	e_action action;
	int actor = rand() % _count;

	std::cout << "[Action] Enter: random | 0: attack | 1: beRepaired | "
				 "2: whoAmI | 3: guardGate | 4: highFivesGuys | q: exit"
			  << std::endl;
	std::cout << "> ";
	if (!std::getline(std::cin, input))
		return (false);
	std::cout << std::endl;

	if (input == "q")
	{
		std::cout << "EXIT" << std::endl;
		return (false);
	}

	if (input == "0")
		action = ATTACK;
	else if (input == "1")
		action = BE_REPAIRED;
	else if (input == "2")
		action = WHO_AM_I;
	else if (input == "3")
		action = GUARD_GATE;
	else if (input == "4")
		action = HIGH_FIVES;
	else
		action = (e_action)(rand() % 5);

	if (action == ATTACK)
	{
		if (_count == 1)
		{
			std::cout << _diamonds[0]->getName() << " has no target!"
					  << std::endl;
			return (true);
		}
		int target = rand() % _count;
		while (target == actor)
			target = rand() % _count;

		std::cout << _diamonds[actor]->getName() << "->attack("
				  << _diamonds[target]->getName() << ")" << std::endl;
		_diamonds[actor]->attack(_diamonds[target]->getName());

		std::cout << std::endl;

		std::cout << _diamonds[target]->getName() << "->takeDamage("
				  << _diamonds[actor]->getAttackDamage() << ")" << std::endl;
		_diamonds[target]->takeDamage(_diamonds[actor]->getAttackDamage());
	}
	else if (action == BE_REPAIRED)
	{
		unsigned int amount = rand() % 20 + 1;
		std::cout << _diamonds[actor]->getName() << "->beRepaired(" << amount
				  << ")" << std::endl;
		_diamonds[actor]->beRepaired(amount);
	}
	else if (action == WHO_AM_I)
	{
		std::cout << _diamonds[actor]->getName() << "->whoAmI()" << std::endl;
		_diamonds[actor]->whoAmI();
	}
	else if (action == GUARD_GATE)
	{
		std::cout << _diamonds[actor]->getName() << "->guardGate()"
				  << std::endl;
		_diamonds[actor]->guardGate();
	}
	else
	{
		std::cout << _diamonds[actor]->getName() << "->highFivesGuys()"
				  << std::endl;
		_diamonds[actor]->highFivesGuys();
	}
	return (true);
}
