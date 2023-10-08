/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/28 23:04:54 by ykosaka          ###   ########.fr       */
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
	std::string	getName(void) const;
	void 		setName(std::string name = "John");
	Weapon*		getWeapon(void) const;
	void 		setWeapon(Weapon& weapon);
	void		attack() const;
};

#endif
