/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 16:55:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<Cure> Constructor called (" << this->type << ")\033[m" << std::endl;
	this->type = "Cure";
	this->brain_ = new Brain();
}

Cure::Cure(const Cure& src) : AMateria(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Cure> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
	this->brain_ = new Brain(*src.brain_);
}

Cure&	Cure::operator=(const Cure& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Cure> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
		// this->type = rhs.type;
		*this->brain_ = *rhs.brain_;
	}
	return (*this);
}

Cure::~Cure(void) {
	delete this->brain_;
	std::cout << "\033[31;2;3m[" << this \
		<< "]<Cure> Destructor called (" << this->type << ")\033[m" << std::endl;
}

void	Cure::makeSound(void) const {
	std::cout << "\033[32m[" << this \
		<< "]<Cure> " << this->type << " crys \"Meooow!\"\033[m" << std::endl;
}

const Brain*	Cure::getBrain(void) const {
	return (this->brain_);
}

const std::string*	Cure::getIdea(size_t idx) const {
	// if (!this->brain_[idx])
	// 	return ("(null)");
	return (this->brain_->getIdea(idx));
}
