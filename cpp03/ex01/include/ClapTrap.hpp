/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/03 19:49:10 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <cctype>
# include <string>

class ClapTrap
{
protected:
	std::string	name_;
	unsigned int	hitPoint_;
	unsigned int	energyPoint_;
	unsigned int	attackDamage_;
	void	attack_common(const std::string& target);
public:
	ClapTrap(std::string name = "CL4P-TP");
	ClapTrap(const ClapTrap& src);
	ClapTrap&	operator=(const ClapTrap& rhs);
	~ClapTrap();
	void	attack(const std::string& target = "enemy");
	void	takeDamage(unsigned int amount = 1);
	void	beRepaired(unsigned int amount = 1);
	const std::string&	getName(void) const;
	unsigned int	getHitPoint(void) const;
	unsigned int	getEnergyPoint(void) const;
	unsigned int	getAttackDamage(void) const;
};

#endif
