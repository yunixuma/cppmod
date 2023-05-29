/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 02:24:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors and destructor
Point::Point() {
	std::cout << "\033[36;2m" << "Default constructor called\033[m" << std::endl;
	this->x_ = Fixed(0);
	this->y_ = Fixed(0);
}

Point::Point(const float x, const float y) {
	std::cout << "\033[36;2m" << "Parameterized constructor called\033[m" << std::endl;
	this->x_ = Fixed(x);
	this->y_ = Fixed(y);
}

Point::Point(const Point& src) {
	std::cout << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
	this->x_ = src.getX();
	this->y_ = src.getY();
}

Point&	Point::operator=(const Point& rhs) {
	std::cout << "\033[36;2m" << "Copy assignment operator called\033[m" << std::endl;
	this->x_ = rhs.x_;
	this->y_ = rhs.y_;
	return (*this);
}

Point::~Point(void) {
	std::cout << "\033[31;2m" << "Destructor called\033[m" << std::endl;
}

// Member functions
Fixed&	Point::getX(void) {
	return (this->x_);
}

Fixed&	Point::getY(void) {
	return (this->y_);
}

// Operator overload for stream
std::ostream&	operator<<(std::ostream& stream, const Point& point) {
	stream << "(" << point.getX() \
		<< ", " << point.getY() << ")";
	return (stream);
}
