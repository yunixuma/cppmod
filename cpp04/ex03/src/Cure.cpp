/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 02:38:49 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<Cure> Constructor called (" << this->type_ << ")\033[m" << std::endl;
	this->type_ = "Cure";
}

Cure::Cure(const Cure& src) : AMateria(src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Cure> Copy constructor called (" << this->type_ << ")\033[m" << std::endl;
	// this->type_ = src.type;
}

Cure&	Cure::operator=(const Cure& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Cure> Copy assignment operator called (" << this->type_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
		// *this->type_ = *rhs.type_;
	}
	return (*this);
}

Cure::~Cure(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Cure> Destructor called (" << this->type_ << ")\033[m" << std::endl;
}

AMateria*	clone(void) const {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Cure> clone() called (" << this->type_ << ")\033[m" << std::endl;
	AMateria*	ret = new Cure;
	return (ret);
}

void		use(ICharacter& target) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Cure> use() called (" << this->type_ << ")\033[m" << std::endl;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
