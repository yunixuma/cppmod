/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/12 22:15:59 by Yoshihiro K      ###   ########.fr       */
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

int	main(void) {
	std::string	line = "2021-10-12,0.00000001";
	t_pair	pair = Parser::split2Pair(line);
	std::cout << pair.first << ", " << pair.second << std::endl;
}

/*
int main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "\033[33mUsage: ./sed <source file> <search string> <replacement string> \033[m" << std::endl;
		return (EINVAL);
	}

	std::string s_search = argv[2];
	std::string s_replace = argv[3];
	if (s_search.length() == 0) {
		std::cerr << "\033[31mError: The search string is empty.\033[m" << std::endl;
		return (ESPIPE);
	}

	std::ifstream 	ifs;
	std::string		filepath_in = argv[1];
	try {
		ifs.open(filepath_in.c_str(), std::ios::in | std::ios::binary);
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

	std::ofstream	ofs;
	std::string		filepath_out = filepath_in + ".replace";
	try {
		ofs.open(filepath_out.c_str(), std::ios::out | std::ios::binary);
		if (ofs.fail())
			throw (std::exception());
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m!!! Error opening the dest. file. !!!\033[m" << std::endl;
		return (ENOENT);
	}

	std::string buf_line;
	std::string buf_file;
	while (std::getline (ifs, buf_line)) {
		buf_file += buf_line;
		if (!ifs.rdstate())
			buf_file += "\n";
	}
	buf_file = Parser::split(buf_file, '|');

	ofs << buf_file;
	ifs.close();
	ofs.close();
	return (0);
}
*/