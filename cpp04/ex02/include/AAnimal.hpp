/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 13:39:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <cctype>
# include <string>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal(void);
	AAnimal(const AAnimal& src);
	virtual AAnimal&	operator=(const AAnimal& rhs);
	virtual ~AAnimal(void);
	virtual const std::string&	getType(void) const;
	// virtual void				makeSound(void);
	virtual void				makeSound(void) const = 0;
	virtual const std::string*	getIdea(size_t idx) const = 0;
};

#endif
