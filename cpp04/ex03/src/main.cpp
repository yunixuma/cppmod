/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 01:23:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materia.h"

int	main()
{
	// Change destination of clog/cerr to /dev/null
	std::streambuf* strbuf;
	std::ofstream ofstr("/dev/null");
	strbuf = std::clog.rdbuf(ofstr.rdbuf());
	strbuf = std::cerr.rdbuf(ofstr.rdbuf());
	// Restore destination of clog/cerr when debugging
	if (DEBUG_MODE)
	{
		std::clog.rdbuf(strbuf);
		std::cerr.rdbuf(strbuf);
	}

	std::cout << "\033[35;43mSample test\033[m" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\033[35;43mTest for full or empty slot or store\033[m" << std::endl;
	{
		std::cout << "\033[33mLaunch a default name character\033[m" << std::endl;
		ICharacter* me = new Character();

		std::cout << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		std::cout << "\033[33mTrying to copy & equip a Materia not learned yet\033[m" << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);

		std::cout << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		std::cout << "\033[33mStore is now full, so Materia Materias cannot be learned\033[m" << std::endl;
		src->learnMateria(new Cure());

		std::cout << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		ICharacter* rival = new Character("Golgo XIII");

		std::cout << "\033[33mTrying to use an empty or invalid slot\033[m" << std::endl;
		me->use(3, *rival);
		me->use(5, *rival);

		std::cout << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		std::cout << "\033[33mSlot is now full, so Materia Materias cannot be equipped\033[m" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);

		std::cout << "\033[33mUnequip Materias\033[m" << std::endl;
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);

		std::cout << "\033[33mTrying to unequip an empty or invalid slot\033[m" << std::endl;
		me->unequip(3);
		me->unequip(5);

		std::cout << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		delete rival;
		delete me;
		delete src;
	}

	return 0;
}
