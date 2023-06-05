/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/05 21:51:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "\033[36;2;3mCreating a WrongCat (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	std::cout << "\033[36;2mCopy constructor of WrongCat called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	this->type = src.type;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of WrongCat called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "\033[31;2;3mDestroying the WrongCat (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " crys \" !#\"$%&\'() \"\033[m" << std::endl;
}
