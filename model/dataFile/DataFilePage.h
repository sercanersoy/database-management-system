//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGE_H
#define DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGE_H


#include "DataFilePageHeader.h"
#include "DataFileRecord.h"

class DataFilePage {
    DataFilePageHeader header;
    DataFileRecord records[DATA_FILE_RECORD_LIMIT];
};


#endif //DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGE_H
