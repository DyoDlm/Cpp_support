#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

static void	mainTester()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tMAIN TESTER\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();

	delete dog;
	delete cat;
}

static void	giveIdeas()
{
	std::cout << YELLOW
	<< "\n///////////////////////////\n"
	<< "##\tIDEAS TESTER\t##\n"
	<< "///////////////////////////\n"
	<< std::endl << RESET;
	
    const int size = 10;
    Animal *animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
        delete animals[i];
    }
}

int	main()
{
//	const Animal meta;

//	meta->makeSound();
	mainTester();
	giveIdeas();

	return (0);
}
