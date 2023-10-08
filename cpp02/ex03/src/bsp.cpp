/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/01 21:55:58 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area_tri(Point const a, Point const b, Point const c) {
	float		s;
	const float	ax = a.getX().toFloat();
	const float	ay = a.getY().toFloat();
	const float	bx = b.getX().toFloat();
	const float	by = b.getY().toFloat();
	const float	cx = c.getX().toFloat();
	const float	cy = c.getY().toFloat();
	s = (bx - cx) * (ay - cy) - (by - cy) * (ax - cx);
	std::cerr << "\033[2;3mThe area of the triangle {" \
		<< "a" << a << ", " << "b" << b << ", " << "c" << c \
		<< "} is "<< s / 2 << "\033[m" << std::endl;
	if (s < 0)
		s = -s;
	return (Fixed(s));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	abc;
	Fixed	abp;
	Fixed	bcp;
	Fixed	acp;

	abc = area_tri(a, b, c);
	abp = area_tri(a, b, point);
	bcp = area_tri(b, c, point);
	acp = area_tri(a, c, point);
	if (abc == 0 || abp == 0 || bcp == 0 || acp == 0)
		return (false);
	else if (abc == abp + bcp + acp)
		return (true);
	return (false);
}
