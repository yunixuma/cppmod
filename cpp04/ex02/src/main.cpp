/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 02:24:22 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	showBrain(const AAnimal& animal) {
	std::clog << "\033[33;2m" << &animal << ": " << animal.getType() \
		<< "(" << sizeof(animal) << "bytes)" << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::clog << i << "\t" << animal.getIdea(i) \
			<< "\t{" << *animal.getIdea(i) << "}" << std::endl;
	std::clog << "\033[m";
}

int	main()
{
	std::cout << "\033[35;43mTest for basic behaviors\033[m" << std::endl;
	{
// Impossible to use the Animal class due to abstract class
		// const AAnimal* meta = new AAnimal();
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		// const Dog* j = new Dog();
		// const Cat* i = new Cat();

		// showBrain(meta);
		j->makeSound();
		showBrain(*j);
		i->makeSound();
		showBrain(*i);

		// delete meta;
		delete j;
		delete i;
	}
	std::cout << "\033[35;43mTest for deletion array of animals\033[m" << std::endl;
	{
/* Impossible to compile for trying to instantiate the abstract Animal class
		AAnimal*	animals;
		animals = new AAnimal[10];

		for (size_t i = 0; i < 5; i++)
		{
			animals[i] = Dog();
			animals[i + 5] = Cat();
		}

		for (size_t i = 0; i < 10; i++)
			showBrain(animals[i]);

		delete[] animals;
*/
		Dog*	dogs;
		dogs = new Dog[5];

		for (size_t i = 0; i < 5; i++)
		{
			dogs[i] = Dog();
		}

		for (size_t i = 0; i < 5; i++)
		{
			dogs[i].makeSound();
			showBrain(dogs[i]);
		}

		delete[] dogs;
	}
/* Impossible to compile for trying to instantiate the abstract Animal class
	std::cout << "\033[35;43mTest for looping over an array of animals\033[m" << std::endl;
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		const AAnimal	*animals[10];

		for (size_t k = 0; k < 5; k++)
		{
			animals[k] = new AAnimal(*j);
			animals[k + 5] = new AAnimal(*i);
		}

		for (size_t i = 0; i < 10; i++)
			showBrain(*animals[i]);

		for (size_t i = 0; i < 10; i++)
		{
			// std::cerr << "\033[2;3m" << i << "\033[m" << std::endl;
			delete animals[i];
		}

		delete j;
		delete i;
*/
/* Impossible to compile for trying to convert type from Cat to Dog class
		const Dog* j = new Dog();
		const Dog* i = new Cat();

		const Dog	*dogs[10];

		for (size_t k = 0; k < 5; k++)
		{
			dogs[k] = new Dog(*j);
			dogs[k + 5] = new Dog(*i);
		}

		for (size_t i = 0; i < 10; i++)
			showBrain(*dogs[i]);

		for (size_t i = 0; i < 10; i++)
		{
			// std::cerr << "\033[2;3m" << i << "\033[m" << std::endl;
			delete dogs[i];
		}

		delete j;
		delete i;
	}
*/
	std::cout << "\033[35;43mTest for copy constuctor and copy assignment operator\033[m" << std::endl;
	{
/* Impossible to compile for trying to instantiate the abstract Animal class
		const AAnimal *meta0 = new AAnimal();
		const AAnimal meta1(*meta0);
		AAnimal *meta2 = new AAnimal();
		*meta2 = meta1;

		meta0->makeSound();
		meta1.makeSound();
		meta2->makeSound();

		delete meta0;
		delete meta2;
*/
// Impossible to compile for trying to instantiate the abstract Animal class
		const AAnimal* j0 = new Dog();
		// const AAnimal j1(*j0);
		AAnimal* j2 = new Dog(); 
		*j2 = *j0;

		j0->makeSound();
		// j1.makeSound();
		j2->makeSound();

		delete j0;
		delete j2;

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
