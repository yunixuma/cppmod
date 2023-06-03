/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/03 19:55:44 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap(std::string name = "FL4K");
	FragTrap(const FragTrap& src);
	FragTrap&	operator=(const FragTrap& rhs);
	~FragTrap();
	void	attack(const std::string& target = "bandit");
	void	highFivesGuys(void) const;
	// void	takeDamage(unsigned int amount = 1);
	// void	beRepaired(unsigned int amount = 1);
};

#endif
