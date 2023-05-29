/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 19:23:02 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					fixedRawBits_;
	static const int	fractionalBits_ = 8;
public:
	Fixed();
	Fixed(const int d);
	Fixed(const float f);
	Fixed(const Fixed& fixed);
	Fixed&	operator=(const Fixed& rhs);
	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	Fixed	operator+(const Fixed& roperand);
	Fixed	operator-(const Fixed& roperand);
	Fixed	operator*(const Fixed& roperand);
	Fixed	operator/(const Fixed& roperand);
	void	operator++(int n);
	Fixed	operator++(void);
	void	operator--(int n);
	Fixed	operator--(void);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2) const;
	const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif
