/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 02:24:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "\033[36;2m" << "Default constructor called\033[m" << std::endl;
	this->fixedRawBits_ = 0;
}

Fixed::Fixed(const int d) {
	std::cout << "\033[36;2m" << "Int constructor called\033[m" << std::endl;
	this->fixedRawBits_ = d << this->fractionalBits_;
}

Fixed::Fixed(const float f) {
	std::cout << "\033[36;2m" << "Float constructor called\033[m" << std::endl;
	this->fixedRawBits_ = f * (1 << this->fractionalBits_);
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
	this->fixedRawBits_ = fixed.fixedRawBits_;
}

Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cout << "\033[36;2m" << "Copy assignment operatorcalled\033[m" << std::endl;
	this->fixedRawBits_ = rhs.fixedRawBits_;
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

int	Fixed::toInt( void ) const {
	return (this->fixedRawBits_ >> this->fractionalBits_);
}

float	Fixed::toFloat( void ) const {
	float	f = this->fixedRawBits_;
	return (f / (1 << this->fractionalBits_));
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}
