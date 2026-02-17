/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:32:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 18:35:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.hpp"

void sed_is_for_losers(const std::string &filename, const std::string &from,
					   const std::string &to);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <from> <to>"
				  << std::endl;
		return (1);
	}

	try
	{
		const std::string filename = argv[1];
		const std::string from = argv[2];
		const std::string to = argv[3];

		if (from.empty())
			throw std::invalid_argument("<from> must not be empty");

		sed_is_for_losers(filename, from, to);
		return (0);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
}

void sed_is_for_losers(const std::string &filename, const std::string &from,
					   const std::string &to)
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
		throw std::ios_base::failure("Could not open " + filename);

	const std::string input = readFile(infile);

	const std::string replaced = ftReplace(input, from, to);

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
		throw std::ios_base::failure("Could not open " + filename + ".replace");

	outfile << replaced;
	if (!outfile)
		throw std::ios_base::failure("Failed to write to " + filename +
									 ".replace");
	outfile.close();
	if (!outfile)
		throw std::ios_base::failure("Failed to close file");
}
