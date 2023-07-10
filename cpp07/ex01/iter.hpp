/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/10 20:29:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// # include <iostream>
// # include <iomanip>
// # include <sstream>
// # include <string>
// # include <limits>

template <typename T>
void	iter(T* arr, size_t len, void (*func)(T&)) {
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
};

template <typename T1, typename T2>
void	iter(T1* arr1, T2* arr2, size_t len, void (*func)(T1&, T2&)) {
	if (!arr1 || !arr2 || !func)
		return ;
	for (size_t i = 0; i < len; i++)
		func(arr1[i], arr2[i]);
};

#endif
