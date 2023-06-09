/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/30 05:05:44 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "\033[36;2m" << "Default constructor called\033[m" << std::endl;
	this->fixedRawBits_ = 0;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
	this->fixedRawBits_ = src.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cout << "\033[36;2m" << "Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs)
		this->fixedRawBits_ = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "\033[31;2m" << "Destructor called\033[m" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "\033[33;2m" << "getRawBits member function called\033[m" << std::endl;
	return (this->fixedRawBits_);
}

void	Fixed::setRawBits( int const raw ) {
	this->fixedRawBits_ = raw;
}
