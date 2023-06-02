/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 16:58:41 by ykosaka          ###   ########.fr       */
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
	ScavTrap	st1("Crowd");
	st1.guardGate();
	showStatus(st1);
	st1.attack("Goblin");
	showStatus(st1);
	st1.beRepaired(1);
	showStatus(st1);
	st1.attack("Goblin");
	showStatus(st1);
	st1.attack("Goblin");
	showStatus(st1);
	st1.beRepaired(2);
	showStatus(st1);
	st1.attack("Goblin");
	showStatus(st1);
	st1.beRepaired(1);
	showStatus(st1);
	st1.beRepaired(3);
	showStatus(st1);
	st1.attack("Goblin");
	showStatus(st1);
	st1.beRepaired(1);
	showStatus(st1);
	st1.beRepaired(3);
	showStatus(st1);
	st1.attack("Goblin");
	showStatus(st1);

	ScavTrap	st2;
	showStatus(st2);
	st2.attack();
	showStatus(st2);
	st2.takeDamage();
	showStatus(st2);
	st2.takeDamage(3);
	showStatus(st2);
	st2.takeDamage(5);
	showStatus(st2);
	st2.takeDamage(4);
	showStatus(st2);
	st2.beRepaired();
	showStatus(st2);
	st2.attack();
	return 0;
}
