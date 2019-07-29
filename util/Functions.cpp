//
// Created by sercanersoy on 28.07.2019.
//

#include <iostream>
#include "Functions.h"

void Functions::printWelcome() {
    std::cout << "Welcome!" << std::endl;
    std::cout << "Enter 'h' for help, 'q' to exit." << std::endl;
    std::cout << "Enter your command: " << std::endl;
}

void Functions::printHelp() {
    std::cout << "Available commands are listed below:\n" << std::endl;

    std::cout << "Create Type:\t\tcreate type <type-name> <number-of-fields> <field1-name> <field2-name> ..."
              << std::endl;
    std::cout << "Delete Type:\t\tdelete type <type-name>" << std::endl;
    std::cout << "List All Types:\t\tlist type\n" << std::endl;

    std::cout << "Create Record:\t\tcreate record <type-name> <field1-value> <field2-value> ..." << std::endl;
    std::cout << "Delete Record:\t\tdelete record <type-name> <primary-key>" << std::endl;
    std::cout << "Update Record:\t\tupdate record <type-name> <primary-key> <field2-value> <field3-value> ..."
              << std::endl;
    std::cout << "Search Record:\t\tsearch record <type-name> <primary-key>" << std::endl;
    std::cout << "List All Records:\tlist record <type-name>" << std::endl;
}

void Functions::printGoodBye() {
    std::cout << "See you later!" << std::endl;
}

void Functions::printPrompt() {
    std::cout << "> ";
}
