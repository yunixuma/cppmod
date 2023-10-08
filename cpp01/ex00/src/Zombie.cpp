/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 16:34:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name_ = name;
	std::cout << "\033[36;2;3m" << "Creating a zombie (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "\033[31;2;3m" << "Destroying the zombie (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

const std::string&	Zombie::get_name(void) const {
	return (this->name_);
}

void	Zombie::set_name(std::string name) {
	std::cout << "\033[2;3m" << "Rename " << this \
		<< ": " << this->name_ << " -> " << name << "\033[m" << std::endl;
	this->name_ = name;
}

void	Zombie::announce(void) const {
	std::cout << "\033[33m" << this->name_ << ": BraiiiiiiinnnzzzZ...\033[m" << std::endl;
}
