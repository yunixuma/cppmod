/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 15:42:58 by ykosaka          ###   ########.fr       */
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
	std::cout << "\033[32m* shoots an ice bolt at " << target.getName() << " *\033[m" << std::endl;
}
