/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 23:56:53 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	std::cout << "\033[35;43mAdditional test\033[m" << std::endl;
	{
		Weapon sword = Weapon("Nichirin sword");
		HumanA slayerA("Shinazugawa", sword);
		slayerA.attack();
		HumanB slayerB("Inosuke");
		slayerB.attack();
		Weapon dsword = Weapon();
		slayerB.setWeapon(dsword);
		slayerB.attack();
		dsword.setType("dual swords");
		slayerB.attack();
		Weapon gun = Weapon("scarlet gun");
		slayerA.setWeapon(gun);
		slayerA.attack();
	}
	return 0;
}
