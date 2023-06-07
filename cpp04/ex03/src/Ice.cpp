/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 16:55:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<Ice> Constructor called (" << this->type << ")\033[m" << std::endl;
	this->type = "Ice";
	this->brain_ = new Brain();
}

Ice::Ice(const Ice& src) : AMateria(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Ice> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
	this->brain_ = new Brain(*src.brain_);
}

Ice&	Ice::operator=(const Ice& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Ice> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
		// this->type = rhs.type;
		*this->brain_ = *rhs.brain_;
	}
	return (*this);
}

Ice::~Ice(void) {
	delete this->brain_;
	std::cout << "\033[31;2;3m[" << this \
		<< "]<Ice> Destructor called (" << this->type << ")\033[m" << std::endl;
}

void	Ice::makeSound(void) const {
	std::cout << "\033[32m[" << this \
		<< "]<Ice> " << this->type << " barks \"Bowwow!\"\033[m" << std::endl;
}

const Brain*	Ice::getBrain(void) const {
	return (this->brain_);
}

const std::string*	Ice::getIdea(size_t idx) const {
	// if (!this->brain_[idx])
	// 	return ("(null)");
	return (this->brain_->getIdea(idx));
}
