/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/01 14:52:35 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
// #include <list>
#include "Span.hpp"

static int	case_basic(void) {
	std::clog << "\033[43mCASE: Test for vector of integers\033[m" << std::endl;
	Span	mySpan = Span(5);

	mySpan.addNumber(1);
	mySpan.addNumber(-3);
	mySpan.addNumber(7);
	mySpan.addNumber(-18);

	try {
		std::cout << "shortestSpan: " << mySpan.shortestSpan() << "\033[m" << std::endl;
		std::cout << "longestSpan: " << mySpan.longestSpan() << "\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << std::endl;
	}

	return (0);
}

int	main(void) {
	case_basic();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
