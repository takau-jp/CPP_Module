/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_is_for_losers.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:32:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/17 01:19:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_IS_FOR_LOSERS_HPP
#define SED_IS_FOR_LOSERS_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

std::string readFile(std::ifstream &infile);
std::string ftReplace(std::string s, const std::string &from,
					  const std::string &to);

#endif
