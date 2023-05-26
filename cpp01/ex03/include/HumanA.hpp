/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 20:04:55 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <cctype>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name_;
	Weapon*		weapon_;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	std::string	getName(void);
	void 		setName(std::string name = "John");
	Weapon*		getWeapon(void);
	void		setWeapon(Weapon *weapon = new Weapon);
	void		attack();
};

#endif
