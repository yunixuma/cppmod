/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 15:01:47 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	// std::string	name_;
	// unsigned int	hitPoint_;
	// unsigned int	energyPoint_;
	// unsigned int	attackDamage_;
public:
	FragTrap(std::string name = "FL4K");
	FragTrap(const FragTrap& src);
	FragTrap&	operator=(const FragTrap& rhs);
	~FragTrap();
	void	attack(const std::string& target = "bandit");
	void	takeDamage(unsigned int amount = 1);
	void	beRepaired(unsigned int amount = 1);
	void	highFivesGuys(void) const;
};

#endif
