/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 17:47:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat
{
private:
	constant std::string	name_;
	int						grade_;
public:
	Bureaucrat(int grade = 100);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat&	operator=(const Bureaucrat& rhs);
	~Bureaucrat(void);
	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
	void				GradeTooHighException();
	void				GradeTooLowException();
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bc);

#endif
