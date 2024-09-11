#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	delete j;
	delete i;

	const WrongAnimal* k = new WrongCat();
	k->makeSound();
	delete k;
	return 0;
}