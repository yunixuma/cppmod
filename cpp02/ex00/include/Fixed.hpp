/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/30 00:35:18 by Yoshihiro K      ###   ########.fr       */
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
	Fixed(const Fixed& src);
	Fixed&	operator=(const Fixed& rhs);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
