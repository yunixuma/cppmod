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
		std::cerr << "\033[31mEmpty string" << std::endl;
		return ;
	}

	// std::stringstream	ss, ss_copy;
	// ss << str;
	// ss_copy << ss.rdbuf();

	// if (forInt(ss_copy))
	if (forInt(str))
		return ;

	if (forChar(str))
		return ;

	// ss_copy << ss.rdbuf();
	// if (forDouble(ss_copy))
	if (forDouble(str))
		return ;

	// ss.str("");
	// ss.clear(std::stringstream::goodbit);

/*
	if (str == STR_INF || str == STR_INF_POS || str == STR_INF_NEG) {
		std::clog << "\033[35;2;3mdouble inf\033[m" << std::endl;
		display(dbl, \
			(FLAG_IMPOS << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ ((FLAG_CAST | FLAG_PSEUDO) << SHIFT_FLOAT) \
			+ (FLAG_PSEUDO << SHIFT_DOUBLE));
		return ;
	}
*/

// std::clog << std::numeric_limits<int>::min() << std::endl;
// std::clog << std::numeric_limits<int>::max() << std::endl;

	// if (forFloat(ss_copy))
	if (forFloat(str))
		return ;

/*
	if (str == STR_INF || str == STR_INF_POS || str == STR_INF_NEG) {
		std::clog << "\033[35;2;3mfloat inf\033[m" << std::endl;
		display(f, \
			(FLAG_IMPOS << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_PSEUDO << SHIFT_FLOAT) \
			+ ((FLAG_CAST | FLAG_PSEUDO) << SHIFT_DOUBLE));
		return ;
	}
*/

	std::cerr << "\033[31mInvalid input: \"" << str << "\"\033[m" << std::endl;
}

// bool	ScalarConverter::forInt(std::stringstream& ss) {
bool	ScalarConverter::forInt(const std::string& str) {
	std::stringstream	ss;
	int					n;

	ss << str;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		display(n, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_REGULAR << SHIFT_INT) \
			+ (FLAG_INTEGER << SHIFT_FLOAT) \
			+ (FLAG_INTEGER << SHIFT_DOUBLE));
		std::clog << "\033[35;2;3mint\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forChar(const std::string& str) {
	if (str.length() == 1) {
		char	c = str[0];
		display(c, \
			(FLAG_REGULAR << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		std::clog << "\033[35;2;3mchar\033[m" << std::endl;
		return (true);
	}
	return (false);
}

// bool	ScalarConverter::forDouble(std::stringstream& ss) {
bool	ScalarConverter::forDouble(const std::string& str) {
	if (forPseudo(str)) {
		std::clog << "\033[35;2;3mdouble pseudo\033[m" << std::endl;
		return (true);
	}

	std::stringstream	ss;
	double				dbl;

	ss << str;
	ss >> dbl;
	if (!ss.fail() && ss.eof()) {
		int	flag;
		flag = (FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_REGULAR << SHIFT_DOUBLE);
		if (dbl > std::numeric_limits<int>::max())
			flag += (FLAG_MAX << SHIFT_INT);
		else if (dbl < std::numeric_limits<int>::min())
			flag += (FLAG_MIN << SHIFT_INT);
		else
			flag += (FLAG_CAST << SHIFT_INT);
		display(dbl, flag);
		std::clog << "\033[35;2;3mdouble\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forFloat(const std::string& str) {
	if (str[str.length() - 1] != 'f')
		return (false);
	std::string	str_trim(str);
	str_trim.erase(str_trim.length() - 1);

	if (forPseudo(str_trim)) {
		std::clog << "\033[35;2;3mfloat pseudo\033[m" << std::endl;
		return (true);
	}

	std::stringstream	ss;
	float	f;

	// ss.str("");
	// ss.clear(std::stringstream::goodbit);
	ss << str_trim;
	ss >> f;
	if (!ss.fail() && ss.eof()) {
		int	flag;
		flag = (FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_REGULAR << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE);
		if (f > std::numeric_limits<int>::max())
			flag += (FLAG_MAX << SHIFT_INT);
		else if (f < std::numeric_limits<int>::min())
			flag += (FLAG_MIN << SHIFT_INT);
		else
			flag += (FLAG_CAST << SHIFT_INT);
		display(f, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_REGULAR << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		std::clog << "\033[35;2;3mfloat\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forPseudo(const std::string& str) {
	if (str == STR_INF || str == STR_INF_POS) {
		display(str, \
			(FLAG_MAX << SHIFT_CHAR) \
			+ (FLAG_MAX << SHIFT_INT) \
			+ (FLAG_MAX << SHIFT_FLOAT) \
			+ (FLAG_MAX << SHIFT_DOUBLE));
		return (true);
	}
	if (str == STR_INF_NEG) {
		display(str, \
			(FLAG_MIN << SHIFT_CHAR) \
			+ (FLAG_MIN << SHIFT_INT) \
			+ (FLAG_MIN << SHIFT_FLOAT) \
			+ (FLAG_MIN << SHIFT_DOUBLE));
		return (true);
	}
	if (str == STR_NAN) {
		display(str, \
			(FLAG_IMPOS << SHIFT_CHAR) \
			+ (FLAG_IMPOS << SHIFT_INT) \
			+ (FLAG_PSEUDO << SHIFT_FLOAT) \
			+ (FLAG_PSEUDO << SHIFT_DOUBLE));
		return (true);
	}
	return (false);
}

/*
bool	ScalarConverter::isPseudo(std::string& str) {
	if (str == STR_NAN || str == STR_INF || str == STR_INF_POS || str == STR_INF_NEG)
		return (true);
	return (false);
}
*/
void	ScalarConverter::display(const std::string& str, int flag) {
	std::cout << "\033[32mT: \"" << str \
		<< "\" (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	std::cout << "\033[31mchar: " << STR_IMPOS << "\033[m" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::min();
	else
		std::cout << "\033[31mint: " << STR_IMPOS;
	std::cout << "\033[m" << std::endl;

	std::cout << "\033[33mfloat: " << str << CHR_FLOAT << "\033[m" << std::endl;
	std::cout << "\033[33mdouble: " << str << "\033[m" << std::endl;
}

template <typename T>
void	ScalarConverter::display(T scalar, int flag) {
	std::cout << "\033[32mT: " << scalar \
		<< " (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	if (' ' <= static_cast<char>(scalar) && static_cast<char>(scalar) <= '~')
		std::cout << "\033[32mchar: " << static_cast<char>(scalar) << "\033[m" << std::endl;
	else
		std::cout << "\033[33mchar: " << STR_NODISP << "\033[m" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::min();
	else
		std::cout << "\033[32mint: " << static_cast<int>(scalar);
	std::cout << "\033[m" << std::endl;

	const std::ios::fmtflags flags = std::cout.flags();
	// std::cout.setf(std::ios::showpos);

	// if (((flag >> SHIFT_FLOAT) & MASK_FLAG) == FLAG_INTEGER)
	if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(8);
	std::cout << "\033[32mfloat: " << static_cast<float>(scalar);
	std::cout << CHR_FLOAT << "\033[m" << std::endl;
	std::cout.flags(flags);

	// if (((flag >> SHIFT_DOUBLE) & MASK_FLAG) == FLAG_INTEGER)
	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(27);
	std::cout << "\033[32mdouble: " << static_cast<double>(scalar);
	std::cout << "\033[m" << std::endl;
	std::cout.flags(flags);
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