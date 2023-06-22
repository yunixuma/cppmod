/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/22 18:52:09 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Form
{
private:
	const std::string	name_;
	bool				signed_;
	const int			grade_to_sign_;
	const int			grade_to_execute_;
public:
	Form(const std::string& name, int grade = 100);
	Form(const Form& src);
	Form&	operator=(const Form& rhs);
	~Form(void);
	const std::string&	getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExcute(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Form& form);

#endif
