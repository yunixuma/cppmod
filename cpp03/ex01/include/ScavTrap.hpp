/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 16:48:10 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	std::string	name_;
	unsigned int	hitPoint_;
	unsigned int	energyPoint_;
	unsigned int	attackDamage_;
public:
	ScavTrap(std::string name = "You");
	ScavTrap(const ScavTrap& src);
	ScavTrap&	operator=(const ScavTrap& rhs);
	~ScavTrap();
	void	attack(const std::string& target = "Clawler");
	void	takeDamage(unsigned int amount = 1);
	void	beRepaired(unsigned int amount = 1);
	const std::string&	getName(void) const;
	unsigned int	getHitPoint(void) const;
	unsigned int	getEnergyPoint(void) const;
	unsigned int	getAttackDamage(void) const;
	void			guardGate() const;
};

#endif
