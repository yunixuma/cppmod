/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/01 21:55:17 by ykosaka          ###   ########.fr       */
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
	std::cout << "\033[35;43mTest cases: Inside\033[m" << std::endl;
	test_bsp(4, 1, 3, 5, 9, 9, 7, 6);
	std::cout << "\033[35;43mTest cases: Outside\033[m" << std::endl;
	test_bsp(4, 1, 3, 5, 9, 9, 2, 2);
	std::cout << "\033[35;43mTest cases: On the edge\033[m" << std::endl;
	test_bsp(5, 1, 1, 1, 1, 9, 3, 5);
	std::cout << "\033[35;43mTest cases: Overlap the vertex\033[m" << std::endl;
	test_bsp(5, 1, 1, 1, 1, 9, 1, 9);

	return 0;
}
