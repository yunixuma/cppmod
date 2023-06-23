/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/23 21:18:32 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
private:
	const std::string	name_;
	bool				signed_;
	const int			grade_to_sign_;
	const int			grade_to_exec_;
	const std::string	target_;
public:
	AForm(const std::string& name, int grade_to_sign = 50, int grade_to_exec = 25);
	AForm(const AForm& src);
	virtual AForm&				operator=(const AForm& rhs);
	virtual ~AForm(void);
	virtual const std::string&	getName(void) const;
	virtual bool				getSigned(void) const;
	virtual int					getGradeToSign(void) const;
	virtual int					getGradeToExec(void) const;
	virtual void				beSigned(const Bureaucrat& bc) = 0;
};

std::ostream&	operator<<(std::ostream& stream, const AForm& form);

#endif
