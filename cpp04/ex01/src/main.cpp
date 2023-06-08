/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 14:14:14 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	showBrain(const Animal& animal) {
	std::cerr << "\033[33;2m" << &animal << ": " << animal.getType() \
		<< "(" << sizeof(animal) << "bytes)" << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cerr << i << "\t" << animal.getIdea(i) \
			<< "\t{" << *animal.getIdea(i) << "}" << std::endl;
}

int	main()
{
	std::cout << std::endl << "\033[35;43mTest for confirmation of the previous exercise\033[m" << std::endl;
	{
		// const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		// meta->makeSound();
		j->makeSound();
		i->makeSound();

		// showBrain(*meta);
		showBrain(*j);
		showBrain(*i);

		// delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl << "\033[35;43mTest for looping over an array of animals\033[m" << std::endl;
	{
		const Animal	*animals[10];

		for (size_t k = 0; k < 5; k++)
		{
			animals[k] = new Dog();
			animals[k + 5] = new Cat();
		}

		for (size_t i = 0; i < 10; i++)
		{
			animals[i]->makeSound();
			showBrain(*animals[i]);
		}

		for (size_t i = 0; i < 10; i++)
			delete animals[i];
	}

	std::cout << std::endl << "\033[35;43mTest for copy constuctor and copy assignment operator\033[m" << std::endl;
	{
		std::cout << "\033[33mInstantiate Animal from Animal class\033[m" << std::endl;
		const Animal *meta0 = new Animal();
		const Animal meta1(*meta0);
		Animal *meta2 = new Animal();
		*meta2 = meta1;

		meta0->makeSound();
		meta1.makeSound();
		meta2->makeSound();

		delete meta0;
		delete meta2;

		std::cout << std::endl << "\033[33mInstantiate Animal from Dog class\033[m" << std::endl;
		const Animal* j0 = new Dog();
		const Animal j1(*j0);
		Animal* j2 = new Dog(); 
		*j2 = *j0;

		j0->makeSound();
		showBrain(*j0);
		j1.makeSound();
		showBrain(j1);
		j2->makeSound();
		// Copy assignment operator of the base class cannot be virtual
		showBrain(*j2);

		delete j0;
		delete j2;

		std::cout << std::endl << "\033[33mInstantiate Dog from Dog class\033[m" << std::endl;
		const Dog* j3 = new Dog();
		const Dog j4(*j3);
		Dog* j5 = new Dog(); 
		*j5 = j4;

		j3->makeSound();
		showBrain(*j3);
		j4.makeSound();
		showBrain(j4);
		j5->makeSound();
		showBrain(*j5);

		delete j3;
		delete j5;
	}

	return 0;
}
