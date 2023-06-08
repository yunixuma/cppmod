/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 13:39:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("ABeaST"){
	std::cout << "\033[36;2;3m[" << this \
		<< "]<AAnimal> Constructor called (" << this->type << ")\033[m" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) : type(src.type) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<AAnimal> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

AAnimal&	AAnimal::operator=(const AAnimal& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<AAnimal> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<AAnimal> Destructor called (" << this->type << ")\033[m" << std::endl;
}

const std::string&	AAnimal::getType(void) const {
	return (this->type);
}

/*
void	AAnimal::makeSound(void) const {
	std::cout << "\033[32m[" << this \
		<< "]<AAnimal> " << this->type << " growls \"Ugrrr...\"\033[m" << std::endl;
}

const std::string&	AAnimal::getIdea(size_t idx) const {
	return (this->type);
	static_cast<void>(idx);
}
*/
