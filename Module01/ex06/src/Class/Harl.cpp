/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:05:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 18:25:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-specialketchup burger."
			  << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
			  << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
			  << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here "
				 "just last month."
			  << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	static void (Harl::*comments[4])(void) = {&Harl::debug, &Harl::info,
									   &Harl::warning, &Harl::error};
	static std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					(this->*comments[0])();
				case 1:
					(this->*comments[1])();
				case 2:
					(this->*comments[2])();
				case 3:
					(this->*comments[3])();
					return;
				default:
					throw std::runtime_error("Unexpected LEVEL");
			}
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]"
			  << std::endl;
}
