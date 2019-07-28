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
    static void createInitializeSysCatAndOpen(std::fstream &sysCat);
    static void createDataDirIfAbsent();
};


#endif //DATABASE_MANAGEMENT_SYSTEM_FILEMANAGER_H
