/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:44:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 16:11:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.hpp"

std::string readFile(std::ifstream &infile)
{
	infile.seekg(0, std::ios::end);
	if (!infile)
		throw std::ios_base::failure("Failed to seek get");
	const std::streamsize file_size = infile.tellg();
	if (file_size == -1)
		throw std::ios_base::failure("Failed to get file size");
	infile.seekg(0, std::ios::beg);
	if (!infile)
		throw std::ios_base::failure("Failed to seek get");

	if (file_size == 0)
		return ("");
	std::string input(file_size, '\0');
	if (!infile.read(&input[0], file_size))
		throw std::ios_base::failure("Failed to read from file");
	return (input);
}
