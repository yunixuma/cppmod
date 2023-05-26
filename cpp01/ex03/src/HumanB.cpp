/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 22:19:36 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name_ = name;
	this->weapon_ = NULL;
	std::cout << "\033[36;2;3m" << "Creating a humanB (";
	std::cout << this << ": " << this->name_ << ")\033[m" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "\033[31;2;3m" << "Destroying the humanB (";
	std::cout << this << ": " << this->name_ << ")\033[m" << std::endl;
}

std::string	HumanB::getName(void) {
	return (this->name_);
}

void	HumanB::setName(std::string name) {
	std::cout << "\033[2;3m" << "Rename " << this << ": ";
	std::cout << this->name_ << " -> " << name << "\033[m" << std::endl;
	this->name_ = name;
}

Weapon*	HumanB::getWeapon() {
	return (this->weapon_);
}

void	HumanB::setWeapon(Weapon& weapon) {
	if (this->weapon_) {
		std::cout << "\033[2;3m" << "Switching the equipment (" << this << ": ";
		std::cout << this->weapon_->getType() << " -> " << weapon.getType() << ")\033[m" << std::endl;
	} else {
		std::cout << "\033[2;3m" << "Equipping (" << this << ": ";
		std::cout << weapon.getType() << ")\033[m" << std::endl;
	}
	this->weapon_ = &weapon;
}

void	HumanB::attack(void) {
	std::cout << "\033[33m" << this->name_ << " attacks with their ";
	std::cout << this->weapon_->getType() << "\033[m" << std::endl;
}
