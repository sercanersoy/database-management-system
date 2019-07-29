//
// Created by sercanersoy on 27.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_FILEMANAGER_H
#define DATABASE_MANAGEMENT_SYSTEM_FILEMANAGER_H


#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
#include "../config.h"
#include "../model/sysCat/SysCatPage.h"

class FileManager {
public:
    static void initializeSysCat(std::fstream &sysCat);

    static void initializeDataFile(std::fstream &dataFile);

    static void openOrCreateInitializeOpenSysCat(std::fstream &sysCat);

    static void openOrCreateInitializeOpenDataFile(std::fstream &dataFile, std::string &typeName, int fileNo);

    static void createDataDirIfAbsent();

    static void deleteDataFilesOfType(std::fstream &sysCat, std::string &typeName);

    static std::vector<int> returnSortedFileNumbersOfType(std::string &typeName);

    static void deleteDataFile(std::string typeName, int fileNo);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_FILEMANAGER_H
