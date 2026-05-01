/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:42:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 16:25:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  public:
	static const unsigned int max_memory = 100;

  private:
	std::string _ideas[Brain::max_memory];
	unsigned int _idea_count;
	unsigned int _newest;
	unsigned int _oldest;

  public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	void memorize(const std::string &idea);
	const std::string *think(unsigned int ideas_ago) const;
	unsigned int getIdeaCount(void) const;
};

#endif
