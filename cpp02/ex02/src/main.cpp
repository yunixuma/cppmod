/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/30 17:21:27 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

static void	puts_comparison(const Fixed& loperand, std::string op, const Fixed& roperand, bool b) {
	std::cout << "( " << loperand << " " << op << " " << roperand \
		<< " ) is " << (b ? "TRUE" : "false") << std::endl;
}

static void	puts_arithmetic(const Fixed& loperand, std::string op, const Fixed& roperand, const Fixed& res) {
	std::cout << " " << loperand << " " << op << " " << roperand \
		<< "  =  " << res << std::endl;
}

static void	puts_increment(const Fixed& passed, const Fixed& res, std::string op) {
	std::cout << op << " passed as " << passed \
		<< " results " << res << std::endl;
}

static void	puts_max(const Fixed& arg1, const Fixed& arg2, std::string op, const Fixed& ret) {
	std::cout << "The " << op << " of " << arg1 << " & " << arg2 \
		<< " is " << ret << std::endl;
}

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\033[35;43mAdditional tests\033[m" << std::endl;
	Fixed c = 42;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "\033[33mComparison operators\033[m" << std::endl;
	puts_comparison(a, ">", b, a > b);
	puts_comparison(c, ">", b, c > b);
	puts_comparison(b, ">", b, b > b);
	std::cout << std::endl;
	puts_comparison(a, "<", b, a < b);
	puts_comparison(c, "<", b, c < b);
	puts_comparison(b, "<", b, b < b);
	std::cout << std::endl;
	puts_comparison(a, ">=", b, a >= b);
	puts_comparison(c, ">=", b, c >= b);
	puts_comparison(b, ">=", b, b >= b);
	std::cout << std::endl;
	puts_comparison(a, "<=", b, a <= b);
	puts_comparison(c, "<=", b, c <= b);
	puts_comparison(b, "<=", b, b <= b);
	std::cout << std::endl;
	puts_comparison(c, "==", b, c == b);
	puts_comparison(b, "==", b, b == b);
	std::cout << std::endl;
	puts_comparison(c, "!=", b, c != b);
	puts_comparison(b, "!=", b, b != b);
	std::cout << std::endl;

	std::cout << "\033[33mArithmetic operators\033[m" << std::endl;
	puts_arithmetic(4.5f, "+", 3.7f, 4.5f + 3.7f);
//	puts_arithmetic(b, "+", c, b + c);
//	puts_arithmetic(b, "-", c, b - c);
//	puts_arithmetic(b, "/", c, b / c);

	std::cout << "\033[33mIncrement/decrement operators\033[m" << std::endl;
	puts_increment(a++, a, "var++");
	puts_increment(++a, a, "++var");
	puts_increment(a--, a, "var--");
	puts_increment(--a, a, "--var");

	std::cout << "\033[33mGetting the MAX./min.\033[m" << std::endl;
	puts_max(a, b, "MAX.", Fixed::max(a, b));
	puts_max(c, b, "MAX.", Fixed::max(c, b));
	puts_max(a, b, "min.", Fixed::min(a, b));
	puts_max(c, b, "min.", Fixed::min(c, b));

	return 0;
}
