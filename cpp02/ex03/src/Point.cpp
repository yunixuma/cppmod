/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/30 05:21:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors and destructor
Point::Point() : x_(0), y_(0) {
	std::cerr << "\033[36;2m" << "Default constructor called\033[m" << std::endl;
}

Point::Point(const float x, const float y) : x_(x), y_(y) {
	std::cerr << "\033[36;2m" << "Parameterized constructor called\033[m" << std::endl;
}

Point::Point(const Point& src) : x_(src.x_), y_(src.y_) {
	std::cerr << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
}
/*
Point&	Point::operator=(const Point& rhs) {
	std::cout << "\033[36;2m" << "Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs)
	{
		this->x_ = rhs.x_;
		this->y_ = rhs.y_;
	}
	return (*this);
}
*/
Point::~Point(void) {
	std::cerr << "\033[31;2m" << "Destructor called\033[m" << std::endl;
}

// Member functions
const Fixed&	Point::getX(void) const {
	return (this->x_);
}

const Fixed&	Point::getY(void) const {
	return (this->y_);
}

// Operator overload for stream
std::ostream&	operator<<(std::ostream& stream, const Point& point) {
	stream << "(" << point.getX() \
		<< ", " << point.getY() << ")";
	return (stream);
}
