/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 04:29:52 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <cctype>
# include <string>

class ClapTrap
{
private:
	std::string	name_;
	int			hitPoint_;
	int			energyPoint_;
	int			attackDamage_;

public:
	ClapTrap(std::string name, Weapon& weapon);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	// std::string	getName(void) const;
	// void 		setName(std::string name = "John");
	// Weapon&		getWeapon(void) const;
	// void		setWeapon(Weapon& weapon);
	// void		attack() const;
};

#endif
