/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 08:43:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("UMA") {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<WrongAnimal> Constructor called (" << this->type << ")\033[m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<WrongAnimal> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<WrongAnimal> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<WrongAnimal> Destructor called (" << this->type << ")\033[m" << std::endl;
}

const std::string&	WrongAnimal::getType(void) const {
	return (this->type);
}

/*
void	WrongAnimal::makeSound(void) {
	std::cout << "\033[32m" << this->type \
		<< " growls\033[m" << std::endl;
}
*/

void	WrongAnimal::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " growls \" =~|`{+*}<>?_ \"\033[m" << std::endl;
}
