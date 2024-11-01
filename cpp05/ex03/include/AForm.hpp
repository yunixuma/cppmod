/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 15:50:41 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
private:
	const std::string	name_;
	const std::string	target_;
	bool				signed_;
	const int			grade_to_sign_;
	const int			grade_to_exec_;
protected:
	void				setSigned(bool issigned);
	void				copy(const AForm& src);
public:
	AForm(const std::string& name = "sample", \
		const std::string& target = "something", \
		int grade_to_sign = 50, int grade_to_exec = 25);
	AForm(const AForm& src);
	virtual AForm&		operator=(const AForm& rhs);
	virtual ~AForm(void);
	const std::string&	getName(void) const;
	const std::string&	getTarget(void) const;
	void				setTarget(const std::string& target);
	bool				getSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;
	virtual void		beSigned(const Bureaucrat& bc) = 0;
	virtual void		execute(Bureaucrat const & executor) const = 0;
	virtual AForm*		clone(void) const = 0;
};

std::ostream&	operator<<(std::ostream& stream, const AForm& form);

#endif
