//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGE_H
#define DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGE_H


#include "DataFilePageHeader.h"
#include "DataFileRecord.h"

class DataFilePage {
public:
    DataFilePageHeader pageHeader;
    DataFileRecord records[DATA_FILE_RECORD_LIMIT];

    DataFilePage();
    DataFilePage(DataFilePageHeader _pageHeader, DataFileRecord *_records);
    DataFilePage &operator=(const DataFilePage &rhs);
    static DataFilePage readFromFile(std::fstream &file, int pageNo);
    void writeToFile(std::fstream &file, int pageNo);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGE_H
