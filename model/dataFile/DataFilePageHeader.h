//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGEHEADER_H
#define DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGEHEADER_H


class DataFilePageHeader {
    char nofRecords;
    char firstAvailRecord;

    DataFilePageHeader();
    DataFilePageHeader(char _nofRecords, char _firstAvailRecord);
    DataFilePageHeader &operator=(const DataFilePageHeader& rhs);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_DATAFILEPAGEHEADER_H
