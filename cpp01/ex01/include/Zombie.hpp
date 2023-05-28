/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/28 15:58:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cctype>
# include <string>

class Zombie
{
private:
	std::string	name_;
public:
	Zombie(std::string name = "John");
	~Zombie();
	const std::string&	get_name(void);
	void 				set_name(std::string name = "Jane");
	void 				announce(void);
	void				hordeAnnounce(int N = 5);
};

Zombie*		zombieHorde(int N = 5, std::string name = "Jane");

#endif
