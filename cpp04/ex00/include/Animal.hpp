/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/03 19:49:10 by ykosaka          ###   ########.fr       */
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
	Animal&	operator=(const Animal& rhs);
	virtual ~Animal(void);
	const std::string&	getType(void) const;
	// virtual void		makeSound(void);
	virtual void		makeSound(void) const;
};

#endif
