//
// Created by sercanersoy on 28.07.2019.
//

#include <iostream>
#include "Functions.h"

void Functions::printWelcome() {
    std::cout << "Welcome!" << std::endl;
    std::cout << "Enter 'h' for help, 'q' to exit." << std::endl;
    std::cout << "Enter your command: " << std::endl;
    // TODO proper welcome message
}

void Functions::printHelp() {
    std::cout << "Available commands are listed below:\n" << std::endl;
    std::cout << "Create Type:\t\tcreate type <type-name> <number-of-fields> <field1-name> <field2-name> ..."
              << std::endl;
    std::cout << "Delete Type:\t\tdelete type <type-name>" << std::endl;
    std::cout << "List All Types:\t\tlist type" << std::endl;
}

void Functions::printGoodBye() {
    std::cout << "See you later!" << std::endl;
}

void Functions::printPrompt() {
    std::cout << "> ";
}
