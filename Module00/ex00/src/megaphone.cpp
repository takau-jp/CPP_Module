/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:48:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/11 21:39:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int toUpper(char c);
template <typename InputIterator, typename OutputIterator,
		  typename UnaryOperation>
OutputIterator ft_transform(InputIterator first, InputIterator last,
							OutputIterator result, UnaryOperation op);

int main(int argc, char *argv[])
{
	std::string msg;

	if (argc == 1)
	{
		msg = "* loud and unbearable feedback noise *";
		ft_transform(msg.begin(), msg.end(), msg.begin(), toUpper);
		std::cout << msg << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			msg = argv[i];
			ft_transform(msg.begin(), msg.end(), msg.begin(), toUpper);
			std::cout << msg;
		}
		std::cout << std::endl;
	}
}

int toUpper(char c)
{
	return std::toupper(static_cast<unsigned char>(c));
}

template <typename InputIterator, typename OutputIterator,
		  typename UnaryOperation>
OutputIterator ft_transform(InputIterator first, InputIterator last,
							OutputIterator result, UnaryOperation op)
{
	while (first != last)
		*result++ = op(*first++);
	return result;
}
