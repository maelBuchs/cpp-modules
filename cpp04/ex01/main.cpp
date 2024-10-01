#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {

	const Animal* i = new Cat();
	const Animal* j = new Dog();

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	delete i;
	delete j;

	const WrongAnimal* k = new WrongCat();
	k->makeSound();
	delete k;
	return 0;
}