/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/25 07:13:52 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
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
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm(void);
	void				beSigned(const Bureaucrat& bc);
	void				execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& stream, const ShrubberyCreationForm& form);

#endif
