/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/28 22:59:44 by ykosaka          ###   ########.fr       */
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
	const std::string&	get_name(void) const;
	void 				set_name(std::string name = "Jane");
	void 				announce(void) const;
};

Zombie*		newZombie(std::string name = "Jane");
void 		randomChump(std::string name = "Jane");

#endif
