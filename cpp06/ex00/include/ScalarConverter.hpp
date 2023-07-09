/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/30 11:34:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

// template<class T>
// class ScalarConverter;
# define SHIFT_CHAR		12
# define SHIFT_INT		8
# define SHIFT_FLOAT	4
# define SHIFT_DOUBLE	0
# define FLAG_REGULAR	0x0
# define FLAG_CAST		0x1
# define FLAG_NODISP	0x2
# define FLAG_INTEGER	0x2
# define FLAG_PSEUDO	0x4
# define FLAG_IMPOS		0x8
# define MASK_FLAG		0xf
# define MASK_CHAR		0xff
# define CHR_FLOAT		'f'
# define STR_NAN		"nan"
# define STR_INF		"inf"
# define STR_INF_POS	"+inf"
# define STR_INF_NEG	"-inf"
# define STR_DECIMAL	".0"
# define STR_IMPOS		"impossible"
# define STR_NODISP		"Non displayable"

// template<class T> class ScalarConverter
class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	// template<typename T>
	// static bool	isPseudo(std::string& str);
public:
	// template<typename RET>
	static void	convert(std::string& str);
	static void	display(const std::string& str);
	template<typename T>
	static void	display(T scalar, int flag);
	// template<class T>char	convert(std::string& str);
	// template <typename T>
	// char	convert(std::string& str);
	// template <typename T>
	// int		convert(std::string& str);
	// template <typename T>
	// float	convert(std::string& str);
	// template <typename T>
	// double	convert(std::string& str);
	// static std::string	toInt(const std::string& str);
	// static std::string	toChar(const std::string& str);
	// static std::string	toFloat(const std::string& str);
	// static std::string	toDouble(const std::string& str);
};

#endif
