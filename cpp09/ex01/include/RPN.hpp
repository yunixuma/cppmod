/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/15 03:38:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <string>
# include <cstring>
# include <stack>

class RPN
{
private:
	std::stack<int>	numbers_;
	void	stackNum(int num);
	void	operation(char oper);
public:
	RPN(void);
	~RPN(void);
	RPN(const RPN& src);
	RPN&	operator=(const RPN& rhs);
	void	tokenize(char ch);
	int		result(void) const;
	class SyntaxError : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class InvalidToken : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
