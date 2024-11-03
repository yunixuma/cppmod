/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 08:31:02 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

void	showStatus(const ClapTrap& ct) {
	std::cerr << "\033[33;2m" << &ct << ": " << ct.getName() << " (" \
		<< ct.getHitPoint() << "/" << ct.getHitPointMax() << ", " \
		<< ct.getEnergyPoint() << ", " \
		<< ct.getAttackDamage() << ")\033[m" << std::endl;
}

int	main()
{
	{
		std::cout << "\033[35;43mTest for copy constuctor and copy assignment operator (w/ param)\033[m" << std::endl;
		DiamondTrap	dt0 = DiamondTrap("Lilith");
		DiamondTrap	dt1(dt0);
		DiamondTrap	dt2;
		dt2 = dt1;
		showStatus(dt2);
		dt2.attack("Jack");
		showStatus(dt2);
		dt2.beRepaired(10);
		showStatus(dt2);
		dt2.attack("Jack");
		showStatus(dt2);
		dt2.attack("Jack");
		showStatus(dt2);
		dt2.beRepaired(20);
		showStatus(dt2);
		dt2.attack("Jack");
		showStatus(dt2);
		dt2.beRepaired(10);
		showStatus(dt2);
		dt2.beRepaired(30);
		showStatus(dt2);
		dt2.attack("Jack");
		showStatus(dt2);
		dt2.beRepaired(10);
		showStatus(dt2);
		dt2.beRepaired(30);
		showStatus(dt2);
		dt2.attack("Jack");
		showStatus(dt2);
		dt2.whoAmI();
	}	
	{
		DiamondTrap	*dt3 = new DiamondTrap;
		showStatus(*dt3);
		dt3->attack();
		showStatus(*dt3);
		dt3->takeDamage();
		showStatus(*dt3);
		dt3->takeDamage(30);
		showStatus(*dt3);
		dt3->takeDamage(50);
		showStatus(*dt3);
		dt3->takeDamage(40);
		showStatus(*dt3);
		dt3->beRepaired();
		showStatus(*dt3);
		dt3->attack();
		showStatus(*dt3);
		dt3->whoAmI();
		delete dt3;
	}
	return 0;
}
