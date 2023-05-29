/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 15:58:56 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	test_unit(void) {
	std::cout << "Before renamed" << std::endl;
}

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
	std::string*& stringPTRREF = stringPTR;

	std::cout << "The memory address of the variable" << std::endl;
	std::cout << "string      : " << &string << std::endl;
	std::cout << "stringPTR   : " << stringPTR << std::endl;
	std::cout << "stringREF   : " << &stringREF << std::endl;
	std::cout << "stringPTRREF: " << stringPTRREF << std::endl;
	std::cout << "The value of the variable" << std::endl;
	std::cout << "string      : " << string << std::endl;
	std::cout << "stringPTR   : " << *stringPTR << std::endl;
	std::cout << "stringREF   : " << stringREF << std::endl;
	std::cout << "stringPTRREF: " << *stringPTRREF << std::endl;
	return (0);
}
