/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/06 12:09:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	this->brain_ = new Brain();
	std::cout << "\033[36;2;3mCreating a Dog (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "\033[36;2mCopy constructor of Dog called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	this->type = src.type;
	this->brain_ = src.brain_;
}

Dog&	Dog::operator=(const Dog& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of Dog called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain_ = rhs.brain_;
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "\033[31;2;3mDestroying the Dog (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " barks \"Bowwow!\"\033[m" << std::endl;
	delete this->brain_;
}
