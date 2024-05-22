/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/05/22 00:54:26 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int	main(int argc, char *argv[]) {
	// Change destination of clog to /dev/null
	std::streambuf* strbuf;
	std::ofstream ofstr("/dev/null");
	strbuf = std::clog.rdbuf(ofstr.rdbuf());
	strbuf = std::cerr.rdbuf(ofstr.rdbuf());
	// Restore destination of clog/cerr when debugging
	if (DEBUG_MODE)
	{
		std::clog.rdbuf(strbuf);
		std::cerr.rdbuf(strbuf);
	}

	if (argc != 2) {
		std::cout << "\033[33mUsage: ./RPN \"<RPN expression>\" \033[m" << std::endl;
		return (ENOENT);
	}

	RPN			rpn;
	std::string	formula = argv[1];
	std::string::iterator	it = formula.begin();
	std::string::iterator	ite = formula.end();
	try {
		while (it != ite) {
			rpn.tokenize(it);
			it++;
		}
		std::cout << rpn.getResult() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "\033[31m" << e.what() << "\033[m" << std::endl;
		return (EINVAL);
	}
	return (0);
}
