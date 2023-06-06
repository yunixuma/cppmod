/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/06 16:47:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
void	showBrain(const Brain& br) {
	std::cerr << "\033[33;2m" << br << ": " << br.getType() << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		std::cerr << "\t" << br.[i] << std::endl;
	}
}
*/

void	showBrain(const Animal& animal) {
	std::cerr << "\033[33;2m" << &animal << ": " << animal.getType() << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cerr << i << "\t" << &animal.getIdea(i) \
			<< "\t" << animal.getIdea(i) << std::endl;
}
/*
void	showCat(const Cat& animal) {
	std::cerr << "\033[33;2m" << &animal << ": " << animal.getType() << std::endl;
	for (size_t i = 0; i < 100; i++)
		std::cerr << i << "\t" << &animal.getIdea(i) \
			<< "\t" << animal.getIdea(i) << std::endl;
}
*/

int	main()
{
	std::cout << "\033[35;43mTest for Confirmation of the previous exercise\033[m" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		showBrain(*j);
		showBrain(*i);

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "\033[35;43mTest for deletion array of animals\033[m" << std::endl;
	{
		Animal*	animals;
		animals = new Animal[10];
		for (size_t i = 0; i < 5; i++)
		{
			animals[i] = Dog();
			animals[i + 5] = Cat();
		}

		for (size_t i = 0; i < 10; i++)
			showBrain(animals[i]);

		delete[] animals;
	}

	return 0;
}
