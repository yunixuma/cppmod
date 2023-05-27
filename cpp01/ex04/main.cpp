/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/27 17:43:12 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
//#include <utility>
#include <string>
 
int main()
{
	std::string filename = "Makefile";
	try {
	//	std::ifstream fs;
	//	fs.open(filename.c_str(), std::ios::in);
	std::ifstream fs(filename, std::ios::in);
		if (fs.fail())
			throw (std::exception());
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m!!! Error opening the file. !!!\033[m" << std::endl;
		return (1);
	}
	std::string line_buffer;
	while (std::getline (fs, line_buffer)) {
	    std::cout << line_buffer << std::endl;
	}
	return (0);

}
