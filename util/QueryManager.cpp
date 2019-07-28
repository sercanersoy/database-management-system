#include <utility>

#include <utility>

//
// Created by sercan.ersoy on 24.07.2019.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include "QueryManager.h"
#include "../config.h"
#include "../model/sysCat/SysCatPage.h"
#include "Functions.h"
#include "FileManager.h"

std::string const QueryManager::helpMessage = "Enter 'h' for help.";

void QueryManager::assertExpr(bool expr, std::string message) {
    if(!expr) {
        throw message + "\n" + helpMessage;
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

bool QueryManager::doesTypeExist(std::fstream &sysCat, std::string &typeName) {
    for (int i = 0; i < SYS_CAT_PAGE_LIMIT; ++i) {
        SysCatPage page = SysCatPage::readFromFile(sysCat, i);
        if(page.pageHeader.nofTypes > 0) {
            for (auto &type : page.types) {
                if (type.typeHeader.valid == 1) {
                    if (type.typeHeader.typeName == typeName) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void QueryManager::parseAndExecute(std::fstream &sysCat, std::string line) {
    std::vector<std::string> words = splitLine(std::move(line), ' ');
    assertExpr(words.size() >= 2, "Number of words cannot be less than 2.");
    // DDL Operations
    if(words[0] == "create" && words[1] == "type") {
        assertExpr(words.size() >= 5, "Number of words cannot be less than 5 in a create type command.");
        std::string typeName = words[2];
        int nofFields = std::stoi(words[3]);
        assertExpr(words.size() == 4 + nofFields, "Number of fields and number of field names must be equal.");
        createType(sysCat, words);
    } else if(words[0] == "delete" && words[1] == "type") {
        assertExpr(words.size() == 3, "Number of words must be equal to 3 in a delete type command.");
        std::string typeName = words[2];
        deleteType(sysCat, typeName);
    } else if(words[0] == "list" && words[1] == "type") {
        listType(sysCat);
    }
    // DML Operations
    else if(words[0] == "create" && words[1] == "record") {
        std::string typeName = words[2];
        assertExpr(doesTypeExist(sysCat, typeName), "Type does not exist.");

    } else if(words[0] == "delete" && words[1] == "record") {

    }
    else {
        assertExpr(false, "Command you entered is not valid.");
    }
}

void QueryManager::createType(std::fstream &sysCat, std::vector<std::string> &words) {
    std::string typeName = words[2];
    int nofFields = std::stoi(words[3]);
    assertExpr(!QueryManager::doesTypeExist(sysCat, typeName), "Type already exists.");
    for (int i = 0; i < SYS_CAT_PAGE_LIMIT; ++i) {
        SysCatPage page = SysCatPage::readFromFile(sysCat, i);
        int firstAvailType = page.pageHeader.firstAvailType;
        if(firstAvailType != SYS_CAT_TYPE_LIMIT) {
            page.types[firstAvailType].typeHeader.valid = 1;
            page.types[firstAvailType].typeHeader.nofFields = (char) nofFields;
            std::strcpy(page.types[firstAvailType].typeHeader.typeName, typeName.c_str());
            for (int j = 0; j < nofFields; ++j) {
                std::string fieldName = words[4 + j];
                std::strcpy(page.types[firstAvailType].fields[j], fieldName.c_str());
            }
            page.pageHeader.nofTypes++;
            for (int j = firstAvailType + 1; j < SYS_CAT_TYPE_LIMIT; ++j) {
                if(page.types[j].typeHeader.valid == 0) {
                    page.pageHeader.firstAvailType = (char)j;
                    page.writeToFile(sysCat, i);
                    std::cout << "Successfully created type." << std::endl;
                    return;
                }
            }
            page.pageHeader.firstAvailType = SYS_CAT_TYPE_LIMIT;
            page.writeToFile(sysCat, i);
            std::cout << "Successfully created type." << std::endl;
            return;
        }
    }
    throw std::string("System catalog is full.");
}

void QueryManager::deleteType(std::fstream &sysCat, std::string &typeName) {
    for (int i = 0; i < SYS_CAT_PAGE_LIMIT; ++i) {
        SysCatPage page = SysCatPage::readFromFile(sysCat, i);
        int nofTypes = page.pageHeader.nofTypes;
        int firstAvailType = page.pageHeader.firstAvailType;
        if(nofTypes > 0) {
            for (int j = 0; j < SYS_CAT_TYPE_LIMIT; ++j) {
                int valid = page.types[j].typeHeader.valid;
                if(valid == 1) {
                    if(page.types[j].typeHeader.typeName == typeName) {
                        page.types[j].typeHeader.valid = 0;
                        int nofFields = page.types[j].typeHeader.nofFields;
                        page.types[j].typeHeader.nofFields = 0;
                        char empty[SYS_CAT_TYPE_FIELD_SIZE];
                        std::memset(empty, 0, SYS_CAT_TYPE_FIELD_SIZE);
                        std::strcpy(page.types[j].typeHeader.typeName, empty);
                        for (int k = 0; k < nofFields; ++k) {
                            std::strcpy(page.types[j].fields[k], empty);
                        }
                        page.pageHeader.nofTypes--;
                        if(firstAvailType > j) {
                            page.pageHeader.firstAvailType = (char)j;
                        }
                        page.writeToFile(sysCat, i);
                        FileManager::deleteDataFilesOfType(sysCat, typeName);
                        std::cout << "Type deleted successfully." << std::endl;
                        return;
                    }
                }
            }
        }
    }
    throw std::string("Couldn't find type.");
}

void QueryManager::listType(std::fstream &sysCat) {
    for (int i = 0; i < SYS_CAT_PAGE_LIMIT; ++i) {
        SysCatPage page = SysCatPage::readFromFile(sysCat, i);
        int nofTypes = page.pageHeader.nofTypes;
        if(nofTypes > 0) {
            for (auto &type : page.types) {
                int valid = type.typeHeader.valid;
                if(valid == 1) {
                    std::cout << type.typeHeader.typeName << std::endl;
                }
            }
        }
    }
}

void QueryManager::createRecord(std::fstream &sysCat, std::vector<std::string> &words) {

}
