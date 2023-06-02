/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 16:59:26 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) {
	this->name_ = name;
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 20;
	std::cout << "\033[36;2;3m" << "Creating a ScavTrap (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) {
	std::cerr << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
	this->name_ = src.name_;
	this->hitPoint_ = src.hitPoint_;
	this->energyPoint_ = src.energyPoint_;
	this->attackDamage_ = src.attackDamage_;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs) {
	std::cerr << "\033[36;2m" << "Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs)
	{
		this->name_ = rhs.name_;
		this->hitPoint_ = rhs.hitPoint_;
		this->energyPoint_ = rhs.energyPoint_;
		this->attackDamage_ = rhs.attackDamage_;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "\033[31;2;3m" << "Destroying the ScavTrap (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->hitPoint_ == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << this->name_ \
			<< " cannot attack," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (this->energyPoint_ == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << this->name_ \
			<< " cannot attack," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	this->energyPoint_ -= 1;
	std::cout << "\033[32m" << "ScavTrap " << this->name_ \
		<< " attacks " << target << ", causing " << this->attackDamage_ \
		<< " points of damage!\033[m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->hitPoint_ < amount)
		this->hitPoint_ = 0;
	else
		this->hitPoint_ -= amount;
	std::cout << "\033[32m" << "ScavTrap " << this->name_ \
		<< " take damage and loses " << amount \
		<< " hit points!\033[m" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->hitPoint_ == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << this->name_ \
			<< " cannot be repaired," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (this->energyPoint_ == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << this->name_ \
			<< " cannot be repaired," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	this->hitPoint_ += amount;
	this->energyPoint_ -= 1;
	std::cout << "\033[32m" << "ScavTrap " << this->name_ \
		<< " is repaired and gets " << amount \
		<< " hit points!\033[m" << std::endl;
}

const std::string&	ScavTrap::getName(void) const {
//	std::cerr << "\033[2;3m" << "getName member function called\033[m" << std::endl;
	return (this->name_);
}

unsigned int	ScavTrap::getHitPoint(void) const {
//	std::cerr << "\033[2;3m" << "getHitPoint member function called\033[m" << std::endl;
	return (this->hitPoint_);
}

unsigned int	ScavTrap::getEnergyPoint(void) const {
//	std::cerr << "\033[2;3m" << "getEnergyPoint member function called\033[m" << std::endl;
	return (this->energyPoint_);
}

unsigned int	ScavTrap::getAttackDamage(void) const {
//	std::cerr << "\033[2;3m" << "getAttackDamage member function called\033[m" << std::endl;
	return (this->attackDamage_);
}

void	ScavTrap::guardGate() const {
	std::cout << "\033[36m" << "ScavTrap " << this->name_ \
		<< " is now in Gatekeeper mode\033[m" << std::endl;
}
