/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 12:38:45 by ykosaka          ###   ########.fr       */
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

	std::clog << "\033[35;43mSample test\033[m" << std::endl;
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

	std::clog << "\033[35;43mTest for full or empty slot or store\033[m" << std::endl;
	{
		std::clog << "\033[33mLaunch a default name character\033[m" << std::endl;
		ICharacter* me = new Character();

		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		std::clog << "\033[33mTrying to copy & equip a Materia not learned yet\033[m" << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);

		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		std::clog << "\033[33mStore is now full, so Materia Materias cannot be learned\033[m" << std::endl;
		src->learnMateria(new Cure());

		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		ICharacter* rival = new Character("Golgo XIII");

		std::clog << "\033[33mTrying to use an empty or invalid slot\033[m" << std::endl;
		me->use(3, *rival);
		me->use(5, *rival);

		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		rival->equip(tmp);

		std::clog << "\033[33mSlot is now full, so Materia Materias cannot be equipped\033[m" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);

		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		me->unequip(0);

		std::clog << "\033[33mUnequip Materias\033[m" << std::endl;
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);

		std::clog << "\033[33mTrying to unequip an empty or invalid slot\033[m" << std::endl;
		me->unequip(3);
		me->unequip(5);

		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		delete rival;
		delete me;
		delete src;
	}

	std::clog << "\033[35;43mTest for deep copy a Character & a MaterialSource\033[m" << std::endl;
	{
		Character* me = new Character("Cloud");
		Character* rival = new Character("Sephiroth");
		MateriaSource* src = new MateriaSource();
		MateriaSource* dst = new MateriaSource();
		AMateria* tmp;

		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		dst->learnMateria(new Cure());
		dst->learnMateria(new Cure());

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->unequip(0);

		tmp = src->createMateria("cure");
		rival->equip(tmp);
		tmp = src->createMateria("cure");
		rival->equip(tmp);

		std::clog << std::endl << "\033[33mCharacter\033[m" << std::endl;
		std::clog << "\033[33mContent of the overridden later\033[m" << std::endl;
		rival->showMateria();
		std::clog << "\033[33mOperation of copy constructor\033[m" << std::endl;
		Character*	me2 = new Character(*me);
		Character	me3(*me);
		std::clog << "\033[33mOperation of copy assignment operator\033[m" << std::endl;
		*rival = *me;

		std::clog << "\033[33mContent of the original\033[m" << std::endl;
		me->showMateria();
		std::clog << "\033[33mContent of copy constructored\033[m" << std::endl;
		me2->showMateria();
		me3.showMateria();
		std::clog << "\033[33mContent of copy assigned\033[m" << std::endl;
		rival->showMateria();

		std::clog << std::endl << "\033[33mMateriaSource\033[m" << std::endl;
		std::clog << "\033[33mContent of the overridden later\033[m" << std::endl;
		dst->showMateria();
		std::clog << "\033[33mOperation of copy constructor\033[m" << std::endl;
		MateriaSource*	src2 = new MateriaSource(*src);
		MateriaSource	src3(*src);
		std::clog << "\033[33mOperation of copy assignment operator\033[m" << std::endl;
		*dst = *src;

		std::clog << "\033[33mContent of the original\033[m" << std::endl;
		src->showMateria();
		std::clog << "\033[33mContent of copy constructored\033[m" << std::endl;
		src2->showMateria();
		src3.showMateria();
		std::clog << "\033[33mContent of copy assigned\033[m" << std::endl;
		dst->showMateria();

		std::clog << std::endl << "\033[33m ---- ---- ---- ----\033[m" << std::endl;
		delete me;
		delete me2;
		delete rival;
		delete src;
		delete src2;
		delete dst;
	}

	return 0;
}
