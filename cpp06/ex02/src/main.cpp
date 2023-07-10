/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/10 19:59:42 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	std::clog << std::endl << "\033[35;43mSample test\033[m" << std::endl;
	{
		Base* base = new A();
		A* a = dynamic_cast<A*>(base);

		if (a)
			std::cout << "dynamic_cast succeeded" << std::endl;
		else
			std::cout << "dynamic_cast failed" << std::endl;

		delete base;
	}

	return 0;
}
