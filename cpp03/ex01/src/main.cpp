/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 14:27:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

void	showStatus(const ScavTrap& st) {
	std::cerr << "\033[33;2m" << &st << ": " << st.getName() << " (" \
		<< st.getHitPoint() << ", " << st.getEnergyPoint() << ", " \
		<< st.getAttackDamage() << ")\033[m" << std::endl;
}

int	main()
{
	ScavTrap	st1("Lilith");
	st1.guardGate();
	showStatus(st1);
	st1.attack("Jack");
	showStatus(st1);
	st1.beRepaired(10);
	showStatus(st1);
	st1.attack("Jack");
	showStatus(st1);
	st1.attack("Jack");
	showStatus(st1);
	st1.beRepaired(20);
	showStatus(st1);
	st1.attack("Jack");
	showStatus(st1);
	st1.beRepaired(10);
	showStatus(st1);
	st1.beRepaired(30);
	showStatus(st1);
	st1.attack("Jack");
	showStatus(st1);
	st1.beRepaired(10);
	showStatus(st1);
	st1.beRepaired(30);
	showStatus(st1);
	st1.attack("Jack");
	showStatus(st1);

	ScavTrap	*st2 = new ScavTrap;
	st2->guardGate();
	showStatus(*st2);
	st2->attack();
	showStatus(*st2);
	st2->takeDamage();
	showStatus(*st2);
	st2->takeDamage(30);
	showStatus(*st2);
	st2->takeDamage(50);
	showStatus(*st2);
	st2->takeDamage(40);
	showStatus(*st2);
	st2->beRepaired();
	showStatus(*st2);
	st2->attack();
	delete st2;
	return 0;
}
