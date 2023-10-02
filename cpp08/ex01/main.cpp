/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/02 12:04:47 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

static int	case_basic(void) {
	std::clog << "\033[43mCASE: Test for normal\033[m" << std::endl;
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

static int	case_full(void) {
	std::clog << "\033[43mCASE: Test for normal\033[m" << std::endl;
	Span	mySpan = Span(2);

	try {
		mySpan.addNumber(1);
		mySpan.addNumber(-3);
		mySpan.addNumber(7);
		mySpan.addNumber(-18);
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << std::endl;
	}

	return (0);
}

static int	case_nostored(void) {
	std::clog << "\033[43mCASE: Test for no numbers stored\033[m" << std::endl;
	Span	mySpan = Span(2);

	try {
		std::cout << "shortestSpan: " << mySpan.shortestSpan() << "\033[m" << std::endl;
		mySpan.addNumber(-3);
		mySpan.addNumber(7);
		mySpan.addNumber(-18);
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << std::endl;
	}

	return (0);
}

static int	case_nospan(void) {
	std::clog << "\033[43mCASE: Test for there is no spans\033[m" << std::endl;
	Span	mySpan = Span(2);

	try {
		mySpan.addNumber(1);
		std::cout << "longestSpan: " << mySpan.longestSpan() << "\033[m" << std::endl;
		mySpan.addNumber(7);
		mySpan.addNumber(-18);
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << std::endl;
	}

	return (0);
}

static int	case_copy(void) {
	std::clog << "\033[43mCASE: " \
		<< "Test for the copy constructor & the copy assignment operator" \
		<< "\033[m" << std::endl;
	Span	mySpan = Span(5);

	mySpan.addNumber(1);
	mySpan.addNumber(-3);
	mySpan.addNumber(7);
	mySpan.addNumber(-18);
	mySpan.debug();

	Span	mySpan2(mySpan);
	mySpan2.debug();

	Span	mySpan3(3);
	mySpan3 = mySpan;
	mySpan3.debug();

	return (0);
}

static int	case_range(void) {
	std::clog << "\033[43mCASE: " \
		<< "Test for add numbers of the range" \
		<< "\033[m" << std::endl;
	Span	mySpan = Span(45);

	try {
		mySpan.addNumbers(300, 300);
		mySpan.addNumbers(200, 180);
		mySpan.debug();
		mySpan.addNumbers(-20, 10);
		mySpan.debug();
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << std::endl;
	}
	mySpan.debug();
	std::cout << "shortestSpan: " << mySpan.shortestSpan() << "\033[m" << std::endl;
	std::cout << "longestSpan: " << mySpan.longestSpan() << "\033[m" << std::endl;

	return (0);
}

int	main(void) {
	case_basic();
	case_full();
	case_nostored();
	case_nospan();
	case_copy();
	case_range();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
