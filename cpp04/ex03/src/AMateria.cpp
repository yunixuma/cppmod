/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/09 20:51:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type_(type) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<AMateria> Constructor called (" << this->type_ << ")\033[m" << std::endl;
}

AMateria::AMateria(const AMateria& src) : type_(src.type_) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<AMateria> Copy constructor called (" << this->type_ << ")\033[m" << std::endl;
	// this->type_ = src.type;
}

AMateria&	AMateria::operator=(const AMateria& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<AMateria> Copy assignment operator called (" << this->type_ << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type_ = rhs.type_;
	return (*this);
}

AMateria::~AMateria(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<AMateria> Destructor called (" << this->type_ << ")\033[m" << std::endl;
}

const std::string&	AMateria::getType(void) const {
	return (this->type_);
}

void	AMateria::use(ICharacter& target) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<AMateria> use() called (" << this->type_ << ")\033[m" << std::endl;
	std::cout << "\033[32m* heals " << target.getName() << "'s wounds *\033[m" << std::endl;
}
