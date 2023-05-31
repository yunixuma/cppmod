/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/31 19:34:41 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
private:
//	static Fixed const	x_;
//	static Fixed const	y_;
	Fixed	x_;
	Fixed	y_;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& point);
	Point&	operator=(const Point rhs);
	~Point();
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Point& point);

#endif
