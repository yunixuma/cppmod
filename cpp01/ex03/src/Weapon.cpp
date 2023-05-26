/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 21:54:31 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type_ = type;
	std::cout << "\033[36;2;3m" << "Creating a weapon (";
	std::cout << this << ": " << this->type_ << ")\033[m" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "\033[31;2;3m" << "Destroying the weapon (";
	std::cout << this << ": " << this->type_ << ")\033[m" << std::endl;
}

std::string	Weapon::getType(void) {
	return (this->type_);
}

void	Weapon::setType(std::string type) {
	std::cout << "\033[2;3m" << "Changing the weapon (" << this << ": ";
	std::cout << this->type_ << " -> " << type << ")\033[m" << std::endl;
	this->type_ = type;
}
