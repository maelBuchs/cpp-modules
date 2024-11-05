#include "Harl.hpp"

void Harl::debug(void) { std::cout << "Debug" << std::endl; }

void Harl::info(void) { std::cout << "Info" << std::endl; }

void Harl::warning(void) { std::cout << "Warning" << std::endl; }

void Harl::error(void) { std::cout << "Error" << std::endl; }

void Harl::complain(std::string level) {
    void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            (this->*functions[i])();
        if (level == levels[i])
            return;
    }
    std::cout << "Invalid level sry" << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}
