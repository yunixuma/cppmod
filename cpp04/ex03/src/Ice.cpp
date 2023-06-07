/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 02:29:17 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<Ice> Constructor called (" << this->type_ << ")\033[m" << std::endl;
	this->type_ = "Ice";
}

Ice::Ice(const Ice& src) : AMateria(src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Ice> Copy constructor called (" << this->type_ << ")\033[m" << std::endl;
	// this->type_ = src.type_;
}

Ice&	Ice::operator=(const Ice& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Ice> Copy assignment operator called (" << this->type_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
		// *this->type_ = *rhs.type_;
	}
	return (*this);
}

Ice::~Ice(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Ice> Destructor called (" << this->type_ << ")\033[m" << std::endl;
}

AMateria*	clone(void) const {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Cure> clone() called (" << this->type_ << ")\033[m" << std::endl;
	AMateria*	ret = new Cure;
	return (ret);
}

void	use(ICharacter& target) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Cure> use() called (" << this->type_ << ")\033[m" << std::endl;
	std::cout << "* heals " << target->name_ << "'s wounds *"" << std::endl;
}
