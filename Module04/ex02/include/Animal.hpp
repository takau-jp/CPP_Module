/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 20:13:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>

class Animal
{
  protected:
	std::string type;

	Animal();
	Animal(const Animal &other);
	explicit Animal(const std::string &type);
	Animal &operator=(const Animal &other);

  public:
	virtual ~Animal();
	virtual void makeSound() const = 0;
	const std::string &getType() const;
};

#endif
