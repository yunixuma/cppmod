/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/22 20:05:44 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	size_t	count;
public:
	PhoneBook();
	~PhoneBook();
	int		search_contact();
	Contact	*get_contact(size_t count);
	size_t	get_count();
	int		set_count(size_t count);
	int		add_contact();
};

#endif
