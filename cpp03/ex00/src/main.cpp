/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 14:28:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	showStatus(const ClapTrap& ct) {
	std::cerr << "\033[33;2m" << &ct << ": " << ct.getName() << " (" \
		<< ct.getHitPoint() << ", " << ct.getEnergyPoint() << ", " \
		<< ct.getAttackDamage() << ")\033[m" << std::endl;
}

int	main()
{
	ClapTrap	ct1("Roland");
	showStatus(ct1);
	ct1.attack("Destroyer");
	showStatus(ct1);
	ct1.beRepaired(1);
	showStatus(ct1);
	ct1.attack("Destroyer");
	showStatus(ct1);
	ct1.attack("Destroyer");
	showStatus(ct1);
	ct1.beRepaired(2);
	showStatus(ct1);
	ct1.attack("Destroyer");
	showStatus(ct1);
	ct1.beRepaired(1);
	showStatus(ct1);
	ct1.beRepaired(3);
	showStatus(ct1);
	ct1.attack("Destroyer");
	showStatus(ct1);
	ct1.beRepaired(1);
	showStatus(ct1);
	ct1.beRepaired(3);
	showStatus(ct1);
	ct1.attack("Destroyer");
	showStatus(ct1);

	ClapTrap	*ct2 = new ClapTrap;
	showStatus(*ct2);
	ct2->attack();
	showStatus(*ct2);
	ct2->takeDamage();
	showStatus(*ct2);
	ct2->takeDamage(3);
	showStatus(*ct2);
	ct2->takeDamage(5);
	showStatus(*ct2);
	ct2->takeDamage(4);
	showStatus(*ct2);
	ct2->beRepaired();
	showStatus(*ct2);
	ct2->attack();
	delete ct2;
	return 0;
}
