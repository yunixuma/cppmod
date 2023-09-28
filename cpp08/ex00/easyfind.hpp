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
// # include <map>
# include <algorithm>
# include <exception>

class EasyFindException : public std::exception
{
public:
	const char* what() const throw() {
		return "Not found";
	}
};

template <typename T>
int	easyfind(const T& container, int toFind) {
	typename T::const_iterator itr = std::find(container.begin(), container.end(), toFind);
	if (itr != container.end())
		return (*itr);
	else
		throw EasyFindException();
};

template <typename T, typename U>
typename T::value_type	easyfindInfer(const T& container, U toFind) {
// U	easyfind(const T& container, U toFind) {
	// typename T::const_iterator itr;
	// U	ret = std::find(itr.begin(), itr.end(), toFind);
	// T&	ret = std::find(container.begin(), container.end(), toFind);
	typename T::const_iterator itr = std::find(container.begin(), container.end(), toFind);
	// itr.find(toFind);
	// return (static_cast<T>(itr));
	if (itr != container.end())
		return (*itr);
	else
		throw EasyFindException();
};

#endif
