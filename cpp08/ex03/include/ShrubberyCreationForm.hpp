/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 13:50:03 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// # include <cstdlib>
# include <fstream>
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
// 	class GradeTooHighException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
// 	class GradeTooLowException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
// 	class AlreadySignedException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
// 	class NotSignedException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const AForm& src);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm(void);
	void	beSigned(const Bureaucrat& bc);
	void	execute(Bureaucrat const & executor) const;
	AForm*	clone(void) const;
};

// std::ostream&	operator<<(std::ostream& stream, const ShrubberyCreationForm& form);

#endif
