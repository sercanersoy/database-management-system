//
// Created by sercanersoy on 27.07.2019.
//

#include <regex>
#include "FileManager.h"

void FileManager::initializeSysCat(std::fstream &sysCat) {
    SysCatPage sysCatPages[SYS_CAT_PAGE_LIMIT];
    sysCat.seekp(0);
    sysCat.write((char*)sysCatPages, SYS_CAT_PAGE_LIMIT*SYS_CAT_PAGE_SIZE);
}

void FileManager::initializeDataFile(std::fstream &dataFile) {

}

void FileManager::createInitializeSysCatAndOpen(std::fstream &sysCat) {
    sysCat.open(std::string(DATA_DIR) + std::string(SYS_CAT_FILE_NAME), std::ios::in | std::ios::out | std::ios::binary);
    if(!sysCat.is_open()) {
        // create the file
        sysCat.open(std::string(DATA_DIR) + std::string(SYS_CAT_FILE_NAME), std::ios::out);
        sysCat.close();
        // then try to open with both in and out modes
        sysCat.open(std::string(DATA_DIR) + std::string(SYS_CAT_FILE_NAME), std::ios::in | std::ios::out | std::ios::binary);
        if(!sysCat.is_open()) {
            // there is another problem, exit with status 1
            std::cerr << "Error opening " << SYS_CAT_FILE_NAME << "." << std::endl;
            exit(1);
        }
        initializeSysCat(sysCat);
    }
}

void FileManager::createDataDirIfAbsent() {
    DIR *dir = opendir(std::string(DATA_DIR).c_str());
    if(dir == nullptr) {
        // no directory named data, create one
        mkdir(DATA_DIR, 0777);
        dir = opendir(std::string(DATA_DIR).c_str());
        if(dir == nullptr) {
            std::cerr << "Error opening data/ directory." << std::endl;
        }
    }
}

void FileManager::deleteDataFilesOfType(std::fstream &sysCat, std::string &typeName) {
    DIR *dir = opendir(std::string(DATA_DIR).c_str());
    if(dir == nullptr) {
        std::cerr << "Directory " + std::string(DATA_DIR) + " is absent. Restart the program." << std::endl;
        return;
    }
    struct dirent *ent = readdir(dir);
    while(ent != nullptr) {
        std::string entName = std::string(ent->d_name);
        std::regex regExpr("^" + typeName + "#[0-9]*.dat$");
        if(std::regex_match(entName, regExpr)) {
            std::string path = std::string(DATA_DIR) + ent->d_name;
            remove(path.c_str());
        }
        ent = readdir(dir);
    }
}

void FileManager::createInitializeDataFileAndOpen(std::fstream &dataFile, std::string &typeName, int fileNo) {
    std::string filePath = std::string(DATA_DIR) + typeName + "#" + std::to_string(fileNo) + ".dat";
    dataFile.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
    if(!dataFile.is_open()) {
        // create the file
        dataFile.open(filePath, std::ios::out);
        dataFile.close();
        // then try to open with both in and out modes
        dataFile.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
        if(!dataFile.is_open()) {
            // there is another problem, exit with status 1
            std::cerr << "Error opening data file for " << typeName << "." << std::endl;
            exit(1);
        }
        initializeDataFile();
    }
}
