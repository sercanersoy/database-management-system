//
// Created by sercan.ersoy on 24.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_QUERYPARSER_H
#define DATABASE_MANAGEMENT_SYSTEM_QUERYPARSER_H

#include <string>
#include <vector>

class QueryManager {
    static const std::string helpMessage;

    static void createType(std::fstream &sysCat, std::vector<std::string> &words);

    static void deleteType(std::fstream &sysCat, std::string &typeName);

    static void listType(std::fstream &sysCat);

    static void createRecord(std::vector<std::string> &words, int nofFields);

    static void listRecord(std::string &typeName, int nofFields);

    static bool doesTypeExist(std::fstream &sysCat, std::string &typeName);

    static int getNofFieldsOfType(std::fstream &sysCat, std::string &typeName);

    static int findFileNumberToCreateDataFile(std::string &typeName);
public:
    static void assertExpr(bool expr, std::string message);

    static std::vector<std::string> splitLine(std::string line, char delimiter);

    static void parseAndExecute(std::fstream &sysCat, std::string line);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_QUERYPARSER_H
