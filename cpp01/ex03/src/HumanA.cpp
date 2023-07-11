/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 16:47:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_(weapon) {
	this->name_ = name;
//	this->weapon_ = weapon;
	std::cout << "\033[36;2;3m" << "Creating a humanA (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "\033[31;2;3m" << "Destroying the humanA (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

std::string	HumanA::getName(void) const {
	return (this->name_);
}

void	HumanA::setName(std::string name) {
	std::cout << "\033[2;3m" << "Rename " << this << ": " \
		<< this->name_ << " -> " << name << "\033[m" << std::endl;
	this->name_ = name;
}

Weapon&	HumanA::getWeapon() const {
	return (this->weapon_);
}

void	HumanA::setWeapon(Weapon& weapon) {
	std::cout << "\033[2;3m" << "Switching the equipment (" << this << ": " \
		<< this->weapon_.getType() << " -> " << weapon.getType() << ")\033[m" << std::endl;
	this->weapon_ = weapon;
}

void	HumanA::attack(void) const {
	std::cout << "\033[33m" << this->name_ << " attacks with their " \
		<< this->weapon_.getType() << "\033[m" << std::endl;
}
