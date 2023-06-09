/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 03:41:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

// # include <string>
// # include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	store_[4];
	// int			_count;
	// void		_clear(void);
	// void		_copy(const MateriaSource& src);
	// void		_init(void);
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& src);
	MateriaSource&	operator=(const MateriaSource& rhs);
	~MateriaSource();
	void			learnMateria(AMateria*);
	AMateria*		createMateria(std::string const & type);
	void			showMateria(void) const;
};

#endif
