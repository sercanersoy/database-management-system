//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_DATAFILERECORD_H
#define DATABASE_MANAGEMENT_SYSTEM_DATAFILERECORD_H


#include "../../config.h"
#include "DataFileRecordHeader.h"

class DataFileRecord {
public:
    DataFileRecordHeader recordHeader;
    char fields[DATA_FILE_RECORD_FIELD_LIMIT][DATA_FILE_RECORD_FIELD_SIZE];

    DataFileRecord();

    DataFileRecord(DataFileRecordHeader _recordHeader, char **_fields);

    DataFileRecord &operator=(const DataFileRecord &rhs);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_DATAFILERECORD_H
