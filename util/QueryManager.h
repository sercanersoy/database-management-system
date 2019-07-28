//
// Created by sercan.ersoy on 24.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_QUERYPARSER_H
#define DATABASE_MANAGEMENT_SYSTEM_QUERYPARSER_H

#include <string>
#include <vector>

class QueryManager {
    static const std::string helpMessage;
public:
    static void assertExpr(bool expr, std::string message);
    static std::vector<std::string> splitLine(std::string line, char delimiter);
    static void parseAndExecute(std::string line);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_QUERYPARSER_H
