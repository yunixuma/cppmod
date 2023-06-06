/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/06 12:04:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	this->brain_ = new Brain();
	std::cout << "\033[36;2;3mCreating a Cat (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "\033[36;2mCopy constructor of Cat called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	this->type = src.type;
	this->brain_ = src.brain_;
}

Cat&	Cat::operator=(const Cat& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of Cat called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain_ = rhs.brain_;
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "\033[31;2;3mDestroying the Cat (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
	delete this->brain_;
}

void	Cat::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " crys \"Meooow!\"\033[m" << std::endl;
}
