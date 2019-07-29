//
// Created by sercanersoy on 29.07.2019.
//

#include <cstring>
#include "DataFileRecord.h"

DataFileRecord::DataFileRecord() {
    for (auto &field : fields) {
        std::memset(field, 0, DATA_FILE_RECORD_FIELD_SIZE);
    }
};

DataFileRecord::DataFileRecord(DataFileRecordHeader _recordHeader, char **_fields) {
    recordHeader = _recordHeader;
    for (int i = 0; i < DATA_FILE_RECORD_FIELD_LIMIT; ++i) {
        std::strcpy(fields[i], _fields[i]);
    }
}

DataFileRecord &DataFileRecord::operator=(const DataFileRecord &rhs) {
    recordHeader = rhs.recordHeader;
    for (int i = 0; i < DATA_FILE_RECORD_FIELD_LIMIT; ++i) {
        std::strcpy(fields[i], rhs.fields[i]);
    }
    return *this;
}
