#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

static void	BasicTester()
{
	std::cout << YELLOW << "\n\n"
		<< "/////////////////////////////\n"
		<< "/////	BASIC TESTER	/////\n"
		<< "//////////////////////////\n" << RESET;

	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	std::cout << "Use\n";

	me->use(0, *bob);

	me->use(1, *bob);
	
	me->use(2, *bob);

	me->use(5, *bob);

	std::cout << "Program complete\n";

	delete bob;

	delete me;
	
	delete src;

	delete tmp;
}

static void	TestMateria()
{
	std::cout << YELLOW << "\n\n"
		<< "////////////////////////\n"
		<< "///// MATERIA TESTER ////\n"
		<< "////////////////////////\n" << RESET;

	IMateriaSource	*src = new MateriaSource();

	std::cout << WHITE << "LEARNING MUCH MATERIA\n" << RESET;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

//	AMateria		*tmp;
//
//	src->createMateria("cure");
//	src->createMateria("ice");
//	src->createMateria("cure");
//	src->createMateria("ice");
//	src->createMateria("cure");
//	src->createMateria("ice");

	delete src;
}

static void	TestCharacter()
{
	std::cout << YELLOW << "\n\n"
		<< "////////////////////////\n"
		<< "/// CHARACTER TESTER ///\n"
		<< "////////////////////////\n" << RESET;

	ICharacter		*me = new Character("me");
	ICharacter		*bob = new Character("Bob");
	IMateriaSource	*src = new MateriaSource();
	AMateria		*tmp;

	////////////////////////////////////////////////////////////////
	std::cout << YELLOW << "\n\t//UNEQUIP NOTHING//\n" << RESET;
	me->unequip(0);
	me->unequip(1);
	me->unequip(5);

	////////////////////////////////////////////////////////////////
	std::cout << YELLOW << "\n\t//CREATE WHAT WAS NOT LEARNED//\n" << RESET;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	////////////////////////////////////////////////////////////////
	std::cout << YELLOW << "\n\t//CREATE MATERIA AND TOO MUCH//\n" << RESET;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("Ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("Ice");
	me->equip(tmp);
	delete tmp;

	////////////////////////////////////////////////////////////////
	std::cout << YELLOW << "\n\t//USE ALL + BAD INDEX//\n" << RESET;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	////////////////////////////////////////////////////////////////
	std::cout << YELLOW << "\n\t//UNEQUIP AND REEQUIP//\n" << RESET;

	me->unequip(0);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);

	me->use(0, *bob);
	
	delete tmp;
	delete me;
	
	////////////////////////////////////////////////////////////////
	std::cout << YELLOW << "\n\t//CREATE AND USE BULLSHIT//\n" << RESET;
	ICharacter	*me2 = new Character("me");

	tmp = src->createMateria("JNVLNL");
	me2->equip(tmp);
	me2->use(0, *bob);
	delete tmp;
	
	tmp = src->createMateria("ice");
	me2->equip(tmp);
	me2->unequip(0);
	bob->equip(tmp);

	delete me2;

	bob->equip(tmp);

	delete src;

	delete bob;

	delete tmp;

	return ;
}

static void	TestEquipment()
{
	std::cout << YELLOW << "\n\n"
		<< "////////////////////////\n"
		<< "/// EQUIPMENT TESTER ///\n"
		<< "////////////////////////\n" << RESET;

	return ;
}

int	main()
{
	BasicTester();

	TestMateria();

	TestCharacter();

	TestEquipment();

	return 0;
}