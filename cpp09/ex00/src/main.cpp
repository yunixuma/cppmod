/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 00:55:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "btc.h"
#include "BitcoinExchange.hpp"
#include "Parser.hpp"

// 相場データファイル読み込み	BitcoinExchange
// 計算対象ファイル読み込み	main
// 日付変換				DateConverter
// $BTC価格計算			BitcoinExchange

int	main(int argc, char *argv[]) {
	std::string	line = "2021-04-10,3.1415926 ";
	t_pair	pair = Parser::split2Pair(line);
	std::cout << "{" << pair.first << "}, {" << pair.second << "}" << std::endl;

	if (argc != 2) {
		std::cerr << "\033[33mUsage: ./btc <input file> \033[m" << std::endl;
		return (EINVAL);
	}

	std::ifstream 	ifs;
	std::string		filepath = argv[1];
	try {
		ifs.open(filepath.c_str(), std::ios::in | std::ios::binary);
		if (ifs) {
			char	c;
			ifs.read(&c, 1);
			ifs.seekg(0, ifs.beg);
		}
		if (ifs.fail()) {
			throw (std::exception());
		}
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m!!! Error opening the src. file. !!!\033[m" << std::endl;
		return (ENOENT);
	}

	while (std::getline (ifs, line)) {
		t_pair	pair = Parser::split2Pair(line);
		std::cout << "{" << pair.first << "}, {" << pair.second << "}" << std::endl;
	}

	ifs.close();
	return (0);
}
