/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/30 04:12:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
private:
	const Fixed	x_;
	const Fixed	y_;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& point);
	Point&	operator=(const Point& rhs);
	~Point();
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Point& point);

#endif
