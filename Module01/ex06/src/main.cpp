/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:05:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 18:34:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	try
	{
		Harl harl;

		if (argc == 1)
		{
			std::cout << "===TEST: DEBUG===" << std::endl;
			harl.complain("DEBUG");

			std::cout << "===TEST: INFO===" << std::endl;
			harl.complain("INFO");

			std::cout << "===TEST: WARNING===" << std::endl;
			harl.complain("WARNING");

			std::cout << "===TEST: ERROR===" << std::endl;
			harl.complain("ERROR");

			std::cout << "===TEST: HELLO===" << std::endl;
			harl.complain("HELLO");
		}
		else
		{
			for (int i = 1; i < argc; ++i)
			{
				std::cout << "===TEST: " << argv[i] << "===" << std::endl;
				harl.complain(argv[i]);
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
