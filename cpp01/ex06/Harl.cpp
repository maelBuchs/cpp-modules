#include "Harl.hpp"

void Harl::debug(void) { std::cout << "Debug" << std::endl; }

void Harl::info(void) { std::cout << "Info" << std::endl; }

void Harl::warning(void) { std::cout << "Warning" << std::endl; }

void Harl::error(void) { std::cout << "Error" << std::endl; }

void Harl::complain(str level) {

    str levels[4] = {"debug", "info", "warning", "error"};
    int i;

    for (i = 0; i < 4; i++) {
        if (levels[i] == level)
            break;
    }

    switch (i) {
    case 0:
        debug();
    case 1:
        info();
    case 2:
        warning();
    case 3:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

Harl::Harl() {}

Harl::~Harl() {}
