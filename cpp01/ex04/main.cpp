/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/28 15:16:06 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
//#include <utility>
#include <string>

std::string sed_line(std::string buf_line, std::string s_search, std::string s_replace)
{
	std::string	buf_line_new;
	size_t		len_line = buf_line.length();
	size_t		len_search = s_replace.length();
	size_t 	pos = 0;
	size_t 	pos2;

	while (pos < len_line)
	{
		pos2 = buf_line.find(s_search, pos);
		if (pos2 == std::string::npos)
			break ;
		buf_line_new += buf_line.substr(pos, pos2 - pos);
		buf_line_new += s_replace;
		std::cerr << pos << "," << pos2 << std::endl;
		pos = pos2 + len_search;
	}
	buf_line_new += buf_line.substr(pos, len_line - pos);
	return (buf_line_new);
}

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		std::cerr << "\033[33mUsage: ./sed <source file> <search string> <replacement string> \033[m" << std::endl;
		return (EINVAL);
	}

	std::string s_search = argv[2];
	std::string s_replace = argv[3];
	if (s_search.length() == 0)
	{
		std::cerr << "\033[31mError: The search string is empty.\033[m" << std::endl;
		return (ESPIPE);
	}

	std::ifstream ifs;
	try {
		ifs.open(argv[1], std::ios::in | std::ios::binary);
//		std::ifstream ifs(filename, std::ios::in);
		if (ifs.fail())
			throw (std::exception());
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m!!! Error opening the src. file. !!!\033[m" << std::endl;
		return (ENOENT);
	}

	std::ofstream ofs;
	try {
		ofs.open(argv[2], std::ios::out | std::ios::binary);
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
		buf_line = sed_line(buf_line, s_search, s_replace);
	    buf_file += buf_line + "\n";
	}

	ofs << buf_file;
	ifs.close();
	ofs.close();
	return (0);

}
