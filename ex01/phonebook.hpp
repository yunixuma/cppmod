/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/04/01 01:34:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

using std::cout; using std::string;
using std::endl; using std::cin;
using std::transform; using std::toupper;
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		std::string s(argv[1]);
		for (int x = 0; x < s.length(); x++)
			putchar((char)s.toupper());
//		icu::UnicodeString unicodeString(s.c_str());
//		std::cout << s.toUpper() << std::endl;
	}
	return (0);
}
