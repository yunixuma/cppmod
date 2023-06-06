/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/06 15:54:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Beast"){
	std::cout << "\033[36;2;3mCreating a Animal (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

Animal::Animal(const Animal& src) {
	std::cout << "\033[36;2mCopy constructor of Animal called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	this->type = src.type;
}

Animal&	Animal::operator=(const Animal& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of Animal called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "\033[31;2;3mDestroying the Animal (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

const std::string&	Animal::getType(void) const {
	return (this->type);
}

/*
void	Animal::makeSound(void) {
	std::cout << "\033[32m" << this->type \
		<< " growls\033[m" << std::endl;
}
*/

void	Animal::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " growls \"Grrr...\"\033[m" << std::endl;
}

const std::string&	Animal::getIdea(size_t idx) const {
	return (this->type);
	static_cast<void>(idx);
}
