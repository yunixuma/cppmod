/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 10:36:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		// Animal* meta = new Animal();
		// Animal* j = new Dog();
		// Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\033[35;43mReplace the Cat by WrongCat class\033[m" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		// Animal* meta = new Animal();
		// Animal* j = new Dog();
		// Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\033[35;43mTest for copy constuctor and copy assignment operator\033[m" << std::endl;
	{
		const Animal *meta0 = new Animal();
		const Animal meta1(*meta0);
		Animal *meta2 = new Animal();
		*meta2 = meta1;

		meta0->makeSound();
		meta1.makeSound();
		meta2->makeSound();

		delete meta0;
		delete meta2;

		const Animal* j0 = new Dog();
		const Animal j1(*j0);
		Animal* j2 = new Dog(); 
		*j2 = j1;

		j0->makeSound();
		j1.makeSound();
		j2->makeSound();

		delete j0;
		delete j2;

		const Dog* j3 = new Dog();
		const Dog j4(*j3);
		Dog* j5 = new Dog(); 
		*j5 = j4;

		j3->makeSound();
		j4.makeSound();
		j5->makeSound();

		delete j3;
		delete j5;
	}

	return 0;
}
