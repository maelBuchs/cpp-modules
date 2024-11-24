#include "A.h"
#include "B.h"
#include "C.h"

Base *generate(void) { return new A; }

void identify(Base *p) {
    std::string type = "C";
    // identify

    std::cout << "This is a " << type << " type" << std::endl;
}

void identify(Base &p) {
    std::string type = "C";
    // identify

    std::cout << "This is a " << type << " type" << std::endl;
}

int main() {

  identify(generate());

  Base &test = *generate();

  identify(test);

}