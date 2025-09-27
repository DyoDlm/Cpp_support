#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	mainTester()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tMAIN TESTER\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;
}

static void	mainWrongTeser()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tMAIN TESTER\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete cat;
}

static void	testRandomAnimal()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tRANDOM ANIMAL\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	Animal	meta;
	Animal	meta2(meta);
	
	meta.makeSound();
	meta2.makeSound();
	return ;
}

static void	testGoodCat()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tGOOD CAT\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;
	Animal	meta;
	Cat		cat;
	Cat		cat2(cat);

	meta.makeSound();
	cat.makeSound();
	cat2.makeSound();
	return ;
}

static void	testGoodDog()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tGOOD DOG\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	Animal	meta;
	Dog		dog;
	Dog		dog2(dog);

	meta.makeSound();
	dog.makeSound();
	dog2.makeSound();
	return ;
}

static void	testWrongAnimal()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tWRONG ANIMAL\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	Animal		meta;
	Animal		meta2(meta);
	WrongAnimal	wMeta;
	WrongAnimal	wMeta2(wMeta);

	meta.makeSound();
	wMeta.makeSound();
	meta2.makeSound();
	wMeta2.makeSound();
	return ;
}

static void	testWrongCat()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tWRONG CAT\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	Cat			cat;
	Cat			cat2(cat);
	WrongCat	wCat;
	WrongCat	wCat2(wCat);
	const WrongAnimal	*wwcat = new WrongCat();

	wwcat->makeSound();
	cat.makeSound();
	wCat.makeSound();
	cat2.makeSound();
	wCat2.makeSound();
	delete wwcat;
	return ;
}

int	main()
{
	mainTester();
	mainWrongTeser();
	testRandomAnimal();
	testGoodCat();
	testGoodDog();
	testWrongAnimal();
	testWrongCat();
	return (0);
}