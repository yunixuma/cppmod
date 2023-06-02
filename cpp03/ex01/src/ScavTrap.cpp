/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 15:03:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) {
	ClapTrap::setName(name);
	ClapTrap::setHitPoint(100);
	ClapTrap::setEnergyPoint(50);
	ClapTrap::setAttackDamage(20);
	std::cout << "\033[36;2;3m" << "Creating a ScavTrap (" \
		<< this << ": " << name << ")\033[m" << std::endl;
}
/*
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
*/
ScavTrap::~ScavTrap(void) {
	std::cout << "\033[31;2;3m" << "Destroying the ScavTrap (" \
		<< this << ": " << ClapTrap::getName() << ")\033[m" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	unsigned int	energyPoint = ClapTrap::getEnergyPoint();
	if (ClapTrap::getHitPoint() == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
			<< " cannot attack," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (energyPoint == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
			<< " cannot attack," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	ClapTrap::setEnergyPoint(energyPoint - 1);
	std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
		<< " attacks " << target << ", causing " << ClapTrap::getAttackDamage() \
		<< " points of damage!\033[m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	unsigned int	hitPoint = ClapTrap::getHitPoint();
	if (hitPoint < amount)
		ClapTrap::setHitPoint(0);
	else
		ClapTrap::setHitPoint(hitPoint - amount);
	std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
		<< " take damage and loses " << amount \
		<< " hit points!\033[m" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	unsigned int	hitPoint = ClapTrap::getHitPoint();
	unsigned int	energyPoint = ClapTrap::getEnergyPoint();
	if (hitPoint == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
			<< " cannot be repaired," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (energyPoint == 0)
	{
		std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
			<< " cannot be repaired," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	ClapTrap::setHitPoint(hitPoint + amount);
	ClapTrap::setEnergyPoint(energyPoint - 1);
	std::cout << "\033[32m" << "ScavTrap " << ClapTrap::getName() \
		<< " is repaired and gets " << amount \
		<< " hit points!\033[m" << std::endl;
}

void	ScavTrap::guardGate(void) const {
	std::cout << "\033[36m" << "ScavTrap " << ClapTrap::getName() \
		<< " is now in Gatekeeper mode\033[m" << std::endl;
}
