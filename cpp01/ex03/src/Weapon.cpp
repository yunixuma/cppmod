/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 16:45:37 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type_ = type;
	std::cout << "\033[36;2;3m" << "Creating a weapon (" \
		<< this << ": " << this->type_ << ")\033[m" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "\033[31;2;3m" << "Destroying the weapon (" \
		<< this << ": " << this->type_ << ")\033[m" << std::endl;
}

const std::string&	Weapon::getType(void) {
	return (this->type_);
}

void	Weapon::setType(std::string type) {
	std::cout << "\033[2;3m" << "Changing the weapon (" << this << ": " \
		<< this->type_ << " -> " << type << ")\033[m" << std::endl;
	this->type_ = type;
}
