#include <utility>

#include <utility>

//
// Created by sercan.ersoy on 24.07.2019.
//

#include <algorithm>
#include <iostream>
#include "QueryManager.h"

std::string const QueryManager::helpMessage = "Enter 'h' for help.";

void QueryManager::assertExpr(bool expr, std::string message) {
    if(!expr) {
        throw message + "\n" + helpMessage;
    }
}

void QueryManager::parseAndExecute(std::string line) {
    std::vector<std::string> words = splitLine(std::move(line), ' ');
    assertExpr(words.size() >= 2, "Number of words cannot be less than 2.");
    if(words[0] == "create" && words[1] == "type") {
        assertExpr(words.size() >= 5, "Number of words cannot be less than 5 in a create type command.");
        std::string typeName = words[2];
        int nofFields = std::stoi(words[3]);
        assertExpr(words.size() == 4 + nofFields, "Number of fields and number of field names must be equal.");
        std::cout << "Test: Successful create type command." << std::endl;
        // TODO execute create type command
    } else if(words[0] == "delete" && words[1] == "type") {
        assertExpr(words.size() == 3, "Number of words must be equal to 3 in a delete type command.");
        std::string typeName = words[2];
        std::cout << "Test: Successful delete type command." << std::endl;
        // TODO execute delete type command
    } // TODO more commands
    else {
        assertExpr(false, "Command you entered is not valid.");
    }
}

std::vector<std::string> QueryManager::splitLine(std::string line, char delimiter) {
    auto it = unique(line.begin(), line.end(), [](char first, char second){return first == second && first == ' ';});
    line.resize((size_t) distance(line.begin(), it));
    if(line[0] == delimiter) {
        line = line.substr(1, line.size()-1);
    }
    if(line[line.size()-1] == delimiter) {
        line = line.substr(0, line.size()-1);
    }
    // now the string is trimmed and blank symbols unified
    std::vector<std::string> resultVec;
    size_t pos = line.find(delimiter);
    while(pos != std::string::npos) {
        std::string token = line.substr(0, pos);
        resultVec.push_back(token);
        line = line.substr(pos+1);
        pos = line.find(delimiter);
    }
    // last token remains in line
    resultVec.push_back(line);
    return resultVec;
}
