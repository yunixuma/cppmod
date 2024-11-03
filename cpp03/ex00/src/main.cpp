/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 07:58:56 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

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
		ClapTrap	ct0 = ClapTrap("Roland");
		ClapTrap	ct1(ct0);
		ClapTrap	ct2;
		ct2 = ct1;
		showStatus(ct2);
		ct2.attack("Destroyer");
		showStatus(ct2);
		ct2.beRepaired(1);
		showStatus(ct2);
		ct2.attack("Destroyer");
		showStatus(ct2);
		ct2.attack("Destroyer");
		showStatus(ct2);
		ct2.beRepaired(2);
		showStatus(ct2);
		ct2.attack("Destroyer");
		showStatus(ct2);
		ct2.beRepaired(1);
		showStatus(ct2);
		ct2.beRepaired(3);
		showStatus(ct2);
		ct2.attack("Destroyer");
		showStatus(ct2);
		ct2.beRepaired(1);
		showStatus(ct2);
		ct2.beRepaired(3);
		showStatus(ct2);
		ct2.attack("Destroyer");
		showStatus(ct2);
	}
	{
		std::cout << "\033[35;43mTest for new/delete default constructor (w/o param)\033[m" << std::endl;
		ClapTrap	*ct3 = new ClapTrap;
		ct3->attack();
		showStatus(*ct3);
		ct3->takeDamage();
		showStatus(*ct3);
		ct3->takeDamage(3);
		showStatus(*ct3);
		ct3->takeDamage(5);
		showStatus(*ct3);
		ct3->takeDamage(4);
		showStatus(*ct3);
		ct3->beRepaired();
		showStatus(*ct3);
		ct3->attack();
		delete ct3;
	}
	return 0;
}
