/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 08:31:32 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<Cat> Constructor called (" << this->type << ")\033[m" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Cat> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

Cat&	Cat::operator=(const Cat& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Cat> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		// this->type = rhs.type;
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<Cat> Destructor called (" << this->type << ")\033[m" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " crys \"Meooow!\"\033[m" << std::endl;
}
