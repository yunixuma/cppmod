/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/14 19:59:22 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

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
