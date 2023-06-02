/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 15:05:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

void	showStatus(const FragTrap& ft) {
	std::cerr << "\033[33;2m" << &ft << ": " << ft.getName() << " (" \
		<< ft.getHitPoint() << ", " << ft.getEnergyPoint() << ", " \
		<< ft.getAttackDamage() << ")\033[m" << std::endl;
}

int	main()
{
	FragTrap	ft1("Lilith");
	showStatus(ft1);
	ft1.attack("Jack");
	showStatus(ft1);
	ft1.beRepaired(10);
	showStatus(ft1);
	ft1.attack("Jack");
	showStatus(ft1);
	ft1.attack("Jack");
	showStatus(ft1);
	ft1.beRepaired(20);
	showStatus(ft1);
	ft1.attack("Jack");
	showStatus(ft1);
	ft1.beRepaired(10);
	showStatus(ft1);
	ft1.beRepaired(30);
	showStatus(ft1);
	ft1.attack("Jack");
	showStatus(ft1);
	ft1.beRepaired(10);
	showStatus(ft1);
	ft1.beRepaired(30);
	showStatus(ft1);
	ft1.attack("Jack");
	ft1.highFivesGuys();
	showStatus(ft1);

	FragTrap	*ft2 = new FragTrap;
	showStatus(*ft2);
	ft2->attack();
	showStatus(*ft2);
	ft2->takeDamage();
	showStatus(*ft2);
	ft2->takeDamage(30);
	showStatus(*ft2);
	ft2->takeDamage(50);
	showStatus(*ft2);
	ft2->takeDamage(40);
	showStatus(*ft2);
	ft2->beRepaired();
	showStatus(*ft2);
	ft2->attack();
	ft2->highFivesGuys();
	delete ft2;
	return 0;
}
