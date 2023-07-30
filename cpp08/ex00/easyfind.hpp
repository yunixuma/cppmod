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

# include <iostream>

template <typename T>
int	easyfind(T& container, int tofind) {
	for ( itr = container.begin(); itr != container.end(); ++itr) {
		if (*itr == tofind)
			return (*itr);
	}
};

template <typename T>
int	easyfind(const T& container, int tofind) {
	for ( itr = container.begin(); itr != container.end(); ++itr) {
		if (*itr == tofind)
			return (*itr);
	}
};

#endif
