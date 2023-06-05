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

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <cctype>
# include <string>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal&	operator=(const WrongAnimal& rhs);
	virtual ~WrongAnimal(void);
	const std::string&	getType(void) const;
	// virtual void		makeSound(void);
	virtual void		makeSound(void) const;
};

#endif
