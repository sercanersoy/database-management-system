//
// Created by sercanersoy on 29.07.2019.
//

#include <fstream>
#include "DataFilePage.h"

DataFilePage::DataFilePage() = default;

DataFilePage::DataFilePage(DataFilePageHeader _pageHeader, DataFileRecord *_records) {
    pageHeader = _pageHeader;
    for (int i = 0; i < DATA_FILE_RECORD_LIMIT; ++i) {
        records[i] = _records[i];
    }
}

DataFilePage &DataFilePage::operator=(const DataFilePage &rhs) {
    pageHeader = rhs.pageHeader;
    for (int i = 0; i < DATA_FILE_RECORD_LIMIT; ++i) {
        records[i] = rhs.records[i];
    }
    return *this;
}

DataFilePage DataFilePage::readFromFile(std::fstream &file, int pageNo) {
    DataFilePage dataFilePage;
    file.seekg(pageNo * DATA_FILE_PAGE_SIZE);
    file.read((char*) &dataFilePage, DATA_FILE_PAGE_SIZE);
    return dataFilePage;
}

void DataFilePage::writeToFile(std::fstream &file, int pageNo) {
    file.seekp(pageNo * DATA_FILE_PAGE_SIZE);
    file.write((char*) this, DATA_FILE_PAGE_SIZE);
}
