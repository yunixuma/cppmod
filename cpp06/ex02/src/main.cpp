/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/12 20:22:54 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	std::cout << "\033[32mgenerate() called\033[m" << std::endl;
	std::srand(std::time(NULL));
	int	idx = std::rand() % 3;
	if (idx == 0)
		return (new A());
	else if (idx == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p) {
	std::cout << "\033[32midentify(*p) called\033[m" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	std::cout << "\033[32midentify(&p) called\033[m" << std::endl;
	try {
		Base base = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}
	try {
		Base base = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}
	try {
		Base base = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}
}

void	trial(void) {
	std::cout << "\033[33mtrial() called\033[m" << std::endl;
	Base*	ptr = generate();
	Base&	ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
}

int	main(void)
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 5; i++) {
		std::clog << std::endl << "\033[35;43mTrial " << i + 1 << "\033[m" << std::endl;
		trial();
		unsigned int us_sleep = rand() % 1000000;
		usleep(us_sleep);
	}
	return 0;
}
