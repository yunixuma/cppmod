/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/30 05:31:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

void	test_bsp( \
	float ax, float ay, \
	float bx, float by, \
	float cx, float cy, \
	float px, float py ) {	
	Point a(ax, ay);
	Point b(bx, by);
	Point c(cx, cy);
	Point point(px, py);

	std::cout << "The point " << point << " is " << std::endl \
		<< (bsp(a, b, c, point) ? "truely" : "NOT") \
		<< " inside of the triangle {" \
		<< "a" << a << ", " << "b" << b << ", " << "c" << c \
		<< "}" << std::endl;
}

int main( void ) {
	test_bsp(0, 0, 0, 4, 4, 0, 1, 1);

	return 0;
}
