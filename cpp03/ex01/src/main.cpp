/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 07:58:50 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

void	showStatus(const ScavTrap& st) {
	std::cerr << "\033[33;2m" << &st << ": " << st.getName() << " (" \
		<< st.getHitPoint() << "/" << st.getHitPointMax() << ", " \
		<< st.getEnergyPoint() << ", " \
		<< st.getAttackDamage() << ")\033[m" << std::endl;
}

int	main()
{
	{
		std::cout << "\033[35;43mTest for copy constuctor and copy assignment operator (w/ param)\033[m" << std::endl;
		ScavTrap	st0 = ScavTrap("Lilith");
		ScavTrap	st1(st0);
		ScavTrap	st2;
		st2 = st1;
		st2.guardGate();
		showStatus(st2);
		st2.attack("Jack");
		showStatus(st2);
		st2.beRepaired(10);
		showStatus(st2);
		st2.attack("Jack");
		showStatus(st2);
		st2.attack("Jack");
		showStatus(st2);
		st2.beRepaired(20);
		showStatus(st2);
		st2.attack("Jack");
		showStatus(st2);
		st2.beRepaired(10);
		showStatus(st2);
		st2.beRepaired(30);
		showStatus(st2);
		st2.attack("Jack");
		showStatus(st2);
		st2.beRepaired(10);
		showStatus(st2);
		st2.beRepaired(30);
		showStatus(st2);
		st2.attack("Jack");
		showStatus(st2);
	}
	{
		std::cout << "\033[35;43mTest for new/delete default constructor (w/o param)\033[m" << std::endl;
		ScavTrap	*st3 = new ScavTrap;
		st3->guardGate();
		showStatus(*st3);
		st3->attack();
		showStatus(*st3);
		st3->takeDamage();
		showStatus(*st3);
		st3->takeDamage(30);
		showStatus(*st3);
		st3->takeDamage(50);
		showStatus(*st3);
		st3->takeDamage(40);
		showStatus(*st3);
		st3->beRepaired();
		showStatus(*st3);
		st3->attack();
		delete st3;
	}
	return 0;
}
