/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 21:32:04 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_(weapon) {
	this->name_ = name;
//	this->weapon_ = weapon;
	std::cout << "\033[36;2;3m" << "Creating a humanA (";
	std::cout << this << ": " << this->name_ << ")\033[m" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "\033[31;2;3m" << "Destroying the humanA (";
	std::cout << this << ": " << this->name_ << ")\033[m" << std::endl;
}

std::string	HumanA::getName(void) const {
	return (this->name_);
}

void	HumanA::setName(std::string name) {
	std::cout << "\033[2;3m" << "Rename " << this << ": ";
	std::cout << this->name_ << " -> " << name << "\033[m" << std::endl;
	this->name_ = name;
}

Weapon&	HumanA::getWeapon() const {
	return (this->weapon_);
}

void	HumanA::setWeapon(Weapon& weapon) {
	std::cout << "\033[2;3m" << "Switching the equipment (" << this << ": ";
	std::cout << this->weapon_.getType() << " -> " << weapon.getType() << ")\033[m" << std::endl;
	this->weapon_ = weapon;
}

void	HumanA::attack(void) const {
	std::cout << "\033[33m" << this->name_ << " attacks with their ";
	std::cout << this->weapon_.getType() << "\033[m" << std::endl;
}
