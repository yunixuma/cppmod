/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/05 05:28:08 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
// # include <cmath>

class Scalar
{
private:
	int		int_;
	int		char_;
	float	float_;
public:
	Scalar();
	Scalar(const int d);
	Scalar(const float f);
	Scalar(const Scalar& src);
	Scalar&	operator=(const Scalar& rhs);
	~Scalar();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	bool	operator>(const Scalar& rhs) const;
	bool	operator<(const Scalar& rhs) const;
	bool	operator>=(const Scalar& rhs) const;
	bool	operator<=(const Scalar& rhs) const;
	bool	operator==(const Scalar& rhs) const;
	bool	operator!=(const Scalar& rhs) const;
	Scalar	operator+(const Scalar& roperand) const;
	Scalar	operator-(const Scalar& roperand) const;
	Scalar	operator*(const Scalar& roperand) const;
	Scalar	operator/(const Scalar& roperand) const;
	Scalar	operator++(int);
	Scalar	operator++(void);
	Scalar	operator--(int);
	Scalar	operator--(void);
	static Scalar&		min(Scalar& fixed1, Scalar& fixed2) {
		return (fixed1 <= fixed2 ? fixed1 : fixed2);
	};
	static const Scalar&	min(const Scalar& fixed1, const Scalar& fixed2)  {
		return (fixed1 <= fixed2 ? fixed1 : fixed2);
	};
	static Scalar&		max(Scalar& fixed1, Scalar& fixed2) {
		return (fixed1 >= fixed2 ? fixed1 : fixed2);
	};
	static const Scalar&	max(const Scalar& fixed1, const Scalar& fixed2) {
		return (fixed1 >= fixed2 ? fixed1 : fixed2);
	};
};

std::ostream&	operator<<(std::ostream& stream, const Scalar& fixed);

#endif
