/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 21:38:57 by ykosaka          ###   ########.fr       */
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

Zombie*	test_array(void) {
	std::cout << "Tests for arrays" << std::endl;
	Zombie*	ar_1 = zombieHorde(3);
	Zombie*	ar_2 = zombieHorde(7, "Ariel");
	Zombie*	ar_0 = zombieHorde();

	ar_1->hordeAnnounce(3);
	ar_2->hordeAnnounce(7);
	ar_0->hordeAnnounce();

	delete[] ar_1;
	delete[] ar_0;

	std::cout << "Return " << ar_0->get_name();
	std::cout << " on the heap (" << ar_0 << ")" << std::endl;
	return (ar_2);
}

int main(void)
{
	test_unit();

	std::cout << " ---- ---- ---- ---- ---- ---- ---- ----" << std::endl;
	Zombie*	ar = test_array();
	ar->hordeAnnounce(7);
	delete[] ar;
	return (0);
}
