/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/03 19:59:17 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "\033[36;2;3mCreating a Cat (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "\033[36;2mCopy constructor of Cat called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	this->type = src.type;
}

Cat&	Cat::operator=(const Cat& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of Cat called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "\033[31;2;3mDestroying the Cat (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

/*
void	Cat::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< ": crys\033[m" << std::endl;
}
*/