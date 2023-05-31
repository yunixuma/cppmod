/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/31 19:46:06 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <limits>

class Fixed
{
private:
public:
	int					fixedRawBits_;
	static const int	fractionalBits_ = 8;
	Fixed();
	Fixed(const int d);
	Fixed(const float f);
	Fixed(const Fixed& src);
	Fixed&	operator=(const Fixed& rhs);
//	const Fixed&	operator=(const Fixed& rhs) const;
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	Fixed	operator+(const Fixed& roperand) const;
	static Fixed	operator-(const Fixed& loperand, const Fixed& roperand);
//	Fixed	operator-(const Fixed& roperand) const;
//	Fixed	operator-(Fixed& roperand);
	Fixed	operator*(const Fixed& roperand) const;
	Fixed	operator/(const Fixed& roperand) const;
	Fixed	operator++(int);
	Fixed	operator++(void);
	Fixed	operator--(int);
	Fixed	operator--(void);
	static Fixed&		min(Fixed& fixed1, Fixed& fixed2) {
		return (fixed1 <= fixed2 ? fixed1 : fixed2);
	};
	static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2)  {
		return (fixed1 <= fixed2 ? fixed1 : fixed2);
	};
	static Fixed&		max(Fixed& fixed1, Fixed& fixed2) {
		return (fixed1 >= fixed2 ? fixed1 : fixed2);
	};
	static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2) {
		return (fixed1 >= fixed2 ? fixed1 : fixed2);
	};
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif
