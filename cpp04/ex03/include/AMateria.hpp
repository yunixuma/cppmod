/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 01:54:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <cctype>
# include <string>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
protected:
	std::string	type_;
public:
	AMateria(std::string const & type = "(empty)");
	AMateria(const AMateria& src);
	AMateria&	operator=(const AMateria& rhs);
	virtual ~AMateria();
	std::string const&	getType() const; //Returns the Materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
