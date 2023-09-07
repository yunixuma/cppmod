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

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
<<<<<<< HEAD
# include <algorithm>

template <typename T>
int	easyfind(std::iterator<T, int> t, int tofind) {
	for (std::iterator<T, int> itr = t.begin(); itr != t.end(); ++itr) {
		if (*itr == tofind)
=======

# include <iostream>
# include <vector>
# include <list>
# include <map>

template <typename T, typename U>
int	easyfind(const T& container, U tofind) {
	for (typename T::const_iterator itr = container.begin(); itr != container.end(); ++itr) {
		if (static_cast<U>(*itr) == tofind)
>>>>>>> Update cpp08/ex00
			return (*itr);
	}
};

#endif
