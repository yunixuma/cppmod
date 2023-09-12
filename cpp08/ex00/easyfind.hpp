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
# include <vector>
# include <list>
# include <map>
# include <exception>

class EasyFindException : public std::exception
{
public:
	const char* what() const throw() {
		return "Not found";
	}
};

template <typename T, typename U>
U	easyfind(const T& container, U tofind) {
	for (typename T::const_iterator itr = container.begin(); itr != container.end(); ++itr) {
		if (static_cast<U>(*itr) == tofind)
			return (tofind);
	}
	throw EasyFindException();
};

#endif
