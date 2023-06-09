/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 00:15:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(const std::string& type) {
// Ice::Ice(void) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Ice> Constructor called (" << this->type_ << ")\033[m" << std::endl;
	this->type_ = type;
}

Ice::Ice(const Ice& src) : AMateria(src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Ice> Copy constructor called (" << this->type_ << ")\033[m" << std::endl;
	// this->type_ = src.type_;
}

Ice&	Ice::operator=(const Ice& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Ice> Copy assignment operator called (" << this->type_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
		// *this->type_ = *rhs.type_;
	}
	return (*this);
}

Ice::~Ice(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Ice> Destructor called (" << this->type_ << ")\033[m" << std::endl;
}

AMateria*	Ice::clone(void) const {
	std::clog << "\033[2;3m[" << this \
		<< "]<Ice> clone() called (" << this->type_ << ")\033[m" << std::endl;
	AMateria*	ret = new Ice;
	return (ret);
}

void	Ice::use(ICharacter& target) {
	std::clog << "\033[2;3m[" << this \
		<< "]<Ice> use() called (" << this->type_ << ")\033[m" << std::endl;
	std::cout << "\033[32m* heals " << target.getName() << "'s wounds *\033[m" << std::endl;
}
