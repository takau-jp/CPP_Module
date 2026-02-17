/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:32:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 01:19:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.hpp"

std::string ftReplace(std::string s, const std::string &from,
					  const std::string &to)
{
	std::string::size_type pos = 0;

	while ((pos = s.find(from, pos)) != std::string::npos)
	{
		s.erase(pos, from.length());
		s.insert(pos, to);
		pos += to.length();
	}
	return (s);
}
