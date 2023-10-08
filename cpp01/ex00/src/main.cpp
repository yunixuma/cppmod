/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 16:33:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	test_unit(void) {
	std::cout << "Unit tests" << std::endl;
	Zombie un_0;
	Zombie un_1;
	Zombie un_2;

	std::cout << "Before renamed" << std::endl;
	un_1.announce();
	un_2.announce();
	un_0.announce();

	un_1.set_name("Underwood");
	un_2.set_name("Uniacke");
	un_0.set_name();

	std::cout << "After renamed" << std::endl;
	un_1.announce();
	un_2.announce();
	un_0.announce();
}

void	test_stack(void) {
	std::cout << "Tests for allocating on the stack" << std::endl;
	
	randomChump("Stella");
	randomChump("Steve");
	randomChump();
}

Zombie*	test_heap(void) {
	std::cout << "Tests for allocating on the heap" << std::endl;
	Zombie*	he_1 = newZombie("Helen");
	Zombie*	he_2 = newZombie("Henly");
	Zombie*	he_0 = newZombie();

	he_1->announce();
	he_2->announce();
	he_0->announce();

	delete he_1;
	delete he_0;

	std::cout << "Return " << he_2->get_name() \
		<< " on the heap (" << he_2 << ")" << std::endl;
	return (he_2);
}

int main(void) {
	test_unit();
	std::cout << " ---- ---- ---- ---- ---- ---- ---- ----" << std::endl;
	test_stack();
	std::cout << " ---- ---- ---- ---- ---- ---- ---- ----" << std::endl;
	Zombie*	he = test_heap();
	he->announce();
	delete he;
	return (0);
}
