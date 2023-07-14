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

# include <iostream>

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

template <typename T1, typename T2>
void	swap(T1& arg1, T2& arg2) {
	std::clog << "\033[35;2;3mswap(T1&, T2&) called\033[m" << std::endl;
	T1	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
};

template <typename T1, typename T2>
T1	min(T1& arg1, T2& arg2) {
	std::clog << "\033[35;2;3mmin(T1&, T2&) called\033[m" << std::endl;
	return (arg1 < arg2 ? arg1 : arg2);
};

template <typename T1, typename T2>
T1	max(T1& arg1, T2& arg2) {
	std::clog << "\033[35;2;3mmax(T1&, T2&) called\033[m" << std::endl;
	return (arg1 > arg2 ? arg1 : arg2);
};

#endif
