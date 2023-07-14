/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/14 20:02:33 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

static int	case_sample(void) {
	std::clog << "\033[43mSample tests\033[m" << std::endl;
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string	c = "chaine1";
	std::string	d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return (0);
}

static int	case_additional(void) {
	std::clog << "\033[43mAdditional tests\033[m" << std::endl;
	std::clog << "\033[33mCASE: Change the value of one variable\033[m" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine";

	std::clog << "\033[2;3mBefore swap\033[m" << std::endl;
	std::cout << "c[" << &c << "] = " << c \
		<< ", d[" << &d << "] = " << d << std::endl;
	::swap(c, d);
	std::clog << "\033[2;3mAfter swap\033[m" << std::endl;
	std::cout << "c[" << &c << "] = " << c \
		<< ", d[" << &d << "] = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::clog << "\033[33mCASE: Different types\033[m" << std::endl;
	float	a = 4.2;
	int		b = 2;

	std::clog << "\033[2;3mBefore swap\033[m" << std::endl;
	std::cout << "a[" << &a << "] = " << a \
		<< ", b[" << &b << "] = " << b << std::endl;
	::swap( a, b );
	std::clog << "\033[2;3mAfter swap\033[m" << std::endl;
	std::cout << "a[" << &a << "] = " << a \
		<< ", b[" << &b << "] = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	return (0);
}

int	main(void) {
	case_sample();
	case_additional();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
