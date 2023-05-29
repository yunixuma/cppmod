/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 22:08:41 by ykosaka          ###   ########.fr       */
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

std::string	HumanB::getName(void) const {
	return (this->name_);
}

void	HumanB::setName(std::string name) {
	std::cout << "\033[2;3m" << "Rename " << this << ": ";
	std::cout << this->name_ << " -> " << name << "\033[m" << std::endl;
	this->name_ = name;
}

Weapon*	HumanB::getWeapon() const {
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

void	HumanB::attack(void) const {
	std::cout << "\033[33m" << this->name_;
	if (this->weapon_)
		std::cout << " attacks with their " << this->weapon_->getType() << "\033[m" << std::endl;
	else
		std::cout << " cannot attack" << "\033[m" << std::endl;
}
