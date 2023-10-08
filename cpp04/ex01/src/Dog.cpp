/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 15:56:32 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<Dog> Constructor called (" << this->type << ")\033[m" << std::endl;
	this->type = "Dog";
	this->brain_ = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Dog> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
	this->brain_ = new Brain(*src.brain_);
}

Dog&	Dog::operator=(const Dog& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Dog> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		// this->type = rhs.type;
		*this->brain_ = *rhs.brain_;
	}
	return (*this);
}

Dog::~Dog(void) {
	delete this->brain_;
	std::cout << "\033[31;2;3m[" << this \
		<< "]<Dog> Destructor called (" << this->type << ")\033[m" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "\033[32m[" << this \
		<< "]<Dog> " << this->type << " barks \"Bowwow!\"\033[m" << std::endl;
}

const Brain*	Dog::getBrain(void) const {
	return (this->brain_);
}

const std::string*	Dog::getIdea(size_t idx) const {
	// if (!this->brain_[idx])
	// 	return ("(null)");
	return (this->brain_->getIdea(idx));
}
