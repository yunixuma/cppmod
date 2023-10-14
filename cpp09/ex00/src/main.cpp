/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/15 03:47:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
#include "BitcoinExchange.hpp"
#include "Parser.hpp"

// 相場データファイル読み込み	BitcoinExchange
// 計算対象ファイル読み込み	main
// 日付変換				DateConverter
// $BTC価格計算			BitcoinExchange

int	main(int argc, char *argv[]) {
	// Change destination of clog/cerr to /dev/null
	std::streambuf* strbuf;
	std::ofstream ofstr("/dev/null");
	strbuf = std::clog.rdbuf(ofstr.rdbuf());
	// Restore destination of clog/cerr when debugging
	if (DEBUG_MODE)
		std::clog.rdbuf(strbuf);

	std::string	line = "2021-04-10,3.1415926 ";
	t_pair		pair = Parser::split2Pair(line);
	std::clog << "{" << pair.first << "}, {" << pair.second << "}" << std::endl;

	if (argc != 2) {
		std::cerr << "\033[33mUsage: ./btc <input file> \033[m" << std::endl;
		return (EINVAL);
	}

	BitcoinExchange	be;
	// if (be.openData(FILEPATH_DATA) == false)
	// 	return (ENOENT);
	try {
		be.openData(FILEPATH_DATA);
	}
	catch (const std::exception& e) {
		// std::cerr << "\033[31m" << e.what() << "\033[m" << std::endl;
		return (ENOENT);
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

	char	delim;
	std::getline (ifs, line);
	delim = Parser::searchDelim(line);
	while (std::getline (ifs, line)) {
		try {
			pair = Parser::split2Pair(line, delim);
		}
		catch (const std::exception& e) {
			std::cerr << "\033[31m" << e.what() << line << "\033[m" << std::endl;
			continue ;
		}
		std::clog << "{" << pair.first << "} " << delim << " {" << pair.second << "}" << std::endl;
		be.exchange(pair);
	}

	ifs.close();
	return (0);
}
