/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/15 13:10:19 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <stack>

# ifndef DEBUG_MODE
#  define DEBUG_MODE	0
# endif

# define CHRS_NUM		"0123456789"
# define CHRS_OPER		"+-*/%"
# define CHRS_SPACE		" \t\n\v\f\r"

class RPN
{
private:
	std::stack<int>	vals_;
	void	stackVal(int val);
	void	operation(char oper);
	int		calc(int val1, int val2, char oper);
public:
	RPN(void);
	~RPN(void);
	RPN(const RPN& src);
	RPN&	operator=(const RPN& rhs);
	void	tokenize(std::string::iterator& it);
	int		getResult(void) const;
	class SyntaxError : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class InvalidTokenError : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class DivideByZeroException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
