#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *wrong = new WrongCat();

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	wrong->makeSound();

	std::cout << std::endl;
	// delete meta; // Retiré
	delete j;
	delete i;
	delete wrong;
	return 0;
}
