//
// Created by sercanersoy on 27.07.2019.
//

#include <regex>
#include "FileManager.h"
#include "../model/dataFile/DataFilePage.h"

void FileManager::initializeSysCat(std::fstream &sysCat) {
    SysCatPage sysCatPages[SYS_CAT_PAGE_LIMIT];
    sysCat.seekp(0);
    sysCat.write((char *) sysCatPages, SYS_CAT_PAGE_LIMIT * SYS_CAT_PAGE_SIZE);
}

void FileManager::initializeDataFile(std::fstream &dataFile) {
    DataFilePage dataFilePages[DATA_FILE_PAGE_LIMIT];
    dataFile.seekp(0);
    dataFile.write((char *) dataFilePages, DATA_FILE_PAGE_LIMIT * DATA_FILE_PAGE_SIZE);
}

void FileManager::openOrCreateInitializeOpenSysCat(std::fstream &sysCat) {
    sysCat.open(std::string(DATA_DIR) + std::string(SYS_CAT_FILE_NAME),
                std::ios::in | std::ios::out | std::ios::binary);
    if (!sysCat.is_open()) {
        // create the file
        sysCat.open(std::string(DATA_DIR) + std::string(SYS_CAT_FILE_NAME), std::ios::out);
        sysCat.close();
        // then try to open with both in and out modes
        sysCat.open(std::string(DATA_DIR) + std::string(SYS_CAT_FILE_NAME),
                    std::ios::in | std::ios::out | std::ios::binary);
        if (!sysCat.is_open()) {
            // there is another problem, exit with status 1
            std::cerr << "Error opening " << SYS_CAT_FILE_NAME << "." << std::endl;
            exit(1);
        }
        initializeSysCat(sysCat);
    }
}

void FileManager::openOrCreateInitializeOpenDataFile(std::fstream &dataFile, std::string &typeName, int fileNo) {
    std::string filePath = std::string(DATA_DIR) + typeName + "#" + std::to_string(fileNo) + ".dat";
    dataFile.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
    if (!dataFile.is_open()) {
        // create the file
        dataFile.open(filePath, std::ios::out);
        dataFile.close();
        // then try to open with both in and out modes
        dataFile.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
        if (!dataFile.is_open()) {
            // there is another problem, exit with status 1
            std::cerr << "Error opening data file for " << typeName << "." << std::endl;
            exit(1);
        }
        initializeDataFile(dataFile);
    }
}

void FileManager::createDataDirIfAbsent() {
    DIR *dir = opendir(std::string(DATA_DIR).c_str());
    if (dir == nullptr) {
        // no directory named data, create one
        mkdir(DATA_DIR, 0777);
        dir = opendir(std::string(DATA_DIR).c_str());
        if (dir == nullptr) {
            std::cerr << "Error opening data/ directory." << std::endl;
        }
    }
    closedir(dir);
}

void FileManager::deleteDataFilesOfType(std::fstream &sysCat, std::string &typeName) {
    DIR *dir = opendir(std::string(DATA_DIR).c_str());
    dirent *ent = readdir(dir);
    while (ent != nullptr) {
        std::string entName = std::string(ent->d_name);
        std::regex regExpr("^" + typeName + "#[0-9]+.dat$");
        if (std::regex_match(entName, regExpr)) {
            std::string path = std::string(DATA_DIR) + ent->d_name;
            remove(path.c_str());
        }
        ent = readdir(dir);
    }
    closedir(dir);
}

std::vector<int> FileManager::returnSortedFileNumbersOfType(std::string &typeName) {
    std::regex regExpr("^" + typeName + "#([0-9]+).dat$");
    std::vector<int> vector;
    DIR *dir = opendir(DATA_DIR);
    dirent *ent = readdir(dir);
    while (ent != nullptr) {
        std::cmatch cm;
        if (std::regex_match(ent->d_name, cm, regExpr)) {
            int fileNumber = std::stoi(cm[1]);
            vector.push_back(fileNumber);
        }
        ent = readdir(dir);
    }
    std::sort(vector.begin(), vector.end());
    closedir(dir);
    return vector;
}

void FileManager::deleteDataFile(std::string typeName, int fileNo) {
    std::string path = DATA_DIR + typeName + "#" + std::to_string(fileNo) + ".dat";
    if (remove(path.c_str()) != 0) {
        throw std::string("Error deleting data file.");
    }
}
