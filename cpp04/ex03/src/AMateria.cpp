/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 02:25:18 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("ABeaST") {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<AMateria> Constructor called (" << this->type << ")\033[m" << std::endl;
}

AMateria::AMateria(const AMateria& src) : type(src.type) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<AMateria> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

AMateria&	AMateria::operator=(const AMateria& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<AMateria> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria::~AMateria(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<AMateria> Destructor called (" << this->type << ")\033[m" << std::endl;
}

const std::string&	AMateria::getType(void) const {
	return (this->type);
}

void	AMateria::makeSound(void) const {
	std::cerr << "\033[32m[" << this \
		<< "]<AMateria> " << this->type << " growls \"Ugrrr...\"\033[m" << std::endl;
}

// const std::string&	AMateria::getIdea(size_t idx) const {
// 	return (this->type);
// 	static_cast<void>(idx);
// }
