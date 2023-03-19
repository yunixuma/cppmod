/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/20 02:12:35 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
//#include <cctype>
//#include <string>
//#include <ctype.h>

# define OFFSET_ARG		1
# define CHR_DELIM		' '
# define DEFAULT_SOUND	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char *argv[])
{
	size_t		len;

	if (argc <= OFFSET_ARG)
	{
		std::cout << DEFAULT_SOUND << std::endl;
		return (0);
	}
	for (size_t i = OFFSET_ARG; argv[i]; i++)
	{
		std::string	str(argv[i]);
		len = str.length();
		for (size_t j = 0; j < len; j++)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << std::endl;
	return (0);
}

//using std::cout; using std::string;
//using std::endl; using std::cin;
//using std::transform; using std::toupper;
//using namespace std;
/*
class Megaphone
{
public:
	Megaphone::Megaphone(std::string s);
	// ここにメンバ変数、メンバ関数を定義する
	int id;
};
*/
//		icu::UnicodeString unicodeString(s.c_str());
//		std::cout << s.toUpper() << std::endl;
