/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 15:42:56 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(std::string const & type) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Cure> Constructor called (" << this->type_ << ")\033[m" << std::endl;
	this->type_ = type;
}

Cure::Cure(const Cure& src) : AMateria(src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Cure> Copy constructor called (" << this->type_ << ")\033[m" << std::endl;
	// this->type_ = src.type;
}

Cure&	Cure::operator=(const Cure& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Cure> Copy assignment operator called (" << this->type_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
		// *this->type_ = *rhs.type_;
	}
	return (*this);
}

Cure::~Cure(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Cure> Destructor called (" << this->type_ << ")\033[m" << std::endl;
}

AMateria*	Cure::clone(void) const {
	std::clog << "\033[2;3m[" << this \
		<< "]<Cure> clone() called (" << this->type_ << ")\033[m" << std::endl;
	AMateria*	ret = new Cure;
	return (ret);
}

void		Cure::use(ICharacter& target) {
	std::clog << "\033[2;3m[" << this \
		<< "]<Cure> use() called (" << this->type_ << ")\033[m" << std::endl;
	std::cout << "\033[32m* heals " << target.getName() << "'s wounds *\033[m" << std::endl;
}
