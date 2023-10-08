/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/06 23:07:06 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <string>
// #include <iomanip>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void) {
	Data	*ptr = new Data();
	std::cout << *ptr << std::endl;
	uintptr_t	raw = Serializer::serialize(ptr);
	std::cout << "[" << &raw << "]<uintptr_t>{" << raw << "}" << std::endl;
	std::cout << *Serializer::deserialize(raw) << std::endl;
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
