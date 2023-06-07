/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 04:22:06 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cctype>
# include <string>

class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(const Animal& src);
	virtual Animal&	operator=(const Animal& rhs);
	virtual ~Animal(void);
	const std::string&		getType(void) const;
	// virtual void			makeSound(void);
	virtual void			makeSound(void) const;
	virtual const std::string*	getIdea(size_t idx) const;
};

#endif
