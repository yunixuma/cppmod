/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 08:43:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<WrongCat> Constructor called (" << this->type << ")\033[m" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<WrongCat> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<WrongCat> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
		// this->type = rhs.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<WrongCat> Destructor called (" << this->type << ")\033[m" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " crys \" !#\"$%&\'() \"\033[m" << std::endl;
}
