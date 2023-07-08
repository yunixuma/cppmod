/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/30 11:36:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string& str) {
	if (str.empty() || str.length() == 0) {
		std::cout << "\033[31mEmpty string" << std::endl;
		return ;
	}

	std::stringstream	ss;
	ss << str;

	int	n;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		display(n, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_REGULAR << SHIFT_INT) \
			+ (FLAG_INTEGER << SHIFT_FLOAT) \
			+ (FLAG_INTEGER << SHIFT_DOUBLE));
		return ;
	}

	if (str.length() == 1) {
		char	c = str[0];
		display(c, \
			(FLAG_REGULAR << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		return ;
	}

	ss.str("");
	ss.clear(std::stringstream::goodbit);
	double	dbl;
	ss >> dbl;
	if (!ss.fail() && ss.eof()) {
		display(dbl, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_REGULAR << SHIFT_DOUBLE));
		return ;
	}

	if (isPseudo(str))
	{
		display(str);
		return ;
	}

	if (str[str.length() - 1] == 'f') {
		str.erase(str.length() - 1);
	}
	ss.str("");
	ss.clear(std::stringstream::goodbit);
	ss << str;
	float	f;
	ss >> f;
	if (!ss.fail() && ss.eof()) {
		display(f, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_REGULAR << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		return ;
	}

	if (isPseudo(str))
	{
		display(str);
		return ;
	}

	std::cout << "\033[31mInvalid input: " << str << "\033[m" << std::endl;
}

bool	ScalarConverter::isPseudo(std::string& str) {
	if (str == STR_NAN || str == STR_INF || str == STR_INF_POS || str == STR_INF_NEG)
		return (true);
	return (false);
}

void	ScalarConverter::display(const std::string& str) {
	std::cout << "\033[31mint: " << STR_IMPOS << "\033[m" << std::endl;
	std::cout << "\033[31mchar: " << STR_IMPOS << "\033[m" << std::endl;
	std::cout << "\033[33mfloat: " << str << CHR_FLOAT << "\033[m" << std::endl;
	std::cout << "\033[33mdouble: " << str << "\033[m" << std::endl;
}

template <typename T>
void	ScalarConverter::display(T scalar, int flag) {
	std::cout << "\033[32mT: " << scalar \
		<< " (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	std::cout << "\033[32mint: " << static_cast<int>(scalar) << "\033[m" << std::endl;

	if (' ' <= scalar && scalar <= '~')
		std::cout << "\033[32mchar: " << static_cast<char>(scalar) << "\033[m" << std::endl;
	else
		std::cout << "\033[33mint: " << STR_NODISP << "\033[m" << std::endl;

	std::cout << "\033[32mfloat: " << static_cast<float>(scalar);
	if (((flag >> SHIFT_FLOAT) & FLAG_MASK) == FLAG_INTEGER)
		std::cout << STR_DECIMAL;
	std::cout << CHR_FLOAT << "\033[m" << std::endl;

	std::cout << "\033[32mdouble: " << static_cast<double>(scalar);
	if (((flag >> SHIFT_DOUBLE) & FLAG_MASK) == FLAG_INTEGER)
		std::cout << STR_DECIMAL;
	std::cout << "\033[m" << std::endl;

	(void)flag;
}

/*
bool	ScalarConverter::isInt(std::string& str) {
	std::stringstream	ss;
	int					n;

	ss << str;
	ss >> n;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}
*/
/*
template<typename RET>
RET	ScalarConverter::convert(std::string& str) {
	RET			ret;
	std::stringstream	ss;
	ss << str;
	ss >> ret;
	return (static_cast<RET>(ret));
}*/
/*
template<>
char<RET>	ScalarConverter::convert<char>(std::string& str) {
	char			c;
	stringstream	ss;
	ss << str;
	ss >> c;
	return (c);
}

template<>	ScalarConverter::convert float(std::string& str) {
	return (1.5);
}

template<>	ScalarConverter::convert double(std::string& str) {
	return (1.5);
}

// template<class T>
// static char ScalarConverter::convert(std::string& str) {
// 	if (str.length != 1)
// 		return ('!');
// 	return (*str.c_str());
// }

template <typename T>
int	ScalarConverter::convert(std::string& str)
{
	float				f;
	double				dbl;
	int					n;
	char				c;
	std::stringstream	ss;

	std::string	str(argv[1]);

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> dbl;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid double: " << c << "\033[m" << std::endl;
	}
	std::cout << "double: " << dbl << std::endl;

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> f;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid float: " << f << "\033[m" << std::endl;
	}
	std::cout << "float: " << f << std::endl;

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> n;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid int: " << n << "\033[m" << std::endl;
	}
	std::cout << "int: " << n << std::endl;

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> c;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid char: " << c << "\033[m" << std::endl;
	}
	std::cout << "char: " << c << std::endl;
}

std::string	ScalarConverter::convert(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toInt() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}

std::string	ScalarConverter::toChar(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toChar() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}

std::string	ScalarConverter::toFloat(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toFloat() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}

std::string	ScalarConverter::toDouble(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toDouble() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}
*/