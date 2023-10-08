/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 05:49:58 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
private:
	size_t		id_;
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
	std::string	phone_number_;
	std::string	darkest_secret_;
public:
	Contact();
	~Contact();
	int	input_values(size_t count);
	int	copy_values(Contact *src);
	int	output_digest();
	int	output_detail(size_t index);
};

#endif
