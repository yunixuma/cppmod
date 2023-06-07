/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 08:36:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Beast") {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<Animal> Constructor called (" << this->type << ")\033[m" << std::endl;
}

Animal::Animal(const Animal& src) : type(src.type) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Animal> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

Animal&	Animal::operator=(const Animal& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Animal> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<Animal> Destructor called (" << this->type << ")\033[m" << std::endl;
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

const std::string*	Animal::getIdea(size_t idx) const {
	// return (NULL);
	return (&this->type);
	static_cast<void>(idx);
}
