/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 14:13:40 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	// std::string	name_;
	// unsigned int	hitPoint_;
	// unsigned int	energyPoint_;
	// unsigned int	attackDamage_;
public:
	ScavTrap(std::string name = "SC4V-TRP");
	ScavTrap(const ScavTrap& src);
	ScavTrap&	operator=(const ScavTrap& rhs);
	~ScavTrap();
	void	attack(const std::string& target = "Clawler");
	void	takeDamage(unsigned int amount = 1);
	void	beRepaired(unsigned int amount = 1);
	void			guardGate() const;
};

#endif
