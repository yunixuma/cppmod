/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 02:55:06 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

// # include <string>
// # include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	// virtual ICharacter&	operator=(const ICharacter& rhs) = 0;
	virtual ~ICharacter() {}
	virtual std::string const&	getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;
};

#endif
