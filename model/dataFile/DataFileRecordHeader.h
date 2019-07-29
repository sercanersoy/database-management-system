//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_DATAFILERECORDHEADER_H
#define DATABASE_MANAGEMENT_SYSTEM_DATAFILERECORDHEADER_H


class DataFileRecordHeader {
public:
    char valid;

    DataFileRecordHeader();

    explicit DataFileRecordHeader(char _valid);

    DataFileRecordHeader &operator=(const DataFileRecordHeader &rhs);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_DATAFILERECORDHEADER_H
