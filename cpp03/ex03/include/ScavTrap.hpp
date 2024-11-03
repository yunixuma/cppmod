/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 06:49:34 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
public:
	ScavTrap(std::string name = "SC4V-TRP");
	ScavTrap(const ScavTrap& src);
	ScavTrap&	operator=(const ScavTrap& rhs);
	~ScavTrap();
	void	attack(const std::string& target = "monster");
	void	guardGate(void) const;
	// void	takeDamage(unsigned int amount = 1);
	// void	beRepaired(unsigned int amount = 1);
};

#endif
