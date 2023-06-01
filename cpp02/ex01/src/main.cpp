/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/01 19:25:24 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int	main( void ) {
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	std::cout << "\033[35;43mAdditional tests\033[m" << std::endl;
	std::cout << "\033[33mNegative numbers\033[m" << std::endl;
	{
		Fixed a;
		Fixed const b( -10 );
		Fixed const c( -42.42f );
		Fixed const d( b );
		a = Fixed( -1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << "\033[33mOverflow\033[m" << std::endl;
		Fixed a;
		Fixed b( 2147483647 );
		Fixed c( -2147483648.f / 4 );
		Fixed d( b );
		a = Fixed( 2147483647.f / 4 );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "\033[33mMAX. & min.\033[m" << std::endl;
		a.setRawBits(1);
		b.setRawBits(2147483647);
		c.setRawBits(-1);
		d.setRawBits(-2147483648);
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "\033[33mSet precision to 10 digits\033[m" << std::endl;
		std::cout << std::setprecision(10);
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "\033[33mSemi-MAX. & semi-min.\033[m" << std::endl;
		a.setRawBits(2);
		b.setRawBits(2147483647 - 64);
		c.setRawBits(-2);
		d.setRawBits(-2147483648 + 1 + 64);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "\033[33mEvaluate the precision\033[m" << std::endl;
		a.setRawBits(1000000 * 256);
		b.setRawBits(1000000 * 256 + 9);
		c.setRawBits(-1000000 * 256);
		d.setRawBits(-1000000 * 256 - 9);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
	}

	return 0;
}
