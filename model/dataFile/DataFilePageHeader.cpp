//
// Created by sercanersoy on 29.07.2019.
//

#include "DataFilePageHeader.h"

DataFilePageHeader::DataFilePageHeader() {
    nofRecords = 0;
    firstAvailRecord = 0;
};

DataFilePageHeader &DataFilePageHeader::operator=(const DataFilePageHeader &rhs) = default;

DataFilePageHeader::DataFilePageHeader(char _nofRecords, char _firstAvailRecord) {
    nofRecords = _nofRecords;
    firstAvailRecord = _firstAvailRecord;
}
