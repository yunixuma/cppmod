/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 22:12:01 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <cctype>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	name_;
	Weapon*		weapon_;
public:
	HumanB(std::string name);
	~HumanB();
	std::string	getName(void);
	void 		setName(std::string name = "John");
	Weapon*		getWeapon(void);
	void 		setWeapon(Weapon& weapon);
	void		attack();
};

#endif
