/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 22:33:52 by ykosaka          ###   ########.fr       */
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
	std::cout << std::endl << "\033[35;43mSample test\033[m" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl << "\033[35;43mReplace the Cat by WrongCat class\033[m" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
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
		*j2 = j1;

		j0->makeSound();
		j1.makeSound();
		j2->makeSound();

		delete j0;
		delete j2;

		std::cout << std::endl << "\033[33mInstantiate Dog from Dog class\033[m" << std::endl;
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
