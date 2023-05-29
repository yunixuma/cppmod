/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 21:31:16 by ykosaka          ###   ########.fr       */
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
	Weapon&		weapon_;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	std::string	getName(void) const;
	void 		setName(std::string name = "John");
	Weapon&		getWeapon(void) const;
	void		setWeapon(Weapon& weapon);
	void		attack() const;
};

#endif
