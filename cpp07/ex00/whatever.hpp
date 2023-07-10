/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/30 11:34:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// # include <iostream>
// # include <iomanip>
// # include <sstream>
// # include <string>
// # include <limits>

template <typename T>
void	swap(T& arg1, T& arg2) {
	T	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
};

template <typename T>
T	min(T& arg1, T& arg2) {
	return (arg1 < arg2 ? arg1 : arg2);
};

template <typename T>
T	max(T& arg1, T& arg2) {
	return (arg1 > arg2 ? arg1 : arg2);
};

/*
// Comparison operators
template <typename T>
bool	operator>(T& arg1, T& arg2) {
	return (arg1 > arg2);
};
*/
#endif
