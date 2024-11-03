/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 07:58:43 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

void	showStatus(const FragTrap& ft) {
	std::cerr << "\033[33;2m" << &ft << ": " << ft.getName() << " (" \
		<< ft.getHitPoint() << "/" << ft.getHitPointMax() << ", " \
		<< ft.getEnergyPoint() << ", " \
		<< ft.getAttackDamage() << ")\033[m" << std::endl;
}

int	main()
{
	{
		std::cout << "\033[35;43mTest for copy constuctor and copy assignment operator (w/ param)\033[m" << std::endl;
		FragTrap	ft0 = FragTrap("Lilith");
		FragTrap	ft1(ft0);
		FragTrap	ft2;
		ft2 = ft1;
		showStatus(ft2);
		ft2.attack("Jack");
		showStatus(ft2);
		ft2.beRepaired(10);
		showStatus(ft2);
		ft2.attack("Jack");
		showStatus(ft2);
		ft2.attack("Jack");
		showStatus(ft2);
		ft2.beRepaired(20);
		showStatus(ft2);
		ft2.attack("Jack");
		showStatus(ft2);
		ft2.beRepaired(10);
		showStatus(ft2);
		ft2.beRepaired(30);
		showStatus(ft2);
		ft2.attack("Jack");
		showStatus(ft2);
		ft2.beRepaired(10);
		showStatus(ft2);
		ft2.beRepaired(30);
		showStatus(ft2);
		ft2.attack("Jack");
		showStatus(ft2);
		ft2.highFivesGuys();
	}	
	{
		FragTrap	*ft3 = new FragTrap;
		showStatus(*ft3);
		ft3->attack();
		showStatus(*ft3);
		ft3->takeDamage();
		showStatus(*ft3);
		ft3->takeDamage(30);
		showStatus(*ft3);
		ft3->takeDamage(50);
		showStatus(*ft3);
		ft3->takeDamage(40);
		showStatus(*ft3);
		ft3->beRepaired();
		showStatus(*ft3);
		ft3->attack();
		showStatus(*ft3);
		ft3->highFivesGuys();
		delete ft3;
	}
	return 0;
}
