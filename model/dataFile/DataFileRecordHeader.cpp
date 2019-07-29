//
// Created by sercan.ersoy on 29.07.2019.
//

#include "DataFileRecordHeader.h"

DataFileRecordHeader::DataFileRecordHeader() {
    valid = 0;
};

DataFileRecordHeader::DataFileRecordHeader(char _valid) {
    valid = _valid;
}

DataFileRecordHeader &DataFileRecordHeader::operator=(const DataFileRecordHeader &rhs) = default;
