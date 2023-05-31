/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/31 19:12:00 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and destructor
Fixed::Fixed() {
	std::cerr << "\033[36;2m" << "Default constructor called\033[m" << std::endl;
	this->fixedRawBits_ = 0;
}

Fixed::Fixed(const int d) {
	std::cerr << "\033[36;2m" << "Int constructor called\033[m" << std::endl;
	this->fixedRawBits_ = d << this->fractionalBits_;
}

Fixed::Fixed(const float f) {
	std::cerr << "\033[36;2m" << "Float constructor called\033[m" << std::endl;
	this->fixedRawBits_ = f * (1 << this->fractionalBits_);
}

Fixed::Fixed(const Fixed& src) {
	std::cerr << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
	this->fixedRawBits_ = src.fixedRawBits_;
}

//const Fixed&	Fixed::operator=(const Fixed& rhs) const {
Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cerr << "\033[36;2m" << "Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs)
		this->fixedRawBits_ = rhs.fixedRawBits_;
	return (*this);
}

Fixed::~Fixed(void) {
	std::cerr << "\033[31;2m" << "Destructor called\033[m" << std::endl;
}

// Member functions
int	Fixed::getRawBits( void ) const {
	std::cerr << "\033[33;2m" << "getRawBits member function called\033[m" << std::endl;
	return (this->fixedRawBits_);
}

void	Fixed::setRawBits( int const raw ) {
	this->fixedRawBits_ = raw;
}

int	Fixed::toInt( void ) const {
	float	f = static_cast<float>(this->fixedRawBits_);
	return (roundf(f / (1 << this->fractionalBits_)));
}

float	Fixed::toFloat( void ) const {
	float	f = static_cast<float>(this->fixedRawBits_);
	return (f / (1 << this->fractionalBits_));
}

// Operator overload for comparison
bool	Fixed::operator>(const Fixed& rhs) const {
	if (this->fractionalBits_ == rhs.fractionalBits_)
		return (this->fixedRawBits_ > rhs.fixedRawBits_);
	else if (this->fixedRawBits_ == rhs.fixedRawBits_)
		return (this->fractionalBits_ < rhs.fractionalBits_);
	int shift = this->fractionalBits_ - rhs.fractionalBits_;
	if (this->fixedRawBits_ < rhs.fixedRawBits_)
		return (this->fixedRawBits_ > (rhs.fixedRawBits_ >> shift));
	return ((this->fixedRawBits_ >> -shift) > rhs.fixedRawBits_);
}

bool	Fixed::operator<(const Fixed& rhs) const {
	return (!(*this > rhs) && !(*this == rhs));
}

bool	Fixed::operator>=(const Fixed& rhs) const {
	return (*this > rhs || *this == rhs);
}

bool	Fixed::operator<=(const Fixed& rhs) const {
	return !(*this > rhs);
}

bool	Fixed::operator==(const Fixed& rhs) const {
	if (this->fractionalBits_ == rhs.fractionalBits_)
		return (this->fixedRawBits_ == rhs.fixedRawBits_);
	int shift = this->fractionalBits_ - rhs.fractionalBits_;
	if (this->fixedRawBits_ < rhs.fixedRawBits_)
		return (this->fixedRawBits_ == (rhs.fixedRawBits_ >> shift));
	return ((this->fixedRawBits_ >> -shift) == rhs.fixedRawBits_);
}

bool	Fixed::operator!=(const Fixed& rhs) const {
	return !(*this == rhs);
}

// Operator overload for arithmetic
Fixed	Fixed::operator+(const Fixed& roperand) const {
	Fixed	ret;
	int		shift;

	if (ret.fractionalBits_ == this->fractionalBits_ \
		&& ret.fractionalBits_ == roperand.fractionalBits_)
	{
		ret.fixedRawBits_ = this->fixedRawBits_ + roperand.fixedRawBits_;
		return (ret);
	}

	shift = ret.fractionalBits_ - this->fractionalBits_;
	if (shift > 0)
		ret.fixedRawBits_ = (this->fixedRawBits_ << shift);
	else
		ret.fixedRawBits_ = (this->fixedRawBits_ >> -shift);
	shift = ret.fractionalBits_ - roperand.fractionalBits_;
	if (shift > 0)
		ret.fixedRawBits_ += (roperand.fixedRawBits_ << shift);
	else
		ret.fixedRawBits_ += (roperand.fixedRawBits_ >> -shift);
	return (ret);
}

Fixed	Fixed::operator-(const Fixed& roperand) const {
	Fixed	ret;
	int		shift;

	if (ret.fractionalBits_ == this->fractionalBits_ \
		&& ret.fractionalBits_ == roperand.fractionalBits_)
	{
		ret.fixedRawBits_ = this->fixedRawBits_ - roperand.fixedRawBits_;
		return (ret);
	}

	shift = ret.fractionalBits_ - this->fractionalBits_;
	if (shift > 0)
		ret.fixedRawBits_ = (this->fixedRawBits_ << shift);
	else
		ret.fixedRawBits_ = (this->fixedRawBits_ >> -shift);
	shift = ret.fractionalBits_ - roperand.fractionalBits_;
	if (shift > 0)
		ret.fixedRawBits_ -= (roperand.fixedRawBits_ << shift);
	else
		ret.fixedRawBits_ -= (roperand.fixedRawBits_ >> -shift);
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& roperand) const {
	Fixed		ret;
	long long	res;
	int			shift;
std::cout << "frac: " << ret.fractionalBits_ << std::endl;
	res = this->fixedRawBits_ * roperand.fixedRawBits_;
	shift = ret.fractionalBits_ \
		- this->fractionalBits_ - roperand.fractionalBits_;
	if (shift > 0)
		res <<= shift;
	else
		res >>= -shift;
	ret.fixedRawBits_ = res;
	return (ret);
}

Fixed	Fixed::operator/(const Fixed& roperand) const {
	Fixed	ret;
	int		shift;

	if (roperand.fixedRawBits_ == 0)
	{
		throw std::runtime_error("Divided by zero");
		if (this->fixedRawBits_ > 0)
			ret.fixedRawBits_ = std::numeric_limits<int>::max();
		else
			ret.fixedRawBits_ = std::numeric_limits<int>::min();
		return (ret);
	}

	ret.fixedRawBits_ = this->fixedRawBits_ * roperand.fixedRawBits_;
	shift = ret.fractionalBits_ \
		- this->fractionalBits_ - roperand.fractionalBits_;
	if (shift > 0)
		ret.fixedRawBits_ <<= shift;
	else
		ret.fixedRawBits_ >>= -shift;
	return (ret);
}

// Operator overload for increment and decrement
Fixed	Fixed::operator++(int) {
	Fixed	ret = *this;
	this->fixedRawBits_++;
	return (ret);
}
Fixed	Fixed::operator++(void) {
	this->fixedRawBits_++;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	ret = *this;
	this->fixedRawBits_--;
	return (ret);
}
Fixed	Fixed::operator--(void) {
	this->fixedRawBits_--;
	return (*this);
}

// Operator overload for stream
std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}