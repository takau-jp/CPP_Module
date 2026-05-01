/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 20:13:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// WrongAnimalとWrongCatは不使用
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

void create_animals(Animal **animals, const unsigned int size);
void input_ideas(Animal **animals, const unsigned int size);
void deep_copy_test(Animal **animals, const unsigned int size);
void speak_idea(Animal **animals, const unsigned int size, unsigned int ideas_ago);

int main()
{
	const unsigned int size = 10;
	if (size < 4)
	{
		std::cout << "The size of the animal sequence must be greater than 4.";
		return (EXIT_FAILURE);
	}
	Animal *animals[size] = {};

	try
	{
		create_animals(animals, size);

		input_ideas(animals, size);
		deep_copy_test(animals, size);

		speak_idea(animals, size, 0);
		speak_idea(animals, size, 1);
		speak_idea(animals, size, 2);
		speak_idea(animals, size, 98);
		speak_idea(animals, size, 99);
		speak_idea(animals, size, 100);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== destructor =====" << std::endl;

	for (unsigned int i = size; i > 0; i--)
		delete animals[i - 1];

	return (0);
}


/*
animalsのポインターを持つ配列を、CatとDogで半分ずつ埋める
*/
void create_animals(Animal **animals, const unsigned int size)
{
	std::cout << "===== create_animals =====" << std::endl;

	for (unsigned int i = 0; i < size / 2; i++)
		animals[i] = new Cat();
	for (unsigned int i = size / 2; i < size; i++)
		animals[i] = new Dog();
}

/*
ideas.txtから読み込んでそれぞれに記憶させる。
後のdeep_copy_testのために、i == 0 || i == size / 2には記憶させない。
*/
void input_ideas(Animal **animals, const unsigned int size)
{
	std::cout << "===== input_ideas =====" << std::endl;

	std::ifstream ifs("ideas.txt");
	if (!ifs)
		throw std::ios_base::failure("Failed to open ideas.txt");
	
	std::string input;
	while (std::getline(ifs, input))
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (i == 0 || i == size / 2)
				continue;

			Cat *cat = dynamic_cast<Cat *>(animals[i]);
			if (cat != NULL)
			{
				cat->memorize(input);
				continue;
			}
			Dog *dog = dynamic_cast<Dog *>(animals[i]);
			if (dog != NULL)
			{
				dog->memorize(input);
				continue;
			}
			assert(false);
		}
	}

	if (!ifs.eof() && !ifs)
		throw std::ios_base::failure("Failed to read file");
}

/*
deep copyのテスト
i == 0 は i == 1から、i == size / 2 は　i == size / 2 + 1からコピー後、
Hello Worldを新規追加する。
(size >= 4)
*/ 
void deep_copy_test(Animal **animals, const unsigned int size)
{
	std::cout << "===== deep_copy_test =====" << std::endl;

	Cat *dest_cat = dynamic_cast<Cat *>(animals[0]);
	Cat *src_cat = dynamic_cast<Cat *>(animals[1]);
	if (dest_cat != NULL && src_cat != NULL)
	{
		*dest_cat = Cat(*src_cat);
		dest_cat->memorize("Hello World!!");
	}
	else
		assert(false);
	
	Dog *dest_dog = dynamic_cast<Dog *>(animals[size / 2]);
	Dog *src_dog = dynamic_cast<Dog *>(animals[size / 2 + 1]);
	if (dest_dog != NULL && src_dog != NULL)
	{
		*dest_dog = Dog(*src_dog);
		dest_dog->memorize("Hello World!!");
	}
	else
		assert(false);
}

/*
引数に指定したオフセット分前のアイデアを出力する。
ideas_ago == 0 最新のアイデア
ideas_ago == 1 最新から1つ前に覚えさせたアイデア
ideas_ago == 99 覚えている最古のアイデア
*/
void speak_idea(Animal **animals, const unsigned int size, unsigned int ideas_ago)
{
	std::cout << "===== speak_idea(" << ideas_ago << ") =====" << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "[TEST] animals[" << i << "]: ";
		Cat *cat = dynamic_cast<Cat *>(animals[i]);
		if (cat != NULL)
		{
			cat->speak(ideas_ago);
			continue;
		}
		Dog *dog = dynamic_cast<Dog *>(animals[i]);
		if (dog != NULL)
		{
			dog->speak(ideas_ago);
			continue;
		}
		assert(false);
	}
}
