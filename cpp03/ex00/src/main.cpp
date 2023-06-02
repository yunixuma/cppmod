/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 11:08:18 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	showStatus(const ClapTrap& cp) {
	std::cerr << "\033[33;2m" << &cp << ": " << cp.getName() << " (" \
		<< cp.getHitPoint() << ", " << cp.getEnergyPoint() << ", " \
		<< cp.getAttackDamage() << ")" << std::endl;
}

int	main()
{
	ClapTrap	cp1("Crowd");
	showStatus(cp1);
	cp1.attack("Goblin");
	showStatus(cp1);
	cp1.beRepaired(1);
	showStatus(cp1);
	cp1.attack("Goblin");
	showStatus(cp1);
	cp1.attack("Goblin");
	showStatus(cp1);
	cp1.beRepaired(2);
	showStatus(cp1);
	cp1.attack("Goblin");
	showStatus(cp1);
	cp1.beRepaired(1);
	showStatus(cp1);
	cp1.beRepaired(3);
	showStatus(cp1);
	cp1.attack("Goblin");
	showStatus(cp1);
	cp1.beRepaired(1);
	showStatus(cp1);
	cp1.beRepaired(3);
	showStatus(cp1);
	cp1.attack("Goblin");
	showStatus(cp1);

	ClapTrap	cp2;
	showStatus(cp2);
	cp2.attack();
	showStatus(cp2);
	cp2.takeDamage();
	showStatus(cp2);
	cp2.takeDamage(3);
	showStatus(cp2);
	cp2.takeDamage(5);
	showStatus(cp2);
	cp2.takeDamage(4);
	showStatus(cp2);
	cp2.beRepaired();
	showStatus(cp2);
	cp2.attack();
	return 0;
}
